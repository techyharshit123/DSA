#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// You can also do by different method as mentioned in GFG
// You have to initialize the dp array in that case with a different value
// and at the place of max we will be taking min of 2 quantities
// Refer this --> https://www.geeksforgeeks.org/print-shortest-common-supersequence/

string printSCS(int x, int y, string s1, string s2)
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

    string scs; // answer string

    // Start from the right-most-bottom-most corner and
    // one by one store characters in scs
    int i = x, j = y;
    while (i > 0 and j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            scs.push_back(s1[i - 1]);
            i--, j--;
        }
        else
        {
            //Move in direction of maximum element
            if (dp[i - 1][j] > dp[i][j - 1])
            {
                scs.push_back(s1[i - 1]);
                i--;
            }
            else
            {
                scs.push_back(s2[j - 1]);
                j--;
            }
        }
    }
    while (i > 0)
    {
        scs.push_back(s1[i - 1]);
        i--;
    }

    while (j > 0)
    {
        scs.push_back(s1[j - 1]);
        j--;
    }


    reverse(scs.begin(), scs.end()); // this is required as we are moving from bottom right to top left so the resulting string will be in reverse order

    return scs;
}
int main()
{
    int t, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y;      // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2;
        cout << printSCS(x, y, s1, s2) << endl;
    }
    return 0;
}