
#include <cstdlib>
#include <iostream>
#include <unordered_map>

using namespace std;

/*int notostring(unordered_map<int, string> set,unordered_map<int, string> unit,  int a, int count)
{
    unordered_map<int, string>:: iterator it;
    if(count==0)
    {
        return 0;
    }
    else
    {
        notostring(set,unit, a/10,count-1);
        if(set.find(a)!=set.end())
        {
            it = set.find(a);
            cout<<it->second<<" ";
        }
        if(unit.find(count)!=set.end())
        {
            it = set.find(count);
            cout<<it->second<<" ";
        }
    }
}
*/
void notostring(unordered_map <int, string> set, unordered_map <int, string> unit,int a)
{
	unordered_map<int, string>:: iterator it;
	int mil = 1000000;
	int b = a/mil;
	if(b!=0){
		if(set.find(b)!=set.end())
		{
		     it = set.find(b);
		     cout<<it->second<<" ";
		}
		cout<< "million ";
	}
	a = a%mil;
	b=0;
	int lac = 100000;
	b = a/lac;
	if(b!=0)
	{
		if(set.find(b)!=set.end())
				{
				     it = set.find(b);
				     cout<<it->second<<" ";
				}
		cout<< "lac ";
	}
	a = a%lac;b=0;
	int th = 1000;
	b= a/th;
	if(b!=0)
	{	int c = (b/10)*10;
	if(unit.find(c)!=unit.end())
	{
		it = unit.find(c);
		cout<<it->second<<" ";
	}
	b = b%10;
	if(b!=0)
	{
		if(set.find(b)!=unit.end())
	{
		it = set.find(b);
		cout<<it->second<<" ";
	}
	}
		cout<< "thousand ";
	}
	a =a%th;b=0;
	b = a/100;
	if(b!=0)
	{
		if(set.find(b)!=set.end())
		{
			it = set.find(b);
			cout<<it->second<<" ";
		}
		cout<< "hundred";
	}
	a = a%100;
	b = (a/10)*10;
	if(unit.find(b)!=unit.end())
	{
		it = unit.find(b);
		cout<<it->second<<" ";
	}
	a = a%10;
	if(a!=0)
	{
		if(set.find(a)!=unit.end())
	{
		it = set.find(a);
		cout<<it->second<<" ";
	}
	}


}

int main() {
    std:: unordered_map <int, string> set = {
        {1,"One"},
        {2,"two"},
        {3,"three"},
        {4,"four"},
        {5, "Five"},
        {6, "Six"},
        {7, "Seven"},
        {8, "Eight"},
        {9, "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"}};
		std::unordered_map <int, string> unit = {
		{20, "Twenty"},
        {30, "Thirty"},
        {40, "Fourty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
        };
    /*std::unordered_map <int, string> unit = {
        {3,"hundred"},
        {4,"thousand"},
        {6,"lac"},
        {7,"million"},
        {8,"crore"},
        {10,"billion"}
    }*/
    int a=12345678,b,count=0;
    notostring(set,unit,a);
    return 0;
}

