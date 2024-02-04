#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr;

	//pq에 다 넣기
	//뽑아서 arr에 하나 씩 다 넣으면서 판단해보기

	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		pq.push(input);
	}

	int answer = 0;
	int cnt = 0;
	while (!pq.empty())
	{
		cnt++;
		int temp = pq.top() * cnt;
		pq.pop();

		answer = answer < temp ? temp : answer;
	}

	cout << answer;
}