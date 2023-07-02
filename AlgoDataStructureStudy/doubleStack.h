#pragma once

typedef struct
{
	int max;
	int ptr;
	double* stk;
}doubleStack;

int Initialize(doubleStack*, int);
int Push(doubleStack*, double);
int Pop(doubleStack*, double*);
int Peek(const doubleStack*, double*);
void Clear(doubleStack*);
int Capacity(const doubleStack*);
int Size(const doubleStack*);
int IsEmpty(const doubleStack*);
int IsFull(const doubleStack*);
int Search(const doubleStack*, double x);
void Print(const doubleStack*);
void Terminate(doubleStack*);
