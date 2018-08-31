// ջ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
typedef int ElemType;
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 1
typedef int status;

typedef struct {
	ElemType data[MAXSIZE];
	int top;
} stack;
status initStack(stack * st)
{
	st->top = -1;
	return OK;
}
status push(stack* st, ElemType e)
{
	if (st->top == MAXSIZE - 1)//栈满了
		return ERROR;
	st->top++;
	st->data[st->top] = e;
	return OK;
}
status pop(stack * st, ElemType * e)
{
	if (st->top == -1)//栈为空
		return ERROR;
	*e = st->data[st->top];
	st->top--;
}
int main()
{
	stack st;
	initStack(&st);
	for (int i = 0; i < 10; i++)
	{
		printf("压入栈 %d\n", i);
		push(&st, i);
	}
	ElemType val;
	
	while (pop(&st, &val))
	{
		printf("出栈 %d \n", val);
	}
	system("pause");
    return 0;
}

