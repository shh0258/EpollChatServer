/*
 * TcpServer.cpp
 *
 *  Created on: 2018. 5. 16.
 *      Author: han
 */

#include "TcpServer.h"

void TcpServer::memsetServ_adr(int port) {
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(port);
}

void TcpServer::bindSock() {
	if(bind(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))== -1) {
		puts("bind error");
	}
}

void TcpServer::listenSock() {
	if(listen(sock, 100) == -1) {
		puts("listen error");
	}
	setNonBlocking(sock);
}

TcpServer::~TcpServer() {
	// TODO Auto-generated destructor stub
}
void TcpServer::setNonBlocking(int sock) {
	fcntl(sock, F_SETFL, fcntl(sock, F_GETFD, 0) | O_NONBLOCK);
}

