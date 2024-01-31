#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	vector<int> d;
	d.push_back(0);
	for (size_t i = 1; i <= n; i++)
	{
		int input;
		cin >> input;
		d.push_back(d.back() + input);
	}
	for (size_t i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << d[b] - d[a - 1] << '\n';
	}
}