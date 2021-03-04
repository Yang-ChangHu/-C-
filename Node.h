#pragma once
#include<iostream>
#include<string>
#include"myclass.h"
using namespace std;

//双链表
template<class T>
class Node
{
public:
	T item;  //当前节点的值
	Node<T>* next;  //指向上一个节点
	Node<T>* pre;  //指向下一个节点

	Node(T item, Node<T>* next, Node<T>* pre)
	{
		this->item = item;
		this->next = next;
		this->pre = pre;
	}
	Node()
	{
		this->next = NULL;
		this->pre =NULL;
	}

};
