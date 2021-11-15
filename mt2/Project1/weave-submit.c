/*
 *  ADD YOUR STUDENT INFORMATION HERE
 *
 *  Name: Clarence Adrian
 *  Student number: 60595170
 *  CWL: ad2969
 */

#include <stdlib.h>

#include "singlylinkedlist.h"

 // Note that list2 is a double-pointer type. Think of this as a SLLNode*
 // passed by reference (we want to modify the actual parameter).
 // Call it as Weave(front1, &front2); where front1 and front2 are SLLNode*
 // Perform the weave by re-linking existing nodes.
 // DO NOT USE MALLOC OR FREE IN THIS FUNCTION
 // (the autograder will check node addresses)
void Weave(SLLNode* list1, SLLNode** list2) {
    // Fill in the condition below with something appropriate.
    // From the examples provided on PrairieLearn, think about how many
    // elements are in each list such that they will be processed at all.
    if (list1 != NULL && (*list2) != NULL) {
        // set up some local SLLNode pointers
        // Geoff recommends using four of them
        SLLNode* temp;
        SLLNode* head1 = list1;
        SLLNode* head2 = (*list2);
        int direction = 1;

        // Use a loop to reassign the links
        // and to move your local pointers along your lists
        // HINT: some of these may involve conditionals
        while (head1 != NULL && head2 != NULL) {
            // complete the loop body
            if (direction == 1) {
                temp = head1->next;
                head1->next = head2;
                head1 = temp;
                direction = -1;
            }
            else if (direction == -1) {
                temp = head2->next;
                head2->next = head1;
                head2 = temp;
                direction = 1;
            }

        }
        // Loop exited. By now your nodes should be correctly linked.
        // There is still one more thing left to do. Study the example image
        // and write the instruction here
        *list2 = NULL;

    }
}