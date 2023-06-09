#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("?€ν ?μ±???€ν¨?μ΅?λ€.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		printf("?μ¬ ?°μ΄???? %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)?Έμ (2)??(3)?Όν¬ (4)μΆλ ₯ (5)μ΄κΈ°??(6)κ²??(0)μ’λ£: ");
		scanf("%d", &menu);

		if (menu == 0)break;
		switch (menu)
		{
		case 1:
			printf("?°μ΄?? ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("?€λ₯: ?Έμ???€ν¨?μ΅?λ€.");
			break;
		case 2:
			if (Pop(&s, &x) == -1)
				puts("?€λ₯: ?μ ?€ν¨?μ΅?λ€.");
			else
				printf("???°μ΄?°λ %d?λ??\n", x);
			break;
		case 3:
			if (Peek(&s, &x) == -1)
				puts("?€λ₯: ?Όν¬???€ν¨?μ΅?λ€.");
			else
				printf("?Όν¬ ?°μ΄?°λ %d?λ??\n", x);
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
			printf("κ²?ν  ?°μ΄?°λ? ?λ ₯?μΈ??");
			scanf("%d", &input);
			temp = Search(&s, input);
			if (temp != -1)
			{
				printf("%d???€ν??%dμΈ΅μ ?μ΅?λ€.\n", input, temp + 1);
			}
			else
			{
				puts("?°μ΄?°λ? μ°Ύμ ???μ΅?λ€.");
			}
			break;
		}
		}
	}
	Terminate(&s);
	return 0;
}