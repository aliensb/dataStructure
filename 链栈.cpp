// 链栈.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */
typedef struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;


typedef struct
{
	LinkStackPtr top;
	int count;
}LinkStack;

status initStack(LinkStack * stack)
{
	stack->count = 0;
	stack->top = NULL;
	return OK;
}

status push(LinkStack * stack,ElemType e)
{
	LinkStackPtr node = (LinkStackPtr)malloc(sizeof(StackNode));
	node->data = e;
	node->next = stack->top;
	stack->top = node;
	stack->count++;
	return OK;
}
status pop(LinkStack * stack, ElemType * e)
{
	if (stack->top == NULL)
		return ERROR;
	LinkStackPtr node = stack->top;
	*e = node->data;
	stack->top = node->next;
	free(node);
	stack->count--;
	return OK;
}

status clearStack(LinkStack * stack)
{
	if (stack->top == NULL)
		return OK;
	LinkStackPtr node = stack->top;
	LinkStackPtr p;
	while (node)
	{
		p = node;
		node = node->next;
		free(p);
		stack->count--;
	}
	if (stack->count == 0)
		return OK;
	else
		return ERROR;
}

int main()
{
	LinkStack stack;
	initStack(&stack);
	for (int i = 0; i < 10; i++)
	{
		printf("压入数据：%d\n", i);
		push(&stack, i);
	}
	/*出栈
	ElemType e;
	while (stack.top)
	{
		if (pop(&stack, &e))
			printf("出栈数据 : %d\n", e);
	}*/	
	clearStack(&stack);

	system("pause");

    return 0;

}

