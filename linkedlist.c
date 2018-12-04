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

	printf("-입력(입력을 끝낼 시 ctrl-z를 세 번 입력하시오)-\n");

	while (scanf("%d", &value) != EOF)
	{
		cur = create_node(&value);

		if (cur == NULL)
		{
			printf("동적메모리 할당에 문제가 있습니다.\n");
			exit(1); //??
		}
		
		head = append(head, cur);
	}



	printf("입력순대로 출력:			");
	num = printlist(head); 

	printf("자료 개수 출력:				");
	printf("%d\n", num); 

	printf("중간위치 자료 출력:			"); 
	printmid(head, cur, num); 

	printf("역순 출력:				");
	printreverse(num, cur, head); 

	printf("홀수번째 자료 삭제\n");
	head = deleteodd(num, cur, head); 

	printf("남은 자료를 순서대로 출력:		");
	printlist(head); 

	return 0;
}
