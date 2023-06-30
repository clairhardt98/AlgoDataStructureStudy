#pragma once
#include <vector>

extern int compCnt;
extern int swapCnt;

void Swap(int& a, int& b);

void bubbleSort1(std::vector<int>& v);
void bubbleSort2(std::vector<int>& v);
void bubbleSort3(std::vector<int>& v);
void SelectionSort1(std::vector<int>& v);
void SelectionSort2(std::vector<int>& v);
void InsertionSort(std::vector<int>& v);
void ShellSort(std::vector<int>& v);
void QuickSort(std::vector<int>& v, int left, int right);