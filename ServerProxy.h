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
    virtual ~ServerProxy();
    bool sendRequest(Request* request);
    string getResponseLine();
    string getResponseString(int length);
    void init(string hostname, int port);

    static ServerProxy* instance();

private:
    int server;
    string leftOvers;
    char* buf;
    int buflen;
};

#endif	/* SERVERPROXY_H */

