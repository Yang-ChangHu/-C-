#pragma once
#include<iostream>
#include<string>
#include"colorNode.hpp"
using namespace std;

template<class T1,class T2>
class RedBlackTree
{
public:
	RedBlackTree();
	void put(T1 key, T2 value);
	T2 get(T1 key) const;
	int size() const;

private:
	bool isRed(colorNode<T1, T2>* x) const;
	colorNode<T1, T2>* rotateLeft(colorNode<T1, T2>* h);
	colorNode<T1, T2>* rotateRight(colorNode<T1, T2>* h);
	void flipColors(colorNode<T1, T2>* h);
	colorNode<T1, T2>* put(colorNode<T1, T2>* h,T1 key,T2 value);
	T2 get(colorNode<T1, T2>* h, T1 key) const;


	colorNode<T1, T2>* root;
	int N;
	//static bool RED;
	//static bool BLACK;

};

template<class T1,class T2>
int RedBlackTree<T1, T2>::size() const
{
	return this->N;
}

template<class T1, class T2>
bool RedBlackTree<T1, T2>::isRed(colorNode<T1, T2>* x) const
{
	if (x == NULL)
	{
		return false;
	}
	return x->color == true;//??有点不懂
}

template<class T1,class T2>
colorNode<T1, T2>* RedBlackTree<T1, T2>::rotateLeft(colorNode<T1, T2>* h)
{
	colorNode<T1, T2>* x = h->right;
	h->right = x->left;
	x->left = h;
	x->color = h->color;
	h->color = true;
	return x;
}

template<class T1, class T2>
colorNode<T1, T2>* RedBlackTree<T1, T2>::rotateRight(colorNode<T1, T2>* h)
{
	colorNode<T1, T2>* x = h->left;
	h->left= x->right;
	x->right = h;
	x->color = h->color;
	h->color = true;
	return x;
}


template<class T1,class T2>
void RedBlackTree<T1, T2>::flipColors(colorNode<T1, T2>* h)
{
	h->left->color = false;
	h->right->color = false;
	h->color = true;
}

template<class T1,class T2>
void RedBlackTree<T1, T2>::put(T1 key, T2 value)
{
	this->root =put(this->root, key, value);
	this->root->color = false;
	return;
}

template<class T1, class T2>
colorNode<T1, T2>* RedBlackTree<T1, T2>::put(colorNode<T1, T2>* h,T1 key, T2 value)
{
	if (h == NULL)
	{
		N++;
		return new colorNode<T1, T2>(key, value, NULL, NULL, true);
	}
	if (key < h->key)
	{
		h->left = put(h->left, key, value);
	}
	else if (key > h->key)
	{
		h->right = put(h->right, key, value);
	}
	else
	{
		h->value = value;
	}

	//进行左旋:左节点黑右节点红时
	if (isRed(h->right) && (!isRed(h->left)))
	{
		h=rotateLeft(h);
	}
	//进行右旋
	if (isRed(h->left) && (isRed(h->left->left)))
	{
		h=rotateRight(h);
	}
	//进行反转
	if (isRed(h->right) && (isRed(h->left)))
	{
		flipColors(h);
	}

	return h;
}


template<class T1, class T2>
T2 RedBlackTree<T1, T2>::get(T1 key) const
{
	return get(this->root, key);
	
}

template<class T1, class T2>
T2 RedBlackTree<T1, T2>::get(colorNode<T1, T2>* h,T1 key) const
{
	if (h == NULL)
	{
		cout << "没有找到响应值" << endl;
		//return NULL

	}
	else
	{
		if (key < h->key)
		{
			return get(h->left, key);
		}
		else if (key > h->key)
		{
			return get(h->right, key);
		}
		else
		{
			return h->value;
		}

	}
}

template<class T1, class T2>
RedBlackTree<T1, T2>::RedBlackTree()
{
	this->root = NULL;
	this->N = 0;
}