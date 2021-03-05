#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class treeNode
{
public:
	T1 key;
	T2 value;
	treeNode<T1, T2>* left;
	treeNode<T1, T2>* right;

	treeNode();
	treeNode(T1 key,T2 value, treeNode<T1, T2>* left, treeNode<T1, T2>* right);
};

template<class T1,class T2>
treeNode<T1, T2>::treeNode(T1 key, T2 value, treeNode<T1, T2>* left, treeNode<T1, T2>* right)
{
	this->key = key;
	this->value = value;
	this->left = left;
	this->right = right;
}

template<class T1, class T2>
treeNode<T1, T2>::treeNode()
{
	this->left = NULL;
	this->right = NULL;
}