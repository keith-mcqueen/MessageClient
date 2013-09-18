/* 
 * File:   ResetHandler.h
 * Author: kmcqueen
 *
 * Created on September 17, 2013, 5:38 PM
 */

#ifndef RESETHANDLER_H
#define	RESETHANDLER_H

#include "RequestCommandHandler.h"

class ResetHandler : public RequestCommandHandler {
public:
    virtual ~ResetHandler();
    virtual string getHelpString();

    static ResetHandler* instance();

protected:
    virtual string getCommandPrefix();
    virtual string getName();
    virtual Request* prepareRequest(string commandLine);

private:

};

#endif	/* RESETHANDLER_H */

