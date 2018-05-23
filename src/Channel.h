/*
 * Channel.h
 *
 *  Created on: 2018. 5. 18.
 *      Author: han
 */

#ifndef CHANNEL_H_
#define CHANNEL_H_

#include <list>
#include "Packet.h"

using namespace std;

class Channel{
		private:
				list<int> peers;

		public:
				// Add the given peer to this channel.
				void addPeer(int peer);
				// Return 0 for success, -1 if not.
				int deletePeer(int peer);
				// Broadcast message except the given peer(sender).
				int broadcast(Packet packet);
};

#endif /* CHANNEL_H_ */
