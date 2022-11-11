#define _CRT_SECURE_NO_WARNINGS 1
#include "looplink.h"
#include <stdio.h>


int main()
{
	int num;
	Headnode* Head = Looplink_creat();
	Looplink_scanf(Head);
	Looplink_print(Head);
	printf("input num:\n");
	scanf("%d", &num);
	Looplink_delete_data(Head, num);
	Looplink_print(Head);
	Looplink_destroy(Head);
	return 0;
}