#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "looplink.h"

/*
	Looplink_creat:创建一个双向循环链表的头结点指针
	无形参
	返回值：
			返回头结点的指针
*/

Headnode* Looplink_creat(void)
{
	Headnode* Head = malloc(sizeof(Head));
	if (NULL == Head)
	{
		perror("Can not Creat Head");
		exit(0);
	}
	Head->first = NULL;
	return Head;
}

/*
	Looplink_UP:将要添加的数据结点升序
	@Head：头结点指针
	@Data：数据结点指针
	返回值：空
*/
void Looplink_UP(Headnode* Head, Datanode* Data)
{
	Datanode* pk = NULL;
	if (Head == NULL || Data == NULL)
	{
		return;
	}
	else
	{
		pk = Head->first;
		if (pk == NULL)//链表没有任何数据结点
		{
			Head->first = Data;//Data即为第一个结点
			//设置循环指针
			Data->previous = Data;
			Data->next = Data;
		}
		else//链表内有结点
		{
			do
			{
				if (pk->data > Data->data)//寻找插入位置
				{
					break;
				}
				pk = pk->next;
			} while (pk != Head->first);
			if (Head->first == pk)
			{
				if (Data->data <= pk->data)//头插入
				{
					Data->next = pk;
					Data->previous = pk->previous;

					pk->previous->next = Data;
					pk->previous = Data;
					Head->first = Data;
				}
				else//尾部插入
				{
					pk = pk->previous;//回到最后一个结点

					Data->previous = pk;
					Data->next = pk->next;

					pk->next->previous = Data;
					pk->next = Data;

				}
			}
			else//中间插入
			{
				Data->previous = pk->previous;
				Data->next = pk;

				pk->previous->next = Data;
				pk->previous = Data;
			}
		}
	}
}


/*
	Looplink_print:
	@Head：头结点指针
	返回值：空
*/
void Looplink_print(Headnode* Head)
{
	Datanode* p = NULL;
	if (Head == NULL || Head->first == NULL)
	{
		return;
	}
	p = Head->first;
	do
	{
		printf("%d ",p->data);
		p = p->next;
	} while (p != Head->first);
	printf("\n");
	p = Head->first;
	do
	{
		p = p->previous;
		printf("%d ", p->data);

	} while (p != Head->first);
	printf("\n");
}
/*
	Looplink_delete:删除循环链表
	@Head：头结点指针
	返回值：空
*/
void Looplink_delete_data(Headnode* Head, int num)
{
	Datanode* pk = NULL;
	Datanode* flag = NULL;
	if (Head->first == NULL || Head == NULL)
	{
		return;
	}
	//至少有一个结点
	pk = Head->first;
	do
	{
		if (pk->data != num)
		{
			pk = pk->next;
		}
		else
		{
			if (pk != Head->first)
			{
				pk->previous->next = pk->next;
				pk->next->previous = pk->previous;

				flag = pk->next;
				pk->next = NULL;
				pk->previous = NULL;

				free(pk);
				pk = flag;
			}
			else//第一个结点时删除目标，且可能有多个，即删除了后又是第一个结点的情况
			{
				while (pk->data == num)
				{
					if (pk == pk->previous)//删除仅有的一个结点
					{
						Head->first = NULL;

						pk->next = NULL;
						pk->previous = NULL;
						free(pk);
						pk = Head->first;
						break;
					}
					else//有多个相同的结点，且都排在最前头需要删除
					{
						pk->next->previous = pk->previous;
						pk->previous->next = pk->next;

						Head->first = pk->next;

						pk->next = NULL;
						pk->previous = NULL;
						free(pk);
						pk = Head->first;
					}
				}
			}
		}
	} while (pk != Head->first);
}
/*
	Looplink_scanf:数据结点录入函数
	@Head：头结点
	返回值：空
*/
void Looplink_scanf(Headnode* Head)
{
	int num;
	Datanode* p = NULL;
	if (Head == NULL)
	{
		return;
	}
	else
	{
		while (1)
		{
			scanf("%d",&num);
			if (num == 0)
			{
				break;
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

			Looplink_UP(Head, p);
		}
	}
}
/*
	Looplink_destroy:销毁整个链表
	@Head：头结点
	返回值：空
*/
void Looplink_destroy(Headnode* Head)
{
	Datanode* pk = NULL;
	pk = Head->first;
	if (Head == NULL)
	{
		return;
	}
	else
	{
		if (Head->first == NULL)
		{
			free(Head);
			return;
		}
		else
		{

			while (pk != NULL)
			{
				if (pk == pk->previous)
				{
					Looplink_print(Head);
					Head->first = NULL;
					pk->next = NULL;
					pk->previous = NULL;
					free(pk);
					pk = NULL;
				}
				else
				{
					Looplink_print(Head);
					pk->previous->next = pk->next;
					pk->next->previous = pk->previous;

					Head->first = pk->next;
					pk->next = NULL;
					pk->previous = NULL;
					free(pk);
					pk = Head->first;
				}
			}
		}		
	}
	Looplink_print(Head);
	free(Head);
}
