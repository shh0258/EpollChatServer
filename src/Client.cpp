/*
 * Client.cpp
 *
 *  Created on: 2018. 5. 18.
 *      Author: han
 */

#include "Client.h"

void Client::onRead(int epfd) {
	char buf[256]={};
	str_len=read(socket, &buf, BUF_SIZE);
//	str_len = recv(socket, packet, BUF_SIZE);
	if(str_len==0) {
		epoll_ctl(epfd, EPOLL_CTL_DEL, socket, NULL);
		close(socket);
		printf("close client: %d \n", socket);
	} else if(str_len<0){
		puts("client read error");
		printf("%d %d %x", str_len, socket, buf);
	}
	Packet * packet = (Packet *)buf;
	cout<<packet->msg_max<<"   "<<packet->flags<<"    "<<packet->channel_num<<"  "<<endl;
}
State Client::managePacket(int epfd) {
	onRead(epfd);
	return packetManager->get_packet_state(packet);
}
Channel* Client::getChannel(int channelId) {
	return channelManager->getChannel(channelId);

}
void Client::deleteChannel(int channelId) {
	channelManager->deleteChannel(channelId);
}
void Client::insertPeer() {
	m_channel->addPeer(socket);
}
void Client::setM_channel(Channel* channel) {
	m_channel=channel;
}
void Client::deletePeer() {
	m_channel->deletePeer(socket);
	m_channel=NULL;
}
void Client::relay() {
	m_channel->broadcast(packet);
}

Client::~Client() {
	// TODO Auto-generated destructor stub
}

