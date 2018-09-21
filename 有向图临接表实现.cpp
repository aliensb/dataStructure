// 有向图临接表实现.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXVEX 100 /* 最大顶点数，应由用户定义 */
#define INFINITY 65535
typedef int status;
typedef char VertexType;
typedef int EdgeType;

typedef struct EgeNode {
	int adjIndex;
	EdgeType weight;
	EgeNode  * next = NULL;
}EgeNode;

typedef struct VertexNode {
	VertexType data;
	EgeNode * firstEge = NULL;

}VertexNode, adjList[MAXVEX];

typedef struct {
	adjList list;
	int vertexNu, egeNu;
}GraphAdj;


status creatGraph(GraphAdj *adj)
{
	char start, end;
	int v1 = 0, v2 = 0, w = INFINITY;
	printf("请输入图的顶点数\n");
	cin >> adj->vertexNu;
	printf("请输入图的边数\n");
	cin >> adj->egeNu;
	for (int i = 0; i < adj->vertexNu; i++)
	{
		printf("请输入第%d个顶点", i + 1);
		cin >> adj->list[i].data;
	}
	for (int i = 0; i < adj->egeNu; i++)
	{
		printf("请输入第%d条边的数据,格式如，AB5\n", i + 1);
		cin >> start;//边开始的节点
		cin >> end;//边结束的节点
		cin >> w;//边上的权重
		for (int j = 0; j < adj->vertexNu; j++)
		{
			if (adj->list[j].data == start)
				v1 = j;
			if (adj->list[j].data == end)
				v2 = j;
		}
		//头插法插入新的边节点
		EgeNode * node1 = (EgeNode*)malloc(sizeof(EgeNode));
		node1->next = adj->list[v1].firstEge;
		adj->list[v1].firstEge = node1;
		node1->weight = w;
		node1->adjIndex = v2;
	
	}
	return OK;
}
int main()
{
	GraphAdj adj;
	creatGraph(&adj);
	return 0;
}


