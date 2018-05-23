//============================================================================
// Name        : 180517_chatserver.cpp
// Author      : han
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "DefineInfo.h"
#include "TcpServer.h"
#include "EpollController.h"
using namespace std;


int main(int argc, char *argv[]) {
	Clientmanager *clientManager = new Clientmanager();
	ChannelManager *channelManager = new ChannelManager();
	PacketManager *packetManager = new PacketManager();
	clientManager->initManager(channelManager, packetManager);
	PRINT_LINE
	TcpServer tcp;
	tcp.socketInit();
	tcp.memsetServ_adr(atoi(argv[1]));
	tcp.bindSock();
	tcp.listenSock();

	EpollController epollController;
	epollController.epollCreate();
	epollController.epollServerRegist(tcp.getSock());
	epollController.initClientManager(clientManager);
	epollController.epollrun();

	return 0;
}
