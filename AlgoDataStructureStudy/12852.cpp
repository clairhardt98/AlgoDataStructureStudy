#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	int n;
	cin >> n;
	vector<int> dp(1000001);
	vector<int> pre(1000001);
	
	dp[0] = 0;
	dp[1] = 0;
	

	for (size_t i = 2; i <= n; i++)
	{
		//default
		dp[i] = dp[i - 1] + 1;
		pre[i] = i - 1;

		if (i % 3 == 0 && dp[i] > dp[i/3] + 1)
		{
			dp[i] = dp[i / 3] + 1;
			pre[i] = i / 3;
		}
		if (i % 2 == 0 && dp[i] > dp[i/2] + 1)
		{
			dp[i] = dp[i / 2] + 1;
			pre[i] = i / 2;
		}
	}

	cout << dp[n] << '\n';

	int i = n;
	while (true)
	{
		cout << i << ' ';
		if (i == 1) break;
		i = pre[i];
	}
}