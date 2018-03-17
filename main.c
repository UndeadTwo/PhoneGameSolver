#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tokenHandling.h"

void printAllKLength(token* set, int tokenCount, int k, int start, int goal);
void printAllKLengthRec(token* set, token* tokenSet, int n, int k, int m, int start, int goal);

int main(int argc, char ** argv) {
	int moves = atoi(argv[1]);
	int start = atoi(argv[argc-2]);
	int target = atoi(argv[argc-1]);

	int tokenCount = argc - 4;
	token tokens[tokenCount];

	printf("%d\n",argc);

	for(int i = 2; i < argc - 2; i++) {
		tokens[i-2] = tokenBuilder(argv[i]);
		tokenPrint(tokens[i-2]);
	}

	printAllKLength(tokens, tokenCount, moves, start, target);

	fflush(stdout);
	return 0;
}

void printAllKLength(token* set, int tokenCount, int k, int start, int goal) {
    token arry[k]; 
    printAllKLengthRec(set, arry, tokenCount, k, k, start, goal);
}
 
void printAllKLengthRec(token* set, token* tokenSet, int n, int k, int m, int start, int goal) {
    if (k == 0) {
    	double sum = (double)start;
       	for(int i = 0; i < m; i++) {
       		sum = tokenApplier(sum, tokenSet[i]);
       	}

       	if(sum == (double)goal) {
       		printf("Goal reached by: \n");
       		for(int i = 0; i < m; i++) {
       			tokenPrint(tokenSet[i]);
       		}
       		printf("Goal was %d, final sum is %d\n", goal, (int)sum);
       	} else {
       		printf("Sum was %d, goal was not met.\n", (int)sum);
       	}
        return;
    }

    for (int i = 0; i < n; ++i) {
    	tokenSet[m - k] = set[i];
        printAllKLengthRec(set, tokenSet, n, k - 1, m, start, goal); 
    }
}