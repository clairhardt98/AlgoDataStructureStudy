#include "MyHash.h"
#include <random>
#include <string>
#include <vector>
using namespace std;



int main()
{
	srand(time(NULL));

	Student stArr[26];
	std::vector<int> randomNums;
	char c = 'A';
	HashTable stHashTable;
	for (int i = 0; i < 26; i++)
	{
		string temp = string(1, c + i);
		int r = rand() % 50;
		stArr[i] = { r , std::string(temp)};
		randomNums.push_back(r);
		stHashTable.Add(stArr[i]);
	}
	stHashTable.Print();
	//stHashTable.Remove(56);
	int r = randomNums[rand() % randomNums.size()];
	cout << "Remove st no: " << r << endl;
	stHashTable.Remove(r);
	cout << "after remove" << endl;
	stHashTable.Print();
	
}