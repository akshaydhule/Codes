//============================================================================
// Name        : merge_intervals.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

 // Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> output;
    Interval temp(0,0);
    if(newInterval.start>newInterval.end)
    {
        int val = newInterval.start;
        newInterval.start = newInterval.end;
        newInterval.end = val;
    }
    bool pushed = false;
    for(int i=0;i<intervals.size();i++)
    {
        if(newInterval.start>intervals[i].end || newInterval.end<intervals[i].start)
        {
            if(!pushed && newInterval.end<intervals[i].start)
            {
                output.push_back(newInterval);
                pushed = true;
            }
            output.push_back(intervals[i]);
        }
        else
        {
            //skip for included intervals
            if(newInterval.end>intervals[i].end && newInterval.start<intervals[i].start)
                continue;
            else
            {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
            }
        }
    }
    if(output[output.size()-1].end<newInterval.start && pushed == false)
        output.push_back(newInterval);
    return output;
}

int main()
{
	Interval a(1,2), b(6,9), c(2,5);
	//A : [ (6037774, 6198243), (6726550, 7004541), (8842554, 10866536), (11027721, 11341296), (11972532, 14746848), (16374805, 16706396), (17557262, 20518214), (22139780, 22379559), (27212352, 28404611), (28921768, 29621583), (29823256, 32060921), (33950165, 36418956), (37225039, 37785557), (40087908, 41184444), (41922814, 45297414), (48142402, 48244133), (48622983, 50443163), (50898369, 55612831), (57030757, 58120901), (59772759, 59943999), (61141939, 64859907), (65277782, 65296274), (67497842, 68386607), (70414085, 73339545), (73896106, 75605861), (79672668, 84539434), (84821550, 86558001), (91116470, 92198054), (96147808, 98979097) ]
	//B : (36210193, 61984219)

	vector<Interval> intervals;
	intervals.push_back(a);
	intervals.push_back(b);
	insert(intervals, c);
}
