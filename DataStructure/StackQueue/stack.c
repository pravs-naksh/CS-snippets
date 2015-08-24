#include "stack.h"

stack* createStack(){
	stack* new_stack = (stack*)malloc(sizeof(stack)); 
        new_stack->ll = createlinklist();
        return new_stack;
}

void stackPush(stack *s,data *d){
	addBack(s->ll,d);
}

data* stackPop(stack *s){
	return popBack(s->ll);
}

void stackPrint(stack *s){
	printList(s->ll);
}

int stackSize(stack *s){
	return listSize(s->ll);
}

void stackClean(stack *s){
	cleanList(s->ll);
}
