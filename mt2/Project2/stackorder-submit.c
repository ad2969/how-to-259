/*
 *  ADD YOUR STUDENT INFORMATION HERE
 *
 *  Name:
 *  Student number:
 *  CWL:
 */

#include <stdlib.h>

#include "stack.h"
#include "stackfunctions.h"

 // Reorders the contents of st so that the largest-valued items
 // are at the bottom end of the stack, and the smallest-valued items
 // are at the top end of the stack, by repeatedly using calls to
 // InvertPartial with appropriate values of k
 // This is to be done using only the local variables that have already
 // been declared for you (another Stack, and two integers).
 // You may NOT declare any other variables into local or dynamic memory,
 // nor may you access attributes of st directly.
 // Consider st to be a black box, and you can only interact with it via
 // the functions defined in stackfunctions.h
 // 
 // There will be heavy penalties for solutions that declare and use
 // local variables and functions other than the ones provided.
 //
 // HINT: The main logic will be based around making two calls to InvertPartial
 //       within a loop.
void StackOrder(Stack* st) {
    // LOCAL VARIABLE DECLARATIONS (DO NOT DECLARE ANY MORE)
    Stack tempstack; // A separate stack for temporarily holding values transferred from st
    int st_size;     // A variable which will eventually hold the number of items in st
    int items_processed = 0; // A variable which will keep track of the number of elements
                             // placed into their final ordered position (at the bottom of the stack)
    int current_max_value;   // For holding the maximum value encountered for a round of processing
    int current_max_position; // index (from the top, where top = 0) of the maximum element found
    int i;                   // A variable used for counting
    // END LOCAL VARIABLE DECLARATIONS

    Initialize(&tempstack);

    // get the number of items in the input stack
    // This involves removing all of the items in st
    // to count them (storing them temporarily in tempstack),
    // and then replacing them back into the original stack.
    st_size = 0;
    while (!IsEmpty(st)) {
        Push(&tempstack, Peek(st));
        Pop(st);
        st_size++;
    }
    // at this point, all items have been counted and transferred to tempstack.
    // Now put them back into st
    while (!IsEmpty(&tempstack)) {
        Push(st, Peek(&tempstack));
        Pop(&tempstack);
    }

    /* BEGIN YOUR SOLUTION HERE */

}