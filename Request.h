/* 
 * File:   Message.h
 * Author: kmcqueen
 *
 * Created on September 12, 2013, 9:53 PM
 */

#ifndef REQUEST_H
#define	REQUEST_H

#include <string>

using namespace std;

class Request {
public:
    Request(string type, string user);
    virtual ~Request();
    
    string toString();

protected:
    virtual string getHeader();
    virtual string getBody();
    
private:
    string type;
    string user;
};

#endif	/* MESSAGE_H */

