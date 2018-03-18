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
double addDigits(double sum, double digits);
double removeDigit(double sum);
double reverseDigits(double sum);

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
		return addDigits(sum, (double)tkn.value);
	}

	if(tkn.func == REMOVEDIGIT) {
		return removeDigit(sum);
	}

	if(tkn.func == REVERSE) {
		return reverseDigits(sum);
	}

	return sum;
}

void tokenPrint(token tkn) {
	printf("%s Value:%d \n", tokenFunctionString(tkn), tkn.value);
}

char* tokenFunctionString(token tkn) {
	char* result;

	result = "NULL";

	if(tkn.func == NEGATE) {
		result = "NEGATE";
	}

	if(tkn.func == ADDDIGIT) {
		result = "ADDDIGIT";
	}

	if(tkn.func == REMOVEDIGIT) {
		result = "REMOVEDIGIT";
	}

	if(tkn.func == ADD) {
		result = "ADD";
	}

	if(tkn.func == SUBTRACT) {
		result = "SUBTRACT";
	}

	if(tkn.func == MULTIPLY) {
		result = "MULTIPLY";
	}

	if(tkn.func == DIVIDE) {
		result = "DIVIDE";
	}

	if(tkn.func == REVERSE) {
		result = "REVERSE";
	}

	return result;
}

double addDigits(double sum, double digits) {
	return sum * pow(10,log10(digits) + 1) + digits;
}

double removeDigit(double sum) {
	return sum * floor(0.1);
}

double reverseDigits(double sum) {
	int number = (int)sum;
	double reverse = 0;

	while(number > 0) {
		int lastDigit = (int)number % 10;
		reverse = reverse * 10 + lastDigit;
		number /= 10;
	}
	return reverse;
}
