#include "linkedlist.h"

LINK create_node(int*value);
LINK append(LINK head, LINK cur);
int printlist(LINK head);
void printmid(LINK head, LINK cur, int num);
void printreverse(int num, LINK cur, LINK head);
LINK deleteodd(int num, LINK cur, LINK head);

int main(void)
{
	int value = 0, num;

	LINK head = NULL;
	LINK cur = head;

	printf("-�Է�(�Է��� ���� �� ctrl-z�� �� �� �Է��Ͻÿ�)-\n");

	while (scanf("%d", &value) != EOF)
	{
		cur = create_node(&value);

		if (cur == NULL)
		{
			printf("�����޸� �Ҵ翡 ������ �ֽ��ϴ�.\n");
			exit(1); //??
		}
		
		head = append(head, cur);
	}



	printf("�Է¼���� ���:			");
	num = printlist(head); 

	printf("�ڷ� ���� ���:				");
	printf("%d\n", num); 

	printf("�߰���ġ �ڷ� ���:			"); 
	printmid(head, cur, num); 

	printf("���� ���:				");
	printreverse(num, cur, head); 

	printf("Ȧ����° �ڷ� ����\n");
	head = deleteodd(num, cur, head); 

	printf("���� �ڷḦ ������� ���:		");
	printlist(head); 

	return 0;
}
