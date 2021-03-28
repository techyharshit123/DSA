// It is solved using Kadanes's Algorithm for O(n) approach

// =========================================
// 1. Brute force solution    =    O(n^3)



// 2. Better Solution   =    O(n^2)
#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(int a[], int n){

    int ans=0;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            ans=max(ans,sum);
        }
    }
    return ans;    
}

int main()
{
    int n;
    cin>>n; //input size of array
    
    int a[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i]; //inputting elements of array
    
    cout << maxSubarraySum(a, n) << endl;
}




//3. Optimal Solution   =    O(n)-TC    and    O(1)-SC
#include<bits/stdc++.h>
using namespace std;
int maxSubarraySum(int a[], int n){

    int ans=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++)
    {
    	sum+=a[i];
        ans=max(ans,sum);

        if(sum<0)
        	sum=0;
    }
    return ans;    
}

int main()
{
    int n;
    cin>>n; //input size of array
    
    int a[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i]; //inputting elements of array
    
    cout << maxSubarraySum(a, n) << endl;
}
