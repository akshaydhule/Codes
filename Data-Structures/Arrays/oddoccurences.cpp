
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	unordered_map<int,int> map;
	unordered_map<int,int>::iterator it;
	int a[] = {1,2,2,2,2,2,3,3,3,3,4,3,2,3,4,4,6,6};
	int n = sizeof(a)/sizeof(a[0]);
	for(int i=0;i<n;i++)
	{
		if(map.find(a[i])==map.end())
		{
			map.insert(make_pair(a[i],1));
		}
		else
		{

			it = map.find(a[i]);
			it->second = it->second+1;
		}
	}
	for(it=map.begin();it!=map.end();it++)
	{
		int a = it->second;
		cout<<it->first<<" "<<a<<"\n";

		if((a%2)==1)
		{
			cout<<" "<<it->first<<"\n";
		}
	}
	return 0;
}
