//
//  stack.h
//
//===============================================================
// esta biblioteca foi construida especificamente para o teste dos
//  exercicios.
//===============================================================
// a representacao utilizada para esta biblioteca foi a
// representacao por contiguidade física.
//================================================================
//
//  Created by Angela Engelbrecht on 02/04/19.
//  Copyright © 2019 Angela Engelbrecht. All rights reserved.
//

#ifndef stack_h
#define stack_h


#include  <stdlib.h>
#include  <iostream>
#define MAXELEMENTS 100
using namespace std;

struct Stack {
	int top;
	stack_element local[MAXELEMENTS];
};
void initStack(Stack&);
void push(Stack&, stack_element);
stack_element pop(Stack&);
stack_element peek(Stack);
int isEmpty(Stack);
void error(int);

void error(int i) {
	switch (i) {
	case 1:cerr << " OVERFLOW "; exit(1);
	case 2:cerr << " UNDERFLOW "; exit(1);
	}
}
void initStack(Stack& p) { p.top = -1; }

void push(Stack & p, stack_element x) {
	if (p.top == MAXELEMENTS - 1)error(1);
	p.local[++(p.top)] = x;
}

stack_element pop(Stack& p) {
	if (p.top == -1)error(2);
	return (p.local[p.top--]);
}

stack_element peek(Stack p) {
	if (p.top == -1) error(2);
	return (p.local[p.top]);
}
int isEmpty(Stack p) {
	if (p.top == -1)return 1; // verdade
	return 0;  // falso
}

#endif /* stack_h */
