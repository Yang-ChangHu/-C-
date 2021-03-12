#pragma once
#include<iostream>
#include<string>
#include"stack.hpp"
#include"DirectedCycle.h"
using namespace std;

class DepthOrder
{
public:
	DepthOrder(class Digraph G);
	~DepthOrder();
	stack<int> ReversePost();

private:
	void dfs(class Digraph G, int v);

	bool* marked;
	stack<int> reversePost;
};

