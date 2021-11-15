/*
 File:           main-v1.c
 Purpose:        Driver for CPSC259 in-lab quiz 4
                 YOU MAY ADD TEST CODE TO THIS FILE
                 BUT DO NOT SUBMIT TO PRAIRIELEARN
 Author:         Your Name
 Student Number: 12345678
 CWL:            yourcwl
 Date:           Add the date here
*/

/* Preprocessor directives */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "quiz4-v1.h"

/* Forward function declarations */
Node* createList(int length);
Node* destroyList(Node* head);
void  printListContents(Node* head);

/*
 * Main function drives the program.
 * PRE:       NULL (no pre-conditions)
 * POST:      NULL (no side-effects)
 * RETURN:    IF the program exits correctly
 *            THEN 0 ELSE 1
 */
int main(void)
{
  printf("Test case 1: reverse an empty list\n");
  Node* test_list_empty = NULL;
  printf("Contents of list before reversal: ");
  printListContents(test_list_empty);
  test_list_empty = reverse(test_list_empty);
  printf("Contents of list after reversal:  ");
  printListContents(test_list_empty);
  printf("\n");
  // cleanup
  test_list_empty = destroyList(test_list_empty);

  printf("Test case 2: reverse a size 1 list\n");
  Node* test_list_1 = createList(1);
  printf("Contents of list before reversal: ");
  printListContents(test_list_1);
  test_list_1 = reverse(test_list_1);
  printf("Contents of list after reversal:  ");
  printListContents(test_list_1);
  printf("\n");
  // cleanup
  test_list_1 = destroyList(test_list_1);

  printf("Test case 3: reverse a size 2 list\n");
  Node* test_list_2 = createList(2);
  printf("Contents of list before reversal: ");
  printListContents(test_list_2);
  test_list_2 = reverse(test_list_2);
  printf("Contents of list after reversal:  ");
  printListContents(test_list_2);
  printf("\n");
  // cleanup
  test_list_2 = destroyList(test_list_2);

  printf("Test case 4: reverse a size 3 list\n");
  Node* test_list_3 = createList(3);
  printf("Contents of list before reversal: ");
  printListContents(test_list_3);
  test_list_3 = reverse(test_list_3);
  printf("Contents of list after reversal:  ");
  printListContents(test_list_3);
  printf("\n");
  // cleanup
  test_list_3 = destroyList(test_list_3);

  printf("Test case 5: reverse a long list of odd length\n");
  Node* test_list_15 = createList(15);
  printf("Contents of list before reversal: ");
  printListContents(test_list_15);
  test_list_15 = reverse(test_list_15);
  printf("Contents of list after reversal:  ");
  printListContents(test_list_15);
  printf("\n");
  // cleanup
  test_list_15 = destroyList(test_list_15);

  printf("Test case 6: reverse a long list of even length\n");
  Node* test_list_16 = createList(16);
  printf("Contents of list before reversal: ");
  printListContents(test_list_16);
  test_list_16 = reverse(test_list_16);
  printf("Contents of list after reversal:  ");
  printListContents(test_list_16);
  printf("\n");
  // cleanup
  test_list_16 = destroyList(test_list_16);

  system("pause");
  return 0;
}

/*
 * Returns a list with length elements containing data 0 to n-1
 *
 * PARAM:  length, the number of nodes to be added to the list
 * RETURN: the head node of the new list
 */
Node* createList(int length)
{
  int i;
  Node* current;
  Node* newNode;
  Node* head;

  if (length == 0) {
    return NULL;
  }
  else {
    head = (Node*) malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    current = head;
    for (i = 1; i < length; i++) {
      newNode = (Node*) malloc(sizeof(Node));
      newNode->data = i;
      newNode->next = NULL;
      current->next = newNode;
      current = newNode;
    }
    return head;
  }
}

/*
 * Deletes a list
 *
 * PARAM:  head node of list to delete
 * RETURN: NULL, to be assigned to the list which calls the function
 * POST:   list with head node at head has been deallocated
 */
Node* destroyList(Node* head)
{
  Node* temp = head;
  while (head != NULL)
  {
    head = head->next;
    free(temp);
    temp = head;
  }
  return NULL;
}

/*
 * Prints the contents of the list
 *
 * PARAM:  head node of the list to print
 * POST:   contents of the list have been printed to the console
 */
void  printListContents(Node* head)
{
  while (head != NULL)
  {
    printf("%3d ", head->data);
    head = head->next;
  }
  printf("\n");
}