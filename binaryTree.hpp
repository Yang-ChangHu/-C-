#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"treeNode.h"
#include"queue.hpp"

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
	treeNode<T1, T2>* get(treeNode<T1, T2>* x, T1 key) const;
	void mydelete(T1 key);
	treeNode<T1, T2>* mydelete(treeNode<T1, T2>* x, T1 key);
	int size() const;

	void min() ;
	treeNode<T1, T2>* min(treeNode<T1, T2>* x);


	void max();
	treeNode<T1, T2>* max(treeNode<T1, T2>* x);


	Queue<T1> preErgodic();		//前序遍历，获取整个树中所有键

	void preErgodic(treeNode<T1,T2> *x,Queue<T1> &keys);		//前序遍历，获取指定树x中所有键放入keys中


	Queue<T1> midErgodic();
	void midErgodic(treeNode<T1, T2>* x, Queue<T1> &keys);		//中序遍历


	Queue<T1> afterErgodic();
	void afterErgodic(treeNode<T1, T2>* x, Queue<T1>& keys);	//后序遍历

	Queue<T1> layerErgodic();		//层序遍历

	int maxDepth();
	int maxDepth(treeNode<T1, T2>* x);
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
	this->root=put(this->root,  key,  value);
}

template<class T1, class T2>
treeNode<T1, T2>* binaryTree<T1, T2>::put(treeNode<T1, T2>* x,T1 key, T2 value)
{
	
	if (x==NULL)
	{
		treeNode<T1, T2>* newNode= new treeNode<T1, T2>(key, value, NULL, NULL);
		N++;
		x = newNode;
		return x;
	}
	if (key > (x->key))
	{
		x->right=put(x->right, key, value);
	}
	else if (key < (x->key))
	{
		x->left= put(x->left, key, value);
	}
	else
	{
		x->key = key;
		
	}
	return x;
}


template<class T1, class T2>
T2 binaryTree<T1, T2>::get(T1 key) const
{
	treeNode<T1, T2>* targetNode = get(this->root, key);
	if (targetNode == NULL)
	{
		cout << "找不到这个元素" << endl;
		return -1;
	}
	else
	{
		return targetNode->value;
	}
	
}

template<class T1, class T2>
treeNode<T1, T2>* binaryTree<T1, T2>::get(treeNode<T1, T2>* x, T1 key) const
{

	if (x == NULL)
	{
		return NULL;
	}
	if ((x->key) == key)
	{
		return x;
	}
	else if (key < (x->key))
	{
		return get((x->left), key);
	}
	else 
	{
		return get(x->right, key);
	}
	//return x;


}

template<class T1, class T2>
void  binaryTree<T1, T2>::mydelete(T1 key)
{
	this->root=mydelete(this->root, key);
}

template<class T1, class T2>
treeNode<T1, T2>* binaryTree<T1, T2>::mydelete(treeNode<T1, T2>* x, T1 key)
{
	if (x == NULL)
	{
		return x;
	}

	if ((x->key) > key)
	{
		x->left= mydelete(x->left, key);
	}
	else if ((x->key) < key)
	{
		x->right =mydelete(x->right, key);
	}
	else
	{
		if ((x->right == NULL) && (x->left != NULL))
		{
			return x->left;
		}
		if ((x->left == NULL) && (x->right != NULL))
		{
			return x->right;
		}
		if ((x->left == NULL) && (x->right == NULL))
		{
			return NULL;
		}
		treeNode<T1, T2>* minNode = x->right;
		treeNode<T1, T2>* minNodeParent =x-> right;
		while ((minNode->left) != NULL)
		{
			//minNodeParent = minNode;
			minNode = minNode->left;
		}
		while ((minNode->left) != NULL)
		{
			if (minNodeParent->left->left == NULL)
			{
				break;
			}
			minNodeParent = minNodeParent->left;
		}



		minNodeParent->left = NULL;

		minNode->right = x->right;
		minNode->left = x->left;
		x = minNode;
		this->N--;
		
	}
	return x;
}



template<class T1,class T2>
void binaryTree<T1, T2>::min()
{
	treeNode<T1, T2>* minNode = min(root);
	cout << "最小的键是" << minNode->key << endl;
}


template<class T1, class T2>
treeNode<T1, T2>* binaryTree<T1, T2>::min(treeNode<T1, T2>* x)
{
	if (x->left == NULL)
	{
		return x;
	}
	else
	{
		x->left = min(x->left);
	}
}


template<class T1, class T2>
void binaryTree<T1, T2>::max()
{
	treeNode<T1, T2>* maxNode = max(root);
	cout << "最大的键是" << maxNode->key << endl;
}


template<class T1, class T2>
treeNode<T1, T2>* binaryTree<T1, T2>::max(treeNode<T1, T2>* x)
{
	if (x->right == NULL)
	{
		return x;
	}
	else
	{
		x->right = max(x->right);
	}
}



template<class T1, class T2>
Queue<T1> binaryTree<T1, T2>::preErgodic()		//前序遍历，获取整个树中所有键
{
	Queue<T1> keys;
	preErgodic(this->root, keys);
	return keys;
}



template<class T1, class T2>
void binaryTree<T1, T2>::preErgodic(treeNode<T1, T2> *x, Queue<T1> &keys)		//前序排列，获取指定树x中所有键放入keys中
{
	if (x == NULL)
	{
		return;
	}
	keys.enqueue(x->key);
	if (x->left != NULL)
	{
		preErgodic(x->left, keys);
	}
	if (x->right != NULL)
	{
		preErgodic(x->right, keys);
	}
}



template<class T1, class T2>
Queue<T1> binaryTree<T1, T2>::midErgodic()
{
	Queue<T1> keys;
	midErgodic(this->root, keys);
	return keys;

}



template<class T1, class T2>
void binaryTree<T1, T2>::midErgodic(treeNode<T1, T2>* x, Queue<T1> &keys)
{
	if (x == NULL)
	{
		return;
	}
	if (x->left != NULL)
	{
		
		midErgodic(x->left, keys);
	}
	keys.enqueue(x->key);
	if (x->right != NULL)
	{
		midErgodic(x->right, keys);
	}
}


template<class T1, class T2>
Queue<T1> binaryTree<T1, T2>::afterErgodic()
{
	Queue<T1> keys;
	afterErgodic(this->root, keys);
	return keys;
}


template<class T1, class T2>
void binaryTree<T1, T2>::afterErgodic(treeNode<T1, T2>* x, Queue<T1>& keys)
{
	if (x == NULL)
	{
		return;
	}
	if (x->left != NULL)
	{
		afterErgodic(x->left, keys);
	}
	if (x->right != NULL)
	{
		afterErgodic(x->right, keys);
	}
	keys.enqueue(x->key);
}




template<class T1, class T2>
Queue<T1> binaryTree<T1, T2>::layerErgodic()
{
	Queue<T1> keys;
	Queue<treeNode<T1, T2>*> nodes;
	nodes.enqueue(root);
	while (!nodes.isEmpty())
	{
		
		treeNode<T1, T2>* n = nodes.dequeue();
		keys.enqueue(n->key);
		if (n->left != NULL)
		{
			nodes.enqueue(n->left);
		}
		if (n->right != NULL)
		{
			nodes.enqueue(n->right);
		}
	}
	return keys;

}




template<class T1, class T2>
int binaryTree<T1, T2>::maxDepth()
{
	return maxDepth(root);


}


template<class T1, class T2>
int binaryTree<T1, T2>::maxDepth(treeNode<T1,T2> * x)
{
	int maxX = 0;
	int maxL = 0;
	int maxR = 0;
	if (x == NULL)
	{
		return 0;
	}
	if (x->left != 0)
	{
		maxL = maxDepth(x->left);
	}
	if (x->right != 0)
	{
		maxR = maxDepth(x->right);
	}
	(maxR > maxL) ? (maxX = maxR) : (maxX = maxL);
	return maxX+1;
}