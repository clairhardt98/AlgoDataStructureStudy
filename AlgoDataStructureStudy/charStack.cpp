#include <stdio.h>
#include <stdlib.h>
#include "charStack.h"

int Initialize(charStack* s, int max)
{
	s->ptr = 0;
	s->max = max;
	s->stk = (char*)malloc(s->max * sizeof(char));
	if (s->stk == NULL)
		return -1;
	else return 1;
}

int Push(charStack* s, char x)
{
	if (!IsFull(s))
	{
		s->stk[s->ptr] = x;
		s->ptr++;
		return 1;
	}
	return -1;
}

int Pop(charStack* s, char* x)
{
	if (!IsEmpty(s))
	{
		*x = s->stk[s->ptr - 1];
		s->ptr--;
		return 1;
	}
	else
		return -1;
}

int Peek(const charStack* s, char* x)
{
	if (!IsEmpty(s))
	{
		*x = s->stk[s->ptr - 1];
		return 1;
	}
	else
		return -1;
}

void Clear(charStack* s)
{
	s->ptr = 0;
}

int Capacity(const charStack* s)
{
	return s->max;
}

int Size(const charStack* s)
{
	return s->ptr;
}

int IsEmpty(const charStack* s)
{
	if (s->ptr == 0)
		return 1;
	else return 0;
}

int IsFull(const charStack* s)
{
	if (s->ptr == s->max)
		return 1;
	else
		return 0;
}

int Search(const charStack* s, char x)
{
	for (int i = 0; i < s->ptr; i++)
	{
		if (s->stk[i] == x)
			return i;
	}
	return -1;
}

void Print(const charStack* s)
{
	for (int i = 0; i < s->ptr; i++)
	{
		printf("%c ", s->stk[i]);
	}
	printf("\n");
}

void Terminate(charStack* s)
{
	free(s->stk);
}