#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntStack.h"

int main()
{
	IntStack s;
	if (Initialize(&s, 64) == -1)
	{
		puts("?¤íƒ ?ì„±???¤íŒ¨?ˆìŠµ?ˆë‹¤.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		printf("?„ì¬ ?°ì´???? %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)?¸ì‹œ (2)??(3)?¼í¬ (4)ì¶œë ¥ (5)ì´ˆê¸°??(6)ê²€??(0)ì¢…ë£Œ: ");
		scanf("%d", &menu);

		if (menu == 0)break;
		switch (menu)
		{
		case 1:
			printf("?°ì´?? ");
			scanf("%d", &x);
			if (Push(&s, x) == -1)
				puts("?¤ë¥˜: ?¸ì‹œ???¤íŒ¨?ˆìŠµ?ˆë‹¤.");
			break;
		case 2:
			if (Pop(&s, &x) == -1)
				puts("?¤ë¥˜: ?ì— ?¤íŒ¨?ˆìŠµ?ˆë‹¤.");
			else
				printf("???°ì´?°ëŠ” %d?…ë‹ˆ??\n", x);
			break;
		case 3:
			if (Peek(&s, &x) == -1)
				puts("?¤ë¥˜: ?¼í¬???¤íŒ¨?ˆìŠµ?ˆë‹¤.");
			else
				printf("?¼í¬ ?°ì´?°ëŠ” %d?…ë‹ˆ??\n", x);
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
			printf("ê²€?‰í•  ?°ì´?°ë? ?…ë ¥?˜ì„¸??");
			scanf("%d", &input);
			temp = Search(&s, input);
			if (temp != -1)
			{
				printf("%d???¤íƒ??%dì¸µì— ?ˆìŠµ?ˆë‹¤.\n", input, temp + 1);
			}
			else
			{
				puts("?°ì´?°ë? ì°¾ì„ ???†ìŠµ?ˆë‹¤.");
			}
			break;
		}
		}
	}
	Terminate(&s);
	return 0;
}