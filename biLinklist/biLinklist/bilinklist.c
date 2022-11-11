#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "bilinklist.h"

/*
	Head_linklist_creat:����ͷ���
	���β�
	����ֵ��
			ͷ���Ľṹ��ָ��
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
	Head_linklist_insert_UP:��������ݽ������
	@Head��ͷ���ָ��
	@data�����ݽ��ָ��
	����ֵ����
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
		if (pk == NULL)//û�ҵ����ڵ����
		{
			if (Head->first == NULL)//����������һ�����ݽ��
			{
				Head->first = Data;
				Head->last = Data;
			}
			else//����β������
			{
				Head->last->next = Data;
				Data->previous = Head->last;
				Head->last = Data;
			}
		}
		else//�ҵ���
		{
			if (pk->previous == NULL)//����ͷ������
			{
				pk->previous = Data;
				Data->next = pk;
				Head->first = Data;

			}
			else//�����м����
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
	Head_linklist_print����ӡ����
	@Head��ͷ���
	����ֵ����
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
	Head_linklist_scanf_up:�������뺯����������������ݣ�������0��ʾ����¼��
	@Head:˫������ͷ���ָ��
	�޷���ֵ
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
	Head_linklist_deletall:ɾ����������
	@head��ͷ���
	����ֵ����
*/
void Head_linklist_deletall(Headnode* Head)
{
	//˼·һ���ӵ�һ�����ݽ�㿪ʼ�ͷ�
	//˼·������������ݽ�㿪ʼ�ͷ�
	//����ʵ��˼·����˼·һ����������
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
		//ͷ����ͷ�
		printf("Success!\n");
		Head_linklist_print(Head);
		free(Head);

	}
}