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
	TowWayLinkList();   //���캯��
	void clear();		//�������Ա�
	bool isEmpty() const;		//�ж��Ƿ�Ϊ��
	int length() const;		//���Ա���Ԫ�ظ���
	T get(int i);		//�������Ա��е�i��Ԫ�ص�ֵ
	void insert(T t);	//�����Ա������һ��Ԫ��
	void insert(int i, T t);	//	�����Ա��i��λ�����һ��Ԫ��
	void remove(int i);		//ɾ�����������Ա��е�i��Ԫ��
	T getFirst() const;		//��ȡ���Ա��е�һ��Ԫ��
	T getLast() const;		//��ȡ���Ա������һ��Ԫ��
	int indexOf(T t) const;		//����Ԫ��t��һ�γ��ֵ�λ��
	void showMessage() const;	//��ʾ��ǰ˫���Ա���Ϣ


	Node<T>* head;		//ָ���һ��Ԫ�ص�ָ��
	Node<T>* last;		//ָ�����һ��Ԫ�ص�ָ��
	int N;				//���Ա�ǰ��Ԫ��
};


template<class T>
TowWayLinkList<T>::TowWayLinkList()  //���캯��
{
	this->head = NULL;
	this->last = NULL;
	this->N = 0;
}
template<class T>
void TowWayLinkList<T>::clear()		//�������Ա�
{
	this->head->next = NULL;
	this->head->pre = NULL;
	this->head->item = NULL;
	this->N = 0;
	this->last = NULL;
}

template<class T>
bool TowWayLinkList<T>::isEmpty() const		//�ж��Ƿ�Ϊ��
{
	return (this->N == 0);
}

template<class T>
int TowWayLinkList<T>::length() const		//���Ա���Ԫ�ظ���
{
	return this->N;
}

template<class T>
T TowWayLinkList<T>::get(int i)		//�������Ա��е�i��Ԫ�ص�ֵ
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
void TowWayLinkList<T>::insert(T t)	//�����Ա������һ��Ԫ��
{
	if (this->isEmpty()) //�������Ϊ��
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
void TowWayLinkList<T>::insert(int i,T t)	//	�����Ա��i��λ�����һ��Ԫ��
{
	if (i<0 || i>this->N)
	{
		cout << "�����i������Χ" << endl;
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
void TowWayLinkList<T>::remove(int i)		//ɾ�����������Ա��е�i��Ԫ��
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
T TowWayLinkList<T>::getFirst() const		//��ȡ���Ա��е�һ��Ԫ��
{
	if (this->isEmpty())
	{
		cout << "��ǰ�б�Ϊ��" << endl;
	}
	else
	{
		return this->head->item;
	}
}

template<class T>
T TowWayLinkList<T>::getLast() const    //��ȡ���Ա������һ��Ԫ��
{
	if (this->isEmpty())
	{
		cout << "��ǰ�б�Ϊ��" << endl;
	}
	else
	{
		return this->last->item;
	}
}


template<class T>
void TowWayLinkList<T>::showMessage() const	//��ʾ��ǰ˫���Ա���Ϣ
{
	Node<T>* curNode = this->head;
	int i = 0;
	cout << "\t��ǰ˫������Ԫ��:" << this->N << "\t��" << endl;
	cout << "\t��ǰheadָ��:" << this->head << "\t��ǰlastָ��:" << this->last<< endl;
	while ((curNode) != NULL)
	{
		cout << "\t�� " << i << "\t��Ԫ���ǣ�";
		cout << curNode->item;
		cout << "\t�� " << i << "\t��Ԫ��ǰָ���ǣ�" << curNode->pre << "\t��ָ���ǣ�" << curNode->next << endl;
		i++;
		curNode = curNode->next;
	}
}

template<class T>
int TowWayLinkList<T>::indexOf(T t) const		//����Ԫ��t��һ�γ��ֵ�λ��
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
