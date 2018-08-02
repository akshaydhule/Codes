/*
//============================================================================
// Name        : Round_robin.cpp
// Description : Given a pipeline of process implement round robin
 * algorithm to process all processes.
//============================================================================
*/
#include <iostream>
#include <queue>
using namespace std;

class scheduler
{
public:
	int processes;
	queue< pair<int, pair<int, int> > > pipeline; // number and time
	scheduler(int n)
	{
		this->processes = n;
	}
	void push(int p, int enter_time, int process_time)
	{
		pipeline.push(make_pair(p, make_pair(enter_time, process_time)));
	}
	void schedule(int slice)
	{
		int rem_slice =slice , curr_time = 0 ;
		pair<int, pair<int,int > > p, q;
		while(!pipeline.empty())
		{
			p = pipeline.front();
			pipeline.pop();
			if(p.second.second <= rem_slice)
			{
				rem_slice = slice - p.second.second;
				curr_time += p.second.second;
				cout<<p.first<<"         "<<p.second.first<<"         "<<p.second.second<<"\n";
			}
			else
			{
				curr_time += rem_slice;
				p.second.second -= rem_slice;
				q = pipeline.front();
				cout<<p.first<<"         "<<p.second.first<<"         "<<p.second.second<<"\n";
				if(q.second.first<= curr_time)
				{
					push(p.first, p.second.first, p.second.second);
				}
				rem_slice = 0;
			}
			if(rem_slice == 0)
				rem_slice = slice;
		}
	}
};

int main() {
	scheduler a(4);
	a.push(1,0,9);
	a.push(2,1,5);
	a.push(3,2,1);
	a.push(4,3,4);
	cout<<"process enter-time remaining-time\n";
	a.schedule(2);
	return 0;
}
