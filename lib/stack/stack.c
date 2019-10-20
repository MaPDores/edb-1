void error(int i) {
	switch (i) {
	case 1:printf("\n OVERFLOW \n"); exit(6);
	case 2:printf("\n UNDERFLOW \n"); exit(6);
	}
}
void initStack(stack* p) { (*p).top = -1; }

void push(stack* p, stack_element x) {
	if ((*p).top == MAXELEMENTS - 1)error(1);
	(*p).local[++((*p).top)] = x;
}

stack_element pop(stack* p) {
	if ((*p).top == -1)error(2);
	return ((*p).local[(*p).top--]);
}

stack_element peek(stack p) {
	if (p.top == -1) error(2);
	return (p.local[p.top]);
}
int isEmpty(stack p) {
	if (p.top == -1)return 1; // verdade
	return 0;  // falso
}
