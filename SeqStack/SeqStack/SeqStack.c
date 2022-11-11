#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

/*
	SeqStack_creat:����һ��˳��ջ
	@maxl��˳��ջ�Ĵ�С
	����ֵ��
			����˳��ջ��ָ��
*/
Sstack* SeqStack_creat(int maxl)
{
	Sstack* S = malloc(sizeof(*S));//����һ��ջָ��
	if (S == NULL)
	{
		return NULL;
	}
	S->maxlen = maxl;//����ջ���ܴ�С
	S->top = -1;//��ջ���±�Ϊ-1
	S->data = malloc(sizeof(int) * maxl);//��ջ����ռ�
	if (S->data == NULL)
	{
		return NULL;
	}
	return S;
}
/*
	Sstack_destroy:����һ��ջ
	@S��Ŀ��ջָ��
	����ֵ��
			-1������ʧ��
			 0�����ٳɹ�
*/ 
int Sstack_destroy(Sstack* S)
{
	if (S == NULL)
	{
		return -1;
	}
	else
	{
		if (S->top == -1)
		{
			free(S->data);
			free(S);
			
		}
	}
	return 0;
}
/*
	Sstack_clear:���ջ
	@S��ջָ��
	����ֵ��
			-1�����ʧ��
			 0����ճɹ�
*/
int Sstack_clear(Sstack* S)
{
	if (S == NULL)
	{
		return -1;
	}
	if (S->top == -1)
	{
		return 0;
	}
	else
	{
		S->top = -1;
		return 0;
	}
}

/*
	Sstack_isempty:�ж�ջ�Ƿ�Ϊ��
	@S��ջָ��
	����ֵ��
			0����ջ
			1���ǿ�ջ
			-1:���ó���
*/
int Sstack_isempty(Sstack* S)
{
	if (S == NULL)
	{
		return -1;
	}
	if (S->top == -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
/*
	Sstack_get:ջ��Ԫ��
	@S��ջָ��
	����ֵ��
			�Ǹ�����ջ��Ԫ�ظ���
			-1�����ó���
*/
int Sstack_get(Sstack* S)
{
	if (S == NULL)
	{
		return -1;
	}
	return S->top + 1;
}

/*
	Sstack_pop:��ջ
	@S��ջָ��
	@e:	ջ��Ԫ�ر���ָ��
	����ֵ��
			-1�����ó���
			0����ջ�ɹ�
			1:��ջ
*/
int Sstack_pop(Sstack* S,int* e)
{
	if (S == NULL )
	{
		return -1;
	}
	if (S->top == -1)
	{
		return 1;
	}
	*e = S->data[S->top--];
	return 0;
}
/*
	Sstack_push:��ջ
	@S��ջָ��
	@Data:��ջ����Ԫ��
	����ֵ��
			-1�����ó���
			0����ջ�ɹ�
*/

int Sstack_push(Sstack* S,int Data)
{
	if (S == NULL || S->top == S->maxlen - 1)
	{
		return -1;
	}

	S->data[++S->top] = Data;
	return 0;
}
/*
	Sstack_gettop:��ȡջ��Ԫ��
	@S��ջָ��
	@e��ջ��Ԫ�ر���ָ��
	����ֵ��
			-1�����ó���
			0����ȡ�ɹ�
*/
int Sstack_gettop(Sstack* S, int* e)
{
	if (S == NULL || S->top == -1)
	{
		return -1;
	}
	*e = S->data[S->top];
	return 0;
}


