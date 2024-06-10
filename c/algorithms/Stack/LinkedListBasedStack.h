#pragma once
typedef struct StackList {
	SLLNode* top;
	int length;
}StackList;
StackList* createStackList(); 
void deleteStackList(StackList* stack);
void stackListPush(StackList* stackList, int element);
int stackListPop(StackList* stackList);
int stackListIsEmpty(StackList* stackList);
int stackListPeek(StackList* stackList);
int stackListSize(StackList* stackList);
StackList* createStackList() {
	StackList* stackList = malloc(sizeof(StackList));
	stackList->top = NULL;
	return stackList;
}
void deleteStackList(StackList* stacklist) {
	if (stacklist) {
		sllErase(stacklist->top);
		free(stacklist);
	}
}
void stackListPush(StackList* stackList, int element) {
	stackList->length++;
	sllPrepend(&stackList, element);
}
int stackListPop(StackList* stackList) {
	stackList->length--;
	return sllPop(&stackList->top, 0);
}
int stackListIsEmpty(StackList* stackList) {
	return stackList->top == NULL;
}
int stackListPeek(StackList* stackList){
	return stackList->top->data;
}
int stackListSize(StackList* stackList) {
	//return sllLength(stackList->top);
	return stackList->length;
}