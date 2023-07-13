#include "MyList.h"

using namespace std;

int main()
{
	StudentList list;
	int sel;
	while (1)
	{
		cout << "1. 입력, 2. 삭제, 3. 전체 출력, 4. 초기화 : ";
		cin >> sel;
		switch (sel)
		{
		case 1:
		{
			string name;
			int no;
			cout << "이름 : ";
			cin >> name;
			cout << "번호 : ";
			cin >> no;
			list.Insert(name, no);
		}
			break;
		case 2:
		{
			int no;
			cout << "번호 : ";
			cin >> no;
			list.Delete(no);
		}
			break;
		case 3:
			list.Print();
			break;
		case 4:
			list.Clear();
			break;
		default:
			continue;
			break;
		}
	}
	return 0;
}