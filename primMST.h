#pragma once
#include"EdgeWeightGraph.h"
#include"indexMinPriorityQueue.hpp"

class PrimMST
{
public:
	PrimMST(EdgeWeightGraph G);
	Queue<Edge> Edges();

private:
	void visit(EdgeWeightGraph G, int v);
	Edge* Prim_edgeTo;
	double* Prim_distTo;
	bool* Prim_marked;
	IndexMinPriorityQueue<double> pq;

};