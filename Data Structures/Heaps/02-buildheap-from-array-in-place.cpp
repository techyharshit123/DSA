#include "bits/stdc++.h"
// 1 indexed tree --> indexing starts from index=1;
using namespace std;


void print(vector<int>v)
{
	for (auto x : v)
	{
		cout << x << " ";
	}
}

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
int main()
{
	vector<int>v{ -1, 10, 20, 5, 6, 1, 8, 9, 4}; //given heap
	print(v);
	buildMaxHeap(v);
}