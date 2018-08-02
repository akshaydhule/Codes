/*
//============================================================================
// Name        : Merge_sortedArrays_id&weights.cpp
// Description :Given two object arrays of "id,weight" (sorted by weight),
 * merge them together and create a one single array.
 * If the "id"s are same values should be merged.
 * Final resulting array should be sorted by weight.
 * Result should be O(nlogn) in time complexity.
//============================================================================
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class node
{
public:
	int id;
	int weight;
	node():id(0),weight(0){}
	node(int i, int w):id(i),weight(w){}
};

bool comparator (node a, node b)
{
	return a.weight<b.weight;
}

bool idcomparator (node a, node b)
{
	return a.id<b.id;
}


vector<node> sortedarray(vector<node> a1, vector<node> a2)
{
	vector<node> output(a1.begin(), a1.end()), final;
	output.insert(output.end(), a2.begin(), a2.end());
	std::sort(output.begin(), output.end(), idcomparator);
	int i = 0, temp = 1;
	final.push_back(output[0]);
	while(temp<output.size())
	{
		if(final[i].id == output[temp].id)
		{
			final[i].weight += output[temp].weight;
		}
		else
		{
			i++;
			final.push_back(output[temp]);
		}
		temp++;
	}
	std::sort(final.begin(), final.end(), comparator);
	return final;
}

int main() {
	vector<node> a1, a2;
	a1.push_back(node(1,2));
	a1.push_back(node(2,3));
	a1.push_back(node(4,4));
	a1.push_back(node(3,5));
	a2.push_back(node(2,1));
	a2.push_back(node(4,3));
	a2.push_back(node(3,5));
	vector<node> output = sortedarray(a1, a2);
	for(int i=0;i<output.size();i++)
	{
		cout<<output[i].id<<" "<<output[i].weight<<"\n";
	}
	return 0;
}
