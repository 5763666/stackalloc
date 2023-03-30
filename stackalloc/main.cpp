#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_STACK_SIZE 10  //ÇÊ
typedef int element;
typedef struct {
	element* data;
	int capacity;
	int top;
} StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType* s) { return (s->top == -1); }

int is_full(StackType* s) { return (s->top == (MAX_STACK_SIZE - 1)); }


void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack Empty!\n");
		return 0;
	}
	else return s->data[(s->top)--];
}

int main(void) {
	StackType s;
	init_stack(&s);

	printf("-----Using array-----\n");
	srand((unsigned int)time(NULL)); //ÇÊ

	for (int i = 0; i <= 30; i++) {
		if (i < 10) printf("[ %d] ", i);
		else printf("[%d] ", i);

		int rand_num = rand() % 100 + 1; //ÇÊ

		if (rand_num % 2 == 0) {
			push(&s, i);
			printf("Push %d\n", rand_num);
		}
		else {
			printf("Pop %d\n", pop(&s));
		}
	}

	return 0;
}