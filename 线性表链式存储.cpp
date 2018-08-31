// ���Ա���ʽ�洢.cpp : Defines the entry point for the console application.
//


/*
ͷָ�룺����������в�����ͷ��㣬��ͷָ��ָ���һ�����ݽڵ㣬�������ͷ�ڵ㣬ͷָ��ָ��ͷ�ڵ�
ͷ�ڵ㣺�����򲻴����ݵĽڵ㣬���������ͷ�����������
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

#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int status;/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;/* ElemType���͸���ʵ������������������Ϊint */

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList; /* ����LinkList */

//LinkList ��һ��Node��ָ������


typedef struct Node *Linklist;
status initList(Linklist* l)//*l��ͷָ���ָ�루ͷָ���λ�ӣ�����*l��ͷָ�������
{
	*l = (LinkList)malloc(sizeof(Node));/* ����ͷ���,��ʹLָ���ͷ��� */
	if (!(*l))//��������ڴ�ʧ�ܣ���*l��������NULL;
		return ERROR;
	(*l)->next = NULL;
}

int lenList(LinkList l)//l ��ͷָ��
{
	if (!l)//
		return ERROR;
	int count = 0;
	LinkList p = l->next;/* pָ���һ����� */
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
	p = *l;//p��ָ��ͷ���
	while (p&&j < i)//��p��Ϊ�ղ���jС��i
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
	LinkList p = l->next;//lΪͷָ�룬ָ��ͷ��㣬l->next��ָ���һ���ڵ�
	while (p)
	{
		func(p);
		p = p->next;
	}
}
void printNode(Node *node)
{
	printf("�ڵ�ĵ�ַΪ: %x----->�ڵ��ֵΪ: %d----->�ڵ�ĺ����ڵ��ַΪ: %x----->",node, node->data,node->next);
}
/*�������һ����ͷ������ͷ�巨�ĵ�����,ͷ�ڵ��data�����ڴ�Žڵ�ĸ���*/
LinkList createListWithHeadNodeInHead()
{
	LinkList p = (LinkList)malloc(sizeof(Node));
	p->data = 0;
	p->next = NULL;
	srand(time(0));
	int count = rand() % 10 + 1;/*  �������10���ڵ����� */
	printf("������%d���ڵ�\n", count);
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
/*ͨ��β�巨�������һ����ͷ�ڵ�ĵ�����*/
Linklist createListWithHeadNodeInTail()
{
	LinkList l = (LinkList)malloc(sizeof(Node));
	l->data = 0;
	l->next = NULL;
	//rʼ��ָ��ڵ�����һ���ڵ㣬�ڳ�ʼ����ʱ�򣬽ڵ�ս�����ֻ��һ��ͷ�ڵ㣬���ͷ�ڵ㼰���һ���ڵ�
	LinkList r = l;
	srand(time(0));
	int count = rand() % 10 + 1;/*  �������10���ڵ����� */
	printf("������%d���ڵ�\n", count);
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
	LinkList list;//ͷָ��
	ElemType e;
	status i;
	initList(&list);
	int listLen=lenList(list);
	printf("��ʼ��������ĳ���Ϊ��%d\n", listLen);
	ListInsert(&list,1,100);
	ListInsert(&list, 1, 101);
	ListInsert(&list, 1, 102);
	ListInsert(&list, 1, 103);
	//call(1001,1, print);
	//traversList(list, printNode);	
	LinkList headList = createListWithHeadNodeInHead();
	traversList(headList, printNode);
	printf("\nheadList�Ľڵ���Ϊ:%d\n", headList->data);
	printf("len(headList)=%d\n", lenList(headList));

	LinkList tailList = createListWithHeadNodeInTail();
	traversList(tailList, printNode);
	printf("\ntailList�Ľڵ���Ϊ:%d\n", tailList->data);
	printf("len(tailList)=%d\n", lenList(tailList));
	int number = 0;
	printf("������Ҫ��ѯ�ı�ţ�\n");
	scanf_s("%d", &number);
	Node *res;
	status r=getElement(tailList, number, &res);
	if (r)
		printf("���ҵ���Ϊ��%d\n", res->data);
	else
		printf("û���ҵ�\n");
	printf("������Ҫɾ���ı�ţ�\n");
	scanf_s("%d", &number);
	if (deleteNode(tailList, number))
	{
		printf("ɾ���ɹ�\n");
		traversList(tailList, printNode);
	}
	else
		printf("ɾ��ʧ��\n");
	system("pause");
    return 0;
}


