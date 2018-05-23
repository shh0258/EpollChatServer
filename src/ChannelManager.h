/*
 * ChannelManager.h
 *
 *  Created on: 2018. 5. 18.
 *      Author: han
 */

#ifndef CHANNELMANAGER_H_
#define CHANNELMANAGER_H_
#include "Channel.h"
#include <map>

using namespace std;

class ChannelManager{
		private:
				map<int, Channel> channels;

		public:
				ChannelManager(){};
				// Return the channel of the given index.
				Channel* getChannel(int channel_num);
				// Return the new channel created.
				Channel* createChannel(int channel_num);
				// Return 0 for success, -1 if not.
				int deleteChannel(int channel_num);
};

#endif /* CHANNELMANAGER_H_ */
