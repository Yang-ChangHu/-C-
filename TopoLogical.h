#pragma once
#include<iostream>
#include<string>
#include"stack.hpp"
#include"Digraph.h"
#include"DirectedCycle.h"
#include"DepthFirstOrder.h"
using namespace std;

class TopoLogical
{
public:
	bool isCycle();
	stack<int> Order();
	TopoLogical(class Digraph G);

private:
	stack<int> order;


};
