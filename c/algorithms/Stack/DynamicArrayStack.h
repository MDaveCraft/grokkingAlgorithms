#pragma once
typedef struct DynamicArrayStack {
	int* array;
	size_t capacity;
	int top;
}DynamicArrayStack;

DynamicArrayStack* createDynamicArrayStack(size_t capacity);
void reallocateDynamicArrayStack(DynamicArrayStack* stack, int capacity);
void dynamicArrayStackPush(DynamicArrayStack* stack, int data);
int dynamicArrayStackPop(DynamicArrayStack* stack);
int dynamicArrayStackIsFull(DynamicArrayStack* stack);
int dynamicArrayStackIsEmpty(DynamicArrayStack* stack);
void dynamicArrayStackPrint(DynamicArrayStack* stack);
int dynamicArrayStackPeek(DynamicArrayStack* stack);
void deleteDynamicArrayStack(DynamicArrayStack* stack);
DynamicArrayStack* createDynamicArrayStack(size_t capacity) {
	DynamicArrayStack* stack = malloc(sizeof(DynamicArrayStack));
	if (!stack) return NULL;
	stack->top = -1;
	stack->capacity = capacity;
	stack->array = malloc(stack->capacity*sizeof(int));
	if (!stack->array) return NULL;
	return stack;
}
void reallocateDynamicArrayStack(DynamicArrayStack* stack, int capacity) {
	stack->array = realloc(stack->array, (stack->capacity += capacity) * sizeof(int));
}
int dynamicArrayStackIsFull(DynamicArrayStack* stack) { return stack->top == stack->capacity - 1; }
int dynamicArrayStackIsEmpty(DynamicArrayStack* stack) { return stack->top == -1; }
void dynamicArrayStackPush(DynamicArrayStack* stack, int data) {
	if (dynamicArrayStackIsFull(stack)) reallocateDynamicArrayStack(stack,stack->capacity);
	stack->array[++stack->top] = data;
}
int dynamicArrayStackPop(DynamicArrayStack* stack) {
	if (dynamicArrayStackIsEmpty(stack)) {
		printf("\nError: There's no Element to pop\n");
		return INT_MIN;
	}
	return stack->array[stack->top--];
}
void dynamicArrayStackPrint(DynamicArrayStack* stack) {
	printf("[");
	for (int i = 0; i < stack->top; i++) printf("%d, ", stack->array[i]);
	printf("\b\b]\n");
}
int dynamicArrayStackPeek(DynamicArrayStack* stack) {
	if (dynamicArrayStackIsEmpty(stack)) {
		printf("\nError: Stack is Empty\n");
		return INT_MIN;
	}
	return stack->array[stack->top];
}
void deleteDynamicArrayStack(DynamicArrayStack* stack){
	if (stack) {
		if (stack->array) free(stack->array);
		free(stack);
	}
}