all: printy
printy: grafos.o main.o dados.o
	gcc -o printy grafos.o main.o dados.o -lm
grafo.o: grafos.c
	gcc -c grafo.c
dados.o: dados.c 
	gcc -c dados.c
main.o: main.c 
	gcc -c main.c
clean:
	rm -rf *.o 