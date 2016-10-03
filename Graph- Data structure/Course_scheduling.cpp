/*
//============================================================================
// Name        : Course_scheduling.cpp
// Description : There are a total of n courses you have to take,
 * labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0
you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs,
return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them.
 it is impossible to finish all courses, return an empty array.

//============================================================================
*/
#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

class graph
{
public:
	list<int> *adj;
	int n;
	bool cycle;
	graph(int n)
	{
		this->n = n;
		adj = new list<int>[n];
		cycle = false;
	}
	void addnode(int a, int b);
	void buildgraph(vector<pair<int,int> >& set);
	void levelsort(int i, int *visited, stack<int> &stack);
};
void graph::addnode(int a, int b)
{
	adj[a].push_back(b);
}
void graph::buildgraph(vector<pair<int,int> >& set)
{
	for (auto it= set.begin();it!=set.end();it++)
		addnode(it->second,(it->first));
}

void graph::levelsort(int i, int *visited, stack<int> &stack)
{
	list<int>::iterator it;
	visited[i] = 1;
	for(it = adj[i].begin();it!= adj[i].end();it++)
	{
		if(visited[*it] == 0)
			levelsort(*it, visited, stack);
		if(visited[*it] == 1)
		{
			cycle = true;
			break;
		}
	}
	visited[i] = 2;
	stack.push(i);
}

class solution
{
public:
	vector<pair<int, int> > pairset;
	vector<int> findOrder(int numCourses)
	{
		 vector<int> order;
		 stack<int> stack;
		 graph course(numCourses);
		 course.buildgraph(pairset);
		 int visited[numCourses];
		 for(int i=0;i<numCourses;i++)
			 visited[i] = 0;
		 for(int i=0;i<numCourses;i++)
		 {
			 if(visited[i] == 0)
			 {
				 course.levelsort(i, visited, stack);
			 }
		 }
		 if(course.cycle == true)
			 return order;
		 while(!stack.empty())
		 {
			 cout<<stack.top();
			 order.push_back(stack.top());
			 stack.pop();
		 }
		 return order;
	}
	void addtuple(int a, int b)
	{
		pair<int, int> tuple;
		tuple.first = a;
		tuple.second = b;
		pairset.push_back(tuple);
	}
};
int main() {
	solution a;
	a.addtuple(1,0);
	a.addtuple(2,1);
	a.findOrder(3);
	return 0;
}
