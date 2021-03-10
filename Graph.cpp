#include<iostream>
#include<string>
#include<queue>
#include"Graph.h"
using namespace std;

Graph::Graph(int V)
{

	this->v = V;
	this->e = 0;
	this->adj = new queue<int>[V];
}

int Graph::V() const
{
	return this->v;
}

int Graph::E() const
{
	return this->e;
}

void Graph::addEdge(int v,int w) 
{
	this->adj[v].push(w);
	this->adj[w].push(v);
	this->e++;
}

queue<int> Graph::Adj(int v)
{
	return adj[v];
}

void Graph::ShowMessage() const
{

	queue<int>* tmp = new queue<int>[v];
	tmp = adj;
	cout << "\t���������" << V() << "\t�ߵĸ���" << E() << endl;

	for (int i = 0; i < V(); i++)
	{
		cout << "\t��" << i << "\t��Ԫ�ص��ڽӱ��ǣ�";
		while (!tmp[i].empty())
		{
			cout << tmp[i].front() << "  ";
			tmp[i].pop();
		}
			

		cout << endl;
	}

}