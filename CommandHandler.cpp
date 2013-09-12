/* 
 * File:   CommandHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 11, 2013, 12:25 PM
 */

#include "CommandHandler.h"
#include "QuitHandler.h"
#include "HelpHandler.h"

CommandHandler::CommandHandler() {
}

CommandHandler::CommandHandler(const CommandHandler& orig) {
}

CommandHandler::~CommandHandler() {
}

list<CommandHandler*> CommandHandler::getHandlers() {
    list<CommandHandler*> handlers;
    
    handlers.push_front(QuitHandler::instance());
    
    // order is important here -- the HelpHandler *must* be the last in the list
    handlers.push_back(HelpHandler::instance());
    
    return handlers;
}

bool CommandHandler::canHandle(string commandLine) {
    size_t found = commandLine.find(this->getCommandPrefix());
    if (found == string::npos) {
        return false;
    }
    
    return found == 0;
}

