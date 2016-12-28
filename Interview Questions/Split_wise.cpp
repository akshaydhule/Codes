/*
//============================================================================
// Name        : Split_wise.cpp
// Description :
A group of friends went on holiday and sometimes lent each other money.
For example, Alice paid for Bill's lunch for $10.
Then later Chris gave Alice $5 for a taxi ride.
We can model each transaction as a tuple (x, y, z)
which means person x gave person y $z.
Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively
(0, 1, 2 are the person's ID), the transactions can be represented as
[[0, 1, 10], [2, 0, 5]].

Given a list of transactions between a group of people,
return the minimum number of transactions required to settle the debt.

Example 1:

Input:
[[0,1,10], [2,0,5]]

Output:
2

Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.

Two transactions are needed.
One way to settle the debt is person #1 pays person #0 and #2 $5 each.
//============================================================================
*/
#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

class tuple
{
public:
	int x, y, z;
	tuple(int a, int b, int c)
	{
		this->x = a;
		this->y = b;
		this->z= c;
	}
};

class person
{
public:
	int x;
	int bal;
	person(int x, int bal)
	{
		this->x = x;
		this->bal = bal;
	}
};
bool comp(int a, int b)
{
	return a>b?true:false;
}

int transaction(list<int> loaner, list<int> loanie)
{
	if(loanie.size() == 0)
		return 0;
	if(loanie.size()==1 || loaner.size() == 1)
		return (loanie.size()>loaner.size()?loanie.size():loaner.size());
	int trans = INT_MAX;
	list<int>::iterator it;
	for(it = loaner.begin();it!=loaner.end();it++)
	{
		int a = *it, b = loanie.front();
		loanie.pop_front();
		loaner.erase(it);
		if(a>b)
			loaner.push_back(a-b);
		else if(b>a)
			loanie.push_back(b-a);
		trans = min(transaction(loaner, loanie)+1, trans);

	}
	return trans;
}

int buildbal(vector<tuple> transactions)
{
	map<int, int> personBalMap;
	//populate the map
	for(int i=0;i<transactions.size();i++)
	{
		tuple temp =transactions[i];
		//lender
		if(personBalMap.find(temp.x)!=personBalMap.end())
			personBalMap[temp.x] += temp.z;
		else
			personBalMap.insert(make_pair(temp.x, temp.z));
		// borrower
		if(personBalMap.find(temp.y)!=personBalMap.end())
			personBalMap[temp.y] -= temp.z;
		else
			personBalMap.insert(make_pair(temp.y, -temp.z));
	}
	map<int, int>::iterator values;
	list<int> loaner, loanie;
	for(values = personBalMap.begin();values!= personBalMap.end();values++)
	{
		if (values->second>0)
			loaner.push_back(values->second);
		if (values->second<0)
			loanie.push_back(abs(values->second));
	}

	loanie.sort();
	loaner.sort();

	//vector<vector<int>> balmap;
	return transaction(loaner, loanie);
}
int main() {
	vector<tuple> transactions;
	transactions.push_back(tuple(0,1,5));
	transactions.push_back(tuple(0,2,10));
	transactions.push_back(tuple(1,2,5));
	transactions.push_back(tuple(2,3,5));
	cout<<buildbal(transactions);
	return 0;
}
