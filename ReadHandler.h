/* 
 * File:   ReadHandler.h
 * Author: kmcqueen
 *
 * Created on September 13, 2013, 1:59 AM
 */

#ifndef READHANDLER_H
#define	READHANDLER_H

#include "MessageCommandHandler.h"

class ReadHandler : public MessageCommandHandler {
public:
    virtual ~ReadHandler();
    virtual string getHelpString();

    static ReadHandler* instance();

protected:
    virtual string getCommandPrefix();
    virtual string getName();
    virtual Message* prepareMessage(string commandLine);

private:

};

#endif	/* READHANDLER_H */

