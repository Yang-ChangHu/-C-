#pragma once
#include"Node.h"
#include<iostream>
#include<string>
using namespace std;
#include"myclass.h"
#include"chainNode.h"

template<class T>
class TowWayLinkList :public Node<T>
{
public:
	TowWayLinkList();   //构造函数
	void clear();		//空置线性表
	bool isEmpty() const;		//判断是否为空
	int length() const;		//线性表中元素个数
	T get(int i);		//返回线性表中第i个元素的值
	void insert(T t);	//往线性表中添加一个元素
	void insert(int i, T t);	//	往线性表第i个位置添加一个元素
	void remove(int i);		//删除并返回线性表中第i个元素
	T getFirst() const;		//获取线性表中第一个元素
	T getLast() const;		//获取线性表中最后一个元素
	int indexOf(T t) const;		//查找元素t第一次出现的位置
	void showMessage() const;	//显示当前双线性表信息


	Node<T>* head;		//指向第一个元素的指针
	Node<T>* last;		//指向最后一个元素的指针
	int N;				//线性表当前的元素
};


template<class T>
TowWayLinkList<T>::TowWayLinkList()  //构造函数
{
	this->head = NULL;
	this->last = NULL;
	this->N = 0;
}
template<class T>
void TowWayLinkList<T>::clear()		//空置线性表
{
	this->head->next = NULL;
	this->head->pre = NULL;
	this->head->item = NULL;
	this->N = 0;
	this->last = NULL;
}

template<class T>
bool TowWayLinkList<T>::isEmpty() const		//判断是否为空
{
	return (this->N == 0);
}

template<class T>
int TowWayLinkList<T>::length() const		//线性表中元素个数
{
	return this->N;
}

template<class T>
T TowWayLinkList<T>::get(int i)		//返回线性表中第i个元素的值
{
	if (i >= 0 && i < this->N)
	{
		Node<T>* curNode = this->head;
		for (int k = 0; k < i; k++)
		{
			curNode = curNode->next;
		}
		return curNode->item;
	}
}


template<class T>
void TowWayLinkList<T>::insert(T t)	//往线性表中添加一个元素
{
	if (this->isEmpty()) //如果链表为空
	{
		Node<T> *newNode = new Node<T>(t, NULL ,NULL);
		this->head = newNode;
		this->last = newNode;
	}
	else
	{
		Node<T>* newNode = new Node<T>(t,  NULL,NULL);
		newNode->pre = this->last;
		this->last->next = newNode;
		this->last = newNode;
	}

	this->N++;
}

template<class T>
void TowWayLinkList<T>::insert(int i,T t)	//	往线性表第i个位置添加一个元素
{
	if (i<0 || i>this->N)
	{
		cout << "输入的i超出范围" << endl;
		return;
	}
	else if(i>0 && i<this->N)
	{
		Node<T>* curNode = this->head;
		for (int n = 0; n < i-1; n++)
		{
			curNode = curNode->next;
		}
		Node<T>* newNode = new Node<T>(t, NULL, NULL);
		newNode->next = curNode->next;
		curNode->next->pre = newNode;
		newNode->pre = curNode;
		curNode->next = newNode;

	}
	else if(i==0)
	{
		Node<T>* newNode = new Node<T>(t, NULL, NULL);
		newNode->next = this->head;
		this->head->pre = newNode;
		this->head = newNode;
	}
	else if (i == this->N)
	{
		this->insert(t);
		return;
	}
	this->N++;
}

template<class T>
void TowWayLinkList<T>::remove(int i)		//删除并返回线性表中第i个元素
{
	Node<T>* curNode = this->head;
	if (i > 0 && i < this->N - 1)
	{
		for (int n = 0; n < i; n++)
		{
			curNode = curNode->next;
		}
		curNode->pre->next = curNode->next;
		curNode->next->pre = curNode->pre;
	}
	else if (i == 0)
	{
		this->head->next->pre = NULL;
		this->head = this->head->next;
	}
	else if (i == this->N - 1)
	{
		this->last = this->last->pre;
		this->last->next = NULL;
	}
	//delete curNode;
	this->N--;
	return ;
}

template<class T>
T TowWayLinkList<T>::getFirst() const		//获取线性表中第一个元素
{
	if (this->isEmpty())
	{
		cout << "当前列表为空" << endl;
	}
	else
	{
		return this->head->item;
	}
}

template<class T>
T TowWayLinkList<T>::getLast() const    //获取线性表中最后一个元素
{
	if (this->isEmpty())
	{
		cout << "当前列表为空" << endl;
	}
	else
	{
		return this->last->item;
	}
}


template<class T>
void TowWayLinkList<T>::showMessage() const	//显示当前双线性表信息
{
	Node<T>* curNode = this->head;
	int i = 0;
	cout << "\t当前双链表共有元素:" << this->N << "\t个" << endl;
	cout << "\t当前head指针:" << this->head << "\t当前last指针:" << this->last<< endl;
	while ((curNode) != NULL)
	{
		cout << "\t第 " << i << "\t个元素是：";
		cout << curNode->item;
		cout << "\t第 " << i << "\t个元素前指针是：" << curNode->pre << "\t后指针是：" << curNode->next << endl;
		i++;
		curNode = curNode->next;
	}
}

template<class T>
int TowWayLinkList<T>::indexOf(T t) const		//查找元素t第一次出现的位置
{
	Node<T>* curNode = this->head;
	int i = 0;
	while (curNode != NULL && i < this->N && curNode->item!=t)
	{
		curNode = curNode->next;
		i++;
	}
	if (i < this->N)
	{
		return i;
	}
	else
	{
		return -1;
	}
}
