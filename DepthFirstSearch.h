#pragma once
#include<iostream>
#include<string>
#include<queue>
#include"Graph.h"
using namespace std;

class DepthFirstSearch
{
public:

	//�������ͼ��������ʹ��������������ҳ�s������������ͨ�Ķ���
	DepthFirstSearch(Graph G, int s);

	//�ж�w�����Ƿ���s������ͨ
	bool Marked(int w) const;

	//��ȡ��s������ͨ�����ж������
	int Count() const;
private:

	//ʹ��������������ҳ�Gͼ��v�����������ͨ����
	void dfs(Graph G, int v);

	//���������㣬��ʾ��ǰ�����Ƿ��Ѿ�������
	bool* marked;	
	
	//��¼�ж��ٸ�������s��ͨ
	int counts;
};