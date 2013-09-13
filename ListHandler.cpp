/* 
 * File:   ListHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 13, 2013, 1:46 AM
 */
#include "ListHandler.h"

#include "main.h"

ListHandler* ListHandler::instance() {
    static ListHandler* instance = new ListHandler();
    return instance;
}

ListHandler::~ListHandler() {
}

Message* ListHandler::prepareMessage(string commandLine) {
    // extract the user
    string user = commandLine.substr(this->getCommandPrefix().size());
    debug("\tuser is: " + user);
    
    return new Message("list", user);
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