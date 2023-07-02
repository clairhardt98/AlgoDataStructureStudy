#include <iostream>
#include "Stopwatch.h"

int main()
{
	using namespace std;

	Stopwatch sw;
	sw.start();
	int idx;
	for (int i = 0; i < 1000000000; i++)
	{
		idx = i;
	}
	sw.stop();
	
	cout << sw.getElapsedTime() << endl;
}