#include <iostream>
#include <vector>
#include "MySort.h"
using namespace std;

int swapCnt = 0;
int compCnt = 0;
int main()
{
	vector<int> v = { 5,2,3,1,7,9,4,8 };
	MergeSort(v, 0, v.size() - 1);
	for (auto e : v)
		cout << e << " ";
}