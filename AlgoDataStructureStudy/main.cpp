#include <iostream>
using namespace std;

//n단의 숫자 모래시계를 출력하는 프로그램 작성

int main()
{
	int N;
	cout << "몇 단? : ";
	cin >> N;
	int cnt = N;
	int spaceCnt = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < spaceCnt; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < cnt * 2 - 1; j++)
		{
			cout << i + 1;

		}
		for (int j = 0; j < spaceCnt; j++)
		{
			cout << " ";
		}
		cnt--;
		spaceCnt++;
		cout << endl;
	}
	cnt++;
	spaceCnt-=2;

	for (int i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < spaceCnt; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < cnt * 2 + 1; j++)
		{
			cout << i;
		}
		for (int j = 0; j < spaceCnt; j++)
		{
			cout << " ";
		}
		cnt++;
		spaceCnt--;
		cout << endl;
	}
	return 0;
}