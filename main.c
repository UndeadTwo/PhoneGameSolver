#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "tokenHandling.h"

void getAllAnswers(token* set, int tokenCount, int k, int start, int goal);
void getAllAnswersRec(token* set, token* tokenSet, int n, int k, int m, int start, int goal);

int main(int argc, char ** argv) {
	int moves = atoi(argv[1]);
	int start = atoi(argv[argc-2]);
	int target = atoi(argv[argc-1]);

	int tokenCount = argc - 4;
	token tokens[tokenCount];

	for(int i = 2; i < argc - 2; i++) {
		tokens[i-2] = tokenBuilder(argv[i]);
	}

	getAllAnswers(tokens, tokenCount, moves, start, target);

	return 0;
}

void getAllAnswers(token* set, int tokenCount, int k, int start, int goal) {
    token arry[k]; 
    getAllAnswersRec(set, arry, tokenCount, k, k, start, goal);
}
 
void getAllAnswersRec(token* set, token* tokenSet, int n, int k, int m, int start, int goal) {
    if (k == 0) {
    	double sum = (double)start;
        // printf("Start:\n");
       	for(int i = 0; i < m; i++) {
          // tokenPrint(tokenSet[i]);
       		sum = tokenApplier(sum, tokenSet[i]);
          // printf("%f\n",sum);
       	}
        // printf("End\n");

      if(sum == goal) {
        sum = (double)start;
        printf("Start:\n");
        for(int i = 0; i < m; i++) {
          tokenPrint(tokenSet[i]);
          sum = tokenApplier(sum, tokenSet[i]);
          printf("%f\n",sum);
        }
        printf("End\n");
      }
      return;
    }

    for (int i = 0; i < n; ++i) {
    	tokenSet[m - k] = set[i];
        getAllAnswersRec(set, tokenSet, n, k - 1, m, start, goal);
    }
}