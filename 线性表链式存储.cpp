// ���Ա���ʽ�洢.cpp : Defines the entry point for the console application.
//


/*
ͷָ�룺����������в�����ͷ��㣬��ͷָ��ָ���һ�����ݽڵ㣬�������ͷ�ڵ㣬ͷָ��ָ��ͷ�ڵ�
ͷ�ڵ㣺�����򲻴����ݵĽڵ㣬���������ͷ�����������
*/
#include "stdafx.h"
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
	p = *l;//p�����ͷ���ĵ�ַ
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
	printf("��ʼ��������ĳ���Ϊ��%d\n", listLen);
	int a = 10;
	int *l = &a;
	
	printf("%x\n", &a);
	printf("%x\n", l);
	printf("%x\n",*l);
	printf("%x\n",&l);
	getchar();
    return 0;
}


