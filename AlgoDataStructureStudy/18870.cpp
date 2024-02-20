#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> temp(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		temp[i] = arr[i];
	}

	sort(temp.begin(), temp.end());
	
	// �ߺ��� ���Ҹ� �������� ������, ����
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	// �̺�Ž������ 

	for (auto e : arr)
	{
		auto t = lower_bound(temp.begin(), temp.end(), e);
		cout << distance(temp.begin(), t) << ' ';
	}
	return 0;
}