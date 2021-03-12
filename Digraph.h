#pragma once
#include<iostream>
#include"queue.hpp"
#include<string>
#include"DepthFirstOrder.h"
#include"DirectedCycle.h"
#include"TopoLogical.h"
using namespace std;

class Digraph
{
	friend class DirectedCycle;
	friend class DepthOrder;
	friend class TopoLogical;
public:
	Digraph(int v);
	Digraph();
	//Digraph(const Digraph& g);
	~Digraph();
	int V();
	int E();
	void addEdge(int v, int w);
	Queue<int> Adj(int v);

private:
	Digraph reverse();
	int v;
	int e;
	Queue<int>* adj;
};
