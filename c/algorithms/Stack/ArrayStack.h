#pragma once
typedef struct StaticArrayStack {
	int* array;
	size_t capacity;
	int top;
}StaticArrayStack;
StaticArrayStack* createStaticArrayStack(size_t capacity);
void staticArrayStackPush(StaticArrayStack* stack, int data);
void staticArrayStackPop(StaticArrayStack* stack);
int staticArrayStackIsFull(StaticArrayStack* stack);
int staticArrayStackIsEmpty(StaticArrayStack* stack);
void staticArrayStackPrint(StaticArrayStack* stack);
int staticArrayStackPeek(StaticArrayStack* stack);
void deleteStaticArrayStack(StaticArrayStack* stack);
StaticArrayStack* createStaticArrayStack(size_t capacity) {
	StaticArrayStack* stack = malloc(sizeof(StaticArrayStack));
	if (!stack) return NULL;
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = malloc(stack->capacity*sizeof(int));
	if (!stack->array) return NULL;
	return stack;
}
int staticArrayStackIsFull(StaticArrayStack* stack) {
	if (stack->top ==  stack->capacity-1) return 1;
	return 0;
}
int staticArrayStackIsEmpty(StaticArrayStack* stack) {
	if (stack->top == -1) return 1;
	return 0;
}
void staticArrayStackPush(StaticArrayStack* stack, int data) {
	if (staticArrayStackIsFull(stack)) {
		printf("\nError: StackOverflow\n");
		return;
	}
	stack->array[++stack->top] = data;
}
void staticArrayStackPop(StaticArrayStack* stack) {
	if (staticArrayStackIsEmpty(stack)) {
		printf("\nError: There's no Element to pop\n");
		return;
	}
	stack->top--;
}
void staticArrayStackPrint(StaticArrayStack* stack) {
	for (int i = 0; i < stack->top; i++) printf("%d ", stack->array[i]);
	printf("\n");
}
int staticArrayStackPeek(StaticArrayStack* stack) {
	if (staticArrayStackIsEmpty(stack)) {
		printf("\nError: Stack is Empty\n");
		return INT_MIN;
	}
	return stack->array[stack->top];
}
void deleteStaticArrayStack(StaticArrayStack* stack){
	if (stack) {
		if (stack->array) free(stack->array);
		free(stack);
	}
}