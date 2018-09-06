// 二叉树链表实现.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stack>//标准库栈

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef char ElemeType;
typedef struct BiTNode  /* 结点结构 */
{
	ElemeType data;		/* 结点数据 */
	struct BiTNode *lchild, *rchild; /* 左右孩子指针 */
}BiTNode, *BiTree; 

typedef int status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

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
			//内存分配失败
			return ERROR;
		}
		else
		{
			(*bt)->data = ch;
			printf("请输入%c左节点的值：\n",ch);
			getchar();
			//这里传递的是指向子树的指针（子树根节点地址）的地址
			createBtree(&((*bt)->lchild));
			printf("请输入%c右节点的值：\n", ch);
			getchar();
			createBtree(&((*bt)->rchild));
		}
	}
}
void printNode(BiTNode* node)
{
	printf("节点的值为：%c\n", node->data);
}
void preOrderVisitBtree(BiTree bt, void(*func)(BiTNode*))
{
	if (!bt)
	{
//		printf("树为空!!\n");
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
		//		printf("树为空!!\n");
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
		//		printf("树为空!!\n");
		return;
	}
	else
	{

		afterOrderVisitBtree(bt->lchild, func);
		afterOrderVisitBtree(bt->rchild, func);
		func(bt);
	}
}


/*不通过栈实现二叉树的先序遍历*/
void preOrderVisitBtreeWithoutrecursion(BiTree bt, void(*func)(BiTNode*))
{
	if (!bt)
	{
		//		printf("树为空!!\n");
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

void middleOrderVisitBtreeWithoutrecursion(BiTree bt, void(*func)(BiTNode*))
{
		
}
int main()
{
	BiTree bt;//创建一个指向树根节点的指针，

	initBTree(&bt);//初始化树，将根指针指向空，表面是一个空树
	createBtree(&bt);
	printf("先序遍历结果：\n");
	preOrderVisitBtree(bt, printNode);
	printf("中序遍历结果：\n");
	middleOrderVisitBtree(bt, printNode);
	printf("后序遍历结果：\n");
	afterOrderVisitBtree(bt,printNode);
	printf("不通过递归实现先序遍历:\n");
	preOrderVisitBtreeWithoutrecursion(bt, printNode);
	system("pause");
    return 0;
}

