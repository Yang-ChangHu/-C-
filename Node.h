#pragma once
#include<iostream>
#include<string>
#include"myclass.h"
using namespace std;

//˫����
template<class T>
class Node
{
public:
	T item;  //��ǰ�ڵ��ֵ
	Node<T>* next;  //ָ����һ���ڵ�
	Node<T>* pre;  //ָ����һ���ڵ�

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
