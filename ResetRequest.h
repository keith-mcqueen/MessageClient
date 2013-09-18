/* 
 * File:   ResetRequest.h
 * Author: kmcqueen
 *
 * Created on September 17, 2013, 5:43 PM
 */

#ifndef RESETREQUEST_H
#define	RESETREQUEST_H

#include "Request.h"

class ResetRequest : public Request {
public:
    ResetRequest();
    virtual ~ResetRequest();

protected:
    virtual string getHeader();

private:

};

#endif	/* RESETREQUEST_H */

