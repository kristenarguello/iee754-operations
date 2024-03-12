all:
	mkdir -p objects
	gcc -g -c utils.c -o objects/utils.o
	gcc -g -c ieee754-calculator.c -o objects/ieee754-calculator.o
	gcc -g objects/utils.o objects/ieee754-calculator.o -o calculator

clean:
	rm -f calculator
	rm -rf ./objects


