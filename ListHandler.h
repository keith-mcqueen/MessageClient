/* 
 * File:   ListHandler.h
 * Author: kmcqueen
 *
 * Created on September 13, 2013, 1:46 AM
 */

#ifndef LISTHANDLER_H
#define	LISTHANDLER_H

#include "RequestCommandHandler.h"

class ListHandler : public RequestCommandHandler {
public:
    virtual ~ListHandler();
    virtual string getHelpString();

    static ListHandler* instance();

protected:
    virtual string getCommandPrefix();
    virtual string getName();
    virtual Request* prepareRequest(string commandLine);
    virtual void doHandleResponse(string response);

private:

};

#endif	/* LISTHANDLER_H */

