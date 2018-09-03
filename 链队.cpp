// 链队.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
typedef int ElemType;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int status;
typedef struct Node {
	ElemType data;
	Node * next;
};

typedef struct LinkQue {
	Node * front;
	Node * rear;
	int count;
} *LinkQuePtr;
status initQue(LinkQuePtr que)
{
	que->front = que->rear = (Node*)malloc(sizeof(Node));
	if (!que->front)
		return ERROR;//动态内存分配失败
	que->count = 0;
	que->front->next = NULL;
	return OK;
}
status enQue(LinkQuePtr que, ElemType e)
{
	Node * node = (Node *)malloc(sizeof(Node));
	if (!node)
	{
		printf("内存分配失败");
		getchar();
		system("pause");
		return ERROR;
	}
	node->data = e;
	node->next = NULL;
	que->rear->next = node;
	que->rear = node;
	return OK;
}
status deQue(LinkQuePtr que, ElemType * e)
{
	if (que->front->next != NULL)
	{
		Node * node = que->front->next;
		*e = node->data;
		que->front->next = que->front->next->next;
		free(node);
		return OK;
	}
	return ERROR;
}
int main()
{
	LinkQue que;
	initQue(&que);
	for (int i = 0; i < 100; i++)
	{
		printf("%d 尝试入队\n", i);
		if (!enQue(&que, i))
			break;
	}
	ElemType e;
	while (que.front->next != NULL)
	{
		if (deQue(&que, &e));
			printf("出队列：%d \n", e);
	}
	system("pause");
    return 0;
}

