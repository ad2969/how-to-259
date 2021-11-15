/*
 File:            quiz3-v3.h
 Purpose:         CPSC259 In-lab quiz 3
                  THIS FILE WILL NOT BE SUBMITTED
                  DO NOT MAKE OTHER CHANGES TO THIS FILE
 Author:          Your Name
 Student Number:  12345678
 CWL:             yourCWL
 Date:            Add the date here
 */

#pragma once

 /*
  * Converts an integer to binary, and prints the binary number to the screen.
  *
  * Recall that decimal integers are base 10, so we add a digit for every multiple
  * of 10.
  *
  * Recall that binary is base 2, so we add a digit for every multiple of 2.
  * For example:
  * 2 = (2 * 1) + (1 * 0) =  10
  * 10 = (8 * 1) + (4 * 0) + (2 * 1) + (1 * 0) = 1010
  * 100 = (64 * 1) + (32 * 1) + (16 * 0) + (8 * 0) + (4 + 1) + (2 * 0) + (1 * 0) = 1100100
  *
  * We can perform the conversion by keeping track of
  * a sequence of remainders after division by 2,
  * until the quotient is zero
  * e.g. to convert 100 (in base 10):
  *
  * 2 ) 100       ^
  *      50 R 0   |
  *  2 ) 50       ^
  *      25 R 0   |
  *  2 ) 25       |
  *      12 R 1   ^
  *  2 ) 12       |
  *       6 R 0   |
  *   2 ) 6       ^
  *       3 R 0   |
  *   2 ) 3       |
  *       1 R 1   ^
  *   2 ) 1       |
  *       0 R 1   |  Read the remainders from bottom upwards
  *
  * The remainders are obtained from top to bottom, but the result
  * is reported from bottom to top. Note that a stack is useful for
  * reversing sequences.
  * Don't forget that a C-string must end with a null character '\0'
  *
  * PARAM:  number_to_convert, a positive non-zero integer
  * PARAM:  converted_string, a char string of '1's and '0's representing the
  *         converted binary number
  * PRE:    number_to_convert, a positive non-zero integer
  * POST:   number_to_convert is converted to a C-string of '1's and '0's
  *         with the sequence stored into converted_string
  * RETURN: N/A
  */
void convert_to_binary(int number_to_convert, char* converted_string);