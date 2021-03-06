#pragma once
#include<iostream>
#include<string>
#include"myclass.h"
#include"chainNode.h"
using namespace std;


//队列
template<class T>
class Queue
{
public:
	Queue();
	bool isEmpty() const;
	int size() const;
	T dequeue();
	void enqueue(T t);
	void showMessage() const;

	chainNode<T>* head;
	int N;
	chainNode<T>* last;
};

template<class T>
bool Queue<T>::isEmpty() const
{
	return this->N == 0;
}

template<class T>
int Queue<T>::size()  const
{
	return this->N;
}

template<class T>
T Queue<T>::dequeue()
{

	chainNode<T>* curNode = this->head;
	T tmp=(this->head->element);
	this->head = this->head->next;
	N--;
	if (isEmpty())
	{
		this->last = NULL;
	}
	return tmp;
}

template<class T>
void Queue<T>::enqueue(T t)
{
	if (this->N == 0)
	{
		this->head = new chainNode<T>(t, NULL);
		this->last = this->head;
	}
	else 
	{
		chainNode<T>* newNode = new chainNode<T>(t, NULL);
		this->last->next = newNode;
		this->last = newNode;
	}
	N++;
}
template<class T>
Queue<T>::Queue()
{
	this->head = NULL;
	this->last = NULL;
	this->N = 0;
}

template<class T>
void Queue<T>::showMessage() const
{
	chainNode<T>* curNode = this->head;
	int i = 0;
	if ((this->N) == 0)
	{
		cout << "\t当前没有元素" << endl;
		return;
	}
	cout << "\t当前共有" << (this->N) << "\t个元素" << endl;
	while (curNode != (this->last))
	{
		cout << "\t当前第"<<i<<"\t个元素是："<<curNode->element;
		cout << endl;
		curNode = curNode->next;
		i++;
	}
	cout << "\t最后一个元素是：" << (this->last->element);
	cout << endl;
	return;
}

