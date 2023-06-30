#pragma once
#pragma once
typedef struct
{
	int max;
	int num;
	int front;
	int rear;
	char* que;
}charQueue;

int Initialize(charQueue* q, int x);
int Enque(charQueue* q, char x);
int Deque(charQueue* q, char* x);
int Peek(const charQueue* q, char* x);
void Clear(charQueue* q);
int Capacity(const charQueue* q);
int Size(const charQueue* q);
int IsEmpty(const charQueue* q);
int IsFull(const charQueue* q);
int Search(const charQueue* q, int x);
void Print(const charQueue* q);
void Terminate(charQueue* q);