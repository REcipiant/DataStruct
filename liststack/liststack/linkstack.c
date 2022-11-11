#define _CRT_SECURE_NO_WARNINGS 1
#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>

/*
	LStack_creat������һ��ѭ��˫��ջ��ͷ���
	���β�
	����ֵ��ͷ���ָ��
*/
LShead* LStack_creat(void)
{
	LShead* Head = malloc(sizeof(*Head));
	if (Head == NULL)
	{
		return NULL;
	}
	Head->Bottom = NULL;
	Head->top = NULL;
	Head->Snum = 0;
	return Head;
}

/*
	LStack_destroy������˫����ջ
	@Head��ͷ���ָ��
	����ֵ��
		-1������ʧ��
		0�����ٳɹ�
*/
int LStack_destroy(LShead* Head)
{
	Snode* pk = NULL;
	if (Head == NULL)
	{
		return -1;//fail
	}
	if (Head->Snum == 0)
	{
		free(Head);
		return 0;//Success
	}
	else
	{
		pk = Head->top;
		while (pk != NULL)
		{
			if (Head->Snum == 1)
			{
				Head->Snum--;
				break;
			}
			pk->previous->next = NULL;
			Head->top = pk->previous;

			pk->previous = NULL;
			free(pk);
			Head->Snum--;
			pk = Head->top;
		}
		Head->Bottom = NULL;
		Head->top = NULL;
		free(Head);
		Head = NULL;
		return 0;
	}
}

/*
	LStack_clear�����ջ
	@Head��ͷ���ָ��
	����ֵ��
		-1�����ʧ��
		0����ճɹ�
*/
int LStack_clear(LShead* Head)
{
	Snode* pk = NULL;
	if (Head == NULL || Head->Snum == 0)
	{
		return -1;
	}
	else
	{
		pk = Head->top;
		while (pk != NULL)
		{
			if (Head->Snum == 1)
			{
				Head->Snum--;
				break;
			}
			pk->previous->next = NULL;//pk->previous����ΪNULL
			Head->top = pk->previous;

			pk->previous = NULL;
			free(pk);
			Head->Snum--;
			pk = Head->top;
		}
		Head->Bottom = NULL;
		Head->top = NULL;
		return 0;
	}
}

/*
	LStack_isempty���ж�ջ�Ƿ�Ϊ��
	@Head��ͷ���ָ��
	����ֵ��
		-1�����ú���ʧ��
		0����ջ
		1���ǿ�ջ
*/
int LStack_isempty(LShead* Head)
{
	if (Head == NULL)
	{
		return -1;
	}
	if (Head->Snum == 0)
	{
		return 0;//empty
	}
	else
	{
		return 1;//Not empty
	}
}
/*
	LStack_get����ȡջ��Ԫ�ظ���
	@Head��ͷ���ָ��
	����ֵ��
		-1�����ú���ʧ��
		�Ǹ�����ջ��Ԫ�ظ���
*/
int LStack_get(LShead* Head)
{
	if (Head == NULL)
	{
		return -1;
	}
	
	return Head->Snum;
}

/*
	LStack_pop����ջ
	@Head��ͷ���ָ��
	@e������ժ���Ľ��
	����ֵ��
		-1�����ó���
		0���ɹ�ժ��
*/
int LStack_pop(LShead* Head,Snode* e)
{
	if (Head == NULL || Head->Snum == 0)
	{
		return -1;
	}
	e = Head->top;
	if (Head->Snum == 1)
	{
		Head->Bottom = NULL;
		Head->top = NULL;
	}
	else
	{	
		Head->top = e->previous;

		Head->top->next = NULL;
		e->previous = NULL;
	}
	Head->Snum--;
	return 0;
}
/*
	LStack_push����ջ
	@Head��ͷ���ָ��
	@p:����������ݽ��ָ��
	����ֵ��
			-1�����ú���ʧ��
			0������ɹ�
*/
int LStack_push(LShead* Head, Snode* p)
{
	if (Head == NULL)
	{
		return -1;
	}
	else
	{
		if (Head->Snum == 0)
		{
			Head->Bottom = p;
			Head->top = p;
		}
		else
		{
			Head->top->next = p;
			p->previous = Head->top;

			Head->top = p;
		}
		Head->Snum++;
		return 0;
	}
}
/*
	LStack_gettop����ȡջ��Ԫ��
	@Head��ͷ���ָ��
	@e������ջ��Ԫ��
	����ֵ��
			-1�����ú���ʧ��
			0�����óɹ�
*/
int LStack_gettop(LShead* Head, Snode* e)
{
	if (Head == NULL || Head->Snum == 0)
	{
		return -1;
	}
	e = Head->top;
	printf("%d\n", e->data);
	return 0;
}

/*
	LStack_scanf��ջ�������뺯��
	@Head��ͷ���ָ��
	����ֵ��
			-1�����ó���
			0��¼��ɹ�
*/

int LStack_scanf(LShead* Head)
{
	Snode* p = NULL;
	int Data;
	if (Head == NULL)
	{
		return -1;
	}
	else
	{
		while (1)
		{
			scanf("%d",&Data);
			if (0 == Data)
			{
				break;
			}
			p = malloc(sizeof(*p));
			if (p == NULL)
			{
				perror("LStack->scanf");
				return -1;
			}
			p->data = Data;
			p->next = NULL;
			p->previous = NULL;

			LStack_push(Head, p);
		}
	}
	return 0;
}
