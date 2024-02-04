#include <bits/stdc++.h>

using namespace std;

int main()
{
	// ������ ��ġ�� �ִ밡 �ǵ��� ä���
	// i�� °�� ������ �־��� ���� ���� �ʾ��� ��?

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
	vector<int> curWeight(N + 1); // dp[i]������ ����

	dp[0][0] = dp[0][1] = 0;
	curWeight[0] = 0;

	for (int i = 1; i <= N; i++)
	{
		//dp[i][0] : ���� �ڽ��� ���� ���� �ʴ� �ִ밪 -> max(dp[i-1][0], dp[i-1][1])
		//dp[i][1] : ���� �ڽ��� ���� ������ ���� �ִ밪 -> �ڷ� ���ư��鼭 ���԰� ������ ��� ã�Ƽ� �ڱ� �ڽ� �� ���ϱ� -> dp[i][0]���� dp[0][0]���� Ž��
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		int temp = 0;
		for (int j = i; j >= 0; j--)
		{
			int w = curWeight[j]; // w�� ���� ����
			if (w + stuffs[i-1].first > K) continue; //���� ���� �־��� �� ��ġ�� �н�
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