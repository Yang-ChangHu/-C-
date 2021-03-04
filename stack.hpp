#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"myclass.h"
#include"chainNode.h"

//用链表实现栈
template<class T>
class stack 
{
public:
	stack();
	bool isEmpty() const;
	chainNode<T>* pop();
	void push(T t);
	int size() const;
	void showMessage() const;
	chainNode<T>* getHead() const;
private:
	chainNode<T>* head;
	int N;
};

template<class T>
stack<T>::stack()
{
	this->head = NULL;
	this->N = 0;
}

template<class T>
bool stack<T>::isEmpty() const
{
	return this->N == 0;
}

template<class T>
int stack<T>::size() const
{
	return this->N ;
}

template<class T>
void stack<T>::push(T t)
{
	if (this->N == 0)
	{
		chainNode<T>* newNode = new chainNode<T>(t, NULL);
		this->head = newNode;
	}
	else
	{
		chainNode<T>* newNode = new chainNode<T>(t, NULL);
		newNode->next = this->head;
		this->head = newNode;
	}

	N++;
}

template<class T>
chainNode<T>* stack<T>::pop()
{
	if (this->N == 0)
	{
		return NULL;
	}
	else 
	{
		chainNode<T>* curNode = this->head;
		this->head = this->head->next;
		this->N--;
		return curNode;
	}
}


template<class T>
void stack<T>::showMessage() const
{
	cout << "\t当前栈有：" << this->N << "\t个元素" << endl;
	chainNode<T>* curNode = this->head;
	while (curNode != NULL)
	{
		cout << curNode->element << endl;
		curNode = curNode->next;
	}
}

template<class T>
chainNode<T>* stack<T>::getHead() const
{
	return this->head;
}