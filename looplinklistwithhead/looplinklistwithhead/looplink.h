#pragma once
#ifndef  __LOOPLINK_H__
#define	 __LOOPLINK_H__

//���ݽ�㣬��û�ж��仯
typedef struct DataNode
{
	struct DataNode* previous;
	int data;
	struct DataNode* next;

}Datanode;
//ͷ��㣬ֻ��Ҫһ����Ա����
typedef struct HEADNode
{

	Datanode* first;

}Headnode;

/*
	Looplink_creat:����һ��˫��ѭ�������ͷ���ָ��
	���β�
	����ֵ��
			����ͷ����ָ��
*/

Headnode* Looplink_creat(void);
/*
	Looplink_UP:��Ҫ��ӵ����ݽ������
	@Head��ͷ���ָ��
	@Data�����ݽ��ָ��
	����ֵ����
*/
void Looplink_UP(Headnode* Head, Datanode* Data);
/*
	Looplink_print:
	@Head��ͷ���ָ��
	����ֵ����
*/
void Looplink_print(Headnode* Head);
/*
	Looplink_delete:ɾ��ѭ������
	@Head��ͷ���ָ��
	����ֵ����
*/
void Looplink_delete_data(Headnode* Head, int num);
/*
	Looplink_scanf:���ݽ��¼�뺯��
	@Head��ͷ���
	����ֵ����
*/
void Looplink_scanf(Headnode* Head);
/*
	Looplink_destroy:������������
	@Head��ͷ���
	����ֵ����
*/
void Looplink_destroy(Headnode* Head);


#endif