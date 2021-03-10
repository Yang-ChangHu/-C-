#pragma once
#include<iostream>
#include<string>
using namespace std;
class UF 
{
	int* eleAndGroup;
	int countn;

public:
	UF(int n);
	int count();
	int find(int p);
	bool connected(int p, int q);
	void myunion(int p, int q);
};