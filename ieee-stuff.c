#include "headers/ieee-stuff.h"

char* floatToBinary(float f) {
    if (f == 0) {
        return "0 00000000 00000000000000000000000";
    }
    
    return "not implemented yet";
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
