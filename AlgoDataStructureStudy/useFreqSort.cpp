#include <iostream>
#include "MySort.h"

int compCnt;
int swapCnt;

using namespace std;

int main()
{
	vector<int> v = { 4,7,2,5,1,9,6,4,3,11,16,18,14,19 };
	FreqSort(v);
	for (auto e : v)
		cout << e << " ";
}