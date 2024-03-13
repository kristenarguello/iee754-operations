#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h> 


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

void getBit(int number, int size)
{
    int position;
    for (position = size - 1; position >= 0; position--) {
 
        if ((number >> position) & 1)
            printf("1");
        else 
            printf("0");
    }   
}

void floatToBinary(char* val, float f) {
    binary ieee;
    ieee.f = f;
    printf("%s = ", val);

    getBit(ieee.ieee.sign, 1);
    printf(" ");
    getBit(ieee.ieee.exponent, 8);
    printf(" ");
    getBit(ieee.ieee.mantissa, 23);

    printf(" = %f\n", f);
}

int isFloat(char *str) {
    char *endptr;
    strtod(str, &endptr);

    if (*endptr != '\0') {
        return 0; 
    }
    return 1;
}




