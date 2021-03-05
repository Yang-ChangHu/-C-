#include<iostream>
#include<string>
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
using namespace std;


//全局函数重载左移运算法 方便打印
void operator<<(ostream &cout,Person p)
{
	cout << "姓名：" << p.m_name << "   年龄： " << p.m_age << endl;
}

//全局函数重载等号运算法方便比较
bool operator==(Person p1, Person p2)
{
	return ((p1.m_age == p2.m_age) && (p1.m_name == p2.m_name));
}

bool operator!=(Person p1, Person p2)
{
	return ((p1.m_age != p2.m_age)|| (p1.m_name != p2.m_name));
}


Person p1(1, "大娃");
Person p2(2, "二娃");
Person p3(3, "三娃");
Person p4(4, "四娃");
Person p5(5, "五娃");
Person p6(6, "六娃");
Person p7(7, "七娃");
void test01()
{

	arrayList<Person> p(12);
	//p.ShowMessage();
	Person p1(18, "张三");
	Person p2(19, "李四");
	Person p3(20, "王五");
	Person p4(21, "赵六");
	Person p5(22, "周七");

	p.insert(0, p1);
	p.insert(1, p2);
	p.insert(2, p3);
	p.insert(3, p4);
	p.insert(4, p5);

	p.ShowMessage();
	
	//p.ShowMessage();
	cout<<p.indexOf(p2);

}
void test02()		//反转单链表
{




	chain<Person> c(3);
	c.insert(0, p1);
	c.insert(1, p2);
	c.insert(2, p3);
	c.insert(3, p4);
	c.insert(4, p5);
	//c.ShowMessage();

	//cout<<"位置是："<<c.indexOf(p5)<<endl;
	c.ShowMessage();
	cout << "*****************************" << endl;
	c.reverse();
	cout << "反转后地址c.firstNode" <<c.firstNode<< endl;
	//cout << "\t反转后地址p" << p << "\tp->next" << p->next << "\tp->next->next" << p->next->next << endl;
	c.ShowMessage();
	
}





void test03()   //测试双向链表
{
	TowWayLinkList<Person> p;
	cout << "\thead指针是:" << p.head << "\tlast 指针是:" << p.last << "\t当前元素个数为:" << p.N << endl;
	p.insert(p1);
	p.insert(p2);
	p.insert(p3);
	p.insert(p4);
	//p.showMessage();
	p.insert(4, p5);
	p.showMessage();
	//cout << p.getFirst();
	cout << "\t删除的元素是" << endl;
	p.remove(4);
	p.showMessage();
}


void test04()		//快慢指针
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


void test05()		//约瑟夫问题
{
	//创建约瑟夫循环表
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


void test06()		//测试栈
{
	//stack<Person> s;
	//s.push(p1);
	//s.push(p2);
	//s.push(p3);
	//s.push(p4);
	//s.showMessage();
	//s.pop();
	//s.showMessage();

	//括号匹配问题
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
				cout << "有误！" << endl;
				return;
			}
		}
	}
	if (s.isEmpty())
	{
		cout << "无误！" << endl;
	}
	else
	{
		cout << "有误" << endl;
	}
	return;

	
}

void test07()		//逆波兰表达式
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

void test08()		//队列测试
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

void test09()//符号表测试
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


void test10()	//测试二叉树
{
	binaryTree<int, int> bt;
	bt.put(1, 1);
	bt.put(3, 3);
	bt.put(4, 4);
	bt.put(2, 2);
}
int main()
{
	test10();
	system("pause");
	return 0;
}