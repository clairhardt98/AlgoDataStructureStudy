#include <iostream>
#include "Stopwatch.h"
#include "MySort.h"

using namespace std;
int compCnt;
int swapCnt;

int main()
{
	vector<int> v = { 7,4,3,9,8,1,2,5,6 };
	Stopwatch sw;

	cout << "BubbleSort1 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		bubbleSort1(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "비교 횟수: " << compCnt << " 교환 횟수: " << swapCnt << endl;
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;

	cout << "BubbleSort2 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		bubbleSort2(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "비교 횟수: " << compCnt << " 교환 횟수: " << swapCnt << endl;
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;

	cout << "BubbleSort3 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		bubbleSort3(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "비교 횟수: " << compCnt << " 교환 횟수: " << swapCnt << endl;
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;

	cout << "SelectionSort1 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		SelectionSort1(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "비교 횟수: " << compCnt << " 교환 횟수: " << swapCnt << endl;
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;

	cout << "SelectionSort2 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		SelectionSort2(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "비교 횟수: " << compCnt << " 교환 횟수: " << swapCnt << endl;
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;

	cout << "InsertionSort 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		InsertionSort(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "비교 횟수: " << compCnt << " 교환 횟수: " << swapCnt << endl;
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;

	cout << "ShellSort 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		ShellSort(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "비교 횟수: " << compCnt << " 교환 횟수: " << swapCnt << endl;
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;

	cout << "QuickSort 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		swapCnt = compCnt = 0;
		QuickSort(v, 0, v.size() - 1);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "비교 횟수: " << compCnt << " 교환 횟수: " << swapCnt << endl;
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;
	cout << "MergeSort 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		MergeSort(v, 0, v.size() - 1);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;
	cout << "HeapSort 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		HeapSort(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	cout << "비교 횟수: " << compCnt << " 교환 횟수: " << swapCnt << endl;
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;
	cout << "FreqSort 100000회 반복 시간 측정)" << endl;
	sw.start();
	for (int i = 0; i < 100000; i++)
	{
		FreqSort(v);
		v = { 7,4,3,9,8,1,2,5,6 };
	}
	sw.stop();
	//cout << "비교 횟수: " << compCnt << " 교환 횟수: " << swapCnt << endl;
	cout << "걸린 시간 : " << sw.getElapsedTime() << "ms" << endl;

}
