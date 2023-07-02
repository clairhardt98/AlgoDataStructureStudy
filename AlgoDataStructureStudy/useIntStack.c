#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("?�택 ?�성???�패?�습?�다.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		printf("?�재 ?�이???? %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)?�시 (2)??(3)?�크 (4)출력 (5)초기??(6)검??(0)종료: ");
		scanf("%d", &menu);

		if (menu == 0)break;
		switch (menu)
		{
		case 1:
			printf("?�이?? ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("?�류: ?�시???�패?�습?�다.");
			break;
		case 2:
			if (Pop(&s, &x) == -1)
				puts("?�류: ?�에 ?�패?�습?�다.");
			else
				printf("???�이?�는 %d?�니??\n", x);
			break;
		case 3:
			if (Peek(&s, &x) == -1)
				puts("?�류: ?�크???�패?�습?�다.");
			else
				printf("?�크 ?�이?�는 %d?�니??\n", x);
			break;
		case 4:
			Print(&s);
			break;
		case 5:
			Clear(&s);
			break;
		case 6:
		{
			int input, temp;
			printf("검?�할 ?�이?��? ?�력?�세??");
			scanf("%d", &input);
			temp = Search(&s, input);
			if (temp != -1)
			{
				printf("%d???�택??%d층에 ?�습?�다.\n", input, temp + 1);
			}
			else
			{
				puts("?�이?��? 찾을 ???�습?�다.");
			}
			break;
		}
		}
	}
	Terminate(&s);
	return 0;
}