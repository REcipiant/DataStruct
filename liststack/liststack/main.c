#define _CRT_SECURE_NO_WARNINGS 1
#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	Snode* e = NULL;

	LShead* Head =  LStack_creat();
	int temp = LStack_scanf(Head);
	if (temp == -1)
	{
		printf("Error->temp");
		exit(1);
	}
	int flag = LStack_isempty(Head);
	if (1 == flag)
	{
		printf("Not Empty!\n");
	}
	LStack_clear(Head);
	printf("Head->Sum = %d\n", Head->Snum);
	return 0;
}