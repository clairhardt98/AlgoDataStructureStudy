#pragma once

typedef struct
{
	int max;
	int ptr;
	char* stk;
}charStack;

int Initialize(charStack*, int);
int Push(charStack*, char);
int Pop(charStack*, char*);
int Peek(const charStack*, char*);
void Clear(charStack*);
int Capacity(const charStack*);
int Size(const charStack*);
int IsEmpty(const charStack*);
int IsFull(const charStack*);
int Search(const charStack*, char x);
void Print(const charStack*);
void Terminate(charStack*);
