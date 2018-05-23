/*
 * Channel.cpp
 *
 *  Created on: 2018. 5. 18.
 *      Author: han
 */

#include "Channel.h"
#include "sys/socket.h"

using namespace std;

void Channel::addPeer(int peer){
		peers.push_back(peer);
//		return 0;
}

int Channel::deletePeer(int peer){
		list<int>::iterator it;
		for(it = peers.begin(); it != peers.end(); it++){
				if(*it == peer)
						break;
		}

		if(it == peers.end())
				return -1;

		peers.remove(peer);
		return 0;
}

int Channel::broadcast(Packet packet){
		for(list<int>::iterator it = peers.begin(); it != peers.end(); it++){
				if(send(*it, &packet, PACKET_SIZE, 0) < 0){
						perror("eval");
						exit(-1);
				}
		}
		return 0;
}
