#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "looplink.h"

/*
	Looplink_creat:����һ��˫��ѭ�������ͷ���ָ��
	���β�
	����ֵ��
			����ͷ����ָ��
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
	Looplink_UP:��Ҫ��ӵ����ݽ������
	@Head��ͷ���ָ��
	@Data�����ݽ��ָ��
	����ֵ����
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
		if (pk == NULL)//����û���κ����ݽ��
		{
			Head->first = Data;//Data��Ϊ��һ�����
			//����ѭ��ָ��
			Data->previous = Data;
			Data->next = Data;
		}
		else//�������н��
		{
			do
			{
				if (pk->data > Data->data)//Ѱ�Ҳ���λ��
				{
					break;
				}
				pk = pk->next;
			} while (pk != Head->first);
			if (Head->first == pk)
			{
				if (Data->data <= pk->data)//ͷ����
				{
					Data->next = pk;
					Data->previous = pk->previous;

					pk->previous->next = Data;
					pk->previous = Data;
					Head->first = Data;
				}
				else//β������
				{
					pk = pk->previous;//�ص����һ�����

					Data->previous = pk;
					Data->next = pk->next;

					pk->next->previous = Data;
					pk->next = Data;

				}
			}
			else//�м����
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
	@Head��ͷ���ָ��
	����ֵ����
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
	Looplink_delete:ɾ��ѭ������
	@Head��ͷ���ָ��
	����ֵ����
*/
void Looplink_delete_data(Headnode* Head, int num)
{
	Datanode* pk = NULL;
	Datanode* flag = NULL;
	if (Head->first == NULL || Head == NULL)
	{
		return;
	}
	//������һ�����
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
			else//��һ�����ʱɾ��Ŀ�꣬�ҿ����ж������ɾ���˺����ǵ�һ���������
			{
				while (pk->data == num)
				{
					if (pk == pk->previous)//ɾ�����е�һ�����
					{
						Head->first = NULL;

						pk->next = NULL;
						pk->previous = NULL;
						free(pk);
						pk = Head->first;
						break;
					}
					else//�ж����ͬ�Ľ�㣬�Ҷ�������ǰͷ��Ҫɾ��
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
	Looplink_scanf:���ݽ��¼�뺯��
	@Head��ͷ���
	����ֵ����
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
	Looplink_destroy:������������
	@Head��ͷ���
	����ֵ����
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
