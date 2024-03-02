all:
	mkdir -p objects
	gcc -Wall -Werror -g -c utils.c -o ./objects/utils.o
	gcc -Wall -Werror -g -c ieee754-operations.c -o ./objects/ieee754-operations.o
	gcc -Wall -Werror -g ./objects/utils.o ./objects/ieee754-operations.o -o calculator

clean:
	rm -f calculator
	rm -rf ./objects


