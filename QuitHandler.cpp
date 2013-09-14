/* 
 * File:   QuitHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 11, 2013, 1:55 PM
 */
#include "QuitHandler.h"
#include "main.h"
#include <stdlib.h>

QuitHandler* QuitHandler::instance() {
    static QuitHandler* instance = new QuitHandler();
    return instance;
}

QuitHandler::~QuitHandler() {
}

void QuitHandler::doHandleCommand(string commandLine) {
    throw this->getFarewellMessage();
}

string QuitHandler::getHelpString() {
    return "quit\t-- exit the program";
}

string QuitHandler::getCommandPrefix() {
    return "quit";
}

string QuitHandler::getName() {
    return "QuitHandler";
}

bool QuitHandler::canHandle(string commandLine) {
    return commandLine == this->getCommandPrefix();
}

string QuitHandler::getFarewellMessage() {
    static string farewellMessages[] = {
      "Good-bye",
      "See ya, wouldn't wanna be ya!",
      "It's been real and it's been fun, but it hasn't been real fun.",
      "So long and thanks for all the fish!",
      "Hasta la vista, baby!",
      "I'll be back.",
      "It's too late for me.  Save yourself.",
      "Dr. Chandra, will I dream?",
      "May the force be with you."
    };
    static int fm_size = 9;
    
    srand(time(NULL));
    int randomIndex = rand() % fm_size;
    
    return farewellMessages[randomIndex];
}