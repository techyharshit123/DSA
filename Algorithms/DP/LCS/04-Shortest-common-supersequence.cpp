#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


int lcsbottomup(int x, int y, string s1, string s2)
{
    int dp[x + 1][y + 1];

    //Following steps upto line 34 build the dp array in bottom up fashion Note
    // that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
    for (int i = 0; i < x + 1; i++) {
        for (int j = 0; j < y + 1; j++) {
            dp[i][j] = -1;
        }
    }

    for (int i = 0; i < x + 1; i++) {
        for (int j = 0; j < y + 1; j++) {
            if (i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < y + 1; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[x][y];
}

int LCsubsequence(int x, int y, string s1, string s2)
{
    return x + y - lcsbottomup(x, y, s1, s2);
}
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;      // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2;
        cout << LCsubsequence(x, y, s1, s2) << endl;
    }
    return 0;
}