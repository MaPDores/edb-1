#include  <stdlib.h>
#include  <stdio.h>
#define MAXELEMENTS 300

typedef int stack_element;

typedef struct _stack {
	int top;
	stack_element local[MAXELEMENTS];
} stack;

#include "stack.c"

void initStack(stack*);

void push(stack*, stack_element);

stack_element pop(stack*);

stack_element peek(stack);

int isEmpty(stack);

void error(int);
