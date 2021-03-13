#pragma once
#include<iostream>
#include<string>
#include"myclass.h"
#include"chainNode.h"
using namespace std;


//����
template<class T>
class Queue
{
public:
	Queue();
	~Queue();
	Queue(const Queue& q);
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

	if (this->N == 1)
	{
		T headElement = this->head->element;
		this->head = NULL;
		this->N = 0;
		return headElement;
	}
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
		cout << "\t��ǰû��Ԫ��" << endl;
		return;
	}
	cout << "\t��ǰ����" << (this->N) << "\t��Ԫ��" << endl;
	while (curNode != (this->last)  && curNode!=NULL)
	{
		cout << "\t��ǰ��"<<i<<"\t��Ԫ���ǣ�"<<curNode->element;
		cout << endl;
		curNode = curNode->next;
		i++;
	}
	cout << "\t���һ��Ԫ���ǣ�" << (this->last->element);
	cout << endl;
	return;
}


template<class T>
Queue<T>::Queue(const Queue& q)
{
	cout << "Queue�������캯������" << endl;
	if (q.N == 0)
	{
		head = NULL;
		last = NULL;
		N = 0;
	}
	else
	{
	head = new chainNode<T>(*(q.head));
	last = new chainNode<T>(*(q.last));
	N = q.N;
	}

}


template<class T>
Queue<T>::~Queue()
{
	delete head;
	delete last;
	this->head = NULL;
	this->last = NULL;
	cout << "Queue������������" << endl;
}
