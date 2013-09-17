/* 
 * File:   ListHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 13, 2013, 1:46 AM
 */
#include "ListHandler.h"

#include <iostream>
#include <stdlib.h>
#include "main.h"

ListHandler* ListHandler::instance() {
    static ListHandler* instance = new ListHandler();
    return instance;
}

ListHandler::~ListHandler() {
}

Request* ListHandler::prepareRequest(string commandLine) {
    // extract the user
    string user = commandLine.substr(this->getCommandPrefix().size());
    debug("\tuser is: " + user);
    
    return new Request("list", user);
}

void ListHandler::doHandleResponse(string response) {
    // make sure that the response begins with "list"
    if (response.find("list") != 0) {
        debug("ListHandler::doHandleResponse -- Unexpected response: " + response);
        return;
    }
    
    // find the space between "list" and [number]
    int space = response.find(" ");
    if (space == string::npos) {
        debug("ListHandler::doHandleResponse -- Unexpected response: " + response);
        return;        
    }
    
    // parse out the number of messages from the response
    int numMsgs = atoi(response.substr(space + 1).c_str());
    
    // get the server proxy
    ServerProxy* server = ServerProxy::instance();
    
    // get a line from the server for each message
    for (int i = 0; i < numMsgs; i++) {
        // output the line to the user
        cout << server->getResponseLine();
    }
}

string ListHandler::getHelpString() {
    return "list [recipient]\n\t-- list all messages for the [recipient]";
}

string ListHandler::getCommandPrefix() {
    return "list ";
}

string ListHandler::getName() {
    return "ListHandler";
}