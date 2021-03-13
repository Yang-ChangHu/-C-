#pragma once
#include<iostream>
#include<string>
#include"queue.hpp"
#include"Edge.h"
using namespace std;

class EdgeWeightGraph
{
public:
	EdgeWeightGraph(int v);
	int V() const;
	int E() const;
	void addEdge(Edge e);
	Queue<Edge> Adj(int v) const;
	Queue<Edge> Adj() const;


private:
	int v;
	int e;
	Queue<Edge>* adj;


};
