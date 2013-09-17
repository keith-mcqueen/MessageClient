/* 
 * File:   Message.cpp
 * Author: kmcqueen
 * 
 * Created on September 12, 2013, 9:53 PM
 */
#include "Request.h"

#include <sstream>

Request::Request(string type, string user) {
    this->type = type;
    this->user = user;
}

Request::~Request() {
}

string Request::toString() {
    stringstream ss;
    
    ss << this->getHeader() << endl;
    ss << this->getBody();
    
    return ss.str();
}

string Request::getHeader() {
    stringstream ss;
    
    ss << this->type << " " << this->user;
    
    return ss.str();
}

string Request::getBody() {
    return "";
}