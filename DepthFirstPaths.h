#pragma once
#include<iostream>
#include<string>
#include"stack.hpp"
#include"Graph.h"
#include<queue>
using namespace std;

class DepthFirstPaths
{
public:
	DepthFirstPaths(Graph G, int s);
	~DepthFirstPaths();
	bool hasPathTo(int v);
	stack<int> pathRo(int v);

private:
	void dfs(Graph G, int v);
	bool* marked;
	int s;
	int* edgeTo;
};

