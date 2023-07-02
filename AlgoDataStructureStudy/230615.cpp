#include <iostream>
#include <vector>
using namespace std;
void print(vector<vector<int>>&v);
void Hanoi(vector<vector<int>>&v , int N, int src ,int dest);

int printN = 0;

int main()
{
	int N;
	cout << "초기�?: " ;
	cin >> N;
	printN = N;
	vector<vector<int>> v(3);

	for (int i = N; i >= 1; i--)
	{
		v[0].push_back(i);
	}
	print(v);
	Hanoi(v, N, 0, 2);
}

void print(vector<vector<int>>&v)
{
	
	for (int i = printN-1; i >=0; i--)
	{
		cout << "\t[";
		if (i >= v[0].size())
			cout << " ";
		else
			cout << v[0][i];
		cout << "]" << "\t[";
		if (i >= v[1].size())
			cout << " ";
		else
			cout << v[1][i]; 
		cout << "]" << "\t[";
		if (i >= v[2].size())
			cout << " ";
		else
			cout << v[2][i];
		cout << "]" << endl;
	}
	cout << "\t A\t B\t C" << endl << endl;
}

void Hanoi(vector<vector<int>>& v, int N, int src, int dst)
{
	if (N == 0) return;
	int newdst = 3 - src - dst;
	
	Hanoi(v, N - 1, src, newdst);
	
	int temp = v[src].back();
	v[src].pop_back();
	v[dst].push_back(temp);
	print(v);
	
	Hanoi(v, N - 1, newdst, dst);
}