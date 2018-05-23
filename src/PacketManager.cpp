/*
 * PacketManager.cpp
 *
 *  Created on: 2018. 5. 18.
 *      Author: han
 */

#include "PacketManager.h"

State PacketManager::get_packet_state(struct Packet packet){
	this->packet=packet;
	State ret = {packet.flags, packet.channel_num};
	return ret;
}


PacketManager::~PacketManager() {
	// TODO Auto-generated destructor stub
}

