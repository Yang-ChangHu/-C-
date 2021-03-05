#pragma once
#include<iostream>
#include<string>
#include"symbolchainNode.h"

template<class T1,class T2>
class symbolTable
{
public:
	int m_N;
	symbolchainNode<T1, T2>* head;

	T2 get(T1 key) const;
	void put(T1 key, T2 value);
	void rankput(T1 key, T2 value);
	void mydelete(T1 key);
	int size();

	symbolTable();
	void showMessage() const;
};

template<class T1,class T2>
symbolTable<T1, T2>::symbolTable()
{
	this->m_N = 0;
	this->head = NULL;
}

template<class T1,class T2>
T2 symbolTable<T1, T2>::get(T1 key) const
{
	symbolchainNode<T1, T2>* curNode = this->head;
	while (curNode != NULL)
	{
		if ((curNode->key) = key)
		{
			return curNode->value;
		}
	}
}

template<class T1,class T2>
void symbolTable<T1, T2>::put(T1 key, T2 value)
{
	symbolchainNode<T1, T2>* newNode = new symbolchainNode<T1, T2>(key, value, NULL);
		if (m_N == 0)
		{
			this->head = newNode;
		}
		else
		{
			newNode->next = this->head;
			this->head = newNode;
		}
		m_N++;
}

template<class T1, class T2>
void symbolTable<T1, T2>::mydelete(T1 key)
{
	symbolchainNode<T1, T2>* curNode = this->head;
	symbolchainNode<T1, T2>* preNode = NULL;
	if (curNode == NULL)
	{
		cout << "此符号表玛德元素" << endl;
		return;
	}

	while (curNode!=NULL)
	{
		if ((curNode->key == key) && (preNode!=NULL))
		{
			preNode->next = (curNode->next);
			m_N--;
			cout << "删除成功" << endl;
			return;
		}
		else if((curNode->key == key) && (preNode == NULL))
		{
			this->head = (this->head->next);
			m_N--;
			cout << "删除成功" << endl;
			return;
		}
		else
		{
			preNode = curNode;
			curNode = curNode->next;
			//preNode = preNode->next;
		}
	}
	cout << "木找到你要删除的元素" << endl;

}

template<class T1,class T2>
int symbolTable<T1, T2>::size()
{
	return m_N;
}

template<class T1, class T2>
void symbolTable<T1, T2>::showMessage() const
{
	symbolchainNode<T1, T2>* curNode = (this->head);
	int i = 0;
	while (curNode != NULL)
	{
		cout << "第 " << i << " 个元素" << endl;
		cout << "\tkey：" << (curNode->key) << "\tvalue:" << (curNode->value )<< endl;
		i++;
		curNode = curNode->next;
	}
		
}


template<class T1, class T2>
void symbolTable<T1, T2>::rankput(T1 key, T2 value)
{
	if (this->m_N == 0)
	{
		this->put(key, value);
		return;
	}
	else if (this->m_N == 1)
	{
		if ((key) <= (head->key))
			{
				this->put(key, value);
			}
		else
		{
			symbolchainNode<T1, T2>* newNode = new symbolchainNode<T1, T2>(key, value, NULL);
			head->next = newNode;
			m_N++;
		}
	return;
	}
	if ((key) <= (head->key))
	{
		this->put(key, value);
		return;
	}


	symbolchainNode<T1, T2>* newNode = new symbolchainNode<T1, T2>(key, value, NULL);
	symbolchainNode<T1, T2>* curNode = (this->head->next);
	symbolchainNode<T1, T2>* preNode = this->head;
	
	while (curNode != NULL)
	{
		if (((newNode->key) <= (curNode->key)) && ((newNode->key) >= (preNode->key)))
		{
			preNode->next = newNode;
			newNode->next = curNode;
			m_N++;
			return;
		}
		else
		{
			preNode = curNode;
			curNode = curNode->next;
		}

	}
	preNode->next = newNode;
	m_N++;
	return;



}