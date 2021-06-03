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

//O(nlogn)
void buildMaxHeap(vector<int>&v)
{
	for (int i = 2; i < v.size(); i++)
	{
		int index = i;
		int parent = i / 2;

		while (index > 1 and v[index] > v[parent])
		{
			swap(v[index], v[parent]);
			index = parent;
			parent = index / 2;
		}
	}
}

//O(n)
//Let say we are making a max heap so writing code for maxheapify
void heapify(int index, vector<int>&v)
{
	int left = 2 * index;
	int right = 2 * index + 1;

	int largest = index;
	int last = v.size() - 1;
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
		heapify(largest, v);
	}


}
void buildMaxHeapOptimised(vector<int>&v)
{
	int n = v.size() - 1; //as we have blocked a index that is 0th index so subtracting -1 to compensate
	for (int i = n / 2; i >= 1; i--)
	{
		heapify(i, v);
	}
}
int main()
{
	vector<int>v{ -1, 10, 20, 5, 6, 1, 8, 9, 4}; //given heap
	print(v);
	// buildMaxHeap(v);
	// print(v);
	buildMaxHeapOptimised(v);
	print(v);

}