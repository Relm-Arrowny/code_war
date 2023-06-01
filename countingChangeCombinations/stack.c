//stack for storing the state of coin picking
#include <stdlib.h>
#include <stdio.h>//#include <stack.h>
#include "stack.h"
struct Stack * createStack(unsigned size){
	struct Stack * stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->top = -1;
	stack->size = size;
	stack->state = (struct curState*) malloc(sizeof(struct curState)*size);
	return stack;
}

int isFull(struct Stack* stack){
	return stack->size == stack->top - 1;
}

int isEmpty(struct Stack* stack){
        return stack->top == - 1;
}

void push(struct Stack* stack, struct curState newState){
	if (isFull(stack)){
		printf("stack is full");
	}
	else{
		stack->state[++stack->top] = newState;
	}
}
struct curState pop(struct Stack* stack){
	if (isEmpty(stack)){
		printf("stack empty");
//		return NULLSTATE;
	}
	return stack->state[stack->top--];
}
struct curState peak(struct Stack* stack){
	if (isEmpty(stack)){
                printf("stack empty");
//		return NULLSTATE;
	}
	return stack->state[stack->top];
}




