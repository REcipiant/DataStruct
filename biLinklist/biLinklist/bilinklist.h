#pragma once
#ifndef  __BILINKLIST_H__
#define  __BILINKLIST_H__


//���ݽ��
typedef struct DataNode
{
	struct DataNode* previous;
	int data;
	struct DataNode* next;

}Datanode;

//ͷ���
typedef struct HEADNode
{
	Datanode* first;

	Datanode* last;
}Headnode;
/*
	Head_linklist_creat:����ͷ���
	���β�
	����ֵ��
			ͷ���Ľṹ��ָ��
*/
Headnode* Head_linklist_creat(void);

/*
	Head_linklist_insert_UP:��������ݽ������
	@Head��ͷ���ָ��
	@data�����ݽ��ָ��
	����ֵ����
*/
void Head_linklist_insert_UP(Headnode* Head, Datanode* Data);

/*
	Head_linklist_print����ӡ����
	@Head��ͷ���
	����ֵ����
*/
void Head_linklist_print(Headnode* Head);

/*
	Head_linklist_scanf_up:�������뺯����������������ݣ�������0��ʾ����¼��
	@Head:˫������ͷ���ָ��
	�޷���ֵ
*/
void Head_linklist_scanf_up(Headnode* Head);

/*
	Head_linklist_deletall:ɾ����������
	@head��ͷ���
	����ֵ����
*/
void Head_linklist_deletall(Headnode* Head);

#endif
