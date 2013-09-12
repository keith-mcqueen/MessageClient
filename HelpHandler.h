/* 
 * File:   HelpHandler.h
 * Author: kmcqueen
 *
 * Created on September 11, 2013, 5:20 PM
 */

#ifndef HELPHANDLER_H
#define	HELPHANDLER_H

#include "CommandHandler.h"

class HelpHandler : public CommandHandler {
public:
    virtual ~HelpHandler();
    virtual void handle(string commandLine);
    virtual string getHelpString();
    virtual bool canHandle(string commandLine);
    
    static HelpHandler* instance();

protected:
    virtual string getCommandPrefix();

private:

};

#endif	/* HELPHANDLER_H */
