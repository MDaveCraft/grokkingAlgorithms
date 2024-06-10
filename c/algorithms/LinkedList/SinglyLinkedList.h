#pragma once
typedef struct SLLNode {
	int data;
	struct SLLNode* next;
}SLLNode;
void sllErase(SLLNode* node);
SLLNode* getNewSLLNode(int data, SLLNode* next);
void sllAppend(SLLNode** node, int data);
void sllPrint(SLLNode* node);
void sllPrepend(SLLNode** node, int data);
int sllIsEmpty(SLLNode* node);
int sllLength(SLLNode* node);
void sllInsert(SLLNode** node, int data, int index);
int sllIndex(SLLNode* node,int data);
int sllPop(SLLNode** node, int index);
void sllRemoveData(SLLNode** node, int data);
void sllReverse(SLLNode** node);
void zipperSLL(SLLNode** node1,SLLNode* node2);
SLLNode* getNewSLLNode(int data, SLLNode* next) {
	SLLNode* temp = (SLLNode*)malloc(sizeof(SLLNode));
	temp->data = data;
	temp->next = next;
	return temp;
}
int sllIsEmpty(SLLNode* node) { return node == NULL; }
void sllAppend(SLLNode** node, int data) {
	if (sllIsEmpty(*node)) {
		*node = getNewSSLNode(data,NULL);
		return;
	}
	SLLNode* current = *node;
	while (current->next != NULL) current = current->next;
	SLLNode* temp2 = getNewSSLNode(data, NULL);
	current->next = temp2;
}
void sllPrint(SLLNode* node) {
	if (sllIsEmpty(node)) {
		printf("[]\n");
		return;
	}
	SLLNode* current = node;
	while (current != NULL) {
		if (current == node) printf("[Head:%d] -> ", node->data);
		else if (current->next == NULL) printf("[Tail:%d]", current->data);
		else printf("[%d] -> ", current->data);
		current = current->next;
	}
	printf("\n");
}
void sllPrepend(SLLNode** node,int data) {
	*node = getNewSSLNode(data, *node);
}
int sllLength(SLLNode* node) {
	if (sllIsEmpty(node)) return 0;
	int cnt = 0;
	for (SLLNode* current = node; current != NULL; cnt++,current = current->next);
	return cnt;
}
void sllInsert(SLLNode** node, int data, int index) {
	if (sllIsEmpty(*node)) return;
	else if (index >= sllLength(*node) || index < -sllLength(*node)) {
		printf("Length is out of bound\n\n");
		return;
	}
	else if (index < 0) index += sllLength(*node);
	if (index == 0) {
		*node = getNewSSLNode(data, *node);
		return;
	}
	SLLNode* current = *node;
	for (int cnt = 1; cnt < index-1 && current!=NULL;cnt++,current=current->next);
	SLLNode* temp = getNewSSLNode(data,current->next);
	current->next = temp;
}
int sllPop(SLLNode** node, int index) {
	if (sllIsEmpty(*node))
	{
		printf("\nList is Empty\n");
		return INT_MIN;
	}else if (index >= sllLength(*node) && index < -sllLength(*node)) {
		printf("\nLength is out od bound\n\n");
		return INT_MIN;
	}else if (index < 0) index += sllLength(*node);
	SLLNode* current = *node;
	int data = 0;
	if (index == 0) {
		(*node)->next = current->next;
		data = current->data;
		free(current);
		return data;
	}
	for (int cnt = 1; cnt < index && current != NULL; cnt++, current = current->next);
	SLLNode* temp = current->next;
	current->next = temp->next;
	data = temp->data;
	free(temp);
	return data;
}
int sllIndex(SLLNode* node, int data) {
	if (sllIsEmpty(node))
	{
		printf("\nList is Empty\n");
		return -1;
	}
	int cnt = 0;
	for (SLLNode* current=node;current!=NULL; cnt++,current = current->next)
		if (current->data == data)return cnt;
	return -1;
}
void sllRemoveData(SLLNode** node, int data) {
	if (sllIsEmpty(*node)) { printf("\nList is Empty\n"); return; }
	int pos = sllIndex(*node, data);
	if (pos == -1) { printf("\nThere No Element %d\n", data); return; }
	sllPop(&(*node), pos);
	//SLLNode* current = *node;
	//if (current->data == data) {
	//	(*node) = current->next;
	//	free(current);
	//	return;
	//}
	//for (;current->next != NULL && current->next->data != data; current = current->next);
	//SLLNode* temp = current->next;
	//current->next = temp->next;
	//free(temp);
}
void sllReverse(SLLNode** node) {
	if (sllIsEmpty(*node)) { printf("\nList is Empty\n"); return; }
	if (sllLength(*node) < 2) return;
	SLLNode* current = *node, * previous = NULL;
	while (current != NULL) {
		SLLNode* temp = current->next;
		current->next = previous;
		previous = current;
		current = temp;
	}
	*node = previous;
}
void zipperSLL(SLLNode** node1,SLLNode* node2){
	if (sllIsEmpty(*node1)) { *node1 = node2; return; }
	else if (sllIsEmpty(node2)) return;
	SLLNode* tail = *node1, *current = (*node1)->next, * current2 = node2;
	int count = 0;
	SLLNode* current_Next = NULL, * current2_Next = NULL;
	while (current != NULL && current2 != NULL) {
		if (count%2==0){
			tail->next = current2;
			current2 = current2->next;
		}else{
			tail->next = current;
			current = current->next;
		}
		tail = tail->next;
		count++;
	}
	if (current != NULL) tail->next = current;
	if (current2 != NULL) tail->next = current2;
}
void sllErase(SLLNode* node) {
	SLLNode* current;
	while (node != NULL) {
		current = node;
		node = node->next;
		free(current);
	}
}
/*
//Recursive Print
void recursivePrint(SLLNode* node) {
	if(node == NULL) return;
	printf("%d ",node->data);
	recursivePrint(node->next);
}
//Recursive Reverse 
SLLNode* recursiveReverse(SLLNode* node,SLLNode* previous) {
	if(node == NULL) return previous;
	SLLNode* next = node->next;
	node->next = previous;
	return recursiveReverse(next,head);
}
SLLNode* recursiveZipperSLL(SLLNode* head1,SLLNode* head2){
	if (head1 == Null && head2 == Null) return Null;
	if (head1 == Null) return head2;
	if (head2 === Null) return head1;
	SLLNode* next1 = head1->next,*next2 = head2->next;
	head1->next = head2;
	head2->next = recursiveZipperSLL(next1, next2);
	return head1;
}
*/