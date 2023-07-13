#pragma once
#include <vector>
#include <string>
#include <iostream>
std::vector<int> SetTable(std::string& word);
std::vector<int> SetSkipTable(const std::string& word);
int BruteForce(std::string& target, std::string& word)
{
	for (int i = 0; i < target.size() - word.size() + 1; i++)
	{

		bool Flag = true;

		for (int j = 0; j < word.size(); j++)
		{
			if (target[i + j] != word[j])
			{

				Flag = false;
				break;
			}

		}
		if (Flag)
		{
			return i;
			break;
		}
	}
	return -1;
}
int KMP(std::string& target, std::string& word)
{
	std::vector<int> LPS = SetTable(word);
	/*for (auto e : LPS)
		std::cout << e << " ";*/
		//패턴 길이 - 패턴 인덱스 - 1 => 이동량

	for (int i = 0; i < target.size(); i++)
	{
		std::cout << target << std::endl;
		bool Flag = false;
		int printCnt = i;
		for (int a = 0; a < printCnt; a++)
			std::cout << " ";
		for (int j = 0; j < word.size(); j++)
		{
			if (target[i + j] != word[j])
			{
				std::cout << "|";
				if (j > 1)
					i += LPS[j - 1];
				break;
			}
			std::cout << "+";
			if (j == word.size() - 1)
				Flag = true;
		}
		std::cout << std::endl;
		for (int a = 0; a < printCnt; a++)
			std::cout << " ";
		std::cout << word << std::endl;
		if (Flag)
			return i;
	}
	return -1;
}
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
int BoyerMoore(std::string& target, std::string& word)
{
	std::vector<int> Table = SetSkipTable(word);

	int i = 0;
	while (1)
	{
		if (i + word.size() >= target.size()) return -1;
		bool flag = true;
		int move = Table[word.size()-1];
		for (int j = word.size() - 1; j >= 0; j--)
		{
			if (target[i + j] != word[j])
			{
				flag = false;
				for (int k = word.size() - 2; k >= 0; k--)
				{
					if (word[k] == target[i + j])
					{
						move = Table[k];
						//break;
					}
				}
			}
			if (!flag)break;
		}
		if (flag)
			return i;
		else
			i += move;
	}
}
std::vector<int> SetSkipTable(const std::string& word)
{
	std::vector<int> Table(word.size());
	//일단 만들고
	for (int i = 0; i < word.size() - 1; i++)
	{
		Table[i] = word.size() - i - 1;
	}
	
	Table[word.size() - 1] = word.size();

	
	//중복된 애들은 최소값으로 바꿔주자
	for (int i = 0; i < word.size(); i++)
	{
		for (int j = 0; j < word.size(); j++)
		{
			if (i!=j && word[i] == word[j])
			{
				if (Table[i] > Table[j])
					Table[i] = Table[j];
			}
		}
	}

	for (auto e : Table)
		std::cout << e << " ";

	
	
	return Table;
}