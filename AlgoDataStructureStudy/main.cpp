#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



string DecimalConversion(int N, int K, string x);


int main()
{
	int N, K;
	string src;
	cout << "입력 데이터는 몇 진수 : ";
	cin >> N;
	cout << "값을 입력하시오: ";
	cin >> src;
	cin.ignore();
	cout << "출력 데이터는 몇 진수: ";
	cin >> K;
	if (K < 1 || K>36)
	{
		cout << "잘못된 진수 입력입니다.\n";
		exit(1);
	}
	cout << N << "진수 " << src << "는 " << K << "진수로 " << DecimalConversion(N, K, src) << "입니다.\n";
}

string DecimalConversion(int N, int K, string x)
{
	string answer = "";
	string charArr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//일단 10진수로 돌려놓자
	int dec = 0;
	int mul = 1;
	bool emptyFlag = false;

	while (!emptyFlag)
	{
		for (int i = 0; i < charArr.size(); i++)
		{
			if (x.empty())
			{
				emptyFlag = true;
				break;
			}
			if (charArr[i] == x.back())
			{
				dec += i * mul;
				mul *= N;
				x.pop_back();

			}
		}
	}
	//바꾼 수를 원하는 진수로 돌려놓기

	while (dec)
	{
		int temp = dec % K;
		answer += charArr[temp];
		dec /= K;
	}
	reverse(answer.begin(), answer.end());
	return answer;

}