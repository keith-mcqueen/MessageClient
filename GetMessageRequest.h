/* 
 * File:   GetMessage.h
 * Author: kmcqueen
 *
 * Created on September 13, 2013, 2:10 AM
 */

#ifndef GETMESSAGEREQUEST_H
#define	GETMESSAGEREQUEST_H

#include "Request.h"

class GetMessageRequest : public Request {
public:
    GetMessageRequest(string user, string number);
    GetMessageRequest(const GetMessageRequest& orig);
    virtual ~GetMessageRequest();

protected:
    virtual string getHeader();

private:
    string number;

};

#endif	/* GETMESSAGE_H */

