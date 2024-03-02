#include <stdio.h>
#include <stdlib.h>


#include "utils.h"


int main(int argc, char *argv[]) {
    if (argc == 4) {
        float a = atof(argv[1]);
        char* operation = argv[2];
        float b = atof(argv[3]);

        if (operationChecker(operation) ) {
            float result = calculate(a, operation, b);
            printf("Recebi %f %s %f e resultado deu %f\n", a, operation, b, result);

            char* binaryA = floatToBinary(a);
            char* binaryB = floatToBinary(b);
            char* binaryResult = floatToBinary(result);

            printf("val1 = %s = %f\n", binaryA, a);
            printf("val2 = %s = %f\n", binaryB, b);
            printf("result = %s = %f\n", binaryResult, result);

            printf("\nFlags:\n");
            printf("FE_INEXACT: %d\n", isInexact(result));
            printf("FE_DIVBYZERO: %d\n", isDivByZero(b));
            printf("FE_UNDERFLOW: %d\n", isUnderflow(result));
            printf("FE_OVERFLOW: %d\n", isOverflow(result));
            printf("FE_INVALID: %d\n", isInvalidOperation(result));

            return 1;
        } else {
            printf("Operação inválida.\n");
            return 0;
        }


    } else {
        printf("Essa calculadora de ponto flutuante no padrão IEEE-754 exige exatamente 3 argumentos.\n");
    }

    return 0;
}

