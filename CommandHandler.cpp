/* 
 * File:   CommandHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 11, 2013, 12:25 PM
 */
#include "CommandHandler.h"

#include <iostream>
#include "QuitHandler.h"
#include "HelpHandler.h"
#include "SendHandler.h"
#include "main.h"
#include "ListHandler.h"
#include "ReadHandler.h"

CommandHandler::CommandHandler() {
}

CommandHandler::CommandHandler(const CommandHandler& orig) {
}

CommandHandler::~CommandHandler() {
}

list<CommandHandler*> CommandHandler::getHandlers() {
    list<CommandHandler*> handlers;
    
    // add the send handler
    handlers.push_back(SendHandler::instance());
    
    // add the list handler
    handlers.push_back(ListHandler::instance());
    
    // add the read handler
    handlers.push_back(ReadHandler::instance());
    
    // add the quit handler
    handlers.push_back(QuitHandler::instance());
    
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

void CommandHandler::handle(string commandLine) {
    debug(this->getName() + " is handling command line: " + commandLine);
    if (!this->canHandle(commandLine)) {
        this->printUnexpectedCommand(commandLine);
        return;
    }
    
    this->doHandle(commandLine);
}

void CommandHandler::printUnexpectedCommand(string commandLine) {
    cout << "Unexpected command line: " << commandLine << endl;
    cout << "Command should be of the form:\n" << this->getHelpString() << endl;
}

