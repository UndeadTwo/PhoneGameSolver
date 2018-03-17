#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef enum {
	NEGATE,
	SUBTRACT,
	ADD,
	MULTIPLY,
	DIVIDE,
	ADDDIGIT,
	REMOVEDIGIT,
	REVERSE
} tokenFunction;

typedef struct {
	tokenFunction func;
	int value;
} token;

void reverse_string(char *str);
char* tokenFunctionString(token tkn);

token tokenBuilder(char* tokenString) {

	int bufferSize = strlen(tokenString) - 3;
	char buffer[bufferSize];
	memmove(buffer, tokenString + 3, bufferSize);

	int value = atoi(buffer);
	token newToken;

	if(strncmp(tokenString, "neg", 3) == 0) {
		newToken.func = NEGATE;
	} else if(strncmp(tokenString, "add", 3) == 0) {
		newToken.func = ADD;
	} else if(strncmp(tokenString, "sub", 3) == 0) {
		newToken.func = SUBTRACT;
	} else if(strncmp(tokenString, "mul", 3) == 0) {
		newToken.func = MULTIPLY;
	} else if(strncmp(tokenString, "div", 3) == 0) {
		newToken.func = DIVIDE;
	} else if(strncmp(tokenString, "ins", 3) == 0) {
		newToken.func = ADDDIGIT;
	} else if(strncmp(tokenString, "rmr", 3) == 0) {
		newToken.func = REMOVEDIGIT;
	} else if(strncmp(tokenString, "rvs", 3) == 0) {
		newToken.func = REVERSE;
	}

	newToken.value = value;
	return newToken;
}

double tokenApplier(double sum, token tkn) {
	if(tkn.func == NEGATE) {
		return -sum;
	}

	if(tkn.func == SUBTRACT) {
		return sum - (double)tkn.value;
	}

	if(tkn.func == ADD) {
		return sum + (double)tkn.value;
	}

	if(tkn.func == MULTIPLY) {
		return sum * (double)tkn.value;
	}

	if(tkn.func == DIVIDE) {
		return sum / (double)tkn.value;
	}

	if(tkn.func == ADDDIGIT) {
		int bufferSize = (int)(ceil(log10(sum)) + 3 + ceil(log10(tkn.value)) + 3);
		char buffer[bufferSize];

		snprintf(buffer, bufferSize, "%f%d", sum, tkn.value);

		return atof(buffer);
	}

	if(tkn.func == REMOVEDIGIT) {
		int bufferSize = (int)(ceil(log10(sum)) + 3);
		char buffer[bufferSize];

		snprintf(buffer, bufferSize, "%f", sum);

		return atof(buffer);
	}

	if(tkn.func == REVERSE) {
		int bufferSize = (int)(ceil(log10(sum)) + 1);
		char buffer[bufferSize];
		snprintf(buffer, bufferSize, "%d", (int)sum);
		reverse_string(buffer);
		return atof(buffer);
	}

	return sum;
}

void tokenPrint(token tkn) {
	printf("%s Value:%d\n", tokenFunctionString(tkn), tkn.value);
}

char* tokenFunctionString(token tkn) {
	if(tkn.func == NEGATE) {
		return "NEGATE";
	}

	if(tkn.func == ADDDIGIT) {
		return "ADDDIGIT";
	}

	if(tkn.func == REMOVEDIGIT) {
		return "REMOVEDIGIT";
	}

	if(tkn.func == ADD) {
		return "ADD";
	}

	if(tkn.func == SUBTRACT) {
		return "SUBTRACT";
	}

	if(tkn.func == MULTIPLY) {
		return "MULTIPLY";
	}

	if(tkn.func == DIVIDE) {
		return "DIVIDE";
	}

	if(tkn.func == REVERSE) {
		return "REVERSE";
	}

	return "NULL";
}

// From: https://stackoverflow.com/questions/784417/reversing-a-string-in-c
void reverse_string(char *str)
{
    /* skip null */
    if (str == 0)
    {
        return;
    }

    /* skip empty string */
    if (*str == 0)
    {
        return;
    }

    /* get range */
    char *start = str;
    char *end = start + strlen(str) - 1; /* -1 for \0 */
    char temp;

    /* reverse */
    while (end > start)
    {
        /* swap */
        temp = *start;
        *start = *end;
        *end = temp;

        /* move */
        ++start;
        --end;
    }
}
