#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

int main()
{
	Qnode* e = NULL;
	int num;
	Queue* Q = Queue_Init();
	while (1)
	{
		scanf("%d",&num);
		if (num == 0)
		{
			break;
		}
		Queue_push(Q,num);
	}
	Queue_clear(Q);
	//printf("Q->Data = %d\n", Q->head->data);
	printf("%p\n", Q);
	Queue_destroy(&Q);
	//printf("Here!\n");
	printf("%p\n",Q);
	//getchar();
	 int count = 100;
	//printf("Q->Data = %d\n", Q->head->data);
	//while (count != 0)
	//{
		count = Queue_IsEmpty(Q);
		printf("%d",count);
	//Queue_gettop(Q,e);
		
	//	Queue_out(Q,e);
	//}









	return 0;
}






