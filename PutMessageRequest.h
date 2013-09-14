/* 
 * File:   PutMessage.h
 * Author: kmcqueen
 *
 * Created on September 12, 2013, 10:17 PM
 */

#ifndef PUTMESSAGEREQUEST_H
#define	PUTMESSAGEREQUEST_H

#include "Request.h"

class PutMessage : public Request {
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

