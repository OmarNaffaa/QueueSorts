#include "pch.h"
#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
{
	mArray = new(nothrow) QueueElement[128]; // uses default size of 128

	if (mArray != 0) // if there is space to create the queue
	{
		mFront = 0;
		mBack = 0;
		qAmntFilled = 0;
	}
	else
	{
		cerr << "Inadequate memory to allocate the queue, terminating execution..." << endl;
	}
}

Queue::Queue(int SIZE)
{
	if (SIZE <= 0)
	{
		cerr << "Invalid size for queue, terminating execution..." << endl;
	}

	qSize = SIZE;
	mArray = new(nothrow) QueueElement[qSize];

	if (mArray != 0) // if there is space to create the queue
	{
		mFront = 0;
		mBack = 0;
		qAmntFilled = 0;
	}
	else
	{
		cerr << "Inadequate memory to allocate the queue, terminating execution..." << endl;
	}
}

bool Queue::Empty() const
{
	return (qAmntFilled == 0); // return true if nothing is in the queue
}

bool Queue::Full() const
{
	return (qAmntFilled == qSize); // return true if the queue is full
}

void Queue::Enqueue(const QueueElement& item)
{
	int nextBack = (mBack + 1) % qSize; // back of the queue after an item is added

	if (!Full()) // add to the queue if there is space
	{
		mArray[mBack] = item;
		mBack = nextBack;
		qAmntFilled++;
	}
	else
	{
		cerr << "Queue is full - cannot enqueue another item..." << endl;
	}
}

void Queue::Dequeue()
{
	if (!Empty()) // remove the next item in the queue unless it is empty
	{
		mFront = (mFront + 1) % qSize;
		qAmntFilled--;
	}
	else
	{
		cerr << "Queue is empty - Cannot dequeue an item..." << endl;
	}
}

QueueElement Queue::Front() const
{
	if (!Empty())
		return (mArray[mFront]);
	else
	{
		cerr << "Queue is empty - returning a false value..." << endl;
		QueueElement falseVal = -1;
		return falseVal;
	}
}

int Queue::Size() const
{
	return qSize;
}

void Queue::Display()
{
	int currentFront = mFront;

	if (qAmntFilled == 0)
		cout << "Queue is empty..." << endl;

	for (int i = 0; i < qAmntFilled; i++)
	{
		cout << mArray[currentFront] << " ";
		currentFront = (currentFront + 1) % qSize;
	}

	cout << endl;
}

Queue::~Queue()
{
	delete[] mArray;
}

void Queue::SelectionSort()
{
	for (int i = 0; i < qSize; i++)
	{
		for (int j = i + 1; j < qSize; j++)
		{
			if (mArray[j] < mArray[i])
				Swap(mArray[i], mArray[j]);
		}
	}
}

void Queue::BubbleSort()
{
	for (int i = 0; i < qSize; i++)
	{
		for (int j = 0; j < qSize - 1; j++)
		{
			if (mArray[j] > mArray[j + 1])
				Swap(mArray[j], mArray[j + 1]);
		}
	}
}

void Queue::InsertionSort()
{
	int i = 1;

	while (i < qSize)
	{
		int j = i;

		while ((j > 0) && (mArray[j - 1] > mArray[j]))
		{
			Swap(mArray[j], mArray[j - 1]);
			j -= 1;
		}

		i += 1;
	}
}

void Queue::BucketSort()
{
	// get the maximum number to find max amount of digits
	int max = GetMax(mArray, qSize);

	// use CountSort function on each bucket
	// (passing the place (ones, tens, etc) to search that digit
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		CountSort(mArray, qSize, exp);
	}
}

void Queue::QuickSort(int left, int right)
{
	if (left < right)
	{
		// assign the pivot value in the array
		int pivot = AssignPivot(mArray, left, right);

		QuickSort(left, pivot - 1);
		QuickSort(pivot + 1, right);
	}
}

void Queue::Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Queue::GetMax(int* mArray, int qSize)
{
	int mx = mArray[0];
	for (int i = 1; i < qSize; i++)
		if (mArray[i] > mx)
			mx = mArray[i];
	return mx;
}

void Queue::CountSort(int arr[], int n, int exp)
{
	int* output = new int[n]; // output array 
	int i, count[10] = { 0 };

	// see how many digits need to go into each bucket
	// (arr[i] / exp) % 10 determines index each number would go into
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual 
	// position of this digit in output[] 
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array 
	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	// Copy the output array to arr[], so that arr[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

int Queue::AssignPivot(int a[], int left, int right)
{
	// pivot (Element to be placed at right position)
	int pivot = a[right];

	int i = (left - 1);  // Index of smaller element

	for (int j = left; j <= right - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (a[j] <= pivot)
		{
			i++;    // increment index of smaller element
			Swap(a[i], a[j]);
		}
	}

	Swap(a[i + 1], a[right]);

	return (i + 1);
}