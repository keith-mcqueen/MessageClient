/* 
 * File:   HelpHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 11, 2013, 5:20 PM
 */
#include "HelpHandler.h"

#include <iostream>
#include "main.h"

HelpHandler* HelpHandler::instance() {
    static HelpHandler* instance = new HelpHandler();
    return instance;
}

HelpHandler::~HelpHandler() {
}

bool HelpHandler::canHandle(string commandLine) {
    return true;
}

string HelpHandler::getHelpString() {
    return "help\t-- print this message";
}

string HelpHandler::getCommandPrefix() {
    return "help";
}

string HelpHandler::getName() {
    return "HelpHandler";
}

void HelpHandler::doHandle(string commandLine) {
    list<CommandHandler*> handlers = CommandHandler::getHandlers();
    for (list<CommandHandler*>::iterator it = handlers.begin(); 
            it != handlers.end(); 
            ++it) {
        CommandHandler * handler = *it;
        
        cout << handler->getHelpString() << endl;
    }
}

