/* 
 * File:   ResetHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 17, 2013, 5:38 PM
 */

#include "ResetHandler.h"
#include "ResetRequest.h"

ResetHandler* ResetHandler::instance() {
    static ResetHandler* instance = new ResetHandler();
    return instance;
}

ResetHandler::~ResetHandler() {
}

Request* ResetHandler::prepareRequest(string commandLine) {
    return new ResetRequest();
}

string ResetHandler::getCommandPrefix() {
    return "reset";
}

string ResetHandler::getName() {
    return "ResetHandler";
}

string ResetHandler::getHelpString() {
    return "reset\t-- clear all messages (for development purposes only)";
}

