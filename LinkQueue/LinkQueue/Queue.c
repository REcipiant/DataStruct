#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
/*
	Queue_Init:ѭ��˫����г�ʼ����������һ��ͷ���
	���β�
	����ֵ��
			ͷ���ָ��
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
	Queue_destroy���ݻٶ���
	@Q��ͷ���ָ��
	����ֵ��
		��
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
	Queue_clear:������е����ݽ��
	@Q��ͷ���ָ��
	����ֵ��
		��
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
	Queue_IsEmpty:�ж϶����Ƿ�Ϊ��
	@Q��ͷ���ָ��
	����ֵ��
		-1��ʧ��
		0����
		1���ǿ�
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
	Queue_push:���
	@Q��ͷ���ָ��
	@Data�����Ԫ��
	����ֵ��
			��
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
	Queue_out:����
	@Q��ͷ���ָ��
	@e:����������ӵ�Ԫ�ؽ��
	����ֵ��
			��
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
		//����
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
	Queue_get:��ȡ����Ԫ�ظ���
	@Q��ͷ���ָ��
	����ֵ��
			-1������
			���򷵻�Ԫ�ظ���
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
	Queue_gettop:��ȡ����Ԫ��
	@Q:ͷ���ָ��
	@p��������ӽ��
	����ֵ��
			��
*/
void Queue_gettop(Queue* Q, Qnode* p)
{
	if (Q == NULL || Q->Qnum == 0 || Q->head == NULL)
	{
		return;
	}
	p = Q->head;
	//����
	printf("%p ",Q);
}