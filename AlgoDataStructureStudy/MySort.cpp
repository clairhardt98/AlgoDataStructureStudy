#include "MySort.h"
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
	//책 방법
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
	//영상 방법
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
	//밑작업
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
	//만나기 전까지
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
		QuickSort(v,pl,right);
	if (pr > left)
		QuickSort(v, left , pr);
}

void MergeSort(std::vector<int>& v, int left, int right)
{
	int center = (left + right) / 2;
	if (left < right)
	{
		MergeSort(v, left, center);
		MergeSort(v, center + 1, right);
		__merge(v, left, right);
	}
}
void __merge(std::vector<int>& v, int left, int right)
{
	static std::vector<int> sortedArr(v.size());
	
	int center = (left + right) / 2;
	int v1Idx = left;
	int v2Idx = center + 1;
	int sortedArrIdx = left;
	while (v1Idx <= center && v2Idx <= right)
	{
		if (v[v1Idx] < v[v2Idx])
		{
			sortedArr[sortedArrIdx++] = v[v1Idx];
			v1Idx++;
		}
		else
		{
			sortedArr[sortedArrIdx++] = v[v2Idx];
			v2Idx++;
		}
	}
	if (v1Idx > center)
	{
		for (int i = v2Idx; i <= right; i++)
		{
			sortedArr[sortedArrIdx++] = v[i];
		}
	}
	else
	{
		for (int i = v1Idx; i <= center; i++)
		{
			sortedArr[sortedArrIdx++] = v[i];
		}
	}

	for (int i = left; i <= right; i++)
	{
		v[i] = sortedArr[i];
	}
}
void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}