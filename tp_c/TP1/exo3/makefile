default : main
all : main 
clean : 
	rm *.o main 

main : main.o eleve.o
	gcc main.o eleve.o -o main

%.o : %.c 
	gcc -c $<

eleve.o : eleve.h constante.h
main.o : eleve.h constante.h