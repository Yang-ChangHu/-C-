#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"treeNode.h"

template<class T1,class T2>
class binaryTree
{
public:
	treeNode<T1, T2>* root;
	int N;

	binaryTree();
	void put(T1 key, T2 value);
	treeNode<T1, T2>* put(treeNode<T1, T2>* x, T1 key, T2 value);
	T2 get(T1 key) const;
	T2 get(treeNode<T1, T2>* x, T2 key) const;
	void mydelete(T1 key);
	void mydelete(treeNode<T1, T2>* x, T2 key);
	int size() const;
	
};

template<class T1,class T2>
int binaryTree<T1, T2>::size() const
{
	return N;
}


template<class T1, class T2>
binaryTree<T1, T2>::binaryTree() 
{
	this->root = NULL;
	this->N = 0;;
}

template<class T1, class T2>
void binaryTree<T1, T2>::put(T1 key, T2 value)
{
	root=put(this->root,  key,  value);
}

template<class T1, class T2>
treeNode<T1, T2>* binaryTree<T1, T2>::put(treeNode<T1, T2>* x,T1 key, T2 value)
{
	if (x==NULL)
	{
		N++;
		return  new treeNode<T1, T2>(key, value, NULL, NULL);
	}
	if (key > (x->key))
	{
		x->right = put(x->right, key, value);
	}
	else if (key < (x->key))
	{
		x->left = put(x->left, key, value);
	}
	else
	{
		x->key = key;
		return x;
	}

}


template<class T1, class T2>
T2  binaryTree<T1, T2>::get(T1 key) const
{
	return key;
}

template<class T1, class T2>
T2  binaryTree<T1, T2>::get(treeNode<T1, T2>* x, T2 key) const
{
	return key;
}

template<class T1, class T2>
void  binaryTree<T1, T2>::mydelete(T1 key)
{

}

template<class T1, class T2>
void  binaryTree<T1, T2>::mydelete(treeNode<T1, T2>* x, T2 key)
{

}