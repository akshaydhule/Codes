//============================================================================
// Name        : split_string.cpp
// Description : Split the string
//============================================================================

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<string> splitstream(string str, char delim)
{
	vector<string> tokens;
	std::stringstream ss;
	ss.str(str);
	std::string item;
	while (std::getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	return tokens;
}

vector<string> split(string str)
{
	vector<string> tokens;
	int start = 0;
	int i=0;
	for( i = 1;i<str.size();i++)
	{
		if(str[i] == ',')
		{
			cout<<str.substr(start, (i-start))<<"\n";
			tokens.push_back(str.substr(start, (i-start)));
			start = i+1;
		}
	}
	tokens.push_back(str.substr(start, (i-start)));
	return tokens;
}


int main() {
	string a = "aa,sa,da,fa";
	//1. using stringstream
	vector<string> token = splitstream(a,',');
	//1. using substring
	vector<string> tokens = split(a);
	for(int i = 0; i<tokens.size();i++)
		cout<<tokens[i]<<"\n";
	return 0;
}
