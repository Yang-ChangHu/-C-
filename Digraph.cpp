#pragma once
#include<iostream>
#include"queue.hpp"
#include<string>
#include"Digraph.h"
using namespace std;

Digraph::Digraph(int v)
{
	this->v = v;
	adj = new Queue<int>[v];

	this->e = 0;
}
int Digraph::V()
{
	return this->v;
}
int Digraph::E()
{
	return  this->e;
}
void Digraph::addEdge(int v, int w)
{
	this->adj[v].enqueue(w);
	e++;
}
Queue<int> Digraph::Adj(int v)
{
	return this->adj[v];
}


Digraph Digraph::reverse()
{
	Digraph r(this->v);
	for (int v = 0; v < this->v; v++)
	{
		Queue<int> tmp(adj[v]);
		while (!tmp.isEmpty())
		{
			r.addEdge(tmp.dequeue(),v);
			
		}
	}
	return r;
}

Digraph::~Digraph()
{
	delete this->adj;
	adj = NULL;
}

Digraph::Digraph()
{
	this->v = 0;
	this->adj = NULL;
	this->e = 0;
}
