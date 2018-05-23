/*
 * PacketManager.h
 *
 *  Created on: 2018. 5. 18.
 *      Author: han
 */

#ifndef PACKETMANAGER_H_
#define PACKETMANAGER_H_
#include"DefineInfo.h"
#include "ChannelManager.h"
#include "Packet.h"


#define packet_add 0
#define packet_del 1
#define packet_chat 2

class PacketManager {
private:
	struct Packet packet;
public:

	PacketManager(){};
	State get_packet_state(struct Packet packet);
	virtual ~PacketManager();
};

#endif /* PACKETMANAGER_H_ */
