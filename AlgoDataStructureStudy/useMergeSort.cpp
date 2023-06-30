#include <iostream>
#include "MySort.h"

using namespace std;
int swapCnt;
int compCnt;  
int main()
{
	vector<int> v = { 7,4,3,9,8,1,2,5,6 };
	MergeSort(v, 0, v.size());
	for (auto e : v)
		cout << e << " ";
}