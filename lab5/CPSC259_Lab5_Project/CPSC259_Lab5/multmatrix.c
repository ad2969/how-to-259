#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"

#define BUFSIZE 256
#define DIMENSIONS 3

void printMLMatrix(mxArray* matrix, int dimensions);

void printMLMatrix(mxArray* matrix, int dimensions) {
	size_t i = 0;
	size_t j = 0;
	int size = mxGetNumberOfElements(matrix);

	for (j = 0; j < size / dimensions; ++j) {
		for (i = 0; i < size / dimensions; ++i) {
			printf("%.6f ", *(mxGetPr(matrix) + (i * 3) + j));
		}
		printf("\n");
	}
}

int main(void) {
	/* Variables */
	Engine* ep = NULL;
	mxArray* matrixOne = NULL;
	mxArray* matrixTwo = NULL;
	mxArray* result = NULL;
	double mtxOne[DIMENSIONS][DIMENSIONS] = { { 1.0, 2.0, 3.0 }, { 4.0, 5.0, 6.0 }, { 7.0, 8.0, 9.0 } };
	double mtxTwo[DIMENSIONS][DIMENSIONS] = { { 2.0, 2.0, 2.0 }, { 3.0, 3.0, 3.0 }, { 4.0, 4.0, 4.0 } };
	char buffer[BUFSIZE + 1];

	if (!(ep = engOpen(NULL))) {
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		system("pause");
		return 1;
	}

	/* Create buffer string for automatically capturing MATLAB engine output */
	if (engOutputBuffer(ep, buffer, BUFSIZE)) {
		fprintf(stderr, "\nCan't create buffer for MATLAB output\n");
		system("pause");
		return 1;
	}
	buffer[BUFSIZE] = '\0';

	matrixOne = mxCreateDoubleMatrix(DIMENSIONS, DIMENSIONS, mxREAL);
	memcpy((void*)mxGetPr(matrixOne), (void*)mtxOne, 9 * sizeof(double));
	matrixTwo = mxCreateDoubleMatrix(DIMENSIONS, DIMENSIONS, mxREAL);
	memcpy((void*)mxGetPr(matrixTwo), (void*)mtxTwo, 9 * sizeof(double));

	if (engPutVariable(ep, "matrixOne", matrixOne)) {
		fprintf(stderr, "\nCannot write matrix one to MATLAB\n");
		system("pause");
		exit(1);
	}
	if (engPutVariable(ep, "matrixTwo", matrixTwo)) {
		fprintf(stderr, "\nCannot write matrix two to MATLAB\n");
		system("pause");
		exit(1);
	}

	if (engEvalString(ep, "resultMatrix = matrixOne * matrixTwo")) {
		fprintf(stderr, "\nError multiplying matrices\n");
		system("pause");
		exit(1);
	}

	if ((result = engGetVariable(ep, "resultMatrix")) == NULL) {
		fprintf(stderr, "\nFailed to retrieve result matrix\n");
		system("pause");
		exit(1);
	}
	else {
		size_t i = 0;
		size_t j = 0;

		/* Print all the required stuff */
		printf("The first matrix was:\n");
		printMLMatrix(matrixOne, DIMENSIONS);

		printf("The second matrix was:\n");
		printMLMatrix(matrixTwo, DIMENSIONS);

		printf("The matrix product is:\n");
		printMLMatrix(result, DIMENSIONS);
	}

	engEvalString(ep, "whos");
	printf("%s\n", buffer);

	mxDestroyArray(matrixOne);
	mxDestroyArray(matrixTwo);
	mxDestroyArray(result);
	matrixOne = NULL;
	matrixTwo = NULL;
	result = NULL;

	if (engClose(ep)) {
		fprintf(stderr, "\nFailed to close MATLAB engine\n");
	}

	system("pause");
	return 0;
}
