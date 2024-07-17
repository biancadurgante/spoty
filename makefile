index:
	gcc acervo.c -c -g
	gcc fila.c -c -g
	gcc pilha.c -c -g
	gcc mainAcervo.c pilha.o fila.o acervo.o -o exec -g
clear:
	rm *.o