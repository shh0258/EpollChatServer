/*
 * Tcp.h
 *
 *  Created on: 2018. 5. 16.
 *      Author: han
 */

#ifndef TCP_H_
#define TCP_H_
#include "DefineInfo.h"

class Tcp {
protected:
	int sock;
	struct sockaddr_in serv_adr;

public:
	Tcp(){};
	void socketInit();
	int getSock();
	virtual ~Tcp();
};

#endif /* TCP_H_ */
