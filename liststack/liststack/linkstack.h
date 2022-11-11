#pragma once
#ifndef __LINKSTACK_H__
#define __LINKSTACK_H__
//��ʽջ--˫����ʽջ
//���ݽ��
typedef struct Linkstack
{
	struct Linkstack* previous;
	int data;
	struct Linkstack* next;
}Snode;
//ͷ���
typedef struct LSHead
{
	Snode* Bottom;
	Snode* top;

	int Snum;
}LShead;

/*
	LStack_creat������һ��ѭ��˫��ջ��ͷ���
	���β�
	����ֵ��ͷ���ָ��
*/
LShead* LStack_creat(void);
/*
	LStack_destroy������˫����ջ
	@Head��ͷ���ָ��
	����ֵ��
		-1������ʧ��
		0�����ٳɹ�
*/
int LStack_destroy(LShead* Head);

/*
	LStack_clear�����ջ
	@Head��ͷ���ָ��
	����ֵ��
		-1�����ʧ��
		0����ճɹ�
*/
int LStack_clear(LShead* Head);
/*
	LStack_isempty���ж�ջ�Ƿ�Ϊ��
	@Head��ͷ���ָ��
	����ֵ��
		-1�����ú���ʧ��
		0����ջ
		1���ǿ�ջ
*/
int LStack_isempty(LShead* Head);
/*
	LStack_get����ȡջ��Ԫ�ظ���
	@Head��ͷ���ָ��
	����ֵ��
		-1�����ú���ʧ��
		�Ǹ�����ջ��Ԫ�ظ���
*/
int LStack_get(LShead* Head);

/*
	LStack_pop����ջ
	@Head��ͷ���ָ��
	@e������ժ���Ľ��
	����ֵ��
		-1�����ó���
		0���ɹ�ժ��
*/
int LStack_pop(LShead* Head, Snode* e);
/*
	LStack_push����ջ
	@Head��ͷ���ָ��
	@p:����������ݽ��ָ��
	����ֵ��
			-1�����ú���ʧ��
			0������ɹ�
*/
int LStack_push(LShead* Head, Snode* p);
/*
	LStack_gettop����ȡջ��Ԫ��
	@Head��ͷ���ָ��
	@e������ջ��Ԫ��
	����ֵ��
			-1�����ú���ʧ��
			0�����óɹ�
*/
int LStack_gettop(LShead* Head, Snode* e);

/*
	LStack_scanf��ջ�������뺯��
	@Head��ͷ���ָ��
	����ֵ��
			-1�����ó���
			0��¼��ɹ�
*/

int LStack_scanf(LShead* Head);






#endif