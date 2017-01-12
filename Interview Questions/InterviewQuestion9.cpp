/*
//============================================================================
// Name        : InterviewQuestion9.cpp
// Description : You have rating (0-10) of the hotels per user in this format:

scores = [
{'hotel_id': 1001, 'user_id': 501, 'score': 7},
{'hotel_id': 1001, 'user_id': 502, 'score': 7},
{'hotel_id': 1001, 'user_id': 503, 'score': 7},
{'hotel_id': 2001, 'user_id': 504, 'score': 10},
{'hotel_id': 3001, 'user_id': 505, 'score': 5},
{'hotel_id': 2001, 'user_id': 506, 'score': 5}
]

Any given hotel might have more than one score.

Implement a function, get_hotels(scores, min_avg_score)
that returns a list of hotel ids that have average score
equal to or higher than min_avg_score.

get_hotels(scores, 5) -> [1001, 2001, 3001]
get_hotels(scores, 7) -> [1001, 2001]
//============================================================================
*/
#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class ratings
{
public:
	int hotel_id;
	int user_id;
	int score;
	void setratings(int sid, int uid,int sc)
	{
		hotel_id = sid;
		user_id = uid;
		score = sc;
	}

};

std:: vector<int> get_hotels(unordered_map<int, int> rating_map, int score)
{
	vector<int> hotellist;
	for(auto it = rating_map.begin(); it!= rating_map.end();it++)
	{
		if(rating_map[it->first]>score)
		{
			hotellist.push_back(it->first);
			cout<<it->first<<"\n";
		}
	}
	return hotellist;
}

int main() {
	ratings hotels[6];
	unordered_map<int, int> rating_map, idcount;
	hotels[0].setratings(1001,501,7);
	hotels[1].setratings(1001,502,7);
	hotels[2].setratings(1001,503,7);
	hotels[3].setratings(2001,504,10);
	hotels[4].setratings(3001,505,5);
	hotels[5].setratings(2001,506,5);
	for(int i=0;i<6;i++)
	{
		if(rating_map.find(hotels[i].hotel_id)!=rating_map.end())
		{
			int prev = rating_map[hotels[i].hotel_id];
			int count = idcount[hotels[i].hotel_id] + 1;
			int val = (prev+hotels[i].score);
			rating_map[hotels[i].hotel_id] = val;
			idcount[hotels[i].hotel_id] = count;
		}
		else
		{
			rating_map[hotels[i].hotel_id] = hotels[i].score;
			idcount[hotels[i].hotel_id] = 1;
		}
	}
	for(auto it = rating_map.begin();it!= rating_map.end();it++)
	{
		rating_map[it->first] = rating_map[it->first]/idcount[it->first];
	}
	get_hotels(rating_map, 4);
	return 0;
}
