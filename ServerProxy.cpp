/* 
 * File:   ServerProxy.cpp
 * Author: kmcqueen
 * 
 * Created on September 13, 2013, 1:01 PM
 */
#include "ServerProxy.h"

#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "main.h"

ServerProxy* ServerProxy::instance() {
    static ServerProxy* instance = new ServerProxy();
    return instance;
}

ServerProxy::~ServerProxy() {
    delete this->buf;
}

void ServerProxy::init(string hostname, int port) {
    this->buflen = 1024;
    this->buf = new char[this->buflen + 1];
    
    struct sockaddr_in server_addr;

    // use DNS to get IP address
    debug("ServerProxy::init -- getting address for host name: " + hostname);
    struct hostent *hostEntry;
    hostEntry = gethostbyname(hostname.c_str());
    if (!hostEntry) {
        cout << "No such host name: " << hostname << endl;
        exit(-1);
    }

    // setup socket address structure
    debug("ServerProxy::init -- setting up socket address struct");
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, hostEntry->h_addr_list[0], hostEntry->h_length);

    // create socket
    debug("ServerProxy::init -- creating the socket");
    this->server = socket(PF_INET,SOCK_STREAM,0);
    if (! this->server) {
        perror("socket");
        exit(-1);
    }

    // connect to server
    debug("ServerProxy::init -- connecting to the server");
    if (connect(this->server,(const struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("connect");
        exit(-1);
    }
}

bool ServerProxy::sendRequest(Request* request) {
    // get the request string
    string requestString = request->toString();
    
    // initialize the number of characters to send (the length of the request string)
    int numCharsToSend = requestString.size();
    int numCharsSent;
    
    const char* req = requestString.c_str();
    
    // as long as there are still characters to be sent...
    while (numCharsToSend) {
        debug("ServerProxy::sendRequest -- sending request data to server");
        if ((numCharsSent = send(this->server, req, numCharsToSend, 0)) < 0) {
            if (errno == EINTR) {
                // the socket call was interrupted -- just try again
                continue;
            } else {
                // something bad happened
                perror("write");
                return false;
            }
        } else if (numCharsSent == 0) {
            // the socket is closed
            return false;
        }
        
        // update the number of characters left to be sent
        numCharsToSend -= numCharsSent;
        
        // update the request pointer position
        req += numCharsSent;
    }
    
    return true;
}

string ServerProxy::getResponseLine() {
    debug("ServerProxy::getResponseLine() -- getting a response line from the server");
    
    // start out with the leftovers from the last call
    string response = this->leftOvers;
    
    int newline;
    while ((newline = response.find("\n")) == string::npos) {
        int numCharsRecvd = recv(this->server, this->buf, this->buflen, 0);
        if (numCharsRecvd < 0) {
            if (errno == EINTR) {
                // the socket call was interrupted, just try again
                continue;
            } else {
                // something bad happened
                //perror("read");
                return "";
            }
        } else if (numCharsRecvd == 0) {
            // the socket is closed
            return "";
        }
        
        // append the received characters (bytes) to the response
        response.append(buf, numCharsRecvd);
    }
    
    // save everything after the newline for later
    this->leftOvers = response.substr(newline + 1);
    
    // return the portion of the response that precedes the newline (but keep the newline))
    return response.substr(0, newline + 1);
}

string ServerProxy::getResponseString(int length) {
    debug("ServerProxy::getResponseString -- getting a response string from the server");
    
    // start out with the leftovers from the last call
    string response = this->leftOvers;
    
    while (response.length() < length) {
        int numCharsRecvd = recv(this->server, this->buf, this->buflen, 0);
        if (numCharsRecvd < 0) {
            if (errno == EINTR) {
                // the socket call was interrupted, just try again
                continue;
            } else {
                // something bad happened
                //perror("read");
                return "";
            }
        } else if (numCharsRecvd == 0) {
            // the socket is closed
            return "";
        }
        
        // append the received characters (bytes) to the response
        response.append(buf, numCharsRecvd);
    }
    
    // save everything after the newline for later
    this->leftOvers = response.substr(length);
    
    // return the portion of the response that precedes the newline
    return response.substr(0, length);
}