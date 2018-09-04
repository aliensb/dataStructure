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
	que->front = que->rear = (Node*)malloc(sizeof(Node));//头结点
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
		printf("内存分配失败\n");
		return ERROR;
	}
	node->data = e;
	node->next = NULL;
	que->rear->next = node; //que->rear指向原队列的对尾，	que->rear->next = node; 将
							//原队列尾的那个元素的指针指向新元素，那新元素就是新的对尾了。
	que->rear = node;		//将rear指向新队列的对尾
	return OK;
}
status deQue(LinkQuePtr que, ElemType * e)
{
	//que->front指向的是头节点，que->front->next指向的是队列的头
	if (que->front->next != NULL)
	{
		Node * node = que->front->next;
		*e = node->data;//值拷贝不是地址拷贝，所以下面free（）不会对这个值有影响
		que->front->next = que->front->next->next;//front指向删除了原来队列头后的新的队列头
		free(node);
		return OK;
	}
	return ERROR;
}
int main()
{
	LinkQue que;
	initQue(&que);
	for (int i = 0; i < 10000000; i++)
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

