#pragma once
#include<iostream>
#include<string>
using namespace std;

class UFtreeWeight
{
	int* eleAndGroup;
	int countn;	//����ĸ���
	int* sz;
public:
	UFtreeWeight(int n);
	int count();
	bool connected(int p, int q);
	int find(int p);
	void myunion(int p, int q);
	void showMessage(int n);

};
