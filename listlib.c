#include "linkedlist.h"

LINK create_node(int * value)
{
	LINK cur;
	cur = (LINK)malloc(sizeof(NODE));

	if (cur == NULL)
	{
		printf("노드 생성을 위한 메모리 할당에 문제가 있습니다.\n");
		return NULL;
	}

	cur->value = (int)malloc(sizeof(int)); //int의 간접 참조 수준이 int*과 다릅니다
	cur->value = *value;

	cur->next = NULL;

	return cur;
}

LINK append(LINK head, LINK cur)
{
	LINK nextnode = head;

	if (head == NULL)
	{
		head = cur;
		return head;
	}

	while (nextnode->next != NULL)
	{
		nextnode = nextnode->next;
	}
	nextnode->next = cur;

	return head;
}

int printlist(LINK head)
{
	int num = 0;
	LINK nextnode = head;

	while (nextnode != NULL)
	{
		num++;
		printf("%d ", nextnode->value);
		nextnode = nextnode->next;
	}

	printf("\n");
	return num;
}

void printmid(LINK head, LINK cur, int num)
{
	cur = head; 
	for (int i = 0; i < num / 2; i++)
	{
		cur = cur->next;
	}
	printf("%d\n", cur->value);
}

void printreverse(int num, LINK cur, LINK head)
{
	for (int j = num; j>0; j--) 
	{
		cur = head;
		for (int i = 1; i < j; i++)
		{
			cur = cur->next;
		}
		printf("%d ", cur->value);
	}
	printf("\n");
}

LINK deleteodd(int num, LINK cur, LINK head)
{
	cur = head;
	head = head->next;

	for (int i = 1; i <= num; i++)
	{
		if (i % 2 != 0)
			cur = cur->next;
		else
			cur->next = cur->next->next;
	}

	return head;
}