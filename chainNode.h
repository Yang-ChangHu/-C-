#pragma once
#include<iostream>
#include<string>
using namespace std;

//单链表节点类
template<class T>
class chainNode
{
public:
	T element;
	chainNode<T>* next;

	chainNode()
	{

	}

	chainNode(T element ,chainNode<T>* next)
	{
		this->element = element;
		this->next = next;
	}
	~chainNode()
	{
		cout << "chainNode析构函数调用" << endl;
		/*delete next;
		next = NULL;*/
	}
};