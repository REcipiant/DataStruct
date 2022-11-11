#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

/*
	SeqStack_creat:创建一个顺序栈
	@maxl：顺序栈的大小
	返回值：
			返回顺序栈的指针
*/
Sstack* SeqStack_creat(int maxl)
{
	Sstack* S = malloc(sizeof(*S));//创建一个栈指针
	if (S == NULL)
	{
		return NULL;
	}
	S->maxlen = maxl;//保存栈的总大小
	S->top = -1;//空栈，下标为-1
	S->data = malloc(sizeof(int) * maxl);//给栈分配空间
	if (S->data == NULL)
	{
		return NULL;
	}
	return S;
}
/*
	Sstack_destroy:销毁一个栈
	@S：目标栈指针
	返回值：
			-1：销毁失败
			 0：销毁成功
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
	Sstack_clear:清空栈
	@S：栈指针
	返回值：
			-1：清空失败
			 0：清空成功
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
	Sstack_isempty:判断栈是否为空
	@S：栈指针
	返回值：
			0：空栈
			1：非空栈
			-1:调用出错
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
	Sstack_get:栈的元素
	@S：栈指针
	返回值：
			非负数：栈的元素个数
			-1：调用出错
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
	Sstack_pop:出栈
	@S：栈指针
	@e:	栈顶元素保存指针
	返回值：
			-1：调用出错
			0：出栈成功
			1:空栈
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
	Sstack_push:入栈
	@S：栈指针
	@Data:入栈数据元素
	返回值：
			-1：调用出错
			0：入栈成功
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
	Sstack_gettop:获取栈顶元素
	@S：栈指针
	@e：栈顶元素保存指针
	返回值：
			-1：调用出错
			0：获取成功
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


