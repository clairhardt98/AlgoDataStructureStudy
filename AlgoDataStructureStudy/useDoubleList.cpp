#include "MyDoubleList.h"

using namespace std;

int main()
{
	DoubleList dList;
	cout << "InsertFront 1" << endl;
	dList.InsertFront(1);
	dList.Print();
	cout << "InsertRear 2" << endl;
	dList.InsertRear(2);
	dList.Print();
	cout << "InsertFront 3" << endl;
	dList.InsertFront(3);
	dList.Print();
	cout << "Delete 1" << endl;
	dList.Delete(1);
	dList.Print();

	cout << "Clear" << endl;
	dList.Clear();
	cout << "after clear" << endl;
	dList.Print();

}