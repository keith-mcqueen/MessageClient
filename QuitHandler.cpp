/* 
 * File:   QuitHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 11, 2013, 1:55 PM
 */

#include "QuitHandler.h"
#include "main.h"

QuitHandler* QuitHandler::instance() {
    static QuitHandler* instance = new QuitHandler();
    return instance;
}

QuitHandler::~QuitHandler() {
}

void QuitHandler::handle(string commandLine) {
    debug("QuitHandler is handling command line: " + commandLine);
    throw this->getCommandPrefix();
}

string QuitHandler::getHelpString() {
    return "quit\t-- exit the program";
}

string QuitHandler::getCommandPrefix() {
    return "quit";
}

bool QuitHandler::canHandle(string commandLine) {
    return commandLine == this->getCommandPrefix();
}

