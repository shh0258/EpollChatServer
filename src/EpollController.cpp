/*
 * EpollController.cpp
 *
 *  Created on: 2018. 5. 16.
 *      Author: han
 */

#include "EpollController.h"

void EpollController::epollCreate() {
	epfd = epoll_create(EPOLL_SIZE);
}
void EpollController::epollRegist(int sock){
	event.events = EPOLLIN | EPOLLET;
	event.data.fd = sock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, sock, &event);
}
void EpollController::epollServerRegist(int sock){
	event.events = EPOLLIN;
	event.data.fd = sock;
	serv_sock=sock;
	epoll_ctl(epfd, EPOLL_CTL_ADD, sock, &event);
}
void EpollController::epollUnregist(int sock){

	epoll_ctl(epfd, EPOLL_CTL_DEL, sock, NULL);
}
void EpollController::epollWait(){
	event_cnt = epoll_wait(epfd, events, 256, EPOLL_RUN_TIMEOUT);
}

void EpollController::epollrun(){
	while(1){
		epollWait();
		if(event_cnt==-1) {
			puts("epollWait error");
			break;
		}
		for(int i=0; i<event_cnt; i++) {
			if(events[i].data.fd==serv_sock) {
				acceptClient();
			} else {
				controlClient(events[i].data.ptr);
			}
		}
	}
}

void EpollController::acceptClient() {
	adr_sz=sizeof(clnt_adr);
	clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
	setNonBlocking(clnt_sock);
	event.events=EPOLLIN|EPOLLET;
	event.data.ptr=clientmanager->createClient(clnt_sock);
	epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
	printf("connect client %d \n", clnt_sock);
}

void EpollController::controlClient(void *cnt) {
	Client *client=(Client*)cnt;
	clientmanager->clientControl(client, epfd);
}

void EpollController::setNonBlocking(int sock) {
	fcntl(sock, F_SETFL, fcntl(sock, F_GETFD, 0) | O_NONBLOCK);
}

void EpollController::initClientManager(Clientmanager *cm) {
	this->clientmanager=cm;
}

EpollController::~EpollController() {
	// TODO Auto-generated destructor stub
}

