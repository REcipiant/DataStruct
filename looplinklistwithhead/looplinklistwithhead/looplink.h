#pragma once
#ifndef  __LOOPLINK_H__
#define	 __LOOPLINK_H__

//数据结点，并没有多大变化
typedef struct DataNode
{
	struct DataNode* previous;
	int data;
	struct DataNode* next;

}Datanode;
//头结点，只需要一个成员变量
typedef struct HEADNode
{

	Datanode* first;

}Headnode;

/*
	Looplink_creat:创建一个双向循环链表的头结点指针
	无形参
	返回值：
			返回头结点的指针
*/

Headnode* Looplink_creat(void);
/*
	Looplink_UP:将要添加的数据结点升序
	@Head：头结点指针
	@Data：数据结点指针
	返回值：空
*/
void Looplink_UP(Headnode* Head, Datanode* Data);
/*
	Looplink_print:
	@Head：头结点指针
	返回值：空
*/
void Looplink_print(Headnode* Head);
/*
	Looplink_delete:删除循环链表
	@Head：头结点指针
	返回值：空
*/
void Looplink_delete_data(Headnode* Head, int num);
/*
	Looplink_scanf:数据结点录入函数
	@Head：头结点
	返回值：空
*/
void Looplink_scanf(Headnode* Head);
/*
	Looplink_destroy:销毁整个链表
	@Head：头结点
	返回值：空
*/
void Looplink_destroy(Headnode* Head);


#endif