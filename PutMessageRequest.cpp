/* 
 * File:   PutMessage.cpp
 * Author: kmcqueen
 * 
 * Created on September 12, 2013, 10:17 PM
 */
#include "PutMessageRequest.h"

#include <sstream>

PutMessage::PutMessage(string user, string subject, string body) : Request("put", user) {
    this->subject = subject;
    this->body = body;
}

PutMessage::PutMessage(const PutMessage& orig) : Request("put", orig.user) {
    this->subject = orig.subject;
    this->body = orig.body;
}

PutMessage::~PutMessage() {
}

string PutMessage::getHeader() {
    stringstream ss;
    
    ss << Request::getHeader() << " ";
    ss << this->subject << " ";
    ss << this->body.size();
    
    return ss.str();
}

string PutMessage::getBody() {
    return this->body;
}