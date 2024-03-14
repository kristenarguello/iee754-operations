#include <fenv.h>
#include <stdio.h>
#include <stdlib.h>

#include "headers/utils.h"

int main(int argc, char *argv[]) {
    if (argc == 4) {
        if (isFloat(argv[1]) && isFloat(argv[3])) {
            float a = atof(argv[1]);
            char* operation = argv[2];
            float b = atof(argv[3]);

            if (operationChecker(operation)) { // + - / x
                feclearexcept(FE_ALL_EXCEPT);            
                float result = calculate(a, operation, b);
                
                int exception_invalid = fetestexcept(FE_INVALID);
                int exception_divbyzero = fetestexcept(FE_DIVBYZERO);
                int exception_overflow = fetestexcept(FE_OVERFLOW);
                int exception_underflow = fetestexcept(FE_UNDERFLOW);
                int exception_inexact = fetestexcept(FE_INEXACT);
                
                printf("\nGot %f %s %f and the result is %f\n\n", a, operation, b, result);
                floatToBinary("val1", a);
                floatToBinary("val2", b);
                floatToBinary("result", result);
                printf("\nFlags:\n");
                printf("FE_INEXACT: %d\n", exception_inexact != 0);
                printf("FE_DIVBYZERO: %d\n", exception_divbyzero != 0);
                printf("FE_UNDERFLOW: %d\n", exception_underflow != 0);
                printf("FE_OVERFLOW: %d\n", exception_overflow != 0);
                printf("FE_INVALID: %d\n\n", exception_invalid != 0);
                return 1;
            }
            printf("The operation %s is not valid. Try one of these: + - x / \n", operation);
            return 0;
        }
        printf("The arguments %s and %s are not valid floating-point numbers\n", argv[1], argv[3]);
        return 0;
    }
    printf("This IEEE-754 floating-point calculator requires exactly 3 arguments. \n");
    return 0;
}

