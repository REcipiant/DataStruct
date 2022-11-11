#pragma once
#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__
//链式栈--双向链式栈
//数据结点
typedef struct Linkstack
{
	struct Linkstack* previous;
	int data;
	struct Linkstack* next;
}Snode;
//头结点
typedef struct LSHead
{
	Snode* Bottom;
	Snode* top;

	int Snum;
}LShead;

/*
	LStack_creat：创建一个循环双向栈的头结点
	无形参
	返回值：头结点指针
*/
LShead* LStack_creat(void);
/*
	LStack_destroy：销毁双向链栈
	@Head：头结点指针
	返回值：
		-1：销毁失败
		0：销毁成功
*/
int LStack_destroy(LShead* Head);

/*
	LStack_clear：清空栈
	@Head：头结点指针
	返回值：
		-1：清空失败
		0：清空成功
*/
int LStack_clear(LShead* Head);
/*
	LStack_isempty：判断栈是否为空
	@Head：头结点指针
	返回值：
		-1：调用函数失败
		0：空栈
		1：非空栈
*/
int LStack_isempty(LShead* Head);
/*
	LStack_get：获取栈的元素个数
	@Head：头结点指针
	返回值：
		-1：调用函数失败
		非负数：栈内元素个数
*/
int LStack_get(LShead* Head);

/*
	LStack_pop：出栈
	@Head：头结点指针
	@e：保存摘除的结点
	返回值：
		-1：调用出错
		0：成功摘除
*/
int LStack_pop(LShead* Head, Snode* e);
/*
	LStack_push：入栈
	@Head：头结点指针
	@p:待加入的数据结点指针
	返回值：
			-1：调用函数失败
			0：加入成功
*/
int LStack_push(LShead* Head, Snode* p);
/*
	LStack_gettop：获取栈顶元素
	@Head：头结点指针
	@e：保存栈顶元素
	返回值：
			-1：调用函数失败
			0：调用成功
*/
int LStack_gettop(LShead* Head, Snode* e);

/*
	LStack_scanf：栈数据输入函数
	@Head：头结点指针
	返回值：
			-1：调用出错
			0：录入成功
*/

int LStack_scanf(LShead* Head);






#endif