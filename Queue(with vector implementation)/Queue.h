#pragma once


using namespace std;

template <class var>
class Queue
{
private:
	var* v;
	int front; //index one before the first element
	int rear; //index of the last element 
	int nrEl;
	int size;
	void resizeAndCorretMembers();
public:

	Queue(int = 100);
	~Queue();
	void enqueue(var); //shton ne queue
	var dequeue(); //kthen el qe hoqi nga rradha
	var top(); //kthen el ne fund te rradhes pa e fshire
	bool isEmpty();
	bool isFull();
	void clear();
	int getNrEl();

};
