//It is an inplace algo --> doesn't require extra array to hold the sorted array
#include "bits/stdc++.h"
// 1 indexed tree --> indexing starts from index=1;
using namespace std;


void print(vector<int>v)
{
	for (auto x : v)
	{
		cout << x << " ";
	}
	cout << endl;
}

void heapify(vector<int>&v, int index, int size)
{
	int left = 2 * index;
	int right = 2 * index + 1;

	int largest = index;
	int last = size - 1;
	if (left <= last and v[left] > v[largest])
	{
		largest = left;
	}
	if (right <= last and v[right] > v[largest])
	{
		largest = right;
	}

	if (largest != index)
	{
		swap(v[largest], v[index]);
		heapify(v, largest, size);
	}
}

void buildMaxHeapOptimised(vector<int>&v)
{
	int n = v.size() - 1; //as we have blocked a index that is 0th index so subtracting -1 to compensate
	for (int i = n / 2; i >= 1; i--)
	{
		heapify(v, i, v.size());
	}
}

void heapSort(vector<int>&v)
{
	buildMaxHeapOptimised(v);
	int n = v.size(); //size of the heap

	//remove n-1 elements from the heap *****NOTE--->we are removing elements from heap, not from array/vector
	while (n > 1) //heap has atleast 2 elements
	{
		swap(v[1], v[n - 1]);

		//now remove that element from heap *****NOTE--->we are removing elements from heap, not from array/vector
		n--;

		//fix the heap by calling the heapify method on index = 1 node
		heapify(v, 1, n);
	}
}
int main()
{
	vector<int>v{ -1, 10, 20, 5, 6, 1, 8, 9, 4}; //given heap
	print(v);
	heapSort(v);
	print(v);
}