#include <string.h>

#include "utils.h"

int operationChecker(char *operation) {
    if (strcmp(operation, "+") == 0) {
        return 1;
    } else if (strcmp(operation, "-") == 0) {
        return 1;
    } else if (strcmp(operation, "∗") == 0) {
        return 1;
    } else if (strcmp(operation, "/") == 0) {
        return 1;
    } else {
        return 0;
    }
}

int numbersChecker(char *number) {
    // dois valores em ponto flutuante, NaN ou ±∞
    return 1;
}

float calculate(float a, char *operation, float b) {
    if (strcmp(operation, "+") == 0) {
        return a + b;
    } else if (strcmp(operation, "-") == 0) {
        return a - b;
    } else if (strcmp(operation, "∗") == 0) {
        return a * b;
    } else if (strcmp(operation, "/") == 0) {
        return a / b;
    } else {
        return 0;
    }
}

char* floatToBinary(float f) {
    return "0 10000011 01010000000000000000000";
}

int isInexact(float resultado) {
    return 0;
}

int isDivByZero(float segundoNumero) {
    return 0;
}

int isUnderflow(float resultado) {
    return 0;
}

int isOverflow(float resultado) {
    return 0;
}

int isInvalidOperation(float resultado) {
    return 0;
}
