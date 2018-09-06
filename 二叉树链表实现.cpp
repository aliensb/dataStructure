// ����������ʵ��.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stack>//��׼��ջ

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef char ElemeType;
typedef struct BiTNode  /* ���ṹ */
{
	ElemeType data;		/* ������� */
	int flag;/*�����ڵ��Ƿ񱻷��ʹ�����������ʹ�����ֵΪ1*/
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


/*��ͨ��ջʵ�ֶ��������������*/
void preOrderVisitBtreeWithoutrecursion(BiTree bt, void(*func)(BiTNode*))
{
	if (!bt)
	{
		//		printf("��Ϊ��!!\n");
		return;
	}
	std::stack<BiTNode> stk;
	BiTree point = bt;
	BiTNode node;
	while (point || !stk.empty())
	{
		if (point)
		{
			func(point);
			stk.push(*point);
			point = point->lchild;
		}
		else
		{
			node =stk.top();
			stk.pop();
			point = node.rchild;
		}
	}
}
/*��ͨ��ջʵ�ֶ��������������*/
void middleOrderVisitBtreeWithoutrecursion(BiTree bt, void(*func)(BiTNode*))
{
	if (!bt)
	{
		//		printf("��Ϊ��!!\n");
		return;
	}
	std::stack<BiTNode> stk;
	BiTree point = bt;
	BiTNode node;
	while (point || !stk.empty())
	{
		if (point)
		{
			stk.push(*point);
			point = point->lchild;
		}
		else
		{
			node = stk.top();
			stk.pop();
			func(&node);
			point = node.rchild;
		}
	}
}

void afterOrderVisitBtreeWithoutrecursion(BiTree bt, void(*func)(BiTNode*))
{
	if (!bt)
	{
		//		printf("��Ϊ��!!\n");
		return;
	}
	std::stack<BiTNode*> stk;
	BiTree point = bt;//��ǰ���ʵĽڵ�
	BiTNode* node;//��ǰ�ڵ�ĸ��ڵ�
	while (point || !stk.empty())
	{
		/*�����ǰ�ڵ������Ӳ�������û�б����ʹ��������Һ��Ӳ����Һ���û�б����ʹ�*/
		if ((point->lchild&&point->lchild->flag!=1)||
			(point->rchild&&point->rchild->flag!=1))
		{
			stk.push(point);
			if (point->lchild)
			{
				point = point->lchild;
			}
			else
			{
				point = point->rchild;
			}
		}
		else
		{
			if (point->flag == 1)//���ʹ��Ľڵ�
			{

			}
			else
			{
				func(point);
				point->flag = 1;
				if (stk.empty())//���point����ֵ������ջ���ˣ�˵���͵��˸��ڵ�
					break;
				node = stk.top();//����Ҫ�ж�һ�£����ջ����
				if (node->lchild&&node->lchild->flag != 1)
				{
					point = node->lchild;
				}
				else if (node->rchild&&node->rchild->flag != 1)
				{
					point = node->rchild;
				}
				if ((!node->lchild || node->lchild->flag == 1) &&
					(!node->rchild || node->rchild->flag == 1))
				{
					
					point = node;
					stk.pop();
				}
			}
		}
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
	printf("��ͨ���ݹ�ʵ���������:\n");
	preOrderVisitBtreeWithoutrecursion(bt, printNode);
	printf("��ͨ���ݹ�ʵ���������:\n");
	middleOrderVisitBtreeWithoutrecursion(bt, printNode);
	printf("��ͨ���ݹ�ʵ�ֺ������:\n");
	afterOrderVisitBtreeWithoutrecursion(bt, printNode);
	system("pause");
    return 0;
}

