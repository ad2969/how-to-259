/* 
 *  A Stack ADT which stores integer values
 */

#pragma once

#include "stack.h"

// Prepares st for initial use
void Initialize(Stack* st);

// Returns 1 if st is empty, 0 otherwise
int IsEmpty(Stack* st);

// Returns the item at the top of st (-1 if st is empty)
int Peek(Stack* st);

// Inserts an item to the top of st
void Push(Stack* st, int value);

// Removes an item from st
void Pop(Stack* st);

// Inverts the positions of the k+1 elements at the top of st
// e.g. if st contains:      then InvertPartial(&st, 3) produces:
//        7                        1
//        12                       5
//        5             -->        12 
//        1                        7    <- elements here and above have been inverted
//        9                        9    <- elements here and below have not been moved
//        3                        3
void InvertPartial(Stack* st, int k);

// Orders the contents of st, smallest at the top and largest at the bottom
void StackOrder(Stack* st);