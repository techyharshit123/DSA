#include "bits/stdc++.h"
// 1 indexed tree --> indexing starts from index=1;
using namespace std;

class Heap
{
public:
	vector<int>v;
	bool minHeap; //To maintain whether we are creating a minHeap or maxHeap

	Heap(int default_size, bool type)
	{
		v.reserve(default_size); //by this we reserve the space we took input in variable default_size
		v.push_back(-1); //by this we block the index 0 as we are processing our nodes from 1st index
		//if we need to process our nodes from 0 index then no need of this blocking

		minHeap = type;
	}

	bool compare(int a, int b)
	{
		if (minHeap)
			return a < b;
		else
			return a > b;
	}

	void push(int data)
	{
		v.push_back(data);

		int index = v.size() - 1;
		int parent = index / 2; //parent-->index/2  leftchild-->2*index  rightchild-->2*index+1

		while (index > 1 and compare(v[index], v[parent]))
		{
			swap(v[index], v[parent]);
			index = parent;
			parent = index / 2;
		}
	}

	int top()
	{
		return v[1];
	}

	void heapify(int index)
	{
		int left = 2 * index;
		int right = 2 * index + 1;

		int temp_index = index; //smallest in case of minheapify and largest in case of maxheapify
		int last = v.size() - 1;
		if (left <= last and compare( v[left] , v[temp_index]))
		{
			temp_index = left;
		}
		if (right <= last and  compare(v[right] , v[temp_index]))
		{
			temp_index = right;
		}

		//it acts as base case
		if (temp_index != index)
		{
			swap(v[index], v[temp_index]);
			heapify(temp_index);
		}

	}

	void pop()
	{
		//using these 3 lines we pop out the top element of heap
		int last_index = v.size() - 1;
		swap(v[1], v[last_index]);
		v.pop_back();

		//it's time to heapify the heap
		heapify(1);
	}

	//function to return true if heap is empty
	bool empty()
	{
		return v.size() == 1; //as we have blocked the 0th index
	}
};

int main()
{
	int n;
	cin >> n;
	Heap h1(n, false); //making a maxheap
	// Heap h1;  //gives error that no matching function for call to 'Heap::Heap()'

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		h1.push(x);
	}

	while (!h1.empty())
	{
		cout << h1.top() << " ";
		h1.pop();
	}

}