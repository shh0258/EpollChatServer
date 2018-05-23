/*
 * Clientmanager.h
 *
 *  Created on: 2018. 5. 18.
 *      Author: han
 */

#ifndef CLIENTMANAGER_H_
#define CLIENTMANAGER_H_
#include "Client.h"
#include "ChannelManager.h"
#include "PacketManager.h"

class Clientmanager {
private:
	ChannelManager* channelManager;
	PacketManager* packetManager;
public:
	Clientmanager(){}
	void initManager(ChannelManager *cm, PacketManager *pm);
	Client* createClient(int fd);
	void deleteClient();
	void clientControl(Client* cnt, int epfd);
	virtual ~Clientmanager();
};

#endif /* CLIENTMANAGER_H_ */
