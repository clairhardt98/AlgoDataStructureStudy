#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<pair<int, int>> meetings;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		meetings.push_back({ b,a });
	}


	sort(meetings.begin(), meetings.end());

	auto iter = meetings.begin();

	int cnt = 1; 
	int prevEnd = meetings[0].first;

	for (int i = 1; i < n; i++) 
	{
		if (meetings[i].second >= prevEnd) 
		{
			cnt++;
			prevEnd = meetings[i].first;
		}
	}
	cout << cnt;
}