#include <stdlib.h>
#include <stdio.h>

#include "singlylinkedlist.h"

// Inserts a new element at the front of the list,
// returns a pointer to the newly inserted node
// Call as mylist = SLLInsertFront(mylist, somevalue);
SLLNode* SLLInsertFront(SLLNode* front, int value) {
  // allocate node and set its attributes
  SLLNode* newnode = (SLLNode*)malloc(sizeof(SLLNode));
  newnode->next = NULL;
  newnode->data = value;

  // special case: empty list
  if (front == NULL) {
    return newnode;
  }
  else {
    newnode->next = front;
    return newnode;
  }
}

void SLLPrintList(SLLNode* node) {
  SLLNode* nd = node;
  while (nd != NULL) {
    printf("%d ", nd->data);
    nd = nd->next;
  }
  printf("\n");
}

void SLLDestroyList(SLLNode* front) {
  SLLNode* nd = front;
  while (nd != NULL) {
    front = nd;
    nd = nd->next;
    free(front);
  }
}