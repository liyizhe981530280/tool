/*************************************************************************
	> File Name: main.cpp
	> Author: liyz
	> Mail: 981530280@qq.com 
	> Created Time: 2019年06月24日 星期一 10时22分36秒
 ************************************************************************/

#include <iostream>
#include "sem_util.h"
#include "queue.h"
using namespace std;
static LinkQueue _com_queue;
static LinkQueue _com_queue2;
int init()
{
	
	struct st_cmd data2;
	memset(&data2,0, sizeof(data2));
	DeQueue(&_com_queue, &data2);
	printf("%d___%s\n",__LINE__,data2.buf);
	printf("%d___%d\n",__LINE__,data2.cmd);
	
	return 0;
}
static void* do_1(void *arg)
{
	
	pthread_detach(pthread_self());
	while(1){
	init();
	sleep(5);
		}
pthread_exit(NULL);
}
int main(){
 
    pthread_t id;
    pthread_create(&id,NULL,do_1,NULL);
	InitQueue(&_com_queue);
	struct st_cmd data,data2;
    memset(&data, 0, sizeof(data));

    data.cmd = 1;
    snprintf(data.buf, sizeof(data.buf), "孙学宾   方案2是改动最小的");

    EnQueue(&_com_queue, &data);
	

	while (1)
	{
		/* code */
	}
	
	return 0;
}

