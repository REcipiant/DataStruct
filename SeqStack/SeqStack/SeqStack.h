#pragma once
#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

//栈对象

typedef struct Seqstack
{
	//顺序栈的存储空间，用指针指向一端连续空间的首地址（连续地址是顺序栈的特征）
	int* data;
	//顺序栈的长度
	int maxlen;
	//顺序栈的当前栈顶下标
	int top;

}Sstack;

/*
	SeqStack_creat:创建一个顺序栈
	@maxl：顺序栈的大小
	返回值：
			返回顺序栈的指针
*/
Sstack* SeqStack_creat(int maxl);
/*
	Sstack_destroy:销毁一个栈
	@S：目标栈指针
	返回值：
			-1：销毁失败
			 0：销毁成功
*/
int Sstack_destroy(Sstack* S);

/*
	Sstack_clear:清空栈
	@S：栈指针
	返回值：
			-1：清空失败
			 0：清空成功
*/
int Sstack_clear(Sstack* S);

/*
	Sstack_isempty:判断栈是否为空
	@S：栈指针
	返回值：
			0：空栈
			1：非空栈
			-1:调用出错
*/
int Sstack_isempty(Sstack* S);

/*
	Sstack_get:栈的元素
	@S：栈指针
	返回值：
			非负数：栈的元素个数
			-1：调用出错
*/
int Sstack_get(Sstack* S);
/*
	Sstack_pop:出栈
	@S：栈指针
	@e:	栈顶元素保存指针
	返回值：
			-1：调用出错
			0：出栈成功
*/
int Sstack_pop(Sstack* S, int* e);

/*
	Sstack_push:入栈
	@S：栈指针
	@Data:入栈数据元素
	返回值：
			-1：调用出错
			0：入栈成功
*/

int Sstack_push(Sstack* S, int Data);

/*
	Sstack_gettop:获取栈顶元素
	@S：栈指针
	@e：栈顶元素保存指针
	返回值：
			-1：调用出错
			0：获取成功
*/
int Sstack_gettop(Sstack* S, int* e);





#endif