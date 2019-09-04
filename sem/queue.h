
/******************************************************************************
 *
 *  @file   queue.h
 *
 *  @date   2012.09.03
 *
 *  @author eleven
 *
 *  @brief  线程互斥读写函数，供线程间读写互斥型数据使用。
 *
 ******************************************************************************/

#ifndef _QUEUE_H_H
#define _QUEUE_H_H


#include "sem_util.h"
#include <list>
#include <queue>
#include "common.h"

#define QUEUE_BUF_SIZE 1024*70   
using namespace std;
typedef struct{
    SemHandl_t Handl_t;
    queue <struct st_cmd *> *user_queue;
}LinkQueue;

int InitQueue(LinkQueue *Q);
int DestroyQueue(LinkQueue *Q);
int QueueEmpty(LinkQueue *Q);
int EnQueue(LinkQueue *Q, struct st_cmd* cmd);
int DeQueue(LinkQueue *Q, struct st_cmd* cmd);

typedef  struct {
    SemHandl_t Handl_t;
    list<struct st_cmd *> *user_list;
}double_list;

int init_double_list(double_list *Q); 
int destroy_double_list(double_list *Q);
int add_double_list(double_list *Q, struct st_cmd* cmd);
int find_double_list(double_list *Q, char *data, struct st_cmd *cmd);
int find_double_list_number(double_list *Q,struct st_cmd *src,struct st_cmd *dest);                                  
int clear_double_list(double_list *Q); 
int double_list_empty(double_list *Q);
#endif 

