#include <bits/stdc++.h>

using namespace std;

// 북동남서
int di[4] = { -1,0,1,0 };
int dj[4] = { 0,1,0,-1 };

int solution(vector<vector<int>> office, int r, int c, vector<string> move)
{
	int dir = 0;
	int row = office.size();
	int col = office[0].size();

	//맨 처음칸은 무조건 청소함
	int answer = office[r][c];
	office[r][c] = 0;

	for (size_t i = 0; i < move.size(); i++)
	{
		if (move[i] == "go")
		{
			int ni = r + di[dir];
			int nj = c + dj[dir];

			if (ni >= 0 && ni < row && nj >= 0 && nj < col && office[ni][nj] != -1)
			{
				//조건 만족하면 다음 좌표 0으로 만들기, answer 갱신 후 이동
				answer += office[ni][nj];
				office[ni][nj] = 0;
				r = ni;
				c = nj;
			}

		}
		else if (move[i] == "right")
		{
			dir = (dir + 1) % 4;
		}
		else if (move[i] == "left")
		{
			dir = (dir - 1) % 4;
		}
	}

	return answer;
}
int main()
{
	vector<vector<int>> office =
	{
		{5,-1,4},
		{6,3,-1},
		{2,-1,1}
	};
	vector<string> move =
	{
		"go","go","right","go","right","go","left","go"
	};

	cout << solution(office, 1, 0, move);
}