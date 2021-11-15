#pragma once

typedef struct SLLNode {
  int data;
  struct SLLNode* next;
} SLLNode;

SLLNode* SLLInsertFront(SLLNode* front, int value);

void SLLDestroyList(SLLNode* front);

void SLLPrintList(SLLNode* node);

void Weave(SLLNode* list1, SLLNode** list2);