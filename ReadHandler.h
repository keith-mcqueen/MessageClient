/* 
 * File:   ReadHandler.h
 * Author: kmcqueen
 *
 * Created on September 13, 2013, 1:59 AM
 */

#ifndef READHANDLER_H
#define	READHANDLER_H

#include "RequestCommandHandler.h"

class ReadHandler : public RequestCommandHandler {
public:
    virtual ~ReadHandler();
    virtual string getHelpString();

    static ReadHandler* instance();

protected:
    virtual string getCommandPrefix();
    virtual string getName();
    virtual Request* prepareRequest(string commandLine);
    virtual void doHandleResponse(string response);

private:

};

#endif	/* READHANDLER_H */

