#include<bits/stdc++.h>
using namespace std;

//*********************METHOD-1**************//
// Using recursion
// TC = Exponential
long long int countrecursive( int S[], int m, int n )
{
	if (n == 0)
		return 1;
	if (m == 0)
		return 0;

	if (S[m - 1] > n)
	{
		return countrecursive(S, m - 1, n);
	}
	else
	{
		return countrecursive(S, m, n - S[m - 1]) + countrecursive(S, m - 1, n);
	}

	//code here.
}


//*********************METHOD-2**************//
//recursion with memoization
// TC = O(m*n)
long long int ans(int S[], int m, int n , long long int dp[][1001])
{
	if (n == 0)
		return 1;
	if (m == 0)
		return 0;

	if (dp[m][n] != -1)
		return dp[m][n];
	if (S[m - 1] > n)
	{
		dp[m][n] = ans(S, m - 1, n, dp);
	}
	else
	{
		dp[m][n] = ans(S, m, n - S[m - 1], dp) + ans(S, m - 1, n, dp);
	}
	return dp[m][n];
}
long long int counttopdown( int S[], int m, int n )
{
	long long int dp[1001][1001];
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 1001; j++)
			dp[i][j] = -1;
	}
	if (n == 0)
		return 1;
	if (m == 0)
		return 0;

	return ans(S, m, n, dp);

	//code here.
}

//*********************METHOD-1**************//
// Using bottom up approach
// TC = O(m*n)
long long int countbottomup( int S[], int m, int n )
{
	long long int dp[1001][1001];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			dp[i][j] = -1;
	}

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0)
				dp[i][j] = 0;
			if (j == 0)
				dp[i][j] = 1;
		}
	}

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (S[i - 1] <= j)
			{
				dp[i][j] = dp[i][j - S[i - 1]] + dp[i - 1][j];
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[m][n];

	//code here.
}

int main()

{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int arr[m];
		for (int i = 0; i < m; i++)
			cin >> arr[i];
		cout << counttopdown(arr, m, n) << endl;
	}


	return 0;
}