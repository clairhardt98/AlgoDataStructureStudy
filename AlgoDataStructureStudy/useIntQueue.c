#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntQueue.h"

int main()
{
	IntQueue que;

	if (Initialize(&que, 5) == -1)
	{
		puts("?μ ?μ±???€ν¨?μ??΅λ??");
		return 1;
	}

	while (1)
	{
		int m, x;

		printf("?μ¬ ?°μ΄????: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)?Έν (2)?ν (3)?Όν¬ (4)μΆλ ₯ (5)κ²??(6)μ΄κΈ°??(0)μ’λ£: ");
		scanf("%d", &m);

		if (m == 0)break;
		switch (m)
		{
		case 1:
			printf("?°μ΄??: "); scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("?€λ₯ : ?Έν???€ν¨?μ??΅λ??");
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("?€λ₯ : ?ν???€ν¨?μ??΅λ??");
			else
				printf("?ν???°μ΄?°λ %d?λ??\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("?€λ₯ : ?Όν¬???€ν¨?μ??΅λ??");
			else
				printf("?Όν¬???°μ΄?°λ %d?λ??\n", x);
			break;
		case 4:
			Print(&que);
			break;
		case 5:
		{
			int temp;
			printf("κ²?ν  ?°μ΄?°λ? ?λ ₯?μΈ??:");
			scanf("%d", &temp);
			int res = Search(&que, temp);
			if (res != -1)
				printf("%d???μ %dλ²μ§Έ ?Έλ±?€μ ?μ΅?λ€.\n", temp, res);
			else
				printf("κ²???€ν¨\n");
			break;
		}
		
		case 6:
			Clear(&que);
			printf("?κ? μ΄κΈ°?λ?μ΅?λ€.\n");
			break;
		}
	}
}