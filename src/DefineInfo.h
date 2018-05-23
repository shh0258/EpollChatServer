/*
 * DefineInfo.h
 *
 *  Created on: 2018. 5. 16.
 *      Author: han
 */

#ifndef DEFINEINFO_H_
#define DEFINEINFO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <iostream>
using namespace std;
#define EPOLL_SIZE 100
#define BUF_SIZE 256
#define PACKET_SIZE 256
#define MSG_SIZE 244

#define EPOLL_RUN_TIMEOUT -1

#define CHK(eval) if(eval < 0) {perror("eval"); exit(-1);}
#define CHKR(ret, eval) if((ret = eval) < 0) {perror("eval"); exit(-1);}
#define PRINT_LINE cout<<__FILE__<<":"<<__LINE__<<endl;

#endif /* DEFINEINFO_H_ */
