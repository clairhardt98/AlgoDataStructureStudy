#include "MySort.h"
#include <iostream>

void bubbleSort1(std::vector<int>& v)
{
	compCnt = swapCnt = 0;
	bool flag = false;
	while (!flag)
	{
		flag = true;
		for (int i = 0; i < v.size() - 1; i++)
		{
			compCnt++;
			if (v[i] > v[i + 1])
			{
				Swap(v[i], v[i + 1]);
				swapCnt++;
				flag = false;
			}
		}
	}
}
void bubbleSort2(std::vector<int>& v)
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
				Swap(v[i], v[i + 1]);
				swapCnt++;
				flag = false;
			}
		}
		idx++;
	}
}
void bubbleSort3(std::vector<int>& v)
{
	//������ �ϴٰ� ���� ���� ���ķ� ��ȯ�� �̷������ �ʾҴٸ�, �� ���ķδ� �����ε� �� �ʿ䰡 ����
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
				Swap(v[i], v[i + 1]);
				swapCnt++;
				flag = false;
				last = i;
			}
		}
		j = last;
	}

}
void SelectionSort1(std::vector<int>& v)
{
	compCnt = swapCnt = 0;
	//å ���
	for (int i = 0; i < v.size() - 1; i++)
	{
		int min = v[i];
		int targetidx = i;
		for (int j = i + 1; j < v.size(); j++)
		{
			compCnt++;
			if (v[j] < min)
			{
				min = v[j];
				targetidx = j;
			}
		}
		if (i != targetidx)
		{
			swapCnt++;
			Swap(v[i], v[targetidx]);
		}
	}
}
void SelectionSort2(std::vector<int>& v)
{
	compCnt = swapCnt = 0;
	//���� ���
	for (int i = 0; i < v.size() - 1; i++)
	{
		bool flag = false;
		int min = v[i];
		for (int j = i + 1; j < v.size(); j++)
		{
			compCnt++;
			if (v[j] < min)
			{
				swapCnt++;
				Swap(v[i], v[j]);
				flag = true;
				break;
			}
		}
		if (flag)
			i--;
	}
}
void InsertionSort(std::vector<int>& v)
{
	compCnt = swapCnt = 0;
	int h = v.size();
	for (int i = 1; i < h; i++)
	{
		int temp = v[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			compCnt++;
			if (v[j] > temp)
			{
				swapCnt++;
				v[j + 1] = v[j];
			}
			else
				break;
		}
		v[j + 1] = temp;
	}
}
void ShellSort(std::vector<int>& v)
{
	compCnt = swapCnt = 0;
	int h = v.size();
	//���۾�
	for (int i = h / 2; i > 0; i /= 2)
	{
		for (int j = 0; j < h - i; j++)
		{
			compCnt++;
			if (v[j] > v[j + i])
			{
				swapCnt++;
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
			compCnt++;
			if (v[j] > temp)
			{
				swapCnt++;
				v[j + 1] = v[j];
			}
			else
				break;
		}
		v[j + 1] = temp;
	}

}
void QuickSort(std::vector<int>& v, int left, int right)
{
	int pl = left;
	int pr = right;
	int pivot = v[(right + left) / 2];
	//������ ������
	while (1)
	{
		while (v[pl] < pivot)
		{
			compCnt++;
			pl++;
		}
		while (v[pr] > pivot)
		{
			compCnt++;
			pr--;
		}
		if (pl <= pr)
		{
			swapCnt++;
			Swap(v[pl], v[pr]);
			pl++;
			pr--;
		}
		if (pl > pr)break;
	}
	if (pl < right)
		QuickSort(v, pl, right);
	if (pr > left)
		QuickSort(v, left, pr);
}

void MergeSort(std::vector<int>& v, int start, int end)
{
	using std::cout;
	using std::endl;
	
	if (v.size() <= 1)return;
	int center = (start + end) / 2;
	
	MergeSort(v, start, center);
	MergeSort(v, center+1, end);
	
	int v1_idx = 0;
	int v2_idx = 0;
	std::vector<int> v3;
	while (1)
	{
		if (v1_idx < v1.size() && v2_idx < v2.size())
		{
			if (v1[v1_idx] > v2[v2_idx])
			{
				v3.push_back(v2[v2_idx]);
				v2_idx++;
			}
			else
			{
				v3.push_back(v1[v1_idx]);
				v1_idx++;
			}
		}
		else
			break;
	}
	for (int i = v1_idx; i < v1.size(); i++)
	{
		v3.push_back(v1[i]);
	}
	for (int i = v2_idx; i < v2.size(); i++)
	{
		v3.push_back(v2[i]);
	}
	v = v3;
}
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}