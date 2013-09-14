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
    virtual string getHelpString();
    virtual bool canHandle(string commandLine);
    
    static HelpHandler* instance();

protected:
    virtual string getCommandPrefix();
    virtual string getName();
    virtual void doHandleCommand(string commandLine);

private:

};

#endif	/* HELPHANDLER_H */

