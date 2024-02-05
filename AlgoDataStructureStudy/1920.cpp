#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int input;
		cin >> input;
		cout << binary_search(arr.begin(), arr.end(), input) << '\n';
	}
}