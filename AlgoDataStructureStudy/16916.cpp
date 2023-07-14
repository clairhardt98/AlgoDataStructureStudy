#include <iostream>
#include <vector>

using namespace std;
std::vector<int> SetTable(std::string& word)
{
	std::vector<int> temp(word.size());
	temp[0] = -1;
	int idx = 0;
	int cnt = 0;
	for (int i = 1; i < word.size(); i++)
	{
		if (word[i] != word[idx])
		{
			temp[i] = cnt = 0;
		}
		else
		{
			temp[i] = ++cnt;
			idx++;
		}
	}
	return temp;
}
int KMP(std::string& target, std::string& word)
{
	std::vector<int> LPS = SetTable(word);
	/*for (auto e : LPS)
		std::cout << e << " ";*/
		//패턴 길이 - 패턴 인덱스 - 1 => 이동량

	for (int i = 0; i < target.size(); i++)
	{
		bool Flag = false;
		int printCnt = i;
		
		for (int j = 0; j < word.size(); j++)
		{
			if (target[i + j] != word[j])
			{
				if (j > 1)
					i += LPS[j - 1];
				break;
			}
			if (j == word.size() - 1)
				Flag = true;
		}

		if (Flag)
			return i;
	}
	return -1;
}
int main()
{
	std::string s;
	std::string p;
	cin >> s;
	cin >> p;
	if (KMP(s, p)!=-1)
		std::cout << 1;
	else
		std::cout << 0;
}