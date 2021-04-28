// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Maximum Rectangular area in a histogram
// arr[]: input array
// n: size of array

vector<long long>ps;  //previoussmaller
vector<long long>ns;  //nextsmaller

void previousSmaller(long long a[],long long n)
{
    stack<long long>s;
    s.push(0);
    ps.push_back(-1);
    // long long n=a.size();
    for(long long i=1;i<n;i++)
    {
        while(s.size()!=0 and a[s.top()]>=a[i])
        {
            s.pop();
        }
        
        if(s.size()==0)
        {
            ps.push_back(-1);
        }
        else
        {
            ps.push_back(s.top());            
        }
        
        s.push(i);
    }
}
void nextSmaller(long long a[],long long n)
{
    reverse(a,a+n);
    stack<long long>s;
    s.push(0);
    ns.push_back(n);
    
    for(long long i=1;i<n;i++)
    {
        while(s.size()!=0 and a[s.top()]>=a[i])
        {
            s.pop();
        }
        
        if(s.size()==0)
        {
            ns.push_back(n);
        }
        else
        {
            ns.push_back(n-1-s.top());            
        }
        
        s.push(i);
    }
    reverse(a,a+n);
    reverse(ns.begin(),ns.end());
   
}
long long getMaxArea(long long h[], long long n){

    long long res=0;
    previousSmaller(h,n);
    nextSmaller(h,n);
    for(long long i=0;i<n;i++)
    {
        long long curr=h[i];
        curr+=(i-ps[i]-1)*h[i];
        curr+=(ns[i]-i-1)*h[i];      
        res=max(res,curr);
    }
    return res;
}



// { Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<getMaxArea(arr, n)<<endl;
    }
	return 0;
}
  // } Driver Code Ends