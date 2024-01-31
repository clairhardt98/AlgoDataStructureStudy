#include <bits/stdc++.h>

using namespace std;

int main()
{
	struct node
	{
		int d;
		vector<int> arr;
		node(int d, vector<int> arr)
			:d(d)
		{
			this->arr = move(arr);
		}

		bool operator<(const node& other) const
		{
			return d < other.d;
		}
	};
	vector<node> dp(100001);

	int n;
	cin >> n;
	dp[0] = node(0, {});
	dp[1] = node(0, { 1 });
	dp[2] = node(1, { 1,2 });
	dp[3] = node(1, { 1,3 });


	for (size_t i = 4; i <= n; i++)
	{
		node temp1(INT_MAX, {});
		node temp2(INT_MAX, {});
		temp1 = (i % 3 == 0) ? dp[i / 3] : temp1;
		temp2 = (i % 2 == 0) ? dp[i / 2] : temp2;


		node temp3 = min(min(temp1, temp2), dp[i - 1]);
		temp3.arr.push_back(i);
		dp[i] = node(temp3.d + 1, temp3.arr);
		
	}

	cout << dp[n].d<<'\n';
	while (!dp[n].arr.empty())
	{
		cout << dp[n].arr.back();
		dp[n].arr.pop_back();
	}
}