#include <iostream>
#include <vector>
#include "Stopwatch.h"



using namespace std;
void SelectionSort1(vector<int>& v);
void SelectionSort2(vector<int>& v);
void PrintArr(vector<int>& v,int,int);
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	vector<int> v = { 2,1,6,8,7,9,4,3,5 };
	cout << "SelectionSort1)" << endl;
	SelectionSort1(v);
	cout << endl;
	for (auto e : v)
		cout << e << " ";

	v = { 2,1,6,8,7,9,4,3,5 };
	cout << endl << endl;
	cout << "SelectionSort2)" << endl;
	SelectionSort2(v);
	cout << endl;
	for (auto e : v)
		cout << e << " ";

}

void SelectionSort1(vector<int>& v)
{
	//책 방법
	for (int i = 0; i < v.size() - 1; i++)
	{
		int min = v[i];
		int targetidx = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < min)
			{
				min = v[j];
				targetidx = j;
			}
		}
		if (i != targetidx)
		{
			PrintArr(v, i, targetidx);
			Swap(v[i], v[targetidx]);
		}
	}
}
void SelectionSort2(vector<int>& v)
{
	//영상 방법
	for (int i = 0; i < v.size() - 1; i++)
	{
		bool flag = false;
		int min = v[i];
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < min)
			{
				PrintArr(v, i, j);
				Swap(v[i], v[j]);
				flag = true;
				break;
			}
		}
		if (flag)
			i--;
	}
}

void PrintArr(vector<int>& v,int sorted, int unsorted)
{
	for (int i = 0; i<v.size(); i++)
	{
		if (i == sorted)
			cout << "* ";
		else if (i == unsorted)
			cout << "+ ";
		else
			cout << "  ";
	}
	cout << endl;
	for (auto e : v)
		cout << e<<" ";
	cout << endl;

}