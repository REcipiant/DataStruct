#pragma once
#ifndef __SEQSTACK_H__
#define __SEQSTACK_H__

//ջ����

typedef struct Seqstack
{
	//˳��ջ�Ĵ洢�ռ䣬��ָ��ָ��һ�������ռ���׵�ַ��������ַ��˳��ջ��������
	int* data;
	//˳��ջ�ĳ���
	int maxlen;
	//˳��ջ�ĵ�ǰջ���±�
	int top;

}Sstack;

/*
	SeqStack_creat:����һ��˳��ջ
	@maxl��˳��ջ�Ĵ�С
	����ֵ��
			����˳��ջ��ָ��
*/
Sstack* SeqStack_creat(int maxl);
/*
	Sstack_destroy:����һ��ջ
	@S��Ŀ��ջָ��
	����ֵ��
			-1������ʧ��
			 0�����ٳɹ�
*/
int Sstack_destroy(Sstack* S);

/*
	Sstack_clear:���ջ
	@S��ջָ��
	����ֵ��
			-1�����ʧ��
			 0����ճɹ�
*/
int Sstack_clear(Sstack* S);

/*
	Sstack_isempty:�ж�ջ�Ƿ�Ϊ��
	@S��ջָ��
	����ֵ��
			0����ջ
			1���ǿ�ջ
			-1:���ó���
*/
int Sstack_isempty(Sstack* S);

/*
	Sstack_get:ջ��Ԫ��
	@S��ջָ��
	����ֵ��
			�Ǹ�����ջ��Ԫ�ظ���
			-1�����ó���
*/
int Sstack_get(Sstack* S);
/*
	Sstack_pop:��ջ
	@S��ջָ��
	@e:	ջ��Ԫ�ر���ָ��
	����ֵ��
			-1�����ó���
			0����ջ�ɹ�
*/
int Sstack_pop(Sstack* S, int* e);

/*
	Sstack_push:��ջ
	@S��ջָ��
	@Data:��ջ����Ԫ��
	����ֵ��
			-1�����ó���
			0����ջ�ɹ�
*/

int Sstack_push(Sstack* S, int Data);

/*
	Sstack_gettop:��ȡջ��Ԫ��
	@S��ջָ��
	@e��ջ��Ԫ�ر���ָ��
	����ֵ��
			-1�����ó���
			0����ȡ�ɹ�
*/
int Sstack_gettop(Sstack* S, int* e);





#endif