#pragma once
typedef struct DLLNode{
	int data;
	struct DLLNode* previous;
	struct DLLNode* next;
}DLLNode;
void erase(DLLNode* node);
DLLNode* getNewDLLNode(int data,DLLNode* previous, DLLNode* next);
void append(DLLNode** node, int data);
void print(DLLNode* node);
void prepend(DLLNode** node, int data);
int isEmpty(DLLNode* node);
int length(DLLNode* node);
void insert(DLLNode** node, int data, int index);
int index(DLLNode* node, int data);
void pop(DLLNode** node, int index);
void removeData(DLLNode** node, int data);
void reverse(DLLNode** node);
DLLNode* getNewDLLNode(int data,DLLNode* previous,DLLNode* next) {
	DLLNode* temp = (DLLNode*)malloc(sizeof(DLLNode));
	temp->data = data;
	temp->previous = previous;
	temp->next = next;
	return temp;
}
int isEmpty(DLLNode* node) {
	return node == NULL;
}
void append(DLLNode** node, int data) {
	if (isEmpty(*node)) {
		*node = getNewNode(data, NULL,NULL);
		return;
	}
	DLLNode* current = *node;
	while (current->next != NULL) current = current->next;
	DLLNode* temp2 = getNewNode(data,current,NULL);
	current->next = temp2;
}
void print(DLLNode* node) {
	if (isEmpty(node)) {
		printf("[]\n");
		return;
	}
	DLLNode* current = node;
	while (current != NULL) {
		if (current == node) printf("[Head:%d] -> ", node->data);
		else if (current->next == NULL) printf("[Tail:%d]", current->data);
		else printf("[%d] -> ", current->data);
		current = current->next;
	}
	printf("\n");
}
void prepend(DLLNode** node, int data) {
	*node = getNewNode(data,NULL,*node);
}
void erase(DLLNode* node) {
	DLLNode* current;
	while (node != NULL) {
		current = node;
		node = node->next;
		free(current);
	}
}
int length(DLLNode* node) {
	if (isEmpty(node)) return 0;
	int cnt = 0;
	for (DLLNode* current = node; current != NULL; cnt++, current = current->next);
	return cnt;
}
void insert(DLLNode** node, int data, int index) {
	if (isEmpty(*node)) return;
	else if (index >= length(*node) && index < -length(*node)) {
		printf("Length is out od bound\n\n");
		return;
	}
	else if (index < 0) index += length(*node);
	if (index == 0) {
		*node = getNewNode(data,NULL,*node);
		return;
	}
	DLLNode* current = *node;
	for (int cnt = 1; cnt < index - 1 && current != NULL; cnt++, current = current->next);
	DLLNode* temp = getNewNode(data,current,current->next);
	current->next = temp;
}
void pop(DLLNode** node, int index) {
	if (isEmpty(*node))
	{
		printf("\nList is Empty\n");
		return;
	}
	else if (index >= length(*node) && index < -length(*node)) {
		printf("Length is out od bound\n\n");
		return;
	}
	else if (index < 0) index += length(*node);
	DLLNode* current = *node;
	if (index == 0) {
		(*node)->next = current->next;
		(*node)->previous = NULL;
		free(current);
		return;
	}
	for (int cnt = 1; cnt < index && current != NULL; cnt++, current = current->next);
	DLLNode* temp = current->next;
	current->next = temp->next;
	temp->next->previous = current;
	free(temp);
}
int index(DLLNode* node, int data) {
	if (isEmpty(node))
	{
		printf("\nList is Empty\n");
		return -1;
	}
	int cnt = 0;
	for (DLLNode* current = node; current != NULL; cnt++, current = current->next)
		if (current->data == data)return cnt;
	return -1;
}
void removeData(DLLNode** node, int data) {
	if (isEmpty(*node)) { printf("\nList is Empty\n"); return; }
	int pos = index(*node, data);
	if (pos == -1) { printf("\nThere No Element %d\n", data); return; }
	//pop(&(*node), pos);
	DLLNode* current = *node;
	if (current->data == data) {
		(*node) = current->next;
		free(current);
		return;
	}
	for (;current->next != NULL && current->next->data != data; current = current->next);
	DLLNode* temp = current->next;
	current->next = temp->next;
	temp->next->previous = current;
	free(temp);
}
void reversePrint(DLLNode** node) {
	if (isEmpty(*node)) { printf("\nList is Empty\n"); return; }
	if (length(*node) < 2) return;
	DLLNode* current = *node, * previous = NULL;
	while (current->next != NULL) current = current->next;
	while (current->previous != NULL) { 
		printf("%d ", current->data);
		current = current->previous;
	}
}
void reverse(DLLNode** node) {
	if (isEmpty(*node)) { printf("\nList is Empty\n"); return; }
	if (length(*node) < 2) return;
	DLLNode* current = *node, *previous = NULL;
	while (current->next != NULL) current = current->next;
	while (current->previous != NULL) {
		DLLNode* temp = current->previous;
		current->previous = current->next;
		current->next = temp;
		current = current->previous;
	}
}