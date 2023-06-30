#include <iostream>
#include <vector>

using namespace std;

int chess[20];
int N;
int ans = 0;

bool Check(int num);
void Queen(int x);
void Print(int N);
int main()
{
	cout << "N? ";
	cin >> N;
	Queen(0);
	cout << ans;
}
void Queen(int x)
{
	if (x == N)
	{
		Print(N);
		cout << endl;
		ans++;
	}
	else 
	{
		for (int i = 0; i < N; i++)
		{
			//x행 i열에 퀸을 놔봐서 놓을 수 있으면 다음 행으로, 아니라면 다음 열에 놓아봄
			chess[x] = i;
			if (Check(x))
				Queen(x + 1);
		}
	}
	
}
bool Check(int num)
{
	//지금 놓은 위치에서 가로 세로 대각 판단해서 중복되면 false반환, 중복안되면 true반환
	for (int i = 0; i < num; i++)
	{
		if (chess[i] == chess[num] || abs(chess[num] - chess[i]) == num - i)
			return false;
	}
	return true;
}

void Print(int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (chess[i] == j)
				cout << "■";
			else
				cout << "□";
		}
		cout << endl;
	}
}