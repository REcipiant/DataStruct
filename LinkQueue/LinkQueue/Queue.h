#ifndef __QUEUE_H_
#define __QUEUE_H_
//��ʽѭ������
typedef struct Qnode
{//˫������ṹ��
	struct Qnode* prev;

	int data;

	struct Qnode* next;

}Qnode;
//˫������ͷ���
typedef struct Queue
{
	Qnode* head;//���ף����ڳ���
	Qnode* tail;//��β���������

	int Qnum;//������Ԫ��

}Queue;
/*
	Queue_Init:ѭ��˫����г�ʼ����������һ��ͷ���
	���β�
	����ֵ��
			ͷ���ָ��
*/
Queue* Queue_Init(void);
/*
	Queue_destroy���ݻٶ���
	@Q��ͷ���ָ��
	����ֵ��
		��
*/
void Queue_destroy(Queue* *Q);
/*
	Queue_clear:������е����ݽ��
	@Q��ͷ���ָ��
	����ֵ��
		��
*/
void Queue_clear(Queue* Q);
/*
	Queue_IsEmpty:�ж϶����Ƿ�Ϊ��
	@Q��ͷ���ָ��
	����ֵ��
		-1��ʧ��
		0����
		1���ǿ�
*/
int Queue_IsEmpty(Queue* Q);
/*
	Queue_push:���
	@Q��ͷ���ָ��
	@Data�����Ԫ��
	����ֵ��
			��
*/
void Queue_push(Queue* Q, int Data);
/*
	Queue_out:����
	@Q��ͷ���ָ��
	@e:����������ӵ�Ԫ�ؽ��
	����ֵ��
			��
*/
void Queue_out(Queue* Q, Qnode* e);
/*
	Queue_get:��ȡ����Ԫ�ظ���
	@Q��ͷ���ָ��
	����ֵ��
			-1������
			���򷵻�Ԫ�ظ���
*/
int Queue_get(Queue* Q);
/*
	Queue_gettop:��ȡ����Ԫ��
	@Q:ͷ���ָ��
	@p��������ӽ��
	����ֵ��
			��
*/
void Queue_gettop(Queue* Q, Qnode* p);






#endif
