/* 
 * File:   MessageCommandHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 13, 2013, 12:31 AM
 */
#include "MessageCommandHandler.h"

#include "Message.h"
#include "main.h"

MessageCommandHandler::~MessageCommandHandler() {
}

void MessageCommandHandler::doHandle(string commandLine) {
    Message* msg = this->prepareMessage(commandLine);
    if (NULL == msg) {
        return;
    }
    debug("prepared message:\n" + msg->toString());
    
    // TODO send message to server
    
    // TODO get response from server
    
    // TODO output error (if any)
}

