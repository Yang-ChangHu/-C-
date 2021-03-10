#pragma once
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Graph
{
public:
	Graph(int V);

	//	获取顶点个数
	int V() const;	

	//获取边的个数
	int E() const;		

	//向图中添加一条边v-w
	void addEdge(int v, int w);

	//获取和定点v相邻的所有顶点
	queue<int> Adj(int v);	

	void ShowMessage() const;


	queue<int> *adj;

private:
	int v;	
	int e;

	//
	
};



