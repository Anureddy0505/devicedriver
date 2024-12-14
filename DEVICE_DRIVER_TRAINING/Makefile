all: calculator
	echo "Build Done"
calculator: cal.o 
	gcc cal.o -o cal
cal.o:cal.c
	gcc -c cal.c
clean:
	rm *.o cal

