#define _CRT_SECURE_NO_WARNINGS 1
#include "bilinklist.h"
#include <stdio.h>
int main()
{
	Headnode* Head = Head_linklist_creat();
	printf("--------------\n");
	Head_linklist_scanf_up(Head);
	printf("--------------\n");
	Head_linklist_print(Head);
	printf("--------------\n");
	Head_linklist_deletall(Head);
	Head = NULL;
	//Head_linklist_print(Head);
	return 0;
}
