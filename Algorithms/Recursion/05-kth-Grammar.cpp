//Harshit
 
#include "bits/stdc++.h"
using namespace std;

// *******************************************************************************
//                                     MAIN CODE
// *******************************************************************************


int kthGrammar(int n,int k)
{
    if(n==1 and k==1)
    {
        return 0;
    }
    
    int length=1<<(n-1);
    int mid=length/2;
    
    if(k<=mid)
    {
        return kthGrammar(n-1,k);
    }
    else
    {
        return 1-kthGrammar(n-1,k-mid);
    }
}
void solve()
{
    int n,k;
    cin>>n>>k;
    int ans=kthGrammar(n,k);
}

int main()
{
    solve();
    return 0;
}