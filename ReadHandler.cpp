/* 
 * File:   ReadHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 13, 2013, 1:59 AM
 */
#include "ReadHandler.h"

#include <iostream>
#include <stdlib.h>
#include "GetMessageRequest.h"
#include "main.h"

ReadHandler* ReadHandler::instance() {
    static ReadHandler* instance = new ReadHandler();
    return instance;
}

ReadHandler::~ReadHandler() {
}

Request* ReadHandler::prepareRequest(string commandLine) {
    string prefix = this->getCommandPrefix();
    
    // extract the recipient (which is between the prefix and the space)
    int space = commandLine.find(" ", prefix.size());
    if (space == string::npos) {
        this->printUnexpectedCommand(commandLine);
        return NULL;
    }
    string recipient = commandLine.substr(prefix.size(), space - prefix.size());
    debug("\trecipient is: " + recipient);
    
    // extract the number (which is everything after the space)
    string number = commandLine.substr(space + 1);
    debug("\tnumber is: " + number);
    
    return new GetMessageRequest(recipient, number);
}

void ReadHandler::doHandleResponse(string response) {
    string _message_ = "message ";
    int _message_len_ = _message_.length();
    
    // make sure that the response begins with "message "
    if (response.find(_message_) != 0) {
        debug("ReadHandler::doHandleResponse -- Unexpected response: " + response);
        return;
    }
    
    // find the space between [subject] and [length]
    int space = response.find(" ", _message_len_);
    if (space == string::npos) {
        debug("ReadHandler::doHandleResponse -- Unexpected response: " + response);
        return;        
    }
    
    // extract the subject
    string subject = response.substr(_message_len_, space - _message_len_);
    cout << subject << endl;
    
    // parse out the number of messages from the response
    int msgLen = atoi(response.substr(space + 1).c_str());
    
    // get the server proxy
    ServerProxy* server = ServerProxy::instance();
    
    // get the message body from the server
    string body = server->getResponseString(msgLen);
    
    // output the message body
    cout << body << endl;
}

string ReadHandler::getHelpString() {
    return "read [recipient] [number]\n\t-- get the full message by [number] addressed to the [recipient]";
}

string ReadHandler::getCommandPrefix() {
    return "read ";
}

string ReadHandler::getName() {
    return "ReadHandler";
}