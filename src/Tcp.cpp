/*
 * Tcp.cpp
 *
 *  Created on: 2018. 5. 16.
 *      Author: han
 */

#include "Tcp.h"

void Tcp::socketInit() {
	sock=socket(PF_INET, SOCK_STREAM, 0);
}

int Tcp::getSock() {
	return sock;
}

Tcp::~Tcp() {
	// TODO Auto-generated destructor stub
}

