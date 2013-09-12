/* 
 * File:   QuitHandler.h
 * Author: kmcqueen
 *
 * Created on September 11, 2013, 1:55 PM
 */

#ifndef QUITHANDLER_H
#define	QUITHANDLER_H

#include "CommandHandler.h"

class QuitHandler : public CommandHandler {
public:
    virtual ~QuitHandler();
    virtual void handle(string commandLine);
    virtual string getHelpString();
    virtual bool canHandle(string commandLine);
    
    static QuitHandler* instance();

protected:
    virtual string getCommandPrefix();

private:

};

#endif	/* QUITHANDLER_H */

