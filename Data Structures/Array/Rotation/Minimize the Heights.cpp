// Qn link ---->  https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#


// O(nlogn)


// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
    
        sort(arr,arr+n);
        int ans=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++)
        {
            if(arr[n-1]-k>=0&&arr[i+1]-k>=0)
                ans=min(ans,max(arr[n-1]-k,arr[i]+k)-min(arr[0]+k,arr[i+1]-k)); 
                //it means that until ith index we'll be adding the value of k and at all index after that i we'll subtract k from the value
        }
        
        return ans;


    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends