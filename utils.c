#include <string.h>
#include <ctype.h>
#include <stdio.h>


#include "headers/utils.h"

int operationChecker(char *operation) {
    if (strcmp(operation, "+") == 0) {
        return 1;
    } else if (strcmp(operation, "-") == 0) {
        return 1;
    } else if (strcmp(operation, "x") == 0) {
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

    printf("not implemented yet");
    return 1;
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

// binary stuff
struct IEEE754 {
    unsigned int mantissa: 23;
    unsigned int exponent: 8;
    unsigned int sign: 1;
};
typedef union {
    float f;
    struct IEEE754 ieee;
} binary;

void printBinary(int n, int i)
{
    int k;
    for (k = i - 1; k >= 0; k--) {
 
        if ((n >> k) & 1)
            printf("1");
        else
            printf("0");
    }
}

void floatToBinary(char* val, float f) {
    binary ieee;
    ieee.f = f;
    printf("%s = ", val);
    printf("%d ", ieee.ieee.sign);
    printBinary(ieee.ieee.exponent, 8);
    printf(" ");
    printBinary(ieee.ieee.mantissa, 23);
    printf(" = %f\n", f);
}

