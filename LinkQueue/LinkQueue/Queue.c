#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
/*
	Queue_Init:循环双向队列初始化，即创建一个头结点
	无形参
	返回值：
			头结点指针
*/
Queue* Queue_Init(void)
{
	Queue* Q = malloc(sizeof(*Q));
	if (Q == NULL)
	{
		return NULL;
	}
	Q->head = NULL;
	Q->tail = NULL;
	Q->Qnum = 0;
	return Q;
}
/*
	Queue_destroy：摧毁队列
	@Q：头结点指针
	返回值：
		空
*/
void Queue_destroy(Queue* *Q)
{
	Qnode* pk = NULL;
	if (*Q == NULL)
	{
		return;
	}
	if ((*Q)->Qnum == 0)
	{
		free(*Q);
		*Q = NULL;
		return;
	}
	else
	{
		pk = (*Q)->tail;
		while (pk != NULL)
		{
			if ((*Q)->Qnum == 1)
			{
				free(pk);
				(*Q)->Qnum--;
				break;
			}
			else
			{
				(*Q)->tail = pk->prev;
				pk->prev->next = NULL;
				pk->prev = NULL;
				free(pk);
				pk = (*Q)->tail;
				(*Q)->Qnum--;
			}		
		}
		(*Q)->head = NULL;
		(*Q)->tail = NULL;
		free(*Q);
		*Q = NULL;
	}
}
/*
	Queue_clear:清除队列的数据结点
	@Q：头结点指针
	返回值：
		空
*/
void Queue_clear(Queue* Q)
{
	Qnode* pk = NULL;
	if (Q == NULL || Q->Qnum == 0)
	{
		return;
	}

	pk = Q->tail;
	while (pk != NULL)
	{
		if (Q->Qnum == 1)
		{
			free(pk);
			Q->Qnum--;
			break;
		}
		else
		{
			Q->tail = pk->prev;
			pk->prev->next = NULL;
			pk->prev = NULL;
			free(pk);
			pk = Q->tail;
			Q->Qnum--;
		}
	}
	Q->head = NULL;
	Q->tail = NULL;
}
/*
	Queue_IsEmpty:判断队列是否为空
	@Q：头结点指针
	返回值：
		-1：失败
		0：空
		1：非空
*/
int Queue_IsEmpty(Queue* Q)
{
	if (Q == NULL)
	{
		return -1;
	}
	if (Q->Qnum == 0)
	{
		return 0;
	}
	return 1;
}
/*
	Queue_push:入队
	@Q：头结点指针
	@Data：入队元素
	返回值：
			空
*/
void Queue_push(Queue* Q,int Data)
{
	Qnode* p = malloc(sizeof(*p));
	if (Q == NULL || p == NULL)
	{
		return;
	}
	else
	{
		p->data = Data;
		p->next = NULL;
		p->prev = NULL;
		if (Q->Qnum == 0)
		{
			Q->head = p;
			Q->tail = p;
			Q->Qnum++;
		}
		else
		{
			Q->tail->next = p;
			p->prev = Q->tail;

			Q->tail = p;
			Q->Qnum++;
		}
	}
}

/*
	Queue_out:出队
	@Q：头结点指针
	@e:用来保存出队的元素结点
	返回值：
			空
*/
void Queue_out(Queue* Q, Qnode* e)
{
	Qnode* p = NULL;
	if (Q == NULL || Q->Qnum == 0)
	{
		return;
	}
	else
	{
		p = Q->head;
		e = Q->head;
		//测试
		printf("\n-%d ", e->data);
		if (Q->Qnum == 1)
		{
			p->next = NULL;
		}
		else
		{
			Q->head = p->next;
			p->next->prev = NULL;
			p->next = NULL;
		}
		free(p);

		p = NULL;
		Q->Qnum--;
	}
}


/*
	Queue_get:获取队列元素个数
	@Q：头结点指针
	返回值：
			-1：出错
			否则返回元素个数
*/
int Queue_get(Queue* Q)
{
	if (Q == NULL)
	{
		return -1;
	}
	return Q->Qnum;
}
/*
	Queue_gettop:获取队首元素
	@Q:头结点指针
	@p：保存出队结点
	返回值：
			空
*/
void Queue_gettop(Queue* Q, Qnode* p)
{
	if (Q == NULL || Q->Qnum == 0 || Q->head == NULL)
	{
		return;
	}
	p = Q->head;
	//测试
	printf("%p ",Q);
}