/*
//============================================================================
// Name        : Dijkstra.cpp
// Description : Hello World in C++, Ansi-style
//============================================================================
*/
#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

class graph
{
public:
	int v;
	list<int> * adj;
	map<pair<int, int>, int> edges;

	graph(int v)
	{
		this->v = v;
		adj = new list<int>[v+1];
		//this->edges.reserve(v*(v-1));
	}
	void addedge(int i, int j, int val)
	{
		adj[i].push_back(j);
		adj[j].push_back(i);
		edges.insert( make_pair(make_pair(i,j), val) );
		edges.insert( make_pair(make_pair(j, i), val) );
	}
	void childcheck(int i, int *visited,int *dist)
	{
		visited[i] = 1;
		for(auto it = adj[i].begin();it != adj[i].end(); it++)
		{
			if(dist[*it] < dist[i] + edges.at(make_pair(i,*it)))
				continue;
			else
			{
				dist[*it] = dist[i] + edges.at(make_pair(i,*it));
				if(visited[*it] == 0)
				{
					childcheck(*it, visited, dist);
				}
			}
		}
		visited[i] = 2;
	}
	/* 
	visited[] = {0 : not visited, 1 : added[in process], 2 : visited}
	*/
	int shortestdist(int a, int b)
	{
		int visited[v+1];
		for(int i=0;i<=v;i++)
			visited[i] = 0;
		int dist[v+1];
		memset(dist, INT_MAX, v+1);
		dist[a] = 0;
		visited[a] = 2;
		for(auto it = adj[a].begin();it!=adj[a].end();it++)
		{
			if (*it == b)
			{
				dist[b] = edges.at(make_pair(a,*it));
			}
			if(dist[*it]< dist[a] + edges.at(make_pair(a,*it)))
				continue;
			else
			{
				dist[*it] = dist[a] + edges.at(make_pair(a,*it));
				childcheck(*it, visited, dist);
			}
		}
		return dist[b];
	}
};

int main() {
	graph dij(6);
	dij.addedge(1,6,14);
	dij.addedge(1,2,7);
	dij.addedge(1,3,9);
	dij.addedge(2,4,15);
	dij.addedge(4,5,6);
	dij.addedge(6,5,9);
	dij.addedge(3,4,11);
	dij.addedge(2,3,10);
	dij.addedge(3,6,2);
	cout<<dij.shortestdist(1,6);
	return 0;
}
