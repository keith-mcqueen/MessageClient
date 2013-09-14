/* 
 * File:   SendHandler.h
 * Author: kmcqueen
 *
 * Created on September 12, 2013, 5:35 PM
 */

#ifndef SENDHANDLER_H
#define	SENDHANDLER_H

#include "RequestCommandHandler.h"

class SendHandler : public RequestCommandHandler {
public:
    virtual ~SendHandler();
    virtual string getHelpString();

    static SendHandler* instance();

protected:
    virtual string getCommandPrefix();
    virtual string getName();
    virtual Request* prepareRequest(string commandLine);

private:

};

#endif	/* SENDHANDLER_H */

