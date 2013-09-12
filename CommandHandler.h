/* 
 * File:   CommandHandler.h
 * Author: kmcqueen
 *
 * Created on September 11, 2013, 12:25 PM
 */

#ifndef COMMANDHANDLER_H
#define	COMMANDHANDLER_H

#include <string>
#include <list>

using namespace std;

class CommandHandler {
public:
    CommandHandler();
    CommandHandler(const CommandHandler& orig);
    virtual ~CommandHandler();
    virtual bool canHandle(string commandLine);
    virtual void handle(string commandLine) = 0;
    virtual string getHelpString() = 0;
    
    static list<CommandHandler*> getHandlers();

protected:
    virtual string getCommandPrefix() = 0;
};

#endif	/* COMMANDHANDLER_H */

