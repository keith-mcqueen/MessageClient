/* 
 * File:   main.cpp
 * Author: kmcqueen
 *
 * Created on September 11, 2013, 12:24 PM
 */
#include "main.h"

#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "CommandHandler.h"
#include "HelpHandler.h"

using namespace std;

void printUserPrompt() {
    cout << "% ";
}

bool DEBUG = false;

void debug(string info) {
    if (DEBUG) {
        cout << "[DEBUG] " << info << endl;
    }
}

CommandHandler* getCommandHandler(string commandLine) {
    debug("getting command handler for command line: " + commandLine);
    
    list<CommandHandler*> handlers = CommandHandler::getHandlers();
    for (list<CommandHandler*>::iterator it = handlers.begin(); 
            it != handlers.end(); 
            ++it) {
        CommandHandler* handler = *it;
        if (handler->canHandle(commandLine)) {
            return handler;
        }
    }
    
    debug("no command handler found for command line, defaulting to HelpHandler");
    return HelpHandler::instance();
}

/*
 * 
 */
int main(int argc, char** argv) {
    int option;
    
    int port = 3000;
    string host = "localhost";
    
    // process command line options using getopt()
    // see "man 3 getopt"
    while ((option = getopt(argc,argv,"s:p:d")) != -1) {
        switch (option) {
            case 'p':
                port = atoi(optarg);
                break;
            
            case 's':
                host = optarg;
                break;
                
            case 'd':
                DEBUG = true;
                break;
            
            default:
                cout << "msg [-s IP address] [-p port] [-d]" << endl;
                exit(EXIT_FAILURE);
        }
    }
    
    // initialize the server proxy
    ServerProxy* server = ServerProxy::instance();
    server->init(host, port);
    
    // read input from user
    try {
        string command;
        do {
            CommandHandler * handler = getCommandHandler(command);
            handler->handleCommand(command);
            
            printUserPrompt();
        } while (getline(cin, command));
    } catch (string & exc) {
        cout << exc << endl;
    }

    return 0;
}

