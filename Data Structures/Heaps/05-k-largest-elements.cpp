//Given an array of N positive integers, print k largest elements from the array.


#include "bits/stdc++.h"
using namespace std;


//O(k+(n-k)*logk) ====> O(n*logk) - TC
//O(k) - SC
vector<int> kLargestOptimised(int a[], int n, int k)
{
	vector<int>v;

	//O(k) building a min heap
	priority_queue<int, vector<int>, greater<int>>pq(a, a + k);


	// O((n-k)*logk)
	for (int i = k; i < n; i++)
	{
		int top = pq.top();

		if (a[i] > top)
		{
			pq.pop();
			pq.push(a[i]);
		}
	}


	while (pq.size())
	{
		v.push_back(pq.top());
		pq.pop();
	}

	//to return items in sorted increasing order
	reverse(v.begin(), v.end());
	return v;
}
int main()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int>ans = kLargestOptimised(a, n, k);

	for (auto x : ans)
		cout << x << " ";


}