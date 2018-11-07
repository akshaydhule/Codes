/*
//============================================================================
// Name        : Queue-MovingAverage.cpp
// Description : Calculate a moving average that considers the last N values.
Circular Queue (Interviewer didn't agree with the linked list queue that I suggested at first. Said the pointers took space)
//============================================================================
*/

#include <iostream>
#include <vector>
using namespace std;

class CirQueue{
	vector<int> buffer;
	int tail, head;
	int size, sum;
	int count;
public :
	CirQueue(int s): tail(0), head(0), size(s), sum(0), count(0){
		buffer = vector<int>(s);
	}
	double avg(int n){
		double avg = 0;
		sum += n;

		if(size == count){
			sum -= buffer[head];
			head = (head+1) % size;
		}
		else
		{
			count++;
		}
		buffer[tail] = n;
		tail = (tail + 1) % size;
		avg = 1.0 * sum / count;
		return avg;
	}
};

int main() {
	CirQueue c(4);
	cout<<c.avg(1)<<endl;
	cout<<c.avg(2)<<endl;
	cout<<c.avg(3)<<endl;
	cout<<c.avg(4)<<endl;
	cout<<c.avg(5)<<endl;
	return 0;
}
