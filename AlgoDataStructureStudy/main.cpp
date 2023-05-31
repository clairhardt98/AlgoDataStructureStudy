#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string temp1 = "WBWBWBWB";
	string temp2 = "BWBWBWBW";
	vector<string> chess1;
	vector<string> chess2;
	for (int i = 0; i < 4; i++)
	{
		chess1.push_back(temp1);
		chess1.push_back(temp2);
		chess2.push_back(temp2);
		chess2.push_back(temp1);
	}
	
	int N, M;
	cin >> N >> M;
	vector<string> board;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);
	}
	
	int cnt = 2500;
	int tempcnt = 0;
	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			for (int a = 0; a < 8; a++)
			{
				for (int b = 0; b < 8; b++)
				{
					if (board[i + a][j + b] != chess1[a][b])
					{
;						tempcnt++;
					}
				}
			}
			if (tempcnt < cnt)
				cnt = tempcnt;
		}
	}

	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			for (int a = 0; a < 8; a++)
			{
				for (int b = 0; b < 8; b++)
				{
					if (board[i + a][j + b] != chess2[a][b])
					{
						tempcnt++;
					}
				}
			}
			if (tempcnt < cnt)
				cnt = tempcnt;
		}
	}

	

	cout << cnt;
}#include <iostream>
#include <vector>
using namespace std;

int main()
{
	string temp1 = "WBWBWBWB";
	string temp2 = "BWBWBWBW";
	vector<string> chess1;
	vector<string> chess2;
	for (int i = 0; i < 4; i++)
	{
		chess1.push_back(temp1);
		chess1.push_back(temp2);
		chess2.push_back(temp2);
		chess2.push_back(temp1);
	}
	
	int N, M;
	cin >> N >> M;
	vector<string> board;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		board.push_back(str);
	}
	
	int cnt = 2500;
	int tempcnt = 0;
	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			for (int a = 0; a < 8; a++)
			{
				for (int b = 0; b < 8; b++)
				{
					if (board[i + a][j + b] != chess1[a][b])
					{
;						tempcnt++;
					}
				}
			}
			if (tempcnt < cnt)
				cnt = tempcnt;
		}
	}

	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			for (int a = 0; a < 8; a++)
			{
				for (int b = 0; b < 8; b++)
				{
					if (board[i + a][j + b] != chess2[a][b])
					{
						tempcnt++;
					}
				}
			}
			if (tempcnt < cnt)
				cnt = tempcnt;
		}
	}

	

	cout << cnt;
}