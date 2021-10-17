/*
 File:           main-v6.c
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
 * Main function drives the program.
 * PRE:       NULL (no pre-conditions)
 * POST:      NULL (no side-effects)
 * RETURN:    IF the program exits correctly
 *            THEN 0 ELSE 1
 */
int main(void)
{
  /* Variable list */
  int count = 0;
  char segment[] = "CCGTCATGGTTGGGAGCAACGATTGTTCTGATTTCGACTTCCCCACATCCTCGGGATTTGGTACGCTCACCGGTCTTATAAAGTGTTCATTC";
  char remove_me[] = "AC";

  string_fun(&count, segment, remove_me);

  // print result of string_fun
  printf("Number of characters removed from segment: %d\n", count);
  printf("Modified segment:\n%s\n", segment);

  //system("pause");
  return 0;
}