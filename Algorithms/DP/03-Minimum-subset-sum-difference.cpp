//https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/

#include <bits/stdc++.h>
using namespace std;

int minDifference(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}

	// sum1 and sum2=sum-sum1
	// we need to minimize abs(sum2-sum1)=abs(sum-2*sum1)=sum-2*sum1 ....where sum1<=sum/2



	//here comes the code of subset sum problem
	int dp[n + 1][sum + 1];

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (i == 0)
				dp[i][j] = 0;
			if (j == 0)
				dp[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (a[i - 1] <= j)
			{
				dp[i][j] = max(dp[i - 1][j - a[i - 1]], dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}


	//at this point we are having a dp array with the answer at each and every cell for different conditions
	//now to make difference min we need sum1 to be max so iterating from sum/2 to 0
	//is iteration m agar kahin pr koi subset mila to vhi pr apna minimum answer aayega
	for (int i = sum / 2; i >= 0; i--)
	{
		if (dp[n][i] == 1)
		{
			return sum - 2 * i;
		}
	}

	return 0;
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int ans = minDifference(a, n);
	cout << ans << endl;
}