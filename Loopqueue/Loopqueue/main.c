#define _CRT_SECURE_NO_WARNINGS 1
#include "Loopqueue.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int maxlen;
	printf("Input maxlen:\n");
	scanf("%d",&maxlen);
	Lqueue* LQ = LQ_Init(maxlen);
	int len = LQ_len(LQ);
	printf("元素个数 = %d\n",len);
	int data;
	int flag = 0;
	int p = 0;
	printf("Input Data:\n");
	while (flag != -1)
	{
		scanf("%d", &data);
		if (data == 0)
		{
			break;
		}
		flag = LQ_input(LQ, data);
	}
	len = LQ_len(LQ);
	printf("-元素个数 = %d-\n", len);
	flag = 0;
	while (flag != -1)
	{
		flag = LQ_out(LQ,&p);
	}
	printf("\n");
	len = LQ_len(LQ);
	printf("-元素个数 = %d-\n", len);





	return 0;
}