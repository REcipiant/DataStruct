#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqStack.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int size;
	int flag = 0;
	int flag1 = 0;
	int Data;
	int* e = malloc(sizeof(*e));
	if (e == NULL)
	{
		perror("e Malloc");
		exit(0);
	}
	scanf("%d",&size);
	Sstack* S = SeqStack_creat(size);
	while (1)
	{
		scanf("%d",&Data);
		if (Data == 0)
		{
			break;
		}
		flag = Sstack_push(S, Data);
	}
	while (-1 != flag1)
	{
		if (size == 0)
		{
			break;
		}

		flag = Sstack_pop(S,e);
		printf("%d ",*e);
		flag1 = Sstack_gettop(S, e);

	}
	printf("\n");

	return 0;
}