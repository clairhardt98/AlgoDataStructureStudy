#include "CursorList.h"
#include <iostream>

using namespace std;
int main()
{
	int size;
	cout << "����Ʈ�� ũ�⸦ �����ϼ���: ";
	cin >> size;
	List list(size);

	int sel;

	while (1)
	{
		cout << "1. �Է�, 2. ����, 3. ���, 4. �ʱ�ȭ, 5. ���� :";
		cin >> sel;
		switch (sel)
		{
		case 1:
		{
			string name;
			int no;
			cout << "�̸��� ��ȣ�� �Է��ϼ��� : ";
			cin >> name >> no;
			Student st{ no,name };
			if (!list.Insert(st))
				cout << "���Կ� �����Ͽ����ϴ�.\n";
			break;
		}

		case 2:
		{
			int no;
			cout << "������ �л��� ��ȣ�� �Է��ϼ��� :";
			cin >> no;
			if (!list.Remove(no))
				cout << "���ſ� �����Ͽ����ϴ�.\n";
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