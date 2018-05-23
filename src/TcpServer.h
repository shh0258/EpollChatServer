/*
 * TcpServer.h
 *
 *  Created on: 2018. 5. 16.
 *      Author: han
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_
#include "Tcp.h"
#include "DefineInfo.h"

class TcpServer :public Tcp{
private:
	int clnt_sock;

public:
	TcpServer(){};
	void memsetServ_adr(int port);
	void bindSock();
	void listenSock();
	void setNonBlocking(int sock);
	virtual ~TcpServer();
};

#endif /* TCPSERVER_H_ */
