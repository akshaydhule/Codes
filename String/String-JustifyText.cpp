//============================================================================
// Name        : String-JustifyText.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void JustifyText(vector<string> input, int window)
{
	vector<string> output;
	int size = input.size();
	int length = 0, start = 0, count = 0;
	string line = "";
	for(int i=0; i<size; i++)
	{
		if(length == 0 && input[i].length()<=window)
		{
			length = input[i].length();
			count = 1;
		}
		else if(length + input[i].length() + count-1 <= window)
		{
			length += input[i].length();
			count += 1;
		}
		else
		{
			int spacecount = window - length;
			string spaces = "";
			spacecount = count == 1? spacecount : spacecount/(count-1);
			int currIndex = 0;
			int k = 0;
			while(k<spacecount)
			{
				spaces += " "; k++;
			}
			line = input[i-count];
			currIndex = input[i-count].size()+1;
			//build the line
			for(int j=count-1; j>0; j--)
			{
				line += spaces + input[i-j];
				//currIndex += spacecount + input[i-j].size()+1;
			}
			//single word spaces
			while(currIndex<window)
			{
				line += " ";
				currIndex += 1;
			}
			output.push_back(line);
			line = "";
			count = 1;
			length = input[i].length();
		}
	}
	//last line
	if(count>0)
	{
		while(length != window)
		{
			line += " ";
			length+=1;
		}
		output.push_back(line);
	}

	for(int i=0; i<output.size(); i++)
	{
		cout<<output[i]<<"|"<<endl;
	}
}

int main() {
	vector<string> input = {"The","quick","brown", "fox", "jumped", "over", "the", "lazy", "dogs"};
	JustifyText(input, 12);
	return 0;
}
