/*************************************************************************
	> File Name: clientlibevent1.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2018年12月17日 星期一 17时10分39秒
 ************************************************************************/

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <event.h>
#include <event2/util.h>

int tcp_connect_server(const char *server_ip, int port);
void cmd_msg_cb(int fd, short event, void *arg);
using namespace std;

int main(int argc, char **argv)
{
	if(arg < 3)
	{
		return -1;
	}

	int sockfd = tcp_connect_server(argv[1],atoi(argv[2]));

	if(sockfd == -1)
	{
		return -1;
	}

	struct event_base* base = event_base_new();
	
	struct event *ev_sockfd = event_new(base, sockfd,EV_READ | EV_PERSIST,
			socket_read_cb,NULL);

	struct event* ev_cmd = event_new(base,STDIN_FILENO,EV_READ | EV_PERSIST, cmd_msg_cb, (void *)&sockfd);

	event_add(ev_cmd,NULL);
	event_base_dispatch(base);

	return 0;
}

void cmd_msg_cb(int fd, short events,void *arg)
{
	char msg[1024];
	if(ret <= 0)
	{
	perror("read fail");
	exit(1);
	}
	int sockfd = *((int *)arg);

	write(sockfd, msg, ret);
}

void socket_read_cb(int fd, short event, void *arg)
{
}

