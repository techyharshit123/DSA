#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/longest-common-substring-dp-29/
// DO check out for space optimised approach

// Method-1
// Recursion
// TC = O(n*(m^2))


// Method-2
// TC= o(m*n)
int longestCommonSubstr (string S1, string S2, int n, int m)
{
    int dp[1001][1001];
    // memset(dp,-1,sizeof(dp));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = -1;
            if (i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
    // your code here
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;

        cout << longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends