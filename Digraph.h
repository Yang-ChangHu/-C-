#pragma once
#include<iostream>
#include"queue.hpp"
#include<string>
#include"DirectedCycle.h"
using namespace std;

class Digraph
{
	friend class DirectedCycle;
public:
	Digraph(int v);
	Digraph();
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
