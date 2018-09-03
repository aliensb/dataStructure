// 线性表.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAXSIZE 20
typedef int ElemType;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int status;

typedef struct
{
	ElemType data[MAXSIZE];
	int length;
} SqlList;
status initList(SqlList * l)
{
	l->length = 0;
	return OK;
}
status getElem(SqlList * l, int i, ElemType * e)
{
	//如果表的长度小于0，或者要取的元素编号小于1，或者要去的元素编号大于表的长度
	//这里元素的编号从1开始编号，不存在编号为0的元素
	if (l->length == 0 || i<1 || i>l->length+1)
		return ERROR;
	*e = l->data[i - 1];//i是元素的编号，而元素的下标是从0开始编号的，元素在数组中的下标等于元素的编号减一
	return OK;
}
status insertList(SqlList *l, int i, ElemType e)
{
	if (l->length == MAXSIZE)//表满了
		return ERROR;
	if(i<1||i>l->length+1)//插入的位子在第一个前或者是在数据最后一个元素后+1的位子（如果插入成功，数组会有间隔）
		return ERROR;
	if (i < l->length) //插入的位子在表数据中间，需要将插入位置后面的数据往后移动
	{
		for (int k = l->length - 1; k >= i - 1; k--)
		{
			l->data[k + 1] = l->data[k];
		 }
	}
	l->data[i - 1] = e;
	l->length++;
	return OK;
}

status listDel(SqlList *l, int i)
{
	if (l->length == 0)//表为空的时候不能删除
		return ERROR;
	if (i<1 || i>l->length)//删除的元素编号不能小于1，不能删除大于表长度后的数据
		return ERROR;
	for (; i < l->length - 1; i++)
	{
		l->data[i - 1] = l->data[i];
	}
	l->length--;
	return OK;
}
void printList(SqlList* l)
{
	for (int i = 0; i < l->length - 1; i++)
	{
		printf("%d", l->data[i]);
		if (i != l->length - 2)
			printf(",");
	}

	printf("\n");
}
//char 1B,short 2B,int 4B,long 4B,float 4B,
int main()
{
	SqlList list;
	ElemType e;
	status st;
	int j, k;
	st=initList(&list);
	printf("初始化后，list的长度为：%d \n", list.length);
	for (int j = 0; j <= 5; j++)
	{
		insertList(&list, 1, j);//向数组中第一个元素插入
		printf("插入数据 %d \n", j);
	}
	printList(&list);
	listDel(&list, 3);
	printList(&list);
	getchar();
    return 0;
}

