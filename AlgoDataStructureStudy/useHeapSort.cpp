#include <iostream>
#include "MySort.h"

int compCnt;
int swapCnt;

using namespace std;
int main()
{
	vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };
	HeapSort(v);
	for (auto e : v)
		cout << e << " ";
}