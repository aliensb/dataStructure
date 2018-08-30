// 线性表链式存储.cpp : Defines the entry point for the console application.
//


/*
头指针：如果单链表中不存在头结点，那头指针指向第一个数据节点，如果存在头节点，头指针指向头节点
头节点：数据域不存数据的节点，放在链表的头部，方便操作
*/
#include "stdafx.h"
#include "stdlib.h"
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList; /* 定义LinkList */

//LinkList 是一个Node的指针类型


typedef struct Node *Linklist;
status initList(Linklist* l)//*l是头指针的指针（头指针的位子），那*l是头指针的内容
{
	*l = (LinkList)malloc(sizeof(Node));/* 产生头结点,并使L指向此头结点 */
	if (!(*l))//如果分配内存失败，这*l的内容是NULL;
		return ERROR;
	(*l)->next = NULL;
}

int lenList(LinkList l)//l 是头指针
{
	if (!l)//
		return ERROR;
	int count = 0;
	LinkList p = l->next;/* p指向第一个结点 */
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}

status ListInsert(LinkList *l, int i, ElemType e)
{
	int j;
	LinkList p, node;
	j = 1;
	p = *l;//p存的是头结点的地址
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	node = (Linklist)malloc(sizeof(Node));
	node->data = e;
	node->next = p->next;
	p->next = node;
	return OK;
}
int main()
{
	LinkList list;
	ElemType e;
	status i;
	initList(&list);
	int listLen=lenList(list);
	printf("初始化后链表的长度为：%d\n", listLen);
	int a = 10;
	int *l = &a;
	
	printf("%x\n", &a);
	printf("%x\n", l);
	printf("%x\n",*l);
	printf("%x\n",&l);
	getchar();
    return 0;
}


