#include <stdio.h>
#include <stdlib.h>
#include "doubleStack.h"


int Initialize(doubleStack* s, int max)
{
	s->ptr = 0;
	s->max = max;
	s->stk = (double*)malloc(s->max * sizeof(double));
	if (s->stk == NULL)
		return -1;
	else return 1;
}

int Push(doubleStack* s, double x)
{
	if (!IsFull(s))
	{
		s->stk[s->ptr] = x;
		s->ptr++;
		return 1;
	}
	return -1;
}

int Pop(doubleStack* s, double* x)
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

int Peek(const doubleStack* s, double* x)
{
	if (!IsEmpty(s))
	{
		*x = s->stk[s->ptr - 1];
		return 1;
	}
	else
		return -1;
}

void Clear(doubleStack* s)
{
	s->ptr = 0;
}

int Capacity(const doubleStack* s)
{
	return s->max;
}

int Size(const doubleStack* s)
{
	return s->ptr;
}

int IsEmpty(const doubleStack* s)
{
	if (s->ptr == 0)
		return 1;
	else return 0;
}

int IsFull(const doubleStack* s)
{
	if (s->ptr == s->max)
		return 1;
	else
		return 0;
}

int Search(const doubleStack* s, double x)
{
	for (int i = 0; i < s->ptr; i++)
	{
		if (s->stk[i] == x)
			return i;
	}
	return -1;
}

void Print(const doubleStack* s)
{
	for (int i = 0; i < s->ptr; i++)
	{
		printf("%.1lf ", s->stk[i]);
	}
	printf("\n");
}

void Terminate(doubleStack* s)
{
	free(s->stk);
}