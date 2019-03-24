#include "pch.h"
#include "Queue.h"
#include <iostream>
using namespace std;

int main()
{
	Queue sQueue(10);
	Queue bubQueue(12);
	Queue iQueue(14);
	Queue bQueue(16);
	Queue qQueue(18);

	for (int i = 0; i < sQueue.Size(); i++)
		sQueue.Enqueue(rand() % 50);

	for (int j = 0; j < bubQueue.Size(); j++)
		bubQueue.Enqueue(rand() % 50);

	for (int k = 0; k < iQueue.Size(); k++)
		iQueue.Enqueue(rand() % 50);

	for (int m = 0; m < bQueue.Size(); m++)
		bQueue.Enqueue(rand() % 50);

	for (int n = 0; n < qQueue.Size(); n++)
		qQueue.Enqueue(rand() % 50);

	cout << "Before SelectionSort:\n   ";
	sQueue.Display();
	cout << "After SelectionSort:\n   ";
	sQueue.SelectionSort();
	sQueue.Display();

	cout << "\nBefore BubbleSort:\n   ";
	bubQueue.Display();
	cout << "After BubbleSort:\n   ";
	bubQueue.BubbleSort();
	bubQueue.Display();

	cout << "\nBefore InsertionSort:\n   ";
	iQueue.Display();
	cout << "After InsertionSort:\n   ";
	iQueue.InsertionSort();
	iQueue.Display();

	cout << "\nBefore BucketSort:\n   ";
	bQueue.Display();
	cout << "After BucketSort:\n   ";
	bQueue.BucketSort();
	bQueue.Display();

	cout << "\nBefore QuickSort:\n   ";
	qQueue.Display();
	cout << "After QuickSort:\n   ";
	qQueue.QuickSort(0, qQueue.Size() - 1);
	qQueue.Display();

	cout << endl;
	return 0;
}