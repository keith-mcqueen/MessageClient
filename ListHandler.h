/* 
 * File:   ListHandler.h
 * Author: kmcqueen
 *
 * Created on September 13, 2013, 1:46 AM
 */

#ifndef LISTHANDLER_H
#define	LISTHANDLER_H

#include "MessageCommandHandler.h"

class ListHandler : public MessageCommandHandler {
public:
    virtual ~ListHandler();
    virtual string getHelpString();

    static ListHandler* instance();

protected:
    virtual string getCommandPrefix();
    virtual string getName();
    virtual Message* prepareMessage(string commandLine);

private:

};

#endif	/* LISTHANDLER_H */

