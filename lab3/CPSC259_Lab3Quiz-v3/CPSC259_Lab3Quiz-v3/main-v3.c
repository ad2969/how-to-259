/*
 File:            main-v3.c
 Purpose:         CPSC259 In-lab quiz 3
 Author:          Your Name
 Student Number:  12345678
 CWL:             yourCWL
 Date:            Add the date here
 */


 /* Preprocessor directives */
#define _CRT_SECURE_NO_WARNINGS

#define NUMERIC_BUFFER_SIZE 64 // maximum number of characters in a converted number

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_linkedlist-v3.h"
#include "quiz3-v3.h"
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
  int test_number_one = 2; // Binary is: 10
  int test_number_two = 64; // Binary is: 1000000
  int test_number_three = 63; // Binary is: 111111

  char converted_buffer[NUMERIC_BUFFER_SIZE] = "";

  /* Code that tests your function.  You don't need to write more tests. */
  printf("\n\n%d in binary is 10.  Your function calculated it to be:\n", test_number_one);
  convert_to_binary(test_number_one, converted_buffer);
  printf("%s\n", converted_buffer);

  printf("\n\n%d in binary is 1000000.  Your function calculated it to be:\n", test_number_two);
  convert_to_binary(test_number_two, converted_buffer);
  printf("%s\n", converted_buffer);

  printf("\n\n%d in binary is 111111.  Your function calculated it to be:\n", test_number_three);
  convert_to_binary(test_number_three, converted_buffer);
  printf("%s\n", converted_buffer);

  printf("\n\n");

  system("pause");
  return 0;
}
