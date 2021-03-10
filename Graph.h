#pragma once
#include<iostream>
#include<string>
#include<queue>
using namespace std;

class Graph
{
public:
	Graph(int V);

	//	��ȡ�������
	int V() const;	

	//��ȡ�ߵĸ���
	int E() const;		

	//��ͼ�����һ����v-w
	void addEdge(int v, int w);

	//��ȡ�Ͷ���v���ڵ����ж���
	queue<int> Adj(int v);	

	void ShowMessage() const;


	queue<int> *adj;

private:
	int v;	
	int e;

	//
	
};



