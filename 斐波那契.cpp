// 쳲�����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
int Fbi(int i)  /* 쳲������ĵݹ麯�� */
{
	printf("%d  ",i);
	if (i < 2)
		return i == 0 ? 0 : 1;
	return Fbi(i - 1) + Fbi(i - 2);  /* ����Fbi���Ǻ����Լ��������ڵ����Լ� */
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

Fbi����ѹ��ջ��˳����5��4��3��2��1��0��1��2��1��0��3��2��0��1
�Ƕ�һ�����������������


*/