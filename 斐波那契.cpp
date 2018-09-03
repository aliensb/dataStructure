// 斐波那契.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
int Fbi(int i)  /* 斐波那契的递归函数 */
{
	printf("%d  ",i);
	if (i < 2)
		return i == 0 ? 0 : 1;
	return Fbi(i - 1) + Fbi(i - 2);  /* 这里Fbi就是函数自己，等于在调用自己 */
}

int main()
{
	int i = 0;
	i=Fbi(5);
	printf("%d \n",i);
	system("pause");
    return 0;
}

/*

Fbi函数压入栈的顺序是5，4，3，2，1，0，1，2，1，0，3，2，0，1
是对一个二叉树的先序遍历


*/