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

	while (!x.empty())
	{
		int temp = x.back() - '0';
		dec += temp * mul;
		x.pop_back();
		mul *= N;
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