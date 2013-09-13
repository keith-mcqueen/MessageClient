/* 
 * File:   ReadHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 13, 2013, 1:59 AM
 */
#include "ReadHandler.h"

#include "GetMessage.h"
#include "main.h"

ReadHandler* ReadHandler::instance() {
    static ReadHandler* instance = new ReadHandler();
    return instance;
}

ReadHandler::~ReadHandler() {
}

Message* ReadHandler::prepareMessage(string commandLine) {
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
    
    return new GetMessage(recipient, number);
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