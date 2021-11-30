#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "engine.h"

#define BUFSIZE 256
#define PROBABILITY_FACTOR 0.85
#define FILE_NAME "web.txt"

void print_ml_matrix(mxArray* matrix, int dimensions);
void get_connectivity_matrix(FILE* filePointer, int* dimensions, double*** ConnectivityMatrix);

void print_ml_matrix(mxArray* matrix, int dimensions) {
	size_t i = 0;
	size_t j = 0;
	size_t size = mxGetNumberOfElements(matrix);

	for (j = 0; j < size / dimensions; ++j) {
		for (i = 0; i < size / dimensions; ++i) {
			printf("%f ", *(mxGetPr(matrix) + (i * dimensions) + j));
		}
		printf("\n");
	}
}

void get_connectivity_matrix(FILE* filePointer, int* dimensions, double*** ConnectivityMatrix) {
	char ch;
	int i = 0;
	int j = 0;
	(*dimensions) = 0;

	// get the dimensions of the matrix
	while ((ch = fgetc(filePointer)) != EOF) {
 		if (ch == '\n') break;
		else if (ch != ' ') (*dimensions) = (*dimensions) + 1;
	}

	// initialize the connectivity matrix
	*ConnectivityMatrix = (double**)malloc(sizeof(double*) * (*dimensions));
	for (i = 0; i < (*dimensions); ++i) {
		(*ConnectivityMatrix)[i] = (double*)malloc(sizeof(double) * (*dimensions));
	}

	i = 0;
	j = 0;

	// get to the top of the file and start reading
	fseek(filePointer, 0, SEEK_SET);
	while ((ch = fgetc(filePointer)) != EOF) {
		if (ch == '\n') {
			i = 0;
			j++;
		}
		else if (ch != ' ') {
			(*ConnectivityMatrix)[i][j] = (int)ch - 48;
			i++;
		}
	}
}

int main(void) {
	/* Variables */
	int error = 0;
	int dimensions;
	char buffer[BUFSIZE + 1];

	Engine* ep = NULL;
	FILE* filePointer = NULL;

	double** ConnectivityMatrix = NULL;
	mxArray* MXConnectivityMatrix = NULL;
	char** PageRank = NULL;
	mxArray* MXPageRank = NULL;

	// open the file
	printf("Loading file %s\n", FILE_NAME);
	error = fopen_s(&filePointer, FILE_NAME, "r");
	if (error != 0) {
		fprintf(stderr, "File %s cannot be loaded\n", FILE_NAME);
		exit(EXIT_FAILURE);
	}

	// get connectivity matrix
	get_connectivity_matrix(filePointer, &dimensions, &ConnectivityMatrix);

	if (!(ep = engOpen(NULL))) {
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		exit(EXIT_FAILURE);
	}

	/* Create buffer string for automatically capturing MATLAB engine output */
	if (engOutputBuffer(ep, buffer, BUFSIZE)) {
		fprintf(stderr, "\nCan't create buffer for MATLAB output\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			printf("%f ", ConnectivityMatrix[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");

	// store the connectivity matrix in matlab (need to switch rows and columns)
	MXConnectivityMatrix = mxCreateDoubleMatrix(dimensions, dimensions, mxREAL);
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			memcpy(&mxGetPr(MXConnectivityMatrix)[i * dimensions + j], &ConnectivityMatrix[j][i], sizeof(double));
		}
	}
	memcpy((void*)mxGetPr(MXConnectivityMatrix), (void*)ConnectivityMatrix, dimensions * sizeof(double));
	printf("Read a %i x %i connectivity matrix:\n", dimensions, dimensions);
	print_ml_matrix(MXConnectivityMatrix, dimensions);
	if (engPutVariable(ep, "ConnectivityMatrix", MXConnectivityMatrix)) {
		fprintf(stderr, "\nCannot write matrix one to MATLAB\n");
		exit(EXIT_FAILURE);
	}

	system("PAUSE");

	// cleaning and closing matlab engine
	mxDestroyArray(MXConnectivityMatrix);
	mxDestroyArray(MXPageRank);
	free(ConnectivityMatrix);
	free(PageRank);

	MXConnectivityMatrix = NULL;
	MXPageRank = NULL;
	ConnectivityMatrix = NULL;
	PageRank = NULL;

	if (engClose(ep)) {
		fprintf(stderr, "\nFailed to close MATLAB engine\n");
	}

	system("PAUSE");
	return 1;

	/*

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
	*/
}
