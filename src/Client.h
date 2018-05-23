/*
 * Client.h
 *
 *  Created on: 2018. 5. 18.
 *      Author: han
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include "Channel.h"
#include "ChannelManager.h"
#include "PacketManager.h"
#include "DefineInfo.h"

class Client {
private:
	int socket;
	ChannelManager *channelManager;
	PacketManager *packetManager;
	Channel *m_channel;
	Packet packet;
	long str_len;

public:
	Client(int fd, ChannelManager *cm, PacketManager *pm): socket(fd), channelManager(cm), packetManager(pm), m_channel(NULL), str_len(0){};
	void onRead(int epfd);
	State managePacket(int epfd);
	Channel* getChannel(int channelId);
	void deleteChannel(int channelId);
	void insertPeer();
	void deletePeer();
	void relay();
	void setM_channel(Channel *channel);
	virtual ~Client();
};

#endif /* CLIENT_H_ */
