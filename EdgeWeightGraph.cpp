#include<iostream>
#include<string>
#include"EdgeWeightGraph.h"
#include"queue.hpp"



EdgeWeightGraph::EdgeWeightGraph(int v)
{
	this->v = v;
	this->e = 0;
	this->adj = new Queue<Edge>[v];
}
int EdgeWeightGraph::V() const
{
	return this->v;
}
int EdgeWeightGraph::E() const
{
	return this->e;
}
void EdgeWeightGraph::addEdge(Edge e)
{
	int v = e.Either();
	int w = e.Other(v);
	adj[v].enqueue(e);
	adj[w].enqueue(e);

	this->e++;
}
Queue<Edge> EdgeWeightGraph::Adj(int v) const
{
	return adj[v];
}
Queue<Edge> EdgeWeightGraph::Adj() const
{
	Queue<Edge> allEdge;
	for (int i = 0; i < this->v; i++)
	{
		Queue<Edge> tmp = this->adj[v];
		while (!tmp.isEmpty())
		{
			if (tmp.head->element.Other(v) < v)
			{
				allEdge.enqueue(tmp.dequeue());
			}
			else
			{
				cout << tmp.dequeue().Other(v) << endl;
			}
		}
	}
	return allEdge;
}