#include <bits/stdc++.h>

using namespace std;

int solution(vector<int>A, vector<int>B)
{
	//A, B를 정렬
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	//인덱스 하나씩 올려가면서 체킹
	//A와 B의 인덱스를 따로 두고 현재 인덱스에서 B의 값이 더 큰 경우에는 양쪽의 인덱스를 동시에 증가, answer++
	//B가 더 작으면 클 때까지 B만 올림
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