/* 
 * File:   main.h
 * Author: kmcqueen
 *
 * Created on September 12, 2013, 6:18 AM
 */

#ifndef MAIN_H
#define	MAIN_H

#include <string>
#include "ServerProxy.h"

using namespace std;

void debug(string info);

ServerProxy* getServer();

#endif	/* MAIN_H */

