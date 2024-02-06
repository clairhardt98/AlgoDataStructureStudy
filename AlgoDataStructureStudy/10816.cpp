#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;

	vector<int> Cards(n);
	for (int i = 0; i < n; i++)
	{
		cin >> Cards[i];
	}

	int m;
	cin >> m;

	

	sort(Cards.begin(), Cards.end());

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;

		cout << upper_bound(Cards.begin(), Cards.end(), temp) - lower_bound(Cards.begin(), Cards.end(), temp) << ' ';
	}

	
	return 0;
}