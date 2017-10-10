#include "stdafx.h"
#include "Queue.h"
#include<vector>
#include<iostream>

using namespace std;

template <class var>
Queue<var>::Queue(int siz)
{
	front = -1; //ne fillim kur eshte bosh
	rear = -1;
	nrEl = 0;
	size = siz;
	v = new var[size];
}


template <class var>
Queue<var>::~Queue()
{
	delete v;
}

template <class var>
void Queue<var>::resizeAndCorretMembers()
{
	int newSize = 2 * size;
	var* temp = new var[newSize];

	if (rear == size - 1) //case when the front is -1 and all vecotr is full
	{
		for (int i = 0;i < size;i++)
			temp[i] = v[i];
	}
	else //case when rear==front
	{
		for (int i = rear; i >= 0;--i)
			temp[i] = v[i];

		int i,j;
		for (i = newSize-1,j=size-1; j > front;--j,--i)
			temp[i] = v[j];

		front = i;
	}

	size = newSize;
	delete v;
	v = temp;
}

template <class var>
void Queue<var>::enqueue(var x) //shton
{
	if (isFull())
		resizeAndCorretMembers();

	rear = (rear + 1) % size; //vector rrethor
	v[rear] = x;
	nrEl++;
}

template <class var>
var Queue<var>::dequeue()
{
	if (isEmpty())
	{
		cout << "Queue is empty !!!";
		exit(1);
	}
	else {
		front = (front + 1) % size; //logarisim el e pare qe do hiqet,sepse front mban 1 index para el te par
		nrEl--; //zbresim nr e el

		return v[front]; //sepse kthyem me sukses
	}
}

template <class var>
var Queue<var>::top()
{
	return v[front + 1];//sepse front mban 1 me pak
}

template <class var>
bool Queue<var>::isEmpty()
{
	return (nrEl == 0);
}

template <class var>
bool Queue<var>::isFull()
{
	return (nrEl == size); //ose shef nqs nr el ==0
}

template <class var>
void Queue<var>::clear()
{
	delete v;
	front = -1;
	rear = -1;
	nrEl = 0;
	size = 0;
}

template <class var>
int Queue<var>::getNrEl()
{
	return nrEl;
}