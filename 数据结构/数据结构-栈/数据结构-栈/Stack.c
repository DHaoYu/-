#define _CRT_SECURE_NO_WARNNINGS 1
#include "Stack.h"
#include <assert.h>
#include <malloc.h>
#include <stdio.h>
#include<string.h>


void StackInit(Stack *s)
{
	s->array= (TypeData*)malloc(sizeof(TypeData)* 3);
	s->capecity = 3;
	s->top = 0;
}

void StackPush(Stack *s,TypeData data)
{
	assert(s);
	_CheckStck(s);
	s->array[s->top] = data;
	s->top++;
}

void StackPop(Stack *s)
{
	assert(s);
	s->array[s->top-1];
	s->top--;
}
int StackSize(Stack *s)
{
	return s->top;
}

int StackCapecity(Stack *s)
{
	return s->capecity;
}

void StackDestory(Stack *s)
{
	assert(s);
	s->capecity = 0;
	s->top = 0;
	free(s->array);
	s->array = NULL;
}

TypeData StackBack(Stack *s)
{
	return s->array[s->top];
}

void _CheckStck(Stack *s)
{
	if (s->capecity == s->top)
	{
		TypeData* Stemp = (TypeData*)malloc(sizeof(TypeData)* 2 * s->capecity);
		memcpy(Stemp, s->array, sizeof(TypeData)*s->capecity);
		free(s->array);
		s->array = Stemp;
		s->capecity = 2 * s->capecity;
	}
}

void print(Stack *s)
{
	for (int i = 0; i < s->top; i++)
	{
		printf("%d ", s->array[i]);
	}
}
