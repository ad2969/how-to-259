/*
File:         main.c
Purpose:      Calls the run_analysis function in tide_analyzer
Author:			  Your names
Student #s:		12345678 and 12345678
CS Accounts:	a1a1 and b2b2
Date:				  Add the date here
*/

/******************************************************************
DO NOT EDIT THIS FILE
******************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tide_analyzer.h"
#include "discrete_fourier_transform.h"

/*
Main function drives the program.
PRE:       NULL (no pre-conditions)
POST:      NULL (no side-effects)
RETURN:    IF the program exits correctly THEN 0 ELSE 1
*/
int main(void)
{
  run_analysis();
  system("pause");
  return 0;
}