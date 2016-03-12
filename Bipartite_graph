//============================================================================
// Name        : bipartite.cpp
// Description : check if Graph is a bipartite graph
//============================================================================

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class graph
{
private:
	int v;
	list<int> *adj;

public:
	graph(int v);
	void addedge(int a, int b);
	bool bipartite();
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
	{	adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

bool graph::bipartite()
{
	queue<int> vertices;
	list<int> ::iterator it;
	bool visited[v];
	int partition[v];
	for(int i=0;i<v;i++)
	{	visited[i] =false;
		partition[i] = 0;
	}
	vertices.push(0);
	visited[0] = true;
	partition[0] = 1;
	int i=0;
	while(!vertices.empty())
	{
		i = vertices.front();
		vertices.pop();
		for(it=adj[i].begin();it!=adj[i].end();it++)
		{
			if(visited[*it]==false)
						{
							partition[*it] = 3-partition[i];
							visited[*it] = true;
							vertices.push(*it);
						}
			else
			{
				if(partition[*it]==partition[i])
				{
					return false;
				}
			}
		}
	}
	return true;

}



int main() {
	graph a(6);
	a.addedge(4,3);
	a.addedge(1,5);
	a.addedge(5,0);
	a.addedge(4,0);
	a.addedge(3,2);
	a.addedge(1,2);
	if(a.bipartite()==true)
		cout<<"it is";
	else
		cout<<"not";
	return 0;
}
