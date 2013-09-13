/* 
 * File:   MessageCommandHandler.h
 * Author: kmcqueen
 *
 * Created on September 13, 2013, 12:31 AM
 */

#ifndef MESSAGECOMMANDHANDLER_H
#define	MESSAGECOMMANDHANDLER_H

#include "CommandHandler.h"
#include "Message.h"

class MessageCommandHandler : public CommandHandler {
public:
    //MessageCommandHandler();
    //MessageCommandHandler(const MessageCommandHandler& orig);
    virtual ~MessageCommandHandler();

protected:
    virtual void doHandle(string commandLine);
    virtual Message* prepareMessage(string commandLine) = 0;

private:

};

#endif	/* MESSAGECOMMANDHANDLER_H */

