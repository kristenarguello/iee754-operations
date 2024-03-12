all:
	mkdir -p objects
	gcc -Wall -Werror -g -c utils.c -o ./objects/utils.o
	gcc -Wall -Werror -g -c ieee-stuff.c -o ./objects/ieee-stuff.o
	gcc -Wall -Werror -g -c ieee754-calculator.c -o ./objects/ieee754-calculator.o
	gcc -Wall -Werror -g ./objects/utils.o ./objects/ieee-stuff.o ./objects/ieee754-calculator.o -o calculator

clean:
	rm -f calculator
	rm -rf ./objects


