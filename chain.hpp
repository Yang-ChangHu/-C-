#pragma once
#include<iostream>
#include<string>
#include"LinearList.h"
#include"chainNode.h"
using namespace std;

template<class T>
class chain :public linearList<T>
{
public:
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();

	//抽象数据类型ADT的方法

	virtual bool empty()const ;
	//当线性表为空时返回true

	virtual int size()const ;
	//返回线性表元素个数

	virtual T& get(int theIndex) const;
	//返回索引为theIndex的元素

	virtual int indexOf(const T& theElement) const ;
	//返回元素theElement第一次出现的索引

	virtual void erase(int theIndex) ;
	//删除索引为theIndex的元素

	virtual void insert(int theIndex, const T& theElement) ;
	//把元素theElement插入索引为theIndex的地方

	virtual void ShowMessage();

	//void reverse();		//反转整个链表

	void reverse();  //反转指定节点

	T getMid();		//寻找中间值

	bool CircleCheck();	//检查是否有环

	T getEntrance();

public:
	chainNode<T>* firstNode;
	int listSize;

};

//构造函数
template<class T>
chain<T>::chain(int initialCapacity )
{
	this->firstNode = NULL;
	this->listSize = 0;
}

//拷贝构造函数
template<class T>
chain<T>::chain(const chain<T>& theList)
{
	this->listSize = theList.listSize;
	
	if (this->listSize == 0)
	{
		this->firstNode = NULL;
		return;
	}

	chainNode<T>* sourceNode = theList.firstNode;
	this->firstNode = new chainNode<T>(sourceNode->element);
	chainNode<T>* targetNode = firstNode;
	while (sourceNode != NULL)
	{
		targetNode->next = new chainNode<T>(sourceNode->element);
		sourceNode = sourceNode->next;
		targetNode = targetNode->next;
	}
	targetNode->next = NULL;
}

//析构函数
template<class T>
chain<T>::~chain()
{
	while (firstNode!=NULL)
	{
		//chainNode<T>* nextNode = firstNode->next;
		//delete firstNode;
		//firstNode = nextNode;
	}
}

template<class T>
T& chain<T>::get(int theIndex) const
{
	chainNode<T>* node = firstNode;
	int i = 1;
	while ((node != NULL) && (i<theIndex))
	{
		node = node->next;
		i++;
	}
	return node->element;
}


template<class T>
bool chain<T>::empty()const
{
	return (firstNode == NULL);
}

template<class T>
int chain<T>::indexOf(const T& theElement) const
{
	cout << "indexof调用" << endl;
	int i = 0;
	chainNode<T>* node = firstNode;
	while ((node) != NULL && (node->element) != theElement)
	{
		node = node->next;
		i++;
	}
	if (node == NULL)
	{
		return -1;
	}
	else
	{
		return i;
	}
	
 }

template<class T>
void chain<T>::erase(int theIndex) 
{
	chainNode<T>* deleteNode;
	chainNode<T>* node = firstNode;
	for (int i = 0; i < theIndex-1; i++)
	{
		node = node->next;
		
	}
	deleteNode = node->next;
	node->next = (node->next)->next;
	delete deleteNode;
	listSize--;

}

template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex<0 || theIndex>listSize)
	{
		cout << "输入的数据不合法" << endl;
		return;
	}
	else if (theIndex == 0)
	{
		firstNode = new chainNode<T>(theElement, firstNode);
	}
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; i++)
		{
			p = p->next;
		}
		chainNode<T> newNode(theElement, p->next);
		p->next = new chainNode<T>(newNode);
	}
	listSize++;

}

template<class T>
int chain<T>::size()const
{
	return listSize;
 }

template<class T>
void chain<T>::ShowMessage()
{
	cout << "*************************************" << endl;
	cout << "打印链表信息" << endl;
	chainNode<T>* c = firstNode;
	while (c != NULL)
	{
		cout << "\t当前元素为";
		cout << c->element;
		cout << endl;
		cout<< "当前地址：" << c << "\t下一个元素地址"<<c->next<<endl;;
		c = c->next;
	}
	cout << "元素个数:" << listSize << endl;
}




template<class T>
void chain<T>::reverse() //反转指定节点
{
	if (this->firstNode == NULL || this->firstNode->next == NULL)
	{
		return;
	}
	chainNode<T>* pre = NULL;
	chainNode<T>* curNode = this->firstNode;
	while (curNode != NULL)
	{
		chainNode<T>* nextNode = curNode->next;
		curNode->next = pre;
		pre = curNode;
		curNode = nextNode;


	}
	this->firstNode = pre;

	return;
}




template<class T>
T chain<T>::getMid()
{
	chainNode<T>* fast = this->firstNode;
	chainNode<T>* slow = this->firstNode;
	while ( fast!=NULL && fast->next != NULL )   //注意！fast！=NULL写在前面
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow->element;
}



template<class T>
bool chain<T>::CircleCheck()
{
	chainNode<T>* fast = this->firstNode;
	chainNode<T>* slow = this->firstNode;
	while (fast != NULL && fast->next!=NULL )   //注意！fast！=NULL写在前面
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			cout << "有环" << endl;
			return true;
		}
	}
	cout << "无环" << endl;
	return false;
}



template<class T>
T chain<T>::getEntrance()
{
	chainNode<T>* fast = this->firstNode;
	chainNode<T>* slow = this->firstNode;
	chainNode<T>* newslow = this->firstNode;
	bool bang = false;

	if (this->CircleCheck())
	{

		while (fast != NULL && fast->next != NULL)   //注意！fast！=NULL写在前面
		{

			fast = fast->next->next;
			slow = slow->next;

			if (bang)
			{
				newslow = newslow->next;
			}
			if (slow == newslow)
			{
				return slow->element;
			}
			if (fast == slow )
			{
				cout << "快慢指针遇上了" << endl;
				//chainNode<T>* newslow = this->firstNode;
				bang = true;
			}

		}
		

	}
	
	return fast->element;
}
