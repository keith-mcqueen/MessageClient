/* 
 * File:   ResetRequest.cpp
 * Author: kmcqueen
 * 
 * Created on September 17, 2013, 5:43 PM
 */

#include "ResetRequest.h"

ResetRequest::ResetRequest() : Request("reset", "") {
}

ResetRequest::~ResetRequest() {
}

string ResetRequest::getHeader() {
    return "reset";
}
