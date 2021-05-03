//Harshit
 
#include "bits/stdc++.h"
using namespace std;


vector<int> MaximumOfSubarrays(int* a,int k,int n)
{
	deque<int>dq;

	dq.push_back(0);
	std::vector<int> v;

	int mx=INT_MIN;

	for(int i=0;i<k;i++)
	{
		while(!dq.empty() and a[i]>a[dq.back()])
			dq.pop_back();
			
		dq.push_back(i);
		mx=max(mx,a[i]);
	}

	v.push_back(mx);
	for(int i=k;i<n;i++)
	{
		// cout<<dq.front()<<" ";
		while(!dq.empty() and dq.front()<=(i-k))
			dq.pop_front(); 

		while(!dq.empty() and a[i]>a[dq.back()])
			dq.pop_back();

		dq.push_back(i);
		v.push_back(a[dq.front()]);

	}
	return v;
}
int main()
{
	int n,k;
	cin>>n>>k;

	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}

	std::vector<int> v=MaximumOfSubarrays(a,k,n);

	for(auto x:v)
		cout<<x<<" ";
}