// Queue(with vector implementation).cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

int main()
{

	Queue<int> q(10);

	for (int i = 0; i <10; i++)
		q.enqueue(i);

	cout << q.top() << endl;

	
	for (int i = 0; i <5; i++) //kemi hequr nga 0te 4
		q.dequeue();


	for (int i = 0; i <=10; i++) //shtojme nga 0-10 , 5 6 7 8 9 0 1 2 3 4
		q.enqueue(i);

	while(!q.isEmpty()) //duhet te printoje 5 6 7 8 9 0 1 2 3 4 5 ..10
	{
		cout << q.dequeue() << endl;
	}

	cout << endl << q.isEmpty() << "   " << q.isFull();
}
