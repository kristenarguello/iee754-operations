#include <string.h>
#include <ctype.h>


#include "headers/utils.h"

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

void toLowerCase(char *str) {
    if (str) {
        while (*str) {
            *str = tolower((unsigned char) *str);
            str++;
        }
    }
}

int numbersChecker(char *number) {
    // TODO: finish implementing this shit
    // dois valores em ponto flutuante, NaN ou ±∞
    toLowerCase(number);
    if (strcmp(number, "nan") == 0)
        return 1;
    if (strcmp(number, "+infinity") == 0)
        return 1;   
    if (strcmp(number, "-infinity") == 0)
        return 1;

    
    else return 1;
    // return 0;
}

float calculate(float a, char *operation, float b) {
    if (strcmp(operation, "+") == 0) {
        return a + b;
    } else if (strcmp(operation, "-") == 0) {
        return a - b;
    } else if (strcmp(operation, "x") == 0) {
        return a * b;
    } else if (strcmp(operation, "/") == 0) {
        return a / b;
    } else {
        return 0;
    }
}
