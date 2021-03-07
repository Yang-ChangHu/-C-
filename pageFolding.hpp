#pragma once

#include<iostream>
#include<string>
using namespace std;
#include"treeNode.h"
#include"queue.hpp"
//template<class T1,class T2>
class pageFolding 
{
public:
	pageFolding(int n);
	void createTree();
	void ShowTree(treeNode<int, string>* root) const;
	treeNode<int, string>* root;

	int n;

};

 void pageFolding::createTree()
{
	this->root = NULL;
	for (int i = 0; i < this->n; i++)
	{
		if (i ==0)
		{
			this->root = new treeNode<int,string>(0,"down",NULL,NULL);
			continue;
		}
		//如果不是第一次对折
		//定义一个辅助队列，通过层序遍历的思想，找到叶子节点，叶子节点添加节点
		Queue<treeNode<int, string>*> q;
		q.enqueue(this->root);
		while (!(q.isEmpty()))
		{
			treeNode<int, string>* tmp = q.dequeue();

			if (tmp->left != NULL)
			{
				q.enqueue(tmp->left);
			}

			if (tmp->right != NULL)
			{
				q.enqueue(tmp->right);
			}
			if ((tmp->right == NULL) && (tmp->left == NULL))
			{
				tmp->left = new treeNode<int, string>(0, "down", NULL, NULL);
				tmp->right = new treeNode<int, string>(0, "up", NULL, NULL);
			}
		}
	}
}


void pageFolding::ShowTree(treeNode<int, string>* root) const
{
	if (root == NULL)
	{
		return;
	}
	if (root->left != NULL)
	{
		ShowTree(root->left);
	}

	cout << root->value << endl;
	if (root->right != NULL)
	{
		ShowTree(root->right);
	}
	
}


pageFolding::pageFolding(int n)
{
	this->n = n;
	this->createTree();
}