#include "MyList.h"

using namespace std;

int main()
{
	StudentList list;
	int sel;
	while (1)
	{
		cout << "1. �Է�, 2. ����, 3. ��ü ���, 4. �ʱ�ȭ : ";
		cin >> sel;
		switch (sel)
		{
		case 1:
		{
			string name;
			int no;
			cout << "�̸� : ";
			cin >> name;
			cout << "��ȣ : ";
			cin >> no;
			list.Insert(name, no);
		}
			break;
		case 2:
		{
			int no;
			cout << "��ȣ : ";
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