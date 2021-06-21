// Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.

#include<bits/stdc++.h>
using namespace std;

// Input: str = "aabb"
// Output: "ab"

// Take the input string.
// Perform the Longest common subsequence where s1[i]==s1[j] and i!=j.
// Return the length.

int LongestRepeatingSubsequence(string str) {
    int n = str.length();

    // we are writing code of LCS(str,str)
    // and then we are seeing the dp table
    // with the restriction that when both the characters are same, they shouldn’t be on the same index in the two strings.
    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
            if (i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str[i - 1] == str[j - 1] and i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];

}

int main()
{
    string str;
    cin >> str;
    int ans = LongestRepeatingSubsequence(str);
    cout << ans << "\n";
}