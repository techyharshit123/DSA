//Harshit
 
#include "bits/stdc++.h"
#define l1                      long long int
#define in1(x)                  l1 x; cin>>x;
#define in2(x,y)                l1 x;l1 y; cin>>x; cin>>y
#define rep(x,y,z)              for(l1 x=y;x<z;x++)
#define vl1                     vector<l1>
#define vpll                    vector<pair<l1,l1>>
#define all(v)                  v.begin(),v.end()
#define F                       first
#define S                       second
#define PI                      3.14159265
#define fast                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x)                   (l1)(x).size()
#define print(v)                for(auto x : v){cout << x << " ";}cout <<"\n";
#define printnl(v)              for(auto x : v)cout << x <<"\n";
#define MOD                     1e9+7

using namespace std;


// *******************************************************************************
// 									MAIN CODE
// *******************************************************************************

void deletemid(stack<int>&s,int midpos)
{
	if(s.size()==0)
		return;
	
	if(midpos==1)
	{
		s.pop();
		return;
	}

	int top=s.top();
	s.pop();

	deletemid(s,midpos-1);

	s.push(top);

}

void solve()
{
	int n;
	cin>>n;
	int a[n];
	stack<int>s;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		s.push(a[i]);
	}

	int midpos=s.size()/2+1;

	deletemid(s,midpos);

	while(s.size())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}

int main()
{
	fast
 
    #ifdef NCR
        init();
    #endif
	l1 T=1;
	// cin>>T;
	while(T--)
	solve();
	return 0;
}