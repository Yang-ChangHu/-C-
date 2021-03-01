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

	//������������ADT�ķ���

	virtual bool empty()const ;
	//�����Ա�Ϊ��ʱ����true

	virtual int size()const ;
	//�������Ա�Ԫ�ظ���

	virtual T& get(int theIndex) const;
	//��������ΪtheIndex��Ԫ��

	virtual int indexOf(const T& theElement) const ;
	//����Ԫ��theElement��һ�γ��ֵ�����

	virtual void erase(int theIndex) ;
	//ɾ������ΪtheIndex��Ԫ��

	virtual void insert(int theIndex, const T& theElement) ;
	//��Ԫ��theElement��������ΪtheIndex�ĵط�

	virtual void ShowMessage();

protected:
	chainNode<T>* firstNode;
	int listSize;

};

//���캯��
template<class T>
chain<T>::chain(int initialCapacity )
{
	this->firstNode = NULL;
	this->listSize = 0;
}

//�������캯��
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

//��������
template<class T>
chain<T>::~chain()
{
	while (firstNode!=NULL)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
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
	cout << "indexof����" << endl;
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
		cout << "��������ݲ��Ϸ�" << endl;
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
	cout << "��ӡ������Ϣ" << endl;
	chainNode<T>* c = firstNode;
	while (c != NULL)
	{
		cout << c->element;
		cout<< "��ַ��" << c << endl;;
		c = c->next;
	}
	cout << "Ԫ�ظ���:" << listSize << endl;
}