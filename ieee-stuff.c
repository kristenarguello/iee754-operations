#include <stdio.h>

#include "headers/ieee-stuff.h"

// exceptions: https://docs.oracle.com/cd/E19957-01/806-3568/ncg_handle.html#:~:text=IEEE%20754%20defines%20five%20basic,be%20ignored%20when%20they%20occur


struct IEEE754 {
    unsigned int mantissa: 23;
    unsigned int exponent: 8;
    unsigned int sign: 1;
};
typedef union {
    float f;
    struct IEEE754 ieee;
} binary;

// taken from https://www.geeksforgeeks.org/program-for-conversion-of-32-bits-single-precision-ieee-754-floating-point-representation/
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

char* floatToBinary(float f) {
    binary ieee;
    ieee.f = f;
    printf("%d ", ieee.ieee.sign);
    printBinary(ieee.ieee.exponent, 8);
    printf(" ");
    printBinary(ieee.ieee.mantissa, 23);
    printf("\n");
    return "";
}

int isInexact(float resultado, int* firstRounded, int* secondRounded) {
    // if any of the inserted has to suffer rounding
    return 0;
}

void isDivByZero(float primeiroNumero, float segundoNumero, int* divZero) {
    if (segundoNumero == 0 && primeiroNumero != 0) 
        *divZero = 1;
}

int infinitySign(float primeiroNumero) {
    if (primeiroNumero > 0) {
        return 0; // positive infinity
    } else {
        return 1; // negative infinity
    }
}

void isUnderflow(float result, float a, float b, int* underflow) {
    float underflowLimit = 1.17549435e-38;
    if (result < underflowLimit || a < underflowLimit || b < underflowLimit) 
        *underflow = 1;
}

void isOverflow(float result, float a, float b, int* overflow) {
    float overflowLimit = 3.40282347e+38;
    if (result > overflowLimit || a > overflowLimit || b > overflowLimit) 
        *overflow = 1;
}

int isInvalidOperation(float resultado) {
    return 0;
}

void rounder(float f, int* firstRounded, int* secondRounded) {
    // choose a method? 
    // return the float rounded or change the binary
    // if this is used, the inexact operation is flagged
    printf("not implemented yet");

}
