#include <bits/stdc++.h>

using namespace std;

int main()
{
	// 물건의 가치가 최대가 되도록 채우기
	// i번 째의 물건을 넣었을 때와 넣지 않았을 때?

	int N, K;

	cin >> N >> K;

	vector<pair<int, int>> stuffs;

	for (int i = 0; i < N; i++)
	{
		int w, v;

		cin >> w >> v;
		stuffs.push_back({ w,v });
	}

	vector<vector<int>> dp(N + 1, vector<int>(2, 0)); //
	vector<int> curWeight(N + 1); // dp[i]에서의 무게

	dp[0][0] = dp[0][1] = 0;
	curWeight[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		//dp[i][0] : 현재 자신의 값이 들어가지 않는 최대값 -> max(dp[i-1][0], dp[i-1][1])
		//dp[i][1] : 현재 자신의 값이 무조건 들어가는 최대값 -> 뒤로 돌아가면서 무게가 가용인 경우 찾아서 자기 자신 값 더하기 -> dp[i][0]부터 dp[0][0]까지 탐색
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		int temp = 0;
		for (int j = i; j >= 0; j--)
		{
			int w = curWeight[j]; // w는 현재 무게
			if (w + stuffs[i-1].first > K) continue; //현재 무게 넣었을 때 넘치면 패스
			if (temp < stuffs[i-1].second + dp[j][0])
			{
				temp = stuffs[i-1].second + dp[j][0];
				curWeight[i] = curWeight[j] + stuffs[i-1].first;
			}
		}
		dp[i][1] = temp;
	}

	for (int i = 0; i<dp.size();i++)
	{
		cout << i<<": "<<dp[i][0] << " " << dp[i][1] << endl;
	}
	/*cout << max(dp[N][0], dp[N][1]);*/
	
}