#include <stdio.h>
#include <stdlib.h>


#include "headers/utils.h"
#include "headers/ieee-stuff.h"

/*
TODOs:
- conversion to binary
- div by zero string result (not binary)
- CHECK BUS ERROR
- correct types of return to under and overflow
- inexact operation
- invalid operation
- check normal calculator  
*/ 



int main(int argc, char *argv[]) {
    if (argc == 4) {
        float a = atof(argv[1]);
        char* operation = argv[2];
        printf("%c", operation[0]); 
        float b = atof(argv[3]);

        // int firstRounded = 0;
        // int secondRounded = 0;

        int overflow = 0;
        int underflow = 0;
        int divByZero = 0;

        if (operationChecker(operation) ) {
            isDivByZero(a, b, &divByZero);

            char* binaryA = floatToBinary(a);
            char* binaryB = floatToBinary(b);
            char* binaryResult = "";

            float result = 0;
            if (divByZero) {
                int infSign = infinitySign(a);
                char* infinity = "";
                if (infSign == 0) {
                    infinity = "+inf";
                } else {
                    infinity = "-inf";
                }
                sprintf(binaryResult, "%d 11111111 00000000000000000000000", infSign);

                printf("Recebi %f %s %f e resultado deu %s\n", a, operation, b, infinity);
                printf("val1 = %s = %f\n", binaryA, a);
                printf("val2 = %s = %f\n", binaryB, b);
                printf("result = %s = %s\n", binaryResult, infinity);

            } else {
                result = calculate(a, operation, b);
                binaryResult = floatToBinary(result);
                
                // other exceptions checker
                isUnderflow(result, a, b, &underflow); // still need to return the special value (denormalized number or 0)
                isOverflow(result, a, b, &overflow); // still need to return the special value (infinity or max value)

                printf("Recebi %f %s %f e resultado deu %f\n", a, operation, b, result);
                
                printf("val1 = %s = %f\n", binaryA, a);
                printf("val2 = %s = %f\n", binaryB, b);
                printf("result = %s = %f\n", binaryResult, result);
            }
            
            printf("\nFlags:\n");
            // printf("FE_INEXACT: %d\n", isInexact(result, &firstRounded, &secondRounded)); // TODO
            printf("FE_DIVBYZERO: %d\n", divByZero); 
            printf("FE_UNDERFLOW: %d\n", underflow);
            printf("FE_OVERFLOW: %d\n", overflow); 
            // printf("FE_INVALID: %d\n", isInvalidOperation(result));

            return 1;
        } else {
            printf("Operação inválida.\n");
            return 0;
        }



    } else {
        printf("Essa calculadora de ponto flutuante no padrão IEEE-754 exige exatamente 3 argumentos.\n");
    }

    return 1;
}

