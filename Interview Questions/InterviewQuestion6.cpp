/*
//============================================================================
// Name        : InterviewQuestion6.cpp
// Description : GIven a list of words, and the number of rows and columns,
return the number of words that can be fit into the rows and columns by
stringing together each consecutive word. If the next word doesn't fit in the same line,
it should move to the next line. Find an efficient solution for this. For eg.

List of words: { "Do", "Run" }
Number of columns: 9
Number of rows: 2

First row: "Do Run Do" (7 letters + 2 spaces fit into 9 columns)
Second row: "Run Do" (Only 2 words fit into 9 columns)

//============================================================================
*/
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;

unordered_map<int, string> splitdoc(vector<string> words, unsigned int row, unsigned int col)
{
	unordered_map<int, string> doc;
	unsigned int i=0, count=0, j;
	string colstr;
	while(i<row)
	{
		if(j>=words.size())
		{
			j =0;
		}
		if(count>=col)
		{
			i++;
			count =0;
			if(i>=row)
				return doc;
		}
		string str = words[j];
		if(count + str.size() <= col)
		{
			if(count ==0)
			{
				string str = words[j];
				j++;
				doc[i] = str;
				count += str.size();
			}
			else if (count + str.size() + 1 <= col)
			{
				j++;
				colstr = doc[i];
				colstr = colstr + " " + str;
				doc[i] = colstr;
				count += str.size() + 1;
			}
			else
			{
				i++;
				count =0;
			}
		}
	}
	return doc;
}

int main() {
	vector<string> words = {"Do", "Run"};
	unsigned int row=2, col=9;
	unordered_map<int, string> doc = splitdoc(words, 2, 9);
	for(unsigned int i=0;i<row;i++)
	{
		cout<<doc[i]<<"\n";
	}
	return 0;
}
