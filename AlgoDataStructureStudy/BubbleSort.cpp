#include <iostream>
#include <vector>
#include "Stopwatch.h"
using namespace std;

void Swap(int& a, int& b);

void bubbleSort1(vector<int> &v);
void bubbleSort2(vector<int> &v);
void bubbleSort3(vector<int> &v);

int compCnt = 0;
int swapCnt = 0;
int main()
{
	vector<int> v = { 7,4,3,9,8,1,2,5,6 };
	cout << "정렬 전)\n";
	for (auto e : v)
		cout << e << " ";
	cout << endl;
	bubbleSort1(v);
	cout << "BubbleSort1)" << endl;
	cout << " 비교 횟수 : " << compCnt << endl;
	cout << " 교환 횟수 : " << swapCnt << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v = { 7,4,3,9,8,1,2,5,6 };
	bubbleSort2(v);
	cout << "BubbleSort2)" << endl;
	cout << " 비교 횟수 : " << compCnt << endl;
	cout << " 교환 횟수 : " << swapCnt << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	v = { 7,4,3,9,8,1,2,5,6 };
	bubbleSort3(v);
	cout << "BubbleSort3)" << endl;
	cout << " 비교 횟수 : " << compCnt << endl;
	cout << " 교환 횟수 : " << swapCnt << endl;
	for (auto e : v)
		cout << e << " ";
	cout << endl;

	Stopwatch sw;
	cout << "BubbleSort1 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		bubbleSort1(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;

	cout << "BubbleSort2 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		bubbleSort2(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;

	cout << "BubbleSort3 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		bubbleSort3(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void bubbleSort1(vector<int> &v)
{
	compCnt = swapCnt = 0;
	bool flag = false;
	while(!flag)
	{
		flag = true;
		for (int i = 0; i < v.size() - 1; i++)
		{
			compCnt++;
			if (v[i] > v[i + 1])
			{
				swap(v[i], v[i + 1]);
				swapCnt++;
				flag = false;
			}
		}
	}
}


void bubbleSort2(vector<int> &v)
{
	compCnt = swapCnt = 0;
	bool flag = false;
	int idx = 0;
	while (!flag)
	{
		flag = true;
		for (int i = 0; i < v.size() - 1 - idx; i++)
		{
			compCnt++;
			if (v[i] > v[i + 1])
			{
				swap(v[i], v[i + 1]);
				swapCnt++;
				flag = false;
			}
		}
		idx++;
	}
}
void bubbleSort3(vector<int>& v)
{
	//정렬을 하다가 일정 시점 이후로 교환이 이루어지지 않았다면, 그 이후로는 앞으로도 할 필요가 없음
	compCnt = swapCnt = 0;
	bool flag = false;


	int j = v.size() - 1;
	int last = 0;
	while (!flag)
	{
		flag = true;
		for (int i = 0; i < j; i++)
		{
			compCnt++;
			if (v[i] > v[i + 1])
			{
				swap(v[i], v[i + 1]);
				swapCnt++;
				flag = false;
				last = i;
			}
		}
		j = last;
	}

}