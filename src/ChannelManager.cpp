/*
 * ChannelManager.cpp
 *
 *  Created on: 2018. 5. 18.
 *      Author: han
 */

#include "ChannelManager.h"


using namespace std;

Channel* ChannelManager::getChannel(int channel_num){
		// When there is no channel at the given index,
		// return new created channel.
		if(channels.find(channel_num) == channels.end()){
				return createChannel(channel_num);
		}
		return &channels[channel_num];
}

Channel* ChannelManager::createChannel(int channel_num){
		Channel new_channel;
		channels.insert(pair<int, Channel>(channel_num, new_channel));

		return &channels[channel_num];
}

int ChannelManager::deleteChannel(int channel_num){
		map<int, Channel>::iterator it;
		it = channels.find(channel_num);
		if(it == channels.end()){
				return -1;
		}
		channels.erase(it);

		return 0;
}

