/*
 File:           quiz4-v1.c
 Purpose:        Implementation for CPSC259 in-lab quiz 4
                 COMPLETE THE REQUIRED FUNCTION RECURSIVELY
                 SUBMIT THIS FILE TO PRAIRIELEARN
 Author:         Your Name
 Student Number: 12345678
 CWL:            yourcwl
 Date:           Add the date here
*/

/* Preprocessor directives */
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include "quiz4-v1.h"

/*
 *  Recursively reverses a singly-linked list
 *  Perform the reversal by reassigning pointer links.
 *  Do NOT "reverse" by swapping values of the data attribute.
 *
 *  HINT: TRUST THE NATURAL RECURSION
 *  Reversal of the current list involves recursively reversing a smaller list.
 *  Assuming the smaller list is correctly reversed, what do we need to do
 *  with our current list/element to construct the fully-reversed list from the
 *  reversed partial list?
 *
 *  PARAM:  the front of the list which will be reversed
 *  POST:   the list pointed to by head is reversed,
 *          and head points to the new front of the list
 *  RETURN: the (new) front of the list which is now reversed
 */
Node* reverse(Node* head)
{
    // edge case for when an empty linked list is passed
    if (head == NULL) {
        return NULL;
    }

    // return the last address
    if (head->next == NULL) {
        return head;
    }

    // store values first
    Node* currNode = head;
    Node* nextNode = head->next;

    // reset head's info of the next node
    head->next = NULL;

    // before making changes to nextNode, we need to obtain the information we need first
    head = reverse(nextNode);

    // then, because we know there is a nextNode, we can make reverse it 
    nextNode->next = currNode;

    // return the last address
    return head;
}