/*
 File:           quiz2-v6.c
 Purpose:	       CPSC259 In-lab quiz 2
 Author:         Your Name
 Student Number: 12345678
 CS Account:     a1a1
 Date:	      	 Add the date here
*/

/* Preprocessor directives */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "quiz2-v6.h"

/*
 * Replaces every instance of a character passed in the remove_me string
 * with an asterisk (*), and stores the number of characters removed in the integer
 * whose pointer is passed to the function.
 * For example, invoking
 * string_fun(&count, "ABCBCA", "AB") stores 4 in count, and changes segment to "**C*C*".
 * PARAM: count, a pointer to an int
 * PARAM: segment, an array of char (a string)
 * PARAM: remove_me, an array of char (a string)
 * PRE:   count is a pointer to an int
 * PRE:   segment is an array of char that ends with '\0' (segment is a string)
 * PRE:   remove_me is an array of char that ends with '\0' (remove_me is a string)
 * POST:  count stores the numbers of times a character in remove_me was removed
 * POST:  every instance of the chars in remove_me has been replaced with an asterisk (*)
 */
void string_fun (int * count, char * segment, char * remove_me )
{
	// Insert your code here
	int segment_length = strlen(segment);
	int remove_length = strlen(remove_me);
	char* found_index = "\0";
	char* temp_segment = (char*) malloc(segment_length * sizeof(char));
	char temp[] = "\0";

	int i;

	for (i = 0; i < segment_length; ++i) {
		// see if it is to be removed
		strncpy(temp, &segment[i], 1);
		found_index = strstr(remove_me, temp);

		// if found, replace with star instead
		if (found_index) {
			segment[i] = '*';
			*count = *count + 1;
		}

		// reset the found index
		found_index = "\0";
	}
}