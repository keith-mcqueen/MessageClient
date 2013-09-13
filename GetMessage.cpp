/* 
 * File:   GetMessage.cpp
 * Author: kmcqueen
 * 
 * Created on September 13, 2013, 2:10 AM
 */
#include "GetMessage.h"

#include <sstream>

GetMessage::GetMessage(string user, string number) : Message("get", user) {
    this->number = number;
}

GetMessage::GetMessage(const GetMessage& orig) : Message("get", orig.user) {
    this->number = orig.number;
}

GetMessage::~GetMessage() {
}

string GetMessage::getHeader() {
    stringstream ss;
    
    ss << Message::getHeader() << " ";
    ss << this->number;
    
    return ss.str();
}