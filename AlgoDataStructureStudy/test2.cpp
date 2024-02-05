#include <bits/stdc++.h>

using namespace std;

int solution(vector<int>A, vector<int>B)
{
	//A, B�� ����
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	//�ε��� �ϳ��� �÷����鼭 üŷ
	//A�� B�� �ε����� ���� �ΰ� ���� �ε������� B�� ���� �� ū ��쿡�� ������ �ε����� ���ÿ� ����, answer++
	//B�� �� ������ Ŭ ������ B�� �ø�
	int idxA = 0;
	int idxB = 0;
	int answer = 0;
	while (idxB < B.size())
	{
		if (A[idxA] < B[idxB])
		{
			answer++;
			idxA++;
			idxB++;
		}
		else
		{
			idxB++;
		}
	}

	return answer;
}
int main()
{
	vector<int> A1 = { 5,1,3,7 };
	vector<int> B1 = { 2,2,6,8 };
	vector<int> A2 = { 2,2,2,2 };
	vector<int> B2 = { 1,1,1,1 };

	cout << solution(A1, B1) << '\n';
	cout << solution(A2, B2) << '\n';
}

class Transaction
{
public:
	explicit Transaction(const string& logInfo);
	void LogTransaction(const string& logInfo)const;
};

Transaction::Transaction(const string& logInfo)
{
	LogTransaction(logInfo);
}

class BuyTransaction : public Transaction
{
public:
	BuyTransaction()
		:Transaction(CreateLogString()) {}
	
private:
	static string CreateLogString();
};