//============================================================================
// Name        : routebetweennodes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

class graph
{
private:
	int v;
	list<int> *adj;
public:
	graph(int v);
	void addedge(int a, int b);
	bool reachable(int a, int b);
};

graph::graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

void graph::addedge(int a, int b)
{
	adj[a].push_back(b);
}

bool graph :: reachable(int a, int b)
{
	if(a==b)
		return true;
	else
	{
		list<int> queue;
		list<int>::iterator it;
		bool *vis = new bool[v];
		for(int i=0;i<v;i++)
		{
			vis[i] = false;
		}
		vis[a] = true;
		queue.push_back(a);
		while(!queue.empty())
		{
			int vertex;
			vertex = queue.front();
			queue.pop_front();
			for(it = adj[vertex].begin();it!=adj[vertex].end();it++)
			{
				if(*it==b)
					return true;
				else
				{
					if(vis[*it]!=true)
					{
						queue.push_back(*it);
						vis[*it] = true;
					}
				}
			}
		}
	}
	return false;
}


int main() {
	graph v(4);
	v.addedge(0,2);
	v.addedge(0,3);
	v.addedge(1,2);
	v.addedge(1,4);
	v.addedge(2,3);
	cout<<v.reachable(1,0);
	return 0;
}
