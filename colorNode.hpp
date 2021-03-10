#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class colorNode
{
public:
	T1 key;
	T2 value;
	colorNode<T1, T2>* left;
	colorNode<T1, T2>* right;
	bool color;


	colorNode(T1 key, T2 value, colorNode<T1, T2>* left, colorNode<T1, T2>* right, bool color);
};

template<class T1,class T2>
colorNode<T1, T2>::colorNode(T1 key, T2 value, colorNode<T1, T2>* left, colorNode<T1, T2>* right, bool color)
{
	this->key = key;
	this->value = value;
	this->left = left;
	this->right = right;
	this->color = color;
}