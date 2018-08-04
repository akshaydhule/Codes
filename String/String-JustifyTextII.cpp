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
#include <cmath>
using namespace std;


string buildLine(vector<string> input, int start, int end, int spaceCount)
{
	string line = "", spaces = "";
	int count = end-start, i=0;
	int spaceGap = count == 1 ? spaceCount : ceil(spaceCount/count);
	int remSpaces = spaceCount;
	while(i<spaceGap)
	{
		spaces += " "; i++;
	}
	for(int j=start; j < end; j++)
	{
		line.append(input[j]);
		line.append(spaces);
		remSpaces -= spaceGap;
	}
	i = 0;
	while(i<remSpaces && !line.empty())
	{
		line.append(" "); i++;
	}
	line.append(input[end]);
	return line;
}

void JustifyText(vector<string> input, int window)
{
	vector<string> output;
	int size = input.size();
	int lineLength = 0, start = 0, wordCount = 0;
	string line = "";
	for(int i=0; i<size; i++)
	{
		if(lineLength == 0 && input[i].length()<=window)
		{
			lineLength = input[i].length();
			wordCount = 1;
			start = i;
		}
		else if(lineLength + input[i].length() + wordCount - 1 <= window)
		{
			lineLength += input[i].length();
			wordCount += 1;
		}
		else
		{
			line = buildLine(input, start, i-1, window - lineLength);
			output.push_back(line);
			line = "";
			start = i;
			wordCount = 1;
			lineLength = input[i].length();
		}
	}
	//last line
	if(wordCount>0)
	{
		line = buildLine(input, start, size-1, wordCount-1);
		int i = line.size();
		while(i<window)
		{
			line.append(" "); i++;
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
	JustifyText(input, 16);
	return 0;
}
