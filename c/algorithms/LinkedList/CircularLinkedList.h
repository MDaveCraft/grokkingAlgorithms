#pragma once
typedef struct {
	int data;
	struct CLLNode* next;
}CLLNode;
CLLNode* getNewCLLNode(int data,CLLNode* next);
void cllPrint(CLLNode* head);
void cllInsert(CLLNode** head,int data,int position);
int cllLength(CLLNode* head);
CLLNode* getNewCLLNode(int data, CLLNode* next) {
	CLLNode* temp;
	temp->data = data;
	temp->next = next;
	return temp;
}
void cllPrint(CLLNode* head) {
	if (!head) return;
	CLLNode* current = head;
	do {
		if (current == head) printf("[Head: %d]-> ", current->data);
		else if (current->next == head) printf("[Tail: %d]", current->data);
		else printf("[%d]-> ", current->data);
		current = current->next;
	} while(current->next != head);
}
int cllLength(CLLNode* head) {
	if (!head) return 0;
	int cnt = 0;
	CLLNode* current = head;
	do {
		cnt++;
		current = current->next;
	}while(current->next != head);
	return cnt;
}