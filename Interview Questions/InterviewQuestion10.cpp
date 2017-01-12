/*
//============================================================================
// Name        : UberQ1.cpp
// Description : Given input which is vector of log entries of some online
 * system each entry is something like (user_name, login_time, logout_time),
 * come up with an algorithm with outputs number of users logged in the system
 * at each time slot in the input, output should contain only the time slot which
 * are in the input. For the example given below output should contain timeslots
[(1.2, 1), (3.1, 2), (4.5, 1), (6.7, 0), (8.9, 1), (10.3,0)]

[
("Jane", 1.2, 4.5),
("Jin", 3.1, 6.7),
("June", 8.9, 10.3)
]

=>

[(1.2, 1), (3.1, 2), (4.5, 1), (6.7, 0), (8.9, 1), (10.3, 0)]

//============================================================================
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct user
{
	string name;
	float timeIn;
	float timeOut;
	user(string n, float t, float s)
	{
		this->name = n;
		this->timeIn = t;
		this->timeOut = s;
	}
};

bool comparator (user a, user b)
{
	return a.timeIn<b.timeIn;
}

struct node
{
	float time;
	bool In;
	node (float t, bool i)
	{
		this->time = t;
		this->In = i;
	}
};

bool comp (node a, node b)
{
	return a.time<b.time;
}

void userList(vector<user> input)
{
	vector<node> ar;
	for(int i = 0;i<input.size();i++)
	{
		ar.push_back(node(input[i].timeIn, true));
	}
	for(int i = 0;i<input.size();i++)
	{
		ar.push_back(node(input[i].timeOut, false));
	}
	std::sort(ar.begin(), ar.end(), comp);
	int count = 1;

	cout<<ar[0].time <<" "<<count <<endl;
	for(int i = 1;i<ar.size();i++)
	{
		if(ar[i].In == true)
		{
			count += 1;
			cout<<ar[i].time <<" "<<count  <<endl;
		}
		else
		{
			count -= 1;
			cout<<ar[i].time <<" "<<count  <<endl;
		}

	}
}

int main() {
	vector<user> inputset;
	inputset.push_back(user("Jane", 1.2, 4.5));
	inputset.push_back(user("Jin", 3.1, 6.7));
	inputset.push_back(user("June", 3.9, 10.3));
	inputset.push_back(user("June", 4.6, 10.2));
	userList(inputset);
	return 0;
}
