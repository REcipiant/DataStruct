#ifndef __QUEUE_H_
#define __QUEUE_H_
//链式循环队列
typedef struct Qnode
{//双向链表结构体
	struct Qnode* prev;

	int data;

	struct Qnode* next;

}Qnode;
//双向链表头结点
typedef struct Queue
{
	Qnode* head;//队首，用于出队
	Qnode* tail;//队尾，用于入队

	int Qnum;//队列总元素

}Queue;
/*
	Queue_Init:循环双向队列初始化，即创建一个头结点
	无形参
	返回值：
			头结点指针
*/
Queue* Queue_Init(void);
/*
	Queue_destroy：摧毁队列
	@Q：头结点指针
	返回值：
		空
*/
void Queue_destroy(Queue* *Q);
/*
	Queue_clear:清除队列的数据结点
	@Q：头结点指针
	返回值：
		空
*/
void Queue_clear(Queue* Q);
/*
	Queue_IsEmpty:判断队列是否为空
	@Q：头结点指针
	返回值：
		-1：失败
		0：空
		1：非空
*/
int Queue_IsEmpty(Queue* Q);
/*
	Queue_push:入队
	@Q：头结点指针
	@Data：入队元素
	返回值：
			空
*/
void Queue_push(Queue* Q, int Data);
/*
	Queue_out:出队
	@Q：头结点指针
	@e:用来保存出队的元素结点
	返回值：
			空
*/
void Queue_out(Queue* Q, Qnode* e);
/*
	Queue_get:获取队列元素个数
	@Q：头结点指针
	返回值：
			-1：出错
			否则返回元素个数
*/
int Queue_get(Queue* Q);
/*
	Queue_gettop:获取队首元素
	@Q:头结点指针
	@p：保存出队结点
	返回值：
			空
*/
void Queue_gettop(Queue* Q, Qnode* p);






#endif
