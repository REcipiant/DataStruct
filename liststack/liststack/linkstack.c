#define _CRT_SECURE_NO_WARNINGS 1
#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>

/*
	LStack_creat：创建一个循环双向栈的头结点
	无形参
	返回值：头结点指针
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
	LStack_destroy：销毁双向链栈
	@Head：头结点指针
	返回值：
		-1：销毁失败
		0：销毁成功
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
	LStack_clear：清空栈
	@Head：头结点指针
	返回值：
		-1：清空失败
		0：清空成功
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
			pk->previous->next = NULL;//pk->previous可能为NULL
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
	LStack_isempty：判断栈是否为空
	@Head：头结点指针
	返回值：
		-1：调用函数失败
		0：空栈
		1：非空栈
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
	LStack_get：获取栈的元素个数
	@Head：头结点指针
	返回值：
		-1：调用函数失败
		非负数：栈内元素个数
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
	LStack_pop：出栈
	@Head：头结点指针
	@e：保存摘除的结点
	返回值：
		-1：调用出错
		0：成功摘除
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
	LStack_push：入栈
	@Head：头结点指针
	@p:待加入的数据结点指针
	返回值：
			-1：调用函数失败
			0：加入成功
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
	LStack_gettop：获取栈顶元素
	@Head：头结点指针
	@e：保存栈顶元素
	返回值：
			-1：调用函数失败
			0：调用成功
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
	LStack_scanf：栈数据输入函数
	@Head：头结点指针
	返回值：
			-1：调用出错
			0：录入成功
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
