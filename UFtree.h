#pragma once
#include<iostream>
#include<string>
using namespace std;

class UFtree
{
	int* eleAndGroup;
	int countn;	//����ĸ���
public:
	UFtree(int n);
	int count();
	bool connected(int p,int q);
	int find(int p);
	void myunion(int p, int q);

};
