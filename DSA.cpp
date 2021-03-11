#include<iostream>
#include<string>
//#include<stack>
#include<algorithm>
#include"arrayList.hpp"
#include"LinearList.h"
#include"myclass.h"
#include"chain.hpp"
#include"Node.h"
#include"TowWayLinkList.hpp"
#include"stack.hpp"
#include<sstream>
#include"queue.hpp"
#include"symbolTable.hpp"
#include"binaryTree.hpp"
#include"pageFolding.hpp"
#include"heap.hpp"
#include"MaxPriorityQueue.hpp"
#include"minPriorityQueue.hpp"
#include"colorNode.hpp"
#include"RedBlackTree.hpp"
#include"UF.h"
#include"UFtree.h"
#include"UFtreeWeight.h"
#include<queue>
#include"DepthFirstSearch.h"
#include"Graph.h"
#include"BreadthFirstSearch.h"
#include"DepthFirstPaths.h"
#include"Digraph.h"
#include"DirectedCycle.h"


using namespace std;


//ȫ�ֺ��������������㷨 �����ӡ
void operator<<(ostream &cout,Person p)
{
	cout << "������" << p.m_name << "   ���䣺 " << p.m_age << endl;
}

//ȫ�ֺ������صȺ����㷨����Ƚ�
bool operator==(Person p1, Person p2)
{
	return ((p1.m_age == p2.m_age) && (p1.m_name == p2.m_name));
}

bool operator!=(Person p1, Person p2)
{
	return ((p1.m_age != p2.m_age)|| (p1.m_name != p2.m_name));
}


Person p1(1, "����");
Person p2(2, "����");
Person p3(3, "����");
Person p4(4, "����");
Person p5(5, "����");
Person p6(6, "����");
Person p7(7, "����");
void test01()
{

	arrayList<Person> p(12);
	p.ShowMessage();
	Person p1(18, "����");
	Person p2(19, "����");
	Person p3(20, "����");
	Person p4(21, "����");
	Person p5(22, "����");

	p.insert(0, p1);
	p.insert(1, p2);
	p.insert(2, p3);
	p.insert(3, p4);
	p.insert(4, p5);

	p.ShowMessage();
	
	//p.ShowMessage();
	cout<<p.indexOf(p2);

}

void test02()		//��ת������
{




	chain<Person> c(3);
	c.insert(0, p1);
	c.insert(1, p2);
	c.insert(2, p3);
	c.insert(3, p4);
	c.insert(4, p5);
	//c.ShowMessage();

	//cout<<"λ���ǣ�"<<c.indexOf(p5)<<endl;
	c.ShowMessage();
	cout << "*****************************" << endl;
	c.reverse();
	cout << "��ת���ַc.firstNode" <<c.firstNode<< endl;
	//cout << "\t��ת���ַp" << p << "\tp->next" << p->next << "\tp->next->next" << p->next->next << endl;
	c.ShowMessage();
	
}

void test03()   //����˫������
{
	TowWayLinkList<Person> p;
	cout << "\theadָ����:" << p.head << "\tlast ָ����:" << p.last << "\t��ǰԪ�ظ���Ϊ:" << p.N << endl;
	p.insert(p1);
	p.insert(p2);
	p.insert(p3);
	p.insert(p4);
	//p.showMessage();
	p.insert(4, p5);
	p.showMessage();
	//cout << p.getFirst();
	cout << "\tɾ����Ԫ����" << endl;
	p.remove(4);
	p.showMessage();
}

void test04()		//����ָ��
{
	chainNode<Person>* c1=new chainNode<Person>(p1, NULL);
	chainNode<Person>* c2 = new chainNode<Person>(p2, NULL);
	chainNode<Person>* c3 = new chainNode<Person>(p3, NULL);
	chainNode<Person>* c4 = new chainNode<Person>(p4, NULL);
	chainNode<Person>* c5 = new chainNode<Person>(p5, NULL);
	chainNode<Person>* c6 = new chainNode<Person>(p6, NULL);
	chainNode<Person>* c7 = new chainNode<Person>(p7, NULL);

	c1->next = c2;
	c2->next = c3;
	c3->next = c4;
	c4->next = c5;
	c5->next = c6;
	c6->next = c7;
	c7->next =c6;

	chain<Person> c(3);
	c.firstNode = c1;
	
	//cout << c.getMid();
	cout << c.getEntrance();
	return;

}

void test05()		//Լɪ������
{
	//����Լɪ��ѭ����
	chainNode<int>* first = NULL;
	chainNode<int>* pre = NULL;
	for (int i = 0; i < 41; i++)
	{
		if (i == 0)
		{
			first = new chainNode<int>(i+1, NULL);
			pre = first;
		}
		else if (i == 40)
		{
			chainNode<int>* lastNode = new chainNode<int>(i+1, first);
			pre->next = lastNode;
		}
		else
		{
			chainNode<int>* newNode = new chainNode<int>(i+1, NULL);
			pre->next = newNode;
			pre = newNode;

		}
	}
	chain<int> c(30);
	c.firstNode = first;
	//c.ShowMessage();
	int count = 0;
	chainNode<int>* n = c.firstNode;
	chainNode<int>* before =NULL;
	while (n != n->next)
	{
		count++;
		
		if (count == 3)
		{
			cout << n->element << endl;
			before->next = n->next;
			//before = NULL;
			n=n->next;
			count =0;

		}
		else 
		{
			before = n;
			n = n->next;
		}

	}
	cout << n->element << endl;
}

void test06()		//����ջ
{
	//stack<Person> s;
	//s.push(p1);
	//s.push(p2);
	//s.push(p3);
	//s.push(p4);
	//s.showMessage();
	//s.pop();
	//s.showMessage();

	//����ƥ������
	char chartest[] = "((beijin)g)(shanghai))";
	stack<char> s;
	for (int i = 0; i < (sizeof(chartest) / sizeof(chartest[0])); i++)
	{
		if (chartest[i] == '(')
		{
			s.push(chartest[i]);
		}
		else if (chartest[i] == ')')
		{
			chainNode<char>* tmp = s.pop();
			if (tmp == NULL)
			{
				cout << "����" << endl;
				return;
			}
		}
	}
	if (s.isEmpty())
	{
		cout << "����" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
	return;

	
}

void test07()		//�沨�����ʽ
{
	stack<string> s;
	string notation[] = { "3","17","15","-","*","18","6","/","+" };

	//stack<int> s;
	for (int i = 0; i < (sizeof(notation) / sizeof(notation[0])); i++)
	{
		string curr = notation[i];
		if (curr == "+")
		{
			stringstream stream;
			int a;
			int b;
			stream <<(s.pop()->element);
			stream >> a;

			stream << (s.pop()->element);
			stream >> b;

			
			s.push(to_string(a+b));

		}
		else if (curr == "-")
		{
			stringstream stream;
			int a;
			int b;
			stream << (s.pop()->element);
			stream >> a;

			stream << (s.pop()->element);
			stream >> b;


			s.push(to_string(a - b));

		}
		else if (curr == "*")
		{
			stringstream stream;
			int a;
			int b;
			stream << (s.pop()->element);
			stream >> a;

			stream << (s.pop()->element);
			stream >> b;


			s.push(to_string(a * b));
		}
		else if (curr == "/")
		{
			stringstream stream;
			int a;
			int b;
			stream << (s.pop()->element);
			stream >> a;

			stream << (s.pop()->element);
			stream >> b;


			s.push(to_string(a/ b));
		}
		else
		{
			s.push(curr);
		}

	}
	 cout<<((s.getHead())->element);

}

void test08()		//���в���
{
	Queue<Person> q;
	q.enqueue(p1);
	q.enqueue(p2);
	q.enqueue(p3);
	q.enqueue(p4);
	q.showMessage();
	q.dequeue();
	q.showMessage();
}

void test09()//���ű����
{
	symbolTable<int, int> st;
	//st.rankput(0, 0);
	//st.rankput(1, 1);
	
	st.rankput(3, 3);
	st.showMessage();

	st.rankput(2, 2);
	//st.mydelete(3);
	st.showMessage();
}

void test10()	//���Զ�����
{
	binaryTree<int, int> bt;
	bt.put(6, 11);
	bt.put(4, 33);
	bt.put(8, 44);
	bt.put(5, 22);
	bt.put(3, 22);
	bt.put(7, 22);

	//cout << bt.get(2) << endl;
	Queue<int> keypre = bt.preErgodic();
	keypre.showMessage();


	Queue<int> keymid = bt.midErgodic();
	keymid.showMessage();

	Queue<int> keyafter = bt.afterErgodic();
	keyafter.showMessage();

	Queue<int> keylayer=bt.layerErgodic();
	keylayer.showMessage();


	cout << bt.maxDepth() << endl;
	//bt.mydelete(1);
	//bt.mydelete(4);
	//bt.mydelete(3);
	//bt.mydelete(2);
	//bt.min();
	//bt.max();

}

void test11()	//������ֽ
{
	pageFolding pf(1);
	pf.ShowTree(pf.root);
}

void test12()		//���Զ�
{
	Heap<char> h(10);
	h.insert('A');
	h.insert('B');
	h.insert('C');
	h.insert('D');
	h.insert('E');
	h.insert('F');
	h.insert('G');

	while (h.getSize()>0)
	{
		cout << "\tɾ����Ԫ���ǣ�" << h.deleMax() << endl;
	}
	//h.ShowMessage();
	cout << h.deleMax() << endl;
}

void test13()//���Զ�����
{
	char A[] = { 'A','B','C','D','E','F','G' };
	Heap<char> h(A, sizeof(A) / sizeof(A[0]), sizeof(A) / sizeof(A[0])+1);
	h.ShowMessage();


}

void test14()		//����������ȶ���
{
	MaxPriorityQueue<char> mq(10);
	mq.insert('A');
	mq.insert('B');
	mq.insert('C');
	mq.insert('D');
	mq.insert('E');
	mq.insert('F');
	mq.insert('G');

	while (!mq.isEmpty())
	{
		cout << mq.delMax()<< endl;
	}

}

void test15()		//������С���ȶ���
{
	minPriorityQueue<int> mq(15);
	mq.insert(2);
	mq.insert(5);
	mq.insert(7);
	mq.insert(3);
	mq.insert(4);
	mq.insert(6);
	mq.insert(1);
	mq.insert(9);
	while (!mq.isEmpty())
	{
		cout << mq.delMin() << endl;
	}
}

void test16()		//���Ժ����
{
	RedBlackTree<int, string> rbt;
	rbt.put(1, "����");
	rbt.put(2, "����");
	rbt.put(3, "����");
	//rbt.put(4, "����");

	cout << rbt.get(4) << endl;


}

void test17()
{
	UF uf(5);
	int a = 2;
	int b = 3;
	uf.myunion(2, 3);
	cout << uf.count() << endl;
}

void test18()	//	����uftree
{
	UFtree uft(8);
	int a = 2;
	int b = 3;
	uft.myunion(2, 3);
	cout << uft.count() << endl;
}

void test19()	//	����uftree
{
	UFtreeWeight uft(20);
	//int a = 2;
	//int b = 3;
	uft.myunion(0, 1);
	uft.myunion(6, 9);
	uft.myunion(3, 8);
	uft.myunion(5, 11);
	uft.myunion(2, 12);
	uft.myunion(6, 10);
	uft.myunion(4, 8);
	cout << uft.count() << endl;
	uft.showMessage(20);
}


void test20()	//����ͼ
{
	Graph g(20);
	g.addEdge(0, 1);
	g.addEdge(6, 9);
	g.addEdge(3, 8);
	g.addEdge(5, 11);
	g.addEdge(2, 12);
	g.addEdge(6,10);
	g.addEdge(4, 8);
	//g.addEdge(6, 4);

	//g.addEdge(7, 8);

	//g.addEdge(9, 10);
	//g.addEdge(9, 12);
	//g.addEdge(11,12);
	//g.addEdge(9, 11);

	//g.ShowMessage();

	//DepthFirstSearch Dfs(g, 0);  //�������
	BreadthFirstSearch Dfs(g, 9);		//�������
	cout << Dfs.Count() << endl;
	cout << Dfs.Marked(10) << endl;
	cout << Dfs.Marked(8) << endl;

}

void test21()		//���������������·��
{
	Graph g(6);
	g.addEdge(0, 1);
	g.addEdge(3, 4);
	g.addEdge(2,1);
	g.addEdge(0, 2);
	g.addEdge(2,3);
	g.addEdge(2,4);
	g.addEdge(3,5);
	
	g.addEdge(0, 5);

	//g.ShowMessage();
	DepthFirstPaths dfp(g, 1);
	stack<int> sk = dfp.pathRo(3);
	sk.showMessage();
}



void test22()	//��������ͼ
{
	Digraph g(6);
	g.addEdge(0, 1);
	g.addEdge(3, 4);
	g.addEdge(2, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 5);

	g.addEdge(0, 5);



}


void test23()	//��������ͼ�Ƿ��л�
{
	Digraph g(6);
	g.addEdge(0, 1);
	g.addEdge(3, 4);
	g.addEdge(2, 1);
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 4);
	g.addEdge(3, 5);

	g.addEdge(0, 5);
	DirectedCycle dc(g);
	cout << dc.hasCycle() << endl;

}



int main()
{
	test23();
	system("pause");
	return 0;
}