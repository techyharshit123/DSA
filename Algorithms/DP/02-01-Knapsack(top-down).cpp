#include<bits/stdc++.h>
using namespace std;

int dp[1002][1002]; //n<=1000 and W<=1000;
int knapsack01(int capacity, int wt[], int val[], int n)
{
	if (n == 0 or capacity == 0)
		return 0;

	if (dp[n][capacity] != -1)
		return dp[n][capacity];

	if (wt[n - 1] <= capacity)
	{
		dp[n][capacity] = max( val[n - 1] + knapsack01(capacity - wt[n - 1], wt, val, n - 1), knapsack01(capacity, wt, val, n - 1));
		return dp[n][capacity];
	}
	else
	{
		dp[n][capacity] = knapsack01(capacity, wt, val, n - 1);
		return dp[n][capacity];
	}
}

//Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n)
{
	memset(dp, -1, sizeof(dp)); //initializing the vector of vector by -1
	return  knapsack01(W, wt, val, n);
}

int main()
{
	int n, W;
	cin >> n >> W;

	int val[n];
	int wt[n];

	//inserting the values
	for (int i = 0; i < n; i++)
		cin >> val[i];

	//inserting the weights
	for (int i = 0; i < n; i++)
		cin >> wt[i];

	cout << knapSack(W, wt, val, n);
}