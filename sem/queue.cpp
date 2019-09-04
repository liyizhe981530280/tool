
/******************************************************************************
 *
 *  @file   queue.c
 *
 *  @date   2012.09.03
 *
 *  @author eleven
 *
 *  @brief  线程互斥读写函数，供线程间读写互斥型数据使用。
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

int InitQueue(LinkQueue *Q)
{
    Q->Handl_t = MakeSem();
    Q->user_queue = new queue<struct st_cmd *>;
    return 0;
}

int DestroyQueue(LinkQueue *Q)
{
    if (Q->Handl_t == NULL)
        return -2;
    struct st_cmd tmp;

    while (DeQueue(Q, &tmp) == SUCCESS)
        ;

    DestroySem(Q->Handl_t);
    return 0;
}

/******************************************************************************
 *
 *  @brief          队列是否为空
 *
 *  @return  0   :  不为空
 *           1   :  为空
 *          -2   :  线程锁故障
 *
 ******************************************************************************/
int QueueEmpty(LinkQueue *Q)
{
    int ret;
    if (Q->Handl_t == NULL)
        return -2;
    SemWait(Q->Handl_t);
    bool iRet = false;
    iRet = Q->user_queue->empty();
    if (iRet == true)
    {
        ret = 1;
    }
    else
    {
        ret = 0;
    }
    SemRelease(Q->Handl_t);
    return ret;
}

/******************************************************************************

 *  @brief            元素入队
 *
 *  @param     e   :  char* 型数据，待入队的元素。
 *
 *  @return    0   :  成功
 *             2   :  线程锁故障
 *
 ******************************************************************************/
int EnQueue(LinkQueue *Q, struct st_cmd *cmd)
{
    if (Q->Handl_t == NULL)
        return -2;
    if (cmd == NULL)
        return INVALID_ARGS;
    SemWait(Q->Handl_t);
    Q->user_queue->push(cmd);
    SemRelease(Q->Handl_t);

    return 0;
}

/******************************************************************************

 *  @brief            元素出队
 *
 *  @param     e   :  char* 型数据，用来接收出队元素，直接定义一个字符数组即可
 *
 *  @return    0   :  成功
 *             1   :  队列为空
 *             2   :  线程锁故障
 *
 ******************************************************************************/
int DeQueue(LinkQueue *Q, struct st_cmd *cmd)
{
    if (cmd == NULL)
    {
        return INVALID_ARGS;
    }
    int ret = FAIL;
    if (Q->Handl_t == NULL)
        return -2;

    SemWait(Q->Handl_t);
    struct st_cmd *tmp = Q->user_queue->front();
    Q->user_queue->pop();
    if (tmp != NULL)
    {
        memcpy(cmd, tmp, sizeof(struct st_cmd));
        ret = SUCCESS;
        tmp = NULL;
    }
    SemRelease(Q->Handl_t);
    return ret;
}

int init_double_list(double_list *Q)
{
    Q->Handl_t = MakeSem();
    Q->user_list = new list<struct st_cmd *>;
    return 0;
}
int destroy_double_list(double_list *Q)
{
    clear_double_list(Q);
    DestroySem(Q->Handl_t);
    return SUCCESS;
}
int add_double_list(double_list *Q, struct st_cmd *cmd)
{
    if (Q->Handl_t == NULL)
        return -2;
    if (cmd == NULL)
        return INVALID_ARGS;

    SemWait(Q->Handl_t);
    Q->user_list->push_back(cmd);
    SemRelease(Q->Handl_t);
    return SUCCESS;
}

int find_double_list(double_list *Q, char *data, struct st_cmd *cmd)
{
    if (Q->Handl_t == NULL)
    {
        return -2;
    }
    int ret = FAIL;
    SemWait(Q->Handl_t);
    list<struct st_cmd *>::iterator it;
    for (it == Q->user_list->begin(); it != Q->user_list->end(); ++it)
    {

        if (strcmp((**it).buf, data) == 0)
        {
            memcpy(cmd, *it, sizeof(struct st_cmd));
            SemRelease(Q->Handl_t);
            ret = SUCCESS;
        }
    }
    SemRelease(Q->Handl_t);
    return ret;
}

int find_double_list_number(double_list *Q, struct st_cmd *src, struct st_cmd *dest)
{
    if (Q->Handl_t == NULL)
    {
        return -2;
    }
    int ret = FAIL;

    SemWait(Q->Handl_t);
    list<struct st_cmd *>::iterator it;
    for (it == Q->user_list->begin(); it != Q->user_list->end(); ++it)
    {
        if ((**it).numbersong == src->numbersong)
        {
            memcpy(dest, *it, sizeof(struct st_cmd));
            SemRelease(Q->Handl_t);
            ret = SUCCESS;
        }
    }
    SemRelease(Q->Handl_t);
    return ret;
}

//清空链表
int clear_double_list(double_list *Q)
{
    int ret = FAIL;
    if (Q->Handl_t == NULL)
    {
        return -2;
    }

    SemWait(Q->Handl_t);
    Q->user_list->clear();
    SemRelease(Q->Handl_t);
    return ret;
}

/******************************************************************************
 *
 *  @brief          链表是否为空
 *
 *  @return  0   :  不为空
 *           1   :  为空
 *          -2   :  线程锁故障
 *
 ******************************************************************************/
int double_list_empty(double_list *Q)
{
    int ret;
    if (Q->Handl_t == NULL)
        return -2;
    SemWait(Q->Handl_t);
    bool iRet = false;
    iRet = Q->user_list->empty();
    if (iRet == true)
    {
        ret = 1;
    }
    else if (iRet == false)
    {
        ret = 0;
    }
    SemRelease(Q->Handl_t);
    return ret;
}
