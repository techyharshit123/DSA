// Given an array of n elements, where each element is at most k away from its target position. The task is to print array in sorted form.

//O((n+k)*logk) ====> O(n*logk)
#include "bits/stdc++.h"
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	priority_queue<int, vector<int>, greater<int>>pq; //to create a min-heap

	//inserting first k elements in the priority queue as at index 0 there will be a element from index [0,k]
	//O(k*logk)
	for (int i = 0; i <= k; i++)
	{
		pq.push(a[i]);
	}
	int index = 0;

	//O((n-k)*logk)
	for (int i = k + 1; i < n; i++)
	{
		a[index] = pq.top();
		index++;
		pq.pop();
		pq.push(a[i]);
	}

	//O(k*logk)
	while (index != n)
	{
		a[index] = pq.top();
		index++;
		pq.pop();
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

