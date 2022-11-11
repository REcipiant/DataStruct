#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "bilinklist.h"

/*
	Head_linklist_creat:创建头结点
	无形参
	返回值：
			头结点的结构体指针
*/
Headnode* Head_linklist_creat(void)
{
	Headnode* Head = malloc(sizeof(*Head));
	if (Head == NULL)
	{
		perror("Creat Head Error!");
		exit(0);
	}
	Head->first = NULL;
	Head->last = NULL;
	return Head;
}

/*
	Head_linklist_insert_UP:输入的数据结点升序
	@Head：头结点指针
	@data：数据结点指针
	返回值：空
*/
void Head_linklist_insert_UP(Headnode* Head,Datanode* Data)
{
	Datanode* pk = NULL;
	if (Head == NULL || Data == NULL)
	{
		return;
	}
	else
	{
		pk = Head->first;
		while (pk != NULL)
		{
			if (pk->data > Data->data)
			{
				break;
			}
			pk = pk->next;
		}
		if (pk == NULL)//没找到对于的情况
		{
			if (Head->first == NULL)//空链表接入第一个数据结点
			{
				Head->first = Data;
				Head->last = Data;
			}
			else//链表尾部插入
			{
				Head->last->next = Data;
				Data->previous = Head->last;
				Head->last = Data;
			}
		}
		else//找到了
		{
			if (pk->previous == NULL)//链表头部插入
			{
				pk->previous = Data;
				Data->next = pk;
				Head->first = Data;

			}
			else//链表中间插入
			{
				Data->next = pk;
				Data->previous = pk->previous;

				pk->previous->next = Data;
				pk->previous = Data;
			}
		}
	}
 }

/*
	Head_linklist_print：打印链表
	@Head：头结点
	返回值：无
*/
void Head_linklist_print(Headnode* Head)
{
	Datanode* p = NULL;
	p = Head->first;
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
	p = Head->last;
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->previous;
	}
	printf("\n");
}

/*
	Head_linklist_scanf_up:数据输入函数，保存输入的数据，以输入0表示结束录入
	@Head:双向链表头结点指针
	无返回值
*/
void Head_linklist_scanf_up(Headnode* Head)
{
	Datanode* p = NULL;
	int num;
	if (Head == NULL)
	{
		return;
	}
	//printf("Here!\n");
	while (1)
	{
		scanf("%d",&num);
		if (0 == num)
		{
			return;
		}
		p = malloc(sizeof(*p));
		if (NULL == p)
		{
			perror("Scanf Error");
			exit(0);
		}
		p->data = num;
		p->next = NULL;
		p->previous = NULL;

		Head_linklist_insert_UP(Head, p);
	}
}
/*
	Head_linklist_deletall:删除整个链表
	@head：头结点
	返回值：无
*/
void Head_linklist_deletall(Headnode* Head)
{
	//思路一：从第一个数据结点开始释放
	//思路二：从最后数据结点开始释放
	//以下实现思路二，思路一请自行斟酌
	Datanode* p = NULL;
	if (Head == NULL)
	{
		return;
	}
	else
	{
		p = Head->last;
		while (Head->last != NULL)
		{
			if (Head->last != Head->first)
			{	
				Head_linklist_print(Head);
				p->previous->next = NULL;
				Head->last = p->previous;
				p->previous = NULL;
				free(p);
				p = Head->last;
			}
			else
			{
				Head_linklist_print(Head);
				Head->last = NULL;
				Head->first = NULL;
				free(p);
			}
		}
		//头结点释放
		printf("Success!\n");
		Head_linklist_print(Head);
		free(Head);

	}
}