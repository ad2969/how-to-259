#include <stdlib.h>
#include <stdio.h>

#include "singlylinkedlist.h"

// testing functions
void TestWeave();

int main(void) {

  TestWeave();

  return 0;
}

void TestWeave() {
  printf("TestWeave includes the two examples given in the PrairieLearn diagram. You may add your own test cases to this.\n");

  printf("Example 1\n");

  // prepare the first list
  SLLNode* front1 = NULL;
  front1 = SLLInsertFront(front1, 11);
  front1 = SLLInsertFront(front1, 9);
  front1 = SLLInsertFront(front1, 7);
  front1 = SLLInsertFront(front1, 5);
  front1 = SLLInsertFront(front1, 3);
  front1 = SLLInsertFront(front1, 1);

  // prepare the second list
  SLLNode* front2 = NULL;
  front2 = SLLInsertFront(front2, 8);
  front2 = SLLInsertFront(front2, 6);
  front2 = SLLInsertFront(front2, 4);
  front2 = SLLInsertFront(front2, 2);

  printf("list1 and list2 prepared.\n");
  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");
  
  printf("Calling Weave... ");
  Weave(front1, &front2);
  printf("done.\n");

  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");

  // cleanup
  SLLDestroyList(front1);
  front1 = NULL;
  SLLDestroyList(front2);
  front2 = NULL;

  printf("Example 2\n");

  // prepare the first list
  front1 = NULL;
  front1 = SLLInsertFront(front1, 6);
  front1 = SLLInsertFront(front1, 3);
  front1 = SLLInsertFront(front1, 2);
  front1 = SLLInsertFront(front1, 9);

  // prepare the second list
  front2 = NULL;
  front2 = SLLInsertFront(front2, 12);
  front2 = SLLInsertFront(front2, 4);
  front2 = SLLInsertFront(front2, 8);
  front2 = SLLInsertFront(front2, 13);
  front2 = SLLInsertFront(front2, 1);
  front2 = SLLInsertFront(front2, 5);

  printf("list1 and list2 prepared.\n");
  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");

  printf("Calling Weave... ");
  Weave(front1, &front2);
  printf("done.\n");

  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");

  printf("Example 3\n");

  // prepare the first list
  front1 = NULL;

  // prepare the second list
  front2 = NULL;

  printf("list1 and list2 prepared.\n");
  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");

  printf("Calling Weave... ");
  Weave(front1, &front2);
  printf("done.\n");

  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");

  printf("Example 4\n");

  // prepare the first list
  front1 = NULL;
  front1 = SLLInsertFront(front1, 100);

  // prepare the second list
  front2 = NULL;
  front2 = SLLInsertFront(front2, 98);
  front2 = SLLInsertFront(front2, 99);

  printf("list1 and list2 prepared.\n");
  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");

  printf("Calling Weave... ");
  Weave(front1, &front2);
  printf("done.\n");

  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");

  printf("Example 5\n");

  // prepare the first list
  front1 = NULL;

  // prepare the second list
  front2 = NULL;
  front2 = SLLInsertFront(front2, 98);
  front2 = SLLInsertFront(front2, 99);
  front2 = SLLInsertFront(front2, 100);

  printf("list1 and list2 prepared.\n");
  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");

  printf("Calling Weave... ");
  Weave(front1, &front2);
  printf("done.\n");

  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");

  printf("Example 6\n");

  // prepare the first list
  front1 = NULL;
  front1 = SLLInsertFront(front1, 98);
  front1 = SLLInsertFront(front1, 99);
  front1 = SLLInsertFront(front1, 100);

  // prepare the second list
  front2 = NULL;

  printf("list1 and list2 prepared.\n");
  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");

  printf("Calling Weave... ");
  Weave(front1, &front2);
  printf("done.\n");

  printf("list1 contents:\n");
  SLLPrintList(front1);
  printf("\n");
  printf("list2 contents:\n");
  SLLPrintList(front2);
  printf("\n");

  // cleanup
  SLLDestroyList(front1);
  front1 = NULL;
  SLLDestroyList(front2);
  front2 = NULL;
}