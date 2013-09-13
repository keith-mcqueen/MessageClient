/* 
 * File:   SendHandler.h
 * Author: kmcqueen
 *
 * Created on September 12, 2013, 5:35 PM
 */

#ifndef SENDHANDLER_H
#define	SENDHANDLER_H

#include "MessageCommandHandler.h"

class SendHandler : public MessageCommandHandler {
public:
    virtual ~SendHandler();
    virtual string getHelpString();

    static SendHandler* instance();

protected:
    virtual string getCommandPrefix();
    virtual string getName();
    virtual Message* prepareMessage(string commandLine);

private:

};

#endif	/* SENDHANDLER_H */

