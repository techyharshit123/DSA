//Harshit
 
#include "bits/stdc++.h"
using namespace std;

void solve()
{
	
	int n=15;
	int j=3,i=1;
	int m=2;

	//Clear Range i to j function starts
	int mask=~((~(-1<<(j-i+1)))<<i);
	int n_=n&mask;
	//Clear Range i to j function ends

	//Take or operator with the new mask made with help of m
	int ans=n_|(m<<i);
	cout<<ans<<endl;
}

int main()
{
	solve();
	return 0;
}