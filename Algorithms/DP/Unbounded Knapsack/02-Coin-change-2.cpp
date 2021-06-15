#include<bits/stdc++.h>
using namespace std;
// Find minimum number of coins that make a given value
//Special problem - here top row is initialised by INT_MAX-1

// NOTE---->Yet to understand the 1d DP solution

//*********************METHOD-1**************//
// Using recursion
// TC = Exponential
int ans(int coins[], int M, int V)
{
	if (M == 0)
		return INT_MAX - 1;
	if (V == 0)
		return 0;



	if (coins[M - 1] <= V)
		return min(1 + ans(coins, M, V - coins[M - 1]), ans(coins, M - 1, V));
	else
		return ans(coins, M - 1, V);
}
int minCoins(int coins[], int M, int V)
{
	int x = ans(coins, M, V);
	if (x == INT_MAX - 1)
		return -1;
	else
		return x;
}


//*********************METHOD-2**************//
//recursion with memoization
// TC = O(m*n)
int anstopdown(int coins[], int M, int V, int dp[][1001])
{
	if (M == 0)
		return INT_MAX - 1;
	if (V == 0)
		return 0;

	if (dp[M][V] != -1)
		return dp[M][V];

	if (coins[M - 1] <= V)
		return dp[M][V] = min(1 + anstopdown(coins, M, V - coins[M - 1], dp), anstopdown(coins, M - 1, V, dp));
	else
		return dp[M][V] = anstopdown(coins, M - 1, V, dp);
}
int minCoinstopdown(int coins[], int M, int V)
{
	int dp[1001][1001];
	for (int i = 0; i <= M; i++)
	{
		for (int j = 0; j <= V; j++)
		{
			dp[i][j] = -1;
		}
	}
	int x = anstopdown(coins, M, V, dp);
	if (x == INT_MAX - 1)
		return -1;
	else
		return x;
}

//*********************METHOD-1**************//
// Using bottom up approach
// TC = O(m*n)
int minCoinsbottomup(int coins[], int M, int V)
{
	int dp[M + 1][V + 1];
	for (int i = 0; i <= M; i++)
	{
		for (int j = 0; j <= V; j++)
		{
			dp[i][j] = -1;
			if (j == 0)
				dp[i][j] = 0;
			if (i == 0)
				dp[i][j] = INT_MAX - 1;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (coins[i - 1] <= j)
			{
				dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	if (dp[M][V] != INT_MAX - 1)
		return dp[M][V];
	return -1;
	// Your code goes here
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
		cout << minCoinsbottomup(arr, m, n) << endl;
	}


	return 0;
}