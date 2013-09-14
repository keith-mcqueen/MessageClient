/* 
 * File:   MessageCommandHandler.h
 * Author: kmcqueen
 *
 * Created on September 13, 2013, 12:31 AM
 */

#ifndef REQUESTCOMMANDHANDLER_H
#define	REQUESTCOMMANDHANDLER_H

#include "CommandHandler.h"
#include "Request.h"

class RequestCommandHandler : public CommandHandler {
public:
    virtual ~RequestCommandHandler();

protected:
    virtual void doHandleCommand(string commandLine);
    virtual void doHandleResponse(string response);
    virtual Request* prepareRequest(string commandLine) = 0;

private:

};

#endif	/* MESSAGECOMMANDHANDLER_H */

