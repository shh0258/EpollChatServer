/*
 * Clientmanager.cpp
 *
 *  Created on: 2018. 5. 18.
 *      Author: han
 */

#include "Clientmanager.h"

void Clientmanager::initManager(ChannelManager *cm, PacketManager *pm) {
	this->channelManager=cm;
	this->packetManager=pm;
}
Client* Clientmanager::createClient(int fd) {
	Client *client = new Client(fd, channelManager, packetManager);
	return client;
}
void Clientmanager::clientControl(Client* client, int epfd) {
		client->onRead(epfd);
//		while(1) {
//			if(client->managePacket(epfd).state==0) {//user_add
//				client->setM_channel(channelManager->getChannel(client->managePacket(epfd).channel_num));
//				client->insertPeer();
//			} else if(client->managePacket(epfd).state==1) {//user_del
//				client->deletePeer();
//				client->setM_channel(NULL);
//			} else if(client->managePacket(epfd).state==2) {//start_chat
//				client->relay();
//				cout<<"relay \n"<<endl;
//			} else {
//				puts("client state error");
//				break;
//			}
//		}
}

Clientmanager::~Clientmanager() {
	// TODO Auto-generated destructor stub
}

