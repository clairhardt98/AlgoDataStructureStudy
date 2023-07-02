#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "IntQueue.h"

int main()
{
	IntQueue que;

	if (Initialize(&que, 5) == -1)
	{
		puts("?ì˜ ?ì„±???¤íŒ¨?˜ì??µë‹ˆ??");
		return 1;
	}

	while (1)
	{
		int m, x;

		printf("?„ì¬ ?°ì´????: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)?¸í (2)?”í (3)?¼í¬ (4)ì¶œë ¥ (5)ê²€??(6)ì´ˆê¸°??(0)ì¢…ë£Œ: ");
		scanf("%d", &m);

		if (m == 0)break;
		switch (m)
		{
		case 1:
			printf("?°ì´??: "); scanf("%d", &x);
			if (Enque(&que, x) == -1)
				puts("?¤ë¥˜ : ?¸í???¤íŒ¨?˜ì??µë‹ˆ??");
			break;
		case 2:
			if (Deque(&que, &x) == -1)
				puts("?¤ë¥˜ : ?”í???¤íŒ¨?˜ì??µë‹ˆ??");
			else
				printf("?”í???°ì´?°ëŠ” %d?…ë‹ˆ??\n", x);
			break;
		case 3:
			if (Peek(&que, &x) == -1)
				puts("?¤ë¥˜ : ?¼í¬???¤íŒ¨?˜ì??µë‹ˆ??");
			else
				printf("?¼í¬???°ì´?°ëŠ” %d?…ë‹ˆ??\n", x);
			break;
		case 4:
			Print(&que);
			break;
		case 5:
		{
			int temp;
			printf("ê²€?‰í•  ?°ì´?°ë? ?…ë ¥?˜ì„¸??:");
			scanf("%d", &temp);
			int res = Search(&que, temp);
			if (res != -1)
				printf("%d???ì˜ %dë²ˆì§¸ ?¸ë±?¤ì— ?ˆìŠµ?ˆë‹¤.\n", temp, res);
			else
				printf("ê²€???¤íŒ¨\n");
			break;
		}
		
		case 6:
			Clear(&que);
			printf("?ê? ì´ˆê¸°?”ë˜?ˆìŠµ?ˆë‹¤.\n");
			break;
		}
	}
}