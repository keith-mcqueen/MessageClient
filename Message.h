/* 
 * File:   Message.h
 * Author: kmcqueen
 *
 * Created on September 12, 2013, 9:53 PM
 */

#ifndef MESSAGE_H
#define	MESSAGE_H

#include <string>

using namespace std;

class Message {
public:
    Message(string type, string user);
    Message(const Message& orig);
    virtual ~Message();
    
    string toString();

protected:
    virtual string getHeader();
    virtual string getBody();
    
    string type;
    string user;
};

#endif	/* MESSAGE_H */

