/*
 * EpollController.h
 *
 *  Created on: 2018. 5. 16.
 *      Author: han
 */

#ifndef EPOLLCONTROLLER_H_
#define EPOLLCONTROLLER_H_
#include "DefineInfo.h"
#include "Clientmanager.h"


class EpollController {
private:
	int epfd, serv_sock, clnt_sock;
	struct epoll_event event;
	struct epoll_event events[256];
	int event_cnt;
	Clientmanager *clientmanager;

	socklen_t adr_sz;
	struct sockaddr_in clnt_adr;

public:
	EpollController(){};
	void epollCreate();
	void epollRegist(int sock);
	void epollServerRegist(int sock);
	void epollUnregist(int sock);
	void epollWait();
	void epollrun();
	void acceptClient();
	void controlClient(void *cnt);
	void setNonBlocking(int sock);
	void initClientManager(Clientmanager *cm);
	virtual ~EpollController();
};

#endif /* EPOLLCONTROLLER_H_ */
