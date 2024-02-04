#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> a;
	vector<int>b;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		a.push_back(input);
	}
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		b.push_back(input);
	}
	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());

	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		answer += a[i] * b[i];
	}

	cout << answer;
}