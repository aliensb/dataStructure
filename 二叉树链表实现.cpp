// ����������ʵ��.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef char ElemeType;
typedef struct BiTNode  /* ���ṹ */
{
	ElemeType data;		/* ������� */
	struct BiTNode *lchild, *rchild; /* ���Һ���ָ�� */
}BiTNode, *BiTree; 

typedef int status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */

status initBTree(BiTree *bt)
{
	*bt = NULL;
	return OK;
}

status createBtree(BiTree *bt)
{
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#')
	{
		*bt = NULL;
		
		return OK;
	}
	else
	{
		*bt = (BiTNode *)malloc(sizeof(BiTNode));
		if (!bt)
		{
			//�ڴ����ʧ��
			return ERROR;
		}
		else
		{
			(*bt)->data = ch;
			printf("������%c��ڵ��ֵ��\n",ch);
			getchar();
			//���ﴫ�ݵ���ָ��������ָ�루�������ڵ��ַ���ĵ�ַ
			createBtree(&((*bt)->lchild));
			printf("������%c�ҽڵ��ֵ��\n", ch);
			getchar();
			createBtree(&((*bt)->rchild));
		}
	}
}
void printNode(BiTNode* node)
{
	printf("�ڵ��ֵΪ��%c\n", node->data);
}
void preOrderVisitBtree(BiTree bt, void(*func)(BiTNode*))
{
	if (!bt)
	{
//		printf("��Ϊ��!!\n");
		return;
	}
	else
	{
		func(bt);
		preOrderVisitBtree(bt->lchild, func);
		preOrderVisitBtree(bt->rchild, func);
	}
}

void middleOrderVisitBtree(BiTree bt, void(*func)(BiTNode*))
{
	if (!bt)
	{
		//		printf("��Ϊ��!!\n");
		return;
	}
	else
	{
		
		middleOrderVisitBtree(bt->lchild, func);
		func(bt);
		middleOrderVisitBtree(bt->rchild, func);
	}
}

void afterOrderVisitBtree(BiTree bt, void(*func)(BiTNode*))
{
	if (!bt)
	{
		//		printf("��Ϊ��!!\n");
		return;
	}
	else
	{

		afterOrderVisitBtree(bt->lchild, func);
		afterOrderVisitBtree(bt->rchild, func);
		func(bt);
	}
}
int main()
{
	BiTree bt;//����һ��ָ�������ڵ��ָ�룬

	initBTree(&bt);//��ʼ����������ָ��ָ��գ�������һ������
	createBtree(&bt);
	printf("������������\n");
	preOrderVisitBtree(bt, printNode);
	printf("������������\n");
	middleOrderVisitBtree(bt, printNode);
	printf("������������\n");
	afterOrderVisitBtree(bt,printNode);
	system("pause");
    return 0;
}

