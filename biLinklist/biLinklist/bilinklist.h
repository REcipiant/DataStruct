#pragma once
#ifndef  __BILINKLIST_H__
#define  __BILINKLIST_H__


//数据结点
typedef struct DataNode
{
	struct DataNode* previous;
	int data;
	struct DataNode* next;

}Datanode;

//头结点
typedef struct HEADNode
{
	Datanode* first;

	Datanode* last;
}Headnode;
/*
	Head_linklist_creat:创建头结点
	无形参
	返回值：
			头结点的结构体指针
*/
Headnode* Head_linklist_creat(void);

/*
	Head_linklist_insert_UP:输入的数据结点升序
	@Head：头结点指针
	@data：数据结点指针
	返回值：空
*/
void Head_linklist_insert_UP(Headnode* Head, Datanode* Data);

/*
	Head_linklist_print：打印链表
	@Head：头结点
	返回值：无
*/
void Head_linklist_print(Headnode* Head);

/*
	Head_linklist_scanf_up:数据输入函数，保存输入的数据，以输入0表示结束录入
	@Head:双向链表头结点指针
	无返回值
*/
void Head_linklist_scanf_up(Headnode* Head);

/*
	Head_linklist_deletall:删除整个链表
	@head：头结点
	返回值：无
*/
void Head_linklist_deletall(Headnode* Head);

#endif
