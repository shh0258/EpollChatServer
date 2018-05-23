/*
 * Packet.h
 *
 *  Created on: 2018. 5. 18.
 *      Author: han
 */

#ifndef PACKET_H_
#define PACKET_H_
#include "DefineInfo.h"

struct Packet{
        int flags;
        int fd;
        int channel_num;
        char msg_max[MSG_SIZE];
};

struct State{
        int state;
        int channel_num;
};

#endif /* PACKET_H_ */
