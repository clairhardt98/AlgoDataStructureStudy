#include <stdlib.h>
#include <stdio.h>
#include "charQueue.h"

int Initialize(charQueue* q, int x)
{
	q->max = x;
	q->num = 0;
	q->front = 0;
	q->rear = 0;
	q->que = (char*)malloc(q->max * sizeof(char));
	if (q->que == NULL)
		return -1;
	else return 1;
}
int Enque(charQueue* q, char x)
{
	if (!IsFull(q))
	{
		q->que[q->rear] = x;
		q->num++;
		if (q->rear == q->max - 1)
		{
			q->rear = 0;
		}
		else
			q->rear++;

		return 1;
	}
	else return -1;
}
int Deque(charQueue* q, char* x)
{
	if (!IsEmpty(q))
	{
		*x = q->que[q->front];
		q->num--;

		if (q->front == q->max - 1)
			q->front = 0;
		else q->front++;

		return 1;
	}
	else
		return -1;
}
int Peek(const charQueue* q, char* x)
{
	if (!IsEmpty(q))
	{
		*x = q->que[q->front];
		return 1;
	}
	else
		return -1;
}
void Clear(charQueue* q)
{
	q->front = 0;
	q->rear = 0;
	q->num = 0;
}
int Capacity(const charQueue* q)
{
	return q->max;
}
int Size(const charQueue* q)
{
	return q->num;
}
int IsEmpty(const charQueue* q)
{
	if (q->num == 0)
		return 1;
	else
		return 0;
}
int IsFull(const charQueue* q)
{
	if (q->num == q->max)
		return 1;
	else
		return 0;
}
int Search(const charQueue* q, char x)
{
	int idx = q->front;
	int cnt = 0;
	while (cnt < q->num)
	{
		if (q->que[idx] == x)
			return cnt;
		if (idx == q->max - 1)
			idx = 0;
		else
			idx++;
		cnt++;
	}
	return -1;
}
void Print(const charQueue* q)
{
	int idx = q->front;
	int cnt = 0;
	while (cnt < q->num)
	{
		printf("%c", q->que[idx]);
		if (idx == q->max - 1)
			idx = 0;
		else
			idx++;
		cnt++;
	}
	printf("\n");
}
void Terminate(charQueue* q)
{
	free(q->que);
}