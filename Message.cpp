/* 
 * File:   Message.cpp
 * Author: kmcqueen
 * 
 * Created on September 12, 2013, 9:53 PM
 */
#include "Message.h"

#include <sstream>

Message::Message(string type, string user) {
    this->type = type;
    this->user = user;
}

Message::Message(const Message& orig) {
    this->type = orig.type;
    this->user = orig.user;
}

Message::~Message() {
}

string Message::toString() {
    stringstream ss;
    
    ss << this->getHeader() << endl;
    ss << this->getBody();
    
    return ss.str();
}

string Message::getHeader() {
    stringstream ss;
    
    ss << this->type << " " << this->user;
    
    return ss.str();
}

string Message::getBody() {
    return "";
}