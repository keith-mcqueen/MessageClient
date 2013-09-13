/* 
 * File:   GetMessage.h
 * Author: kmcqueen
 *
 * Created on September 13, 2013, 2:10 AM
 */

#ifndef GETMESSAGE_H
#define	GETMESSAGE_H

#include "Message.h"

class GetMessage : public Message {
public:
    GetMessage(string user, string number);
    GetMessage(const GetMessage& orig);
    virtual ~GetMessage();

protected:
    virtual string getHeader();

private:
    string number;

};

#endif	/* GETMESSAGE_H */

