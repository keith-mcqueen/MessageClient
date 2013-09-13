/* 
 * File:   SendHandler.cpp
 * Author: kmcqueen
 * 
 * Created on September 12, 2013, 5:35 PM
 */
#include "SendHandler.h"

#include <iostream>
#include "PutMessage.h"
#include "main.h"

SendHandler* SendHandler::instance() {
    static SendHandler* instance = new SendHandler();
    return instance;
}

SendHandler::~SendHandler() {
}

Message* SendHandler::prepareMessage(string commandLine) {
    string prefix = this->getCommandPrefix();
    
    // extract the recipient (which is between the prefix and the space)
    int space = commandLine.find(" ", prefix.size());
    if (space == string::npos) {
        this->printUnexpectedCommand(commandLine);
        return NULL;
    }
    string recipient = commandLine.substr(prefix.size(), space - prefix.size());
    debug("\trecipient is: " + recipient);
    
    // extract the subject (which is everything after the space)
    string subject = commandLine.substr(space + 1);
    debug("\tsubject is: " + subject);
    
    // print prompt for user to enter message
    cout << "- Type your message.  End with a blank line. -" << endl;
    
    // read lines from the input until we get a blank line
    string content, line;
    while (getline(cin, line)) {
        if (line.size() == 0) {
            break;
        }
        
        if (!content.empty()) {
            content.append("\n");
        }
        content.append(line);
    }
    
    // prepare the message to be sent to the server
    PutMessage* msg = new PutMessage(recipient, subject, content);
    
    return msg;
}

string SendHandler::getHelpString() {
    return "send [recipient] [subject]\n\t-- send a new message with the [subject] to the [recipient]";
}

string SendHandler::getCommandPrefix() {
    // yes that space at the end is intentional
    return "send ";
}

string SendHandler::getName() {
    return "SendHandler";
}

