/* 
 * File:   MessageCommandHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 13, 2013, 12:31 AM
 */
#include "RequestCommandHandler.h"

#include <iostream>
#include "Request.h"
#include "main.h"

RequestCommandHandler::~RequestCommandHandler() {
}

void RequestCommandHandler::doHandleCommand(string commandLine) {
    Request* msg = this->prepareRequest(commandLine);
    if (NULL == msg) {
        return;
    }
    debug("RequestCommandHandler::doHandle -- prepared message:\n" + msg->toString());
    
    // send request to server
    debug("RequestCommandHandler::doHandle -- send the request to the server");
    ServerProxy* server = ServerProxy::instance();
    server->sendRequest(msg);
    
    // delete the request (recover memory)
    delete msg;
    
    // get response (line) from server
    string response = server->getResponseLine();
    debug("RequestCommandHandler::doHandleCommand -- server response (line) is: " + response);
    
    // if the response starts with "OK" then we can just quit now
    if (response.find("OK") == 0) {
        return;
    }
    
    // if the response starts with "error", then output the error and quit now
    if (response.find("error") == 0) {
        cout << response;
        return;
    }
    
    // perform further processing (as necessary) on the response
    this->doHandleResponse(response);
}

void RequestCommandHandler::doHandleResponse(string response) {
    // no op
}

