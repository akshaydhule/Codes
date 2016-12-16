//============================================================================
// Name        : topologicasort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <stack>
using namespace std;

class graph
{
private:
	int v;
	list<int> *adj;

public:
	graph(int v);
	void addedge(int a, int b);
	void topologicalsort();
	void levelsort(int a, bool *visited, stack<int> &nodes);
};

graph::graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

void graph::addedge(int a, int b)
{
	if(a == b)
		return ;
	else
		adj[a].push_back(b);
}

void graph::levelsort(int i, bool *visited, stack<int> &nodes)
{
	list<int>::iterator it;
	visited[i] = true;
	for(it=adj[i].begin();it!=adj[i].end();++it)
	{
		if(visited[*it]==false)
			levelsort(*it,visited,nodes);
	}
	nodes.push(i);
}


void graph::topologicalsort()
{
	stack<int> nodes;
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i] =false;

	for(int i=0;i<v;i++)
	{
	if(visited[i]==false)
	{
		levelsort(i,visited,nodes);
	}
	}
	while(!nodes.empty())
	{
		cout<<nodes.top()<<" ";
		nodes.pop();
	}
}



int main() {
	graph a(6);
	a.addedge(4,3);
	a.addedge(5,0);
	a.addedge(4,0);
	a.addedge(5,1);
	a.addedge(3,2);
	a.addedge(1,2);
	a.topologicalsort();
	return 0;
}
