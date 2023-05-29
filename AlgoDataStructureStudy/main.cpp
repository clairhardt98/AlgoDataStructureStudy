#include <iostream>
#include <string>
#include <algorithm>

using namespace std;



string DecimalConversion(int N, int K, string x);


int main()
{
	int N, K;
	string src;
	cout << "�Է� �����ʹ� �� ���� : ";
	cin >> N;
	cout << "���� �Է��Ͻÿ�: ";
	cin >> src;
	cin.ignore();
	cout << "��� �����ʹ� �� ����: ";
	cin >> K;
	if (K < 1 || K>36)
	{
		cout << "�߸��� ���� �Է��Դϴ�.\n";
		exit(1);
	}
	cout << N << "���� " << src << "�� " << K << "������ " << DecimalConversion(N, K, src) << "�Դϴ�.\n";
}

string DecimalConversion(int N, int K, string x)
{
	string answer = "";
	string charArr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//�ϴ� 10������ ��������
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
	//�ٲ� ���� ���ϴ� ������ ��������

	while (dec)
	{
		int temp = dec % K;
		answer += charArr[temp];
		dec /= K;
	}
	reverse(answer.begin(), answer.end());
	return answer;

}