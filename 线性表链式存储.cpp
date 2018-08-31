// 线性表链式存储.cpp : Defines the entry point for the console application.
//


/*
头指针：如果单链表中不存在头结点，那头指针指向第一个数据节点，如果存在头节点，头指针指向头节点
头节点：数据域不存数据的节点，放在链表的头部，方便操作
*/
#include "stdafx.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
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
	p = *l;//p就指向头结点
	while (p&&j < i)//当p不为空并且j小于i
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

void print(int a ,int b)
{
	printf(" %d\n",a + b);
}
void call(int a, int b,void(*p)(int, int))
{
	p(a, b);
}

void traversList(LinkList l, void(*func)(Node*))
{
	LinkList p = l->next;//l为头指针，指向头结点，l->next是指向第一个节点
	while (p)
	{
		func(p);
		p = p->next;
	}
}
void printNode(Node *node)
{
	printf("节点的地址为: %x----->节点的值为: %d----->节点的后驱节点地址为: %x----->",node, node->data,node->next);
}
/*随机创建一个带头结点的用头插法的单链表,头节点的data域用于存放节点的个数*/
LinkList createListWithHeadNodeInHead()
{
	LinkList p = (LinkList)malloc(sizeof(Node));
	p->data = 0;
	p->next = NULL;
	srand(time(0));
	int count = rand() % 10 + 1;/*  随机生成10以内的数字 */
	printf("创建了%d个节点\n", count);
	while (count > 0)
	{
		LinkList node = (LinkList)malloc(sizeof(Node));
		node->data = rand() % 100 + 1;
		printf("%d ",node->data);
		node->next = p->next;
		p->next = node;
		p->data++;
		count--;
	}
	printf("\n");
	return p;
}
/*通过尾插法随机创建一个带头节点的单链表*/
Linklist createListWithHeadNodeInTail()
{
	LinkList l = (LinkList)malloc(sizeof(Node));
	l->data = 0;
	l->next = NULL;
	//r始终指向节点的最后一个节点，在初始化的时候，节点刚建立，只有一个头节点，这个头节点及最后一个节点
	LinkList r = l;
	srand(time(0));
	int count = rand() % 10 + 1;/*  随机生成10以内的数字 */
	printf("创建了%d个节点\n", count);
	while (count > 0)
	{
		LinkList node = (LinkList)malloc(sizeof(Node));
		node->data= rand() % 100 + 1;
		printf("%d ", node->data);
		node->next = r->next;
		r->next = node;
		r = node;
		l->data++;
		count--;
	}
	printf("\n");
	return l;
}

status getElement(LinkList l, int i,Node **res)
{
	if (l->data < i || i < 1)
		return ERROR;
	int j = 1;
	LinkList p = l->next;
	while (p&&j < i)
	{
		p = p->next;
		j++;
	}
	if (!p || j > i)
		return ERROR;
	else
	{
		*res = p;
		return OK;
	}
}
status deleteNode(LinkList l, int i)
{
	LinkList p;
	LinkList next;
	if (i == 1)
	{
		p = l;
	}
	else
	{
		if (!getElement(l, i - 1, &p))
			return ERROR;
	}
	next = p->next;
	p->next = next->next;
	free(next);
	return OK;
}
int main()
{
	LinkList list;//头指针
	ElemType e;
	status i;
	initList(&list);
	int listLen=lenList(list);
	printf("初始化后链表的长度为：%d\n", listLen);
	ListInsert(&list,1,100);
	ListInsert(&list, 1, 101);
	ListInsert(&list, 1, 102);
	ListInsert(&list, 1, 103);
	//call(1001,1, print);
	//traversList(list, printNode);	
	LinkList headList = createListWithHeadNodeInHead();
	traversList(headList, printNode);
	printf("\nheadList的节点数为:%d\n", headList->data);
	printf("len(headList)=%d\n", lenList(headList));

	LinkList tailList = createListWithHeadNodeInTail();
	traversList(tailList, printNode);
	printf("\ntailList的节点数为:%d\n", tailList->data);
	printf("len(tailList)=%d\n", lenList(tailList));
	int number = 0;
	printf("请输入要查询的编号：\n");
	scanf_s("%d", &number);
	Node *res;
	status r=getElement(tailList, number, &res);
	if (r)
		printf("查找的数为：%d\n", res->data);
	else
		printf("没有找到\n");
	printf("请输入要删除的编号：\n");
	scanf_s("%d", &number);
	if (deleteNode(tailList, number))
	{
		printf("删除成功\n");
		traversList(tailList, printNode);
	}
	else
		printf("删除失败\n");
	system("pause");
    return 0;
}


