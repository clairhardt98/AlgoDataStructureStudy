#include "CursorList.h"
#include <iostream>

using namespace std;
int main()
{
	int size;
	cout << "리스트의 크기를 지정하세요: ";
	cin >> size;
	List list(size);

	int sel;

	while (1)
	{
		cout << "1. 입력, 2. 제거, 3. 출력, 4. 초기화, 5. 종료 :";
		cin >> sel;
		switch (sel)
		{
		case 1:
		{
			string name;
			int no;
			cout << "이름과 번호를 입력하세요 : ";
			cin >> name >> no;
			Student st{ no,name };
			if (!list.Insert(st))
				cout << "삽입에 실패하였습니다.\n";
			break;
		}

		case 2:
		{
			int no;
			cout << "제거할 학생의 번호를 입력하세요 :";
			cin >> no;
			if (!list.Remove(no))
				cout << "제거에 실패하였습니다.\n";
		}
		break;
		case 3:
		{
			list.Print();
		}
		break;
		case 4:
			list.Clear();
			break;
		case 5:
			return 0;
		break;
		}

	}
}