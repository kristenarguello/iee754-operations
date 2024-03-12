char* floatToBinary(float f);
int isInexact(float resultado, int* firstRounded, int* secondRounded); //recebe o resultado
void isDivByZero(float primeiroNumero, float segundoNumero, int* divZero); //recebe o segundo numero
int infinitySign(float primeiroNumero);
void isUnderflow(float result, float a, float b, int* underflow); //recebe o resultado
void isOverflow(float result, float a, float b, int* overflow); //recebe o resultado
int isInvalidOperation(float resultado); //recebe o resultado?