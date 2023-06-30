#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntQueue.h"

int main()
{
	IntQueue que;

	if (Initialize(&que, 5) == -1)
	{
		puts("?�의 ?�성???�패?��??�니??");
		return 1;
	}

	while (1)
	{
		int m, x;

		printf("?�재 ?�이????: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)?�큐 (2)?�큐 (3)?�크 (4)출력 (5)검??(6)초기??(0)종료: ");
		scanf("%d", &m);

		if (m == 0)break;
		switch (m)
		{
		case 1:
			printf("?�이??: "); scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("?�류 : ?�큐???�패?��??�니??");
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("?�류 : ?�큐???�패?��??�니??");
			else
				printf("?�큐???�이?�는 %d?�니??\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("?�류 : ?�크???�패?��??�니??");
			else
				printf("?�크???�이?�는 %d?�니??\n", x);
			break;
		case 4:
			Print(&que);
			break;
		case 5:
		{
			int temp;
			printf("검?�할 ?�이?��? ?�력?�세??:");
			scanf("%d", &temp);
			int res = Search(&que, temp);
			if (res != -1)
				printf("%d???�의 %d번째 ?�덱?�에 ?�습?�다.\n", temp, res);
			else
				printf("검???�패\n");
			break;
		}
		
		case 6:
			Clear(&que);
			printf("?��? 초기?�되?�습?�다.\n");
			break;
		}
	}
}