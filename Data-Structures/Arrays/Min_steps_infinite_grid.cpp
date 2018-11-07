//============================================================================
// Name        : Min_steps_infinite_grid.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
using namespace std;

class coord
{
    public:
    int x, y;
    coord(int a, int b)
    {
        x= a;
        y = b;
    }
};

int coverPoints(vector<int> &X, vector<int> &Y) {
    vector<coord> path;
    set<coord> visited;
    for(int i=0;i<X.size();i++)
        path.push_back(coord (X[i], Y[i]));
    int startx = path[0].x, starty = path[0].y, dist = 0;
    stack<coord> vals;
    vals.push(coord(X[0], Y[0]));
    for(int i=1;i<path.size();i++)
    {
        int x = path[i].x;
        int y = path[i].y;
        visited.insert(coord(startx, starty));
        while((startx != x && starty != y) || !(vals.empty()))
        {
            startx = vals.top().x;
            starty = vals.top().y;
            vals.pop();
            int xdir[] = {1,-1,0,0,-1,1,-1,1};
            int ydir[] = {0,0,1,-1,-1,1,1,-1};
            int xa =-1, ya = -1;
            for(int i=0;i<8;i++)
            {
                xa = startx+ xdir[i];
                ya = starty+ ydir[i];
                if(((pow(startx-x,2) + pow(starty- y, 2)) >= (pow(xa-x,2) + pow(ya- y, 2)))
                && visited.find(coord(xa, ya))==visited.end())
                {
                    vals.push(coord(xa, ya));
                    visited.insert(coord(xa, ya));
                }
            }
        }
        startx = path[i].x;
        starty = path[i].y;
    }
    return dist;
}


int main() {
	vector<int> X;
	X.push_back(1);
	X.push_back(2);
	vector<int> Y;
	Y.push_back(1);
	Y.push_back(2);
	coverPoints(X, Y);
	return 0;
}
