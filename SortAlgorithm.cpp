#include<iostream>
#include<string>
#include"Bubble.hpp"
#include"selection.hpp"
#include"insection.hpp"
#include"shell.hpp"
#include"Merge.hpp"
#include"Quick.hpp"
using namespace std;

void test02(int * a,int len)		//≤‚ ‘—°‘Ò≈≈–Ú
{

	Bubble<int>* sl = new selection<int>;
	sl->sort(a, len);
	sl->showMessage(a, len);

}

void test03(int* a, int len)		//≤‚ ‘≤Â»Î≈≈–Ú
{
	Bubble<int>* sl = new insection<int>;
	sl->sort(a, len);
	sl->showMessage(a, len);
}


void test04(int* a, int len)		//≤‚ ‘œ£∂˚≈≈–Ú
{
	Bubble<int>* sl = new shell<int>;
	sl->sort(a, len);
	sl->showMessage(a, len);
}

void test05(int* a, int len)		//≤‚ ‘πÈ≤¢≈≈–Ú
{
	Bubble<int>* sl = new Merge<int>;
	sl->sort(a, len);
	sl->showMessage(a, len);
}

void test06(int* a, int len)		//≤‚ ‘πÈ≤¢≈≈–Ú
{
	Bubble<int>* sl = new Quick<int>;
	sl->sort(a, len);
	sl->showMessage(a, len);
}

int main()
{
	int a[6] = { 3,6,5,1,9,4 };
	int len = sizeof(a) / sizeof(a[0]);
	test06(a, len);
	//Bubble<int> bb;
	//bb.sort(a,len);
	//bb.showMessage(a,len);

	system("pause");
	return 0;
}