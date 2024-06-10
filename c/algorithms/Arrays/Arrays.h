#pragma once
typedef struct ArrayList {
	int* array;
	int length;  
	int capacity;  
}ArrayList;
ArrayList* createArrayList(int capacity);
void reallocateArrayList(ArrayList* arrayList,int capacity);
int arrayListSize(ArrayList* arrayList);
int arrayListIsEmpty(ArrayList* arrayList);
int getArrayListElement(ArrayList* arrayList, int index);
void setArrayListElement(ArrayList* arrayList, int element, int index);
void deleteArrayList(ArrayList* arrayList);
void arrayListAppend(ArrayList* arrayList,int element);
void arrayListInsert(ArrayList* arrayList,int target,int pos);
void arrayListRemove(ArrayList* arrayList, int pos);
void arrayListReverse(ArrayList* arrayList);
void arrayListPrint(ArrayList* arrayList);
ArrayList* createArrayList(int capacity) {
	if (capacity < 0) {
		printf("Illegal Capacity: %d",capacity);
		return NULL;
	}
	ArrayList* arrayList = malloc(sizeof(ArrayList));
	if (!arrayList) return NULL;
	arrayList->capacity = capacity;
	arrayList->length = 0;
	arrayList->array = malloc(capacity * sizeof(int));
	if (!arrayList->array) return NULL;
	return arrayList;
}
void reallocateArrayList(ArrayList* arrayList,int capacity) {
	arrayList->capacity += capacity;
	arrayList->array = realloc(arrayList->array,arrayList->capacity * sizeof(int));
}
int arrayListSize(ArrayList* arrayList) { return arrayList->length; }
int arrayListIsEmpty(ArrayList* arrayList) { return arrayListSize(arrayList) == 0; }
int getArrayListElement(ArrayList* arrayList, int index) {
	if (index >= arrayListSize(arrayList) || index < -arrayListSize(arrayList)) {
		printf("\nIndex out of bound\n");
		return NULL;
	}
	if (index < 0) index += arrayListSize(arrayList);
	return arrayList->array[index]; 
}
void setArrayListElement(ArrayList* arrayList,int element,int index){
	if (index >= arrayListSize(arrayList) || index < -arrayListSize(arrayList)) {
		printf("\nIndex out of bound\n");
		return;
	}
	if (index < 0) index += arrayListSize(arrayList);
	arrayList->array[index] = element;
}
void arrayListAppend(ArrayList* arrayList,int element) {
	if (arrayList->length + 1 >= arrayList->capacity) {
		if (arrayList->capacity == 0) arrayList->capacity = 1;
		reallocateArrayList(arrayList,1);
	}
	arrayList->array[arrayList->length++] = element;
}
void arrayListInsert(ArrayList* arrayList, int target, int pos) {
	if (arrayList->length + 1 >= arrayList->capacity) {
		if (arrayList->capacity == 0) arrayList->capacity = 1;
		reallocateArrayList(arrayList, 1);
	}
	for (int cnt = arrayList->length - 1; cnt >= pos; arrayList->array[cnt] = arrayList->array[cnt-1],cnt--);
	arrayList->array[pos] = target;
}
void arrayListRemove(ArrayList* arrayList, int pos) {
	for (int cnt = pos; cnt < arrayList->length; arrayList->array[cnt]= arrayList->array[cnt+1],cnt++);
	arrayList->array[arrayList->length - 1] = NULL;
}
void arrayListReverse(ArrayList* arrayList) {
	for (int cnt = 0; cnt < arrayList->length / 2;(arrayList->array[cnt] ^= arrayList->array[arrayList->length-cnt-1]),(arrayList->array[arrayList->length - cnt - 1] ^= arrayList->array[cnt]),(arrayList->array[cnt]^= arrayList->array[arrayList->length - cnt - 1]),cnt++);
}
void arrayListPrint(ArrayList* arrayList) {
	printf("[");
	for (int cnt = 0; cnt < arrayList->length; printf("%d, ", arrayList->array[cnt]), cnt++);
	printf("\b\b]\n");
}
void deleteArrayList(ArrayList* arrayList) {
	if (arrayList) {
		if (arrayList->array) free(arrayList->array);
		free(arrayList);
	}
}