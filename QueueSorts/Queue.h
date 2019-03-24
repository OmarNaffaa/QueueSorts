#pragma once
#include <iostream>

typedef int QueueElement; // change type here

class Queue
{
private:
	int mFront, mBack, qSize, qAmntFilled;
	QueueElement* mArray;
public:
	Queue();
	Queue(int SIZE = 128);
	bool Empty() const;
	bool Full() const;
	void Enqueue(const QueueElement& item);
	void Dequeue();
	QueueElement Front() const;
	int Size() const;
	void Display();
	~Queue();

	// Sorting
	void SelectionSort();
	void BubbleSort();
	void InsertionSort();
	void BucketSort();
	void QuickSort(int left, int right);

	int AssignPivot(int* arr, int left, int right);
	int GetMax(int* mArray, int SIZE);
	void CountSort(int mArray[], int SIZE, int exp);
	void Swap(int& a, int& b);
};