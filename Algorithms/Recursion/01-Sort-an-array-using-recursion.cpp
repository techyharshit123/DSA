//Harshit
 
#include "bits/stdc++.h"
#define ll                      long long int
#define in1(x)                  ll x; cin>>x;
#define in2(x,y)                ll x;ll y; cin>>x; cin>>y
#define rep(x,y,z)              for(ll x=y;x<z;x++)
#define vll                     vector<ll>
#define vpll                    vector<pair<ll,ll>>
#define all(v)                  v.begin(),v.end()
#define F                       first
#define S                       second
#define PI                      3.14159265
#define fast                    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define sz(x)                   (ll)(x).size()
#define print(v)                for(auto x : v){cout << x << " ";}cout <<"\n";
#define printnl(v)              for(auto x : v)cout << x <<"\n";
#define MOD                     1e9+7

using namespace std;

// *******************************************************************************
// 									MAIN CODE
// *******************************************************************************

vector<ll> sortarr(vector<ll>&v)
{
	if(v.size()==1)
		return v;

	ll n=v.size();
	ll x=v[v.size()-1];
	v.pop_back();

	v=sortarr(v);

	ll index=v.size();
	vector<ll>temp;
	rep(i,0,v.size())
	{
		if(v[i]>x)
		{
			index=i;
			break;
		}
		else
			temp.push_back(v[i]);
	}
	temp.push_back(x);
	rep(i,index,v.size())
	temp.push_back(v[i]);
	return temp;
}


void insert(vector<ll>&v,ll temp)
{
	if(v.size()==0 or v[v.size()-1]<=temp)
	{
		v.push_back(temp);
		return;
	}

	int last=v[v.size()-1];
	v.pop_back();

	insert(v,temp);	
	v.push_back(last);
}
void sortrecursive(vector<ll>&v)
{
	if(v.size()==1)
		return;

	ll temp=v[v.size()-1];
	v.pop_back();

	sortrecursive(v);

	insert(v,temp);
}
void solve()
{
	in1(n);
	vector<ll>v;

	rep(i,0,n)
	{
		in1(x);
		v.push_back(x);
	}

	sortrecursive(v);

	for(auto x:v)
		cout<<x<<" ";
	cout<<endl;



}

int main()
{
	fast
 
    #ifdef NCR
        init();
    #endif
	ll T=1;
	cin>>T;
	while(T--)
	solve();
	return 0;
}