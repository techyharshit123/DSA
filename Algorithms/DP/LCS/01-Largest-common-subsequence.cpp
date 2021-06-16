#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


///////////////////// METHOD-1
// Recursive
// TC = Exponential = O(n*(2^n))
// The naive solution for this problem is to generate all subsequences of both given sequences and find the longest matching subsequence
// In order to find out the complexity of brute force approach, we need to first know the number of possible different subsequences of a string with length n, i.e., find the number of subsequences with lengths ranging from 1,2,..n-1. Recall from theory of permutation and combination that number of combinations with 1 element are nC1. Number of combinations with 2 elements are nC2 and so forth and so on. We know that nC0 + nC1 + nC2 + … nCn = 2^n. So a string of length n has 2^n-1 different possible subsequences since we do not consider the subsequence with length 0. This implies that the time complexity of the brute force approach will be O(n * 2^n). Note that it takes O(n) time to check if a subsequence is common to both the strings. This time complexity can be improved using dynamic programming.
int lcs(int x, int y, string s1, string s2)
{
    if (x == 0 or y == 0)
        return 0;


    char ch1 = s1[x - 1];
    char ch2 = s2[y - 1];

    if (ch1 == ch2)
    {
        return 1 + lcs(x - 1, y - 1, s1, s2);
    }
    else
    {
        return max(lcs(x, y - 1, s1, s2), lcs(x - 1, y, s1, s2));
    }
}

///////////////////// METHOD-2
// Recursion with memoizasation
// TC = O(x*y)
// Here we are passing s1 and s2 by reference so as to avoid from the TLE error on submission on online platform
// Pass the strings by reference. Due to recursive calls by value, it takes some time to create the same string at all function calls. In tabulation there are no recursive calls, therefore it passes.
int ans(int x, int y, string& s1, string& s2, int dp[][1001])
{
    if (x == 0 or y == 0)
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    char ch1 = s1[x - 1];
    char ch2 = s2[y - 1];

    if (ch1 == ch2)
    {
        dp[x][y] = 1 + ans(x - 1, y - 1, s1, s2, dp);
    }
    else
    {
        dp[x][y] = max(ans(x, y - 1, s1, s2, dp), ans(x - 1, y, s1, s2, dp));
    }
    return dp[x][y];
}
int lcstopdown(int x, int y, string s1, string s2)
{
    int dp[1001][1001];
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            dp[i][j] = -1;
        }
    }
    // memset(dp,-1,sizeof(dp));/

    return ans(x, y, s1, s2, dp);
    // your code here
}

///////////////////// METHOD-3
// Bottom up
// TC-O(x*y)
// x<=1000 and y<=1000
int lcsbottomup(int x, int y, string s1, string s2)
{
    int dp[1001][1001];
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < 1001; i++)
    {
        for (int j = 1; j < 1001; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[x][y];
}

// Method-4
// for space optimised solution check out the below link
// https://www.geeksforgeeks.org/space-optimized-solution-lcs/
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;      // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2;
        cout << lcsbottomup(x, y, s1, s2) << endl;
    }
    return 0;
}