#include <iostream>
#include <string>

using namespace std;

int main()
{
	int compCnt = 0;
	string target = "ABABCDEFGHA";
	string word = "ABC";
	
	for (int i = 0; i < target.size()-word.size()+1; i++)
	{
		
		bool Flag = true;
		cout << i << ")" << '\n';
		cout << target << '\n';
		for (int a = 0; a < i; a++)
			cout << " ";
		for (int j = 0; j < word.size(); j++)
		{
			compCnt++;
			if (target[i + j] != word[j])
			{
				cout << "|";
				Flag = false;
				break;
			}
			cout << "+";
		}
		cout << endl;
		
		
		
		for (int a = 0; a < i; a++)
			cout << " ";
		cout << word << endl;
		if (Flag)
		{
			cout << i << "번 째 인덱스에 존재\n";
			break;
		}
	}
	cout << "비교 횟수 : " << compCnt << endl;
}