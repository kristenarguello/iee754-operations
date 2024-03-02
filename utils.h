int operationChecker(char *operation);
int numbersChecker(char *number);

float calculate(float a, char *operation, float b);
char* floatToBinary(float f);

int isInexact(float resultado); //recebe o resultado
int isDivByZero(float segundoNumero); //recebe o segundo numero
int isUnderflow(float resultado); //recebe o resultado
int isOverflow(float resultado); //recebe o resultado
int isInvalidOperation(float resultado); //recebe o resultado?