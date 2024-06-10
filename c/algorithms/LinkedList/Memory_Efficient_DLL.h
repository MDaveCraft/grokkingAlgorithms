#pragma once
typedef struct MEDLL{
	int data;
	struct MEDLL* ptrDiff;
}MEDLL;
MEDLL* NextNode(MEDLL* pNode,MEDLL* pPrevNode) {
  return ((MEDLL*) ((int)pNode->ptrDiff ^ (int)pPrevNode));
}
