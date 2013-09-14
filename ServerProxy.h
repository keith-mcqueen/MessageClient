/* 
 * File:   ServerProxy.h
 * Author: kmcqueen
 *
 * Created on September 13, 2013, 1:01 PM
 */

#ifndef SERVERPROXY_H
#define	SERVERPROXY_H

#include <string>
#include "Request.h"

using namespace std;

class ServerProxy {
public:
    ServerProxy(string host, int port);
    virtual ~ServerProxy();
    bool sendRequest(Request* request);
    string getResponseLine();
    string getResponseString(int length);

private:
    void init(string hostname, int port);
    
    int server;
    string leftOvers;
};

#endif	/* SERVERPROXY_H */

