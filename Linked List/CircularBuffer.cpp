/*
//============================================================================
// Name        : CircularBuffer.cpp
// Description : Hello World in C++, Ansi-style
 * Buffer & size
 * Functions :
 * 1. add data
 * 2. remove data if full
 * 3. get size
 * 4. is it full
 * 5. get front field
//============================================================================
*/

#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

template<class T>
class circularBuffer{

public:
	circularBuffer(int size):
		buffer(unique_ptr<T[]>(new T[size])), maxSize(size){}

	//adding at end(tail) of the buffer
	void addData(T d){
		buffer[tail] = d;
		tail = (tail+1)%maxSize;
		size += 1;
		if(full == true){
			head = (head+1)%maxSize;
			size = maxSize;
		}

		full = (head == tail);
	}

	//get front(head) of buffer
	T getFrontElement(){
		if(size == 0)
			return T();
		T val = buffer[head];
		full = false;
		size -= 1;
		head = (head+1)%maxSize;
		return val;
	}

	int getSize(){
		return size;
	}

	bool isFull(){
		return full;
	}

	bool isEmpty(){
		return (head==tail && !full);
	}

	void reset(){
		head = tail;
		size = 0;
		full = false;
	}

private:
	const int maxSize;
	std::unique_ptr<T[]> buffer;
	int head = 0;
	int tail = 0;
	int size = 0;
	bool full = false;
};

int main() {
	circularBuffer<int> newBuff(4);
	newBuff.addData(1);
	newBuff.addData(2);
	newBuff.addData(3);
	newBuff.addData(4);
	cout<<newBuff.getFrontElement();
	newBuff.addData(5);
	cout<<newBuff.getFrontElement();
	cout<<newBuff.getFrontElement();
	cout<<newBuff.getFrontElement();
	cout<<newBuff.getFrontElement();
	cout<<newBuff.getFrontElement();
	return 0;
}
