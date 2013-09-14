/* 
 * File:   GetMessage.cpp
 * Author: kmcqueen
 * 
 * Created on September 13, 2013, 2:10 AM
 */
#include "GetMessageRequest.h"

#include <sstream>

GetMessageRequest::GetMessageRequest(string user, string number) : Request("get", user) {
    this->number = number;
}

GetMessageRequest::GetMessageRequest(const GetMessageRequest& orig) : Request("get", orig.user) {
    this->number = orig.number;
}

GetMessageRequest::~GetMessageRequest() {
}

string GetMessageRequest::getHeader() {
    stringstream ss;
    
    ss << Request::getHeader() << " ";
    ss << this->number;
    
    return ss.str();
}