/* 
 * File:   PutMessage.h
 * Author: kmcqueen
 *
 * Created on September 12, 2013, 10:17 PM
 */

#ifndef PUTMESSAGE_H
#define	PUTMESSAGE_H

#include "Message.h"

class PutMessage : public Message {
public:
    PutMessage(string user, string subject, string body);
    PutMessage(const PutMessage& orig);
    virtual ~PutMessage();

protected:
    virtual string getHeader();
    virtual string getBody();

private:
    string subject;
    string body;
};

#endif	/* PUTMESSAGE_H */

