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
			printf("%.0f ", *(mxGetPr(matrix) + (i * dimensions) + j));
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
	*ConnectivityMatrix = mxCreateDoubleMatrix(*dimensions, *dimensions, mxREAL);

	// get to the top of the file and start reading
	fseek(filePointer, 0, SEEK_SET);
	while ((ch = fgetc(filePointer)) != EOF) {
		if (ch == '\n') {
			i = 0;
			j++;
		}
		else if (ch != ' ') {
			mxGetPr(*ConnectivityMatrix)[i * (*dimensions) + j] = (double)ch - 48;
			i++;
		}
	}

	if (j != *dimensions - 1) {
		fprintf(stderr, "The provided matrix is not square (#rows = #columns)");
		exit(EXIT_FAILURE);
	}
}

int main(void) {
	/* Variables */
	int error = 0;
	int dimensions;
	char buffer[BUFSIZE + 1];

	Engine* ep = NULL;
	FILE* filePointer = NULL;

	mxArray* ConnectivityMatrix = NULL;
	mxArray* PageRank = NULL;

	// open the file
	printf("Loading file '%s'...\n", FILE_NAME);
	error = fopen_s(&filePointer, FILE_NAME, "r");
	if (error != 0) {
		fprintf(stderr, "File %s cannot be loaded\n", FILE_NAME);
		exit(EXIT_FAILURE);
	}

	// get connectivity matrix
	get_connectivity_matrix(filePointer, &dimensions, &ConnectivityMatrix);
	printf("\nLoaded %i x %i connectivity matrix:\n", dimensions, dimensions);
	print_ml_matrix(ConnectivityMatrix, dimensions);

	// connect to matlab engine
	if (!(ep = engOpen(NULL))) {
		fprintf(stderr, "\nCan't start MATLAB engine\n");
		exit(EXIT_FAILURE);
	}
	if (engOutputBuffer(ep, buffer, BUFSIZE)) {
		fprintf(stderr, "\nCan't create buffer for MATLAB output\n");
		exit(EXIT_FAILURE);
	}

	// save variables to matlab
	if (engPutVariable(ep, "ConnectivityMatrix", ConnectivityMatrix)) {
		fprintf(stderr, "\nCannot write connectivity matrix to MATLAB\n");
		exit(EXIT_FAILURE);
	}
	mxArray* MXDimensions = mxCreateDoubleScalar(dimensions);
	if (engPutVariable(ep, "dimension", MXDimensions)) {
		fprintf(stderr, "\nCannot write dimension variable to MATLAB\n");
		exit(EXIT_FAILURE);
	}
	mxArray* MXPF = mxCreateDoubleScalar(PROBABILITY_FACTOR);
	if (engPutVariable(ep, "pf", MXPF)) {
		fprintf(stderr, "\nCannot write pf variable to MATLAB\n");
		exit(EXIT_FAILURE);
	}

	// do the matlab calculations
	if (engEvalString(ep, "columnsums = sum(ConnectivityMatrix, 1); zerocolumns = find(columnsums ~= 0);")) {
		fprintf(stderr, "\nError getting connectivity matrix parameters\n");
		exit(EXIT_FAILURE);
	}
	if (engEvalString(ep, "D = sparse(zerocolumns, zerocolumns, 1./columnsums(zerocolumns), dimension, dimension);")) {
		fprintf(stderr, "\nError creating sparse matrix\n");
		exit(EXIT_FAILURE);
	}
	if (engEvalString(ep, "StochasticMatrix = ConnectivityMatrix * D;")) {
		fprintf(stderr, "\nError calculating stochastic matrix\n");
		exit(EXIT_FAILURE);
	}
	if (engEvalString(ep, "[row, column] = find(columnsums == 0); StochasticMatrix(:, column) = 1./dimension;")) {
		fprintf(stderr, "\nError filling stochastic matrix\n");
		exit(EXIT_FAILURE);
	}
	if (engEvalString(ep, "Q = ones(dimension, dimension);")) {
		fprintf(stderr, "\nError creating scaling matrix\n");
		exit(EXIT_FAILURE);
	}
	if (engEvalString(ep, "TransitionMatrix = pf * StochasticMatrix + (1 - pf) * (Q/dimension);")) {
		fprintf(stderr, "\nError calculating transition matrix\n");
		exit(EXIT_FAILURE);
	}
	if (engEvalString(ep, "PageRank = ones(dimension, 1);")) {
		fprintf(stderr, "\nError initializing pagerank\n");
		exit(EXIT_FAILURE);
	}
	if (engEvalString(ep, "for i = 1:100 PageRank = TransitionMatrix * PageRank; end")) {
		fprintf(stderr, "\nError calculating pagerank\n");
		exit(EXIT_FAILURE);
	}
	if (engEvalString(ep, "PageRank = PageRank / sum(PageRank)")) {
		fprintf(stderr, "\nError normalizing pagerank\n");
		exit(EXIT_FAILURE);
	}

	// get matlab results
	if ((PageRank = engGetVariable(ep, "PageRank")) == NULL) {
		fprintf(stderr, "\nFailed to retrieve result matrix\n");
		exit(EXIT_FAILURE);
	}

	printf("\nNODE  RANK");
	printf("\n---   ----\n");
	for (int i = 0; i < dimensions; ++i) {
		printf("%i     %.4f\n", i + 1, mxGetPr(PageRank)[i]);
	}
	printf("\n");

	// cleaning and closing matlab engine
	mxDestroyArray(ConnectivityMatrix);
	mxDestroyArray(PageRank);

	if (engClose(ep)) {
		fprintf(stderr, "\nFailed to close MATLAB engine\n");
	}

	system("PAUSE");
	return 0;
}
