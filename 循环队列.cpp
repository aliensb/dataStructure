// 循环队列.cpp : Defines the entry point for the console application.
//



/*
队列判满:(rear+1)%queSize==front
队列长度（rear-front+queSize)%queSize
队列判空rear==front
*/
#include "stdafx.h"
#include<stdlib.h>

typedef int ElemType;
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int status;
typedef struct {
	ElemType data[MAXSIZE];
	int front;
	int rear;
} Queue;
status initQueue(Queue * que)
{
	que->front = 0;
	que->rear = 0;
	return OK;
}
bool isQueueFull(Queue *que)
{
	if ((que->rear + 1) % MAXSIZE == que->front)
		return TRUE;
	return FALSE;
	
}

bool isQueEmpty(Queue * que)
{
	if (que->front == que->rear)
		return TRUE;
	return FALSE;

}
int getQueLength(Queue * que)
{
	return (que->rear - que->front + MAXSIZE) % MAXSIZE;
}

status enQueue(Queue * que,ElemType e)
{
	if (!isQueueFull(que))
	{
		que->data[que->rear] = e;
		que->rear = (que->rear + 1) % MAXSIZE;
		return OK;
	}
	return FALSE;
} 

status deQueue(Queue * que, ElemType * e)
{
	if (!isQueEmpty(que))
	{
		*e = que->data[que->front];
		que->front= (que->front + 1) % MAXSIZE;
		return OK;
	}
	return FALSE;
}
int main()
{
	Queue que;
	initQueue(&que);
	for (int i = 0; i < 10; i++)
	{
		printf("入队列 %d\n", i);
		enQueue(&que, i);
	}
	ElemType e;
	while (!isQueEmpty(&que))
	{
		if (deQueue(&que, &e))
			printf("出队列 %d \n", e);
		else
			printf("错误，队列已为空");
	}
	system("pause");
    return 0;
}

