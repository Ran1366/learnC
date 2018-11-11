#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//定义一个链表,num表示int类型元素,last表示指向下一个同类型元素的指针
typedef struct node
{
	int num;
	struct node* next;
}Node;
typedef struct list
{
	Node* head;
}List;
void add(List * plist,int number)
{
	Node* p = (Node*)malloc(sizeof(Node));
	p->num = number;
	p->next = NULL;
	Node* last = plist->head;
	if (last)
	{
		while (last->next)
		{
			last = last->next;
		}
		last->next = p;
	}
	else
	{
		plist->head = p;
	}
}
void Prin(Node* head)
{
	if (head)
	{
		Prin(head->next);
	}
	if (head)
	{
		printf("%d ", head->num);
	}
	
}
void Print(List list)
{
	Prin(list.head);
}
int main()
{
	//定义头
	List list;
	list.head = NULL;
	int number;
	do 
	{
		scanf("%d",&number);
		if (number != -1)
		{
			//生成节点
			add(&list,number);
		}
	} while (number != -1);
	Print(list);
	system("pause");
	return 0;
}