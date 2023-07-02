#include <iostream>
#include <vector>

using namespace std;
void ShellSort(vector<int>& v);
void Swap(int&, int&);

int swapcnt = 0;
int compcnt = 0;
int main()
{
	vector<int>v = { 8,1,4,2,7,6,3,5 };
	ShellSort(v);
	cout << "비교 횟수 : " << compcnt << ", 교환 횟수 : " << swapcnt << endl;
	for (auto e : v)
		cout << e << " ";
}

void ShellSort(vector<int>& v)
{
	int h = v.size();
	//밑작업
	for (int i = h / 2; i > 0; i /= 2)
	{
		for (int j = 0; j < h - i; j++)
		{
			compcnt++;
			if (v[j] > v[j + i])
			{
				swapcnt++;
				Swap(v[j], v[i]);
			}
		}
	}
	for (int i = 1; i < h; i++)
	{
		int temp = v[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			compcnt++;
			if (v[j] > temp)
			{
				swapcnt++;
				v[j + 1] = v[j];
			}
			else
				break;
		}
		v[j + 1] = temp;
	}

}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}