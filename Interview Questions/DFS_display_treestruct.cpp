/*
//============================================================================
// Name        : DFS_display_treestruct.cpp
// Description : Given a list of manager and employee information represented
 * in hashMap entries {AAA->BBB,CCC,EEE},{CCC->DDD}.
Print company structure tree with proper indentations. BBB, CCC and EEE directly
reports to AAA, so they have one white space before "-", DDD reports to CCC,
it has two whitespace before "-". The input is map<String,List<String>>

(HANDLES DISJOINT SETS)

-AAA
 -BBB
 -CCC
  -DDD
 -EEE

//============================================================================
*/

#include <iostream>
#include <map>
#include <stack>
#include <vector>
using namespace std;

void childcheck(map<string, vector<string> > &entries, stack<string> &words)
{
	string spaces(words.size()-1, ' ');
	cout<<spaces<<"-"<<words.top()<<endl;
	if(entries.find(words.top())== entries.end())
		return;
	for(int i=0;i<entries[words.top()].size();i++)
	{
		words.push(entries[words.top()][i]);
		childcheck(entries, words);
		words.pop();
	}
}

void dfscheck(map<string, vector<string> > &entries, string start)
{
	stack<string> words;
	words.push(start);
	while(!words.empty())
	{
		string spaces(words.size()-1, ' ');
		cout<<spaces<<"-"<<words.top()<<endl;
		for(int i=0;i<entries[words.top()].size();i++)
		{
			words.push(entries[words.top()][i]);
			childcheck(entries, words);
			words.pop();
		}
		words.pop();
	}
}

void display(map<string, vector<string> > &entries)
{
	map<string, int> count;
	map<string, vector<string> >::iterator it;
	for(it = entries.begin();it!= entries.end(); it++)
	{
		count.insert(make_pair(it->first, 0));
		for(int i=0;i<it->second.size();i++)
		{
			if(count.find(it->second[i])!= count.end())
				count[it->first]++;
			else
				count.insert(make_pair(it->second[i], 1));
		}
	}
	map<string, int> :: iterator itcount;
	for(itcount = count.begin();itcount!= count.end(); itcount++)
	{
		if (itcount->second == 0)
			dfscheck(entries, itcount->first);
	}
}

int main() {
	map<string, vector<string> > entries;
	vector<string> values;
	values.push_back("BBB");
	values.push_back("CCC");
	values.push_back("EEE");
	entries.insert(make_pair("AAA", values));
	values.clear();
	values.push_back("DDD");
	entries.insert(make_pair("CCC", values));
	values.clear();
	entries.insert(make_pair("FFF", values));
	display(entries);
	return 0;
}
