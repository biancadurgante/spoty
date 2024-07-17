index:
	gcc acervo.c -c -g
	gcc fila.c -c -g
	gcc mainAcervo.c fila.o acervo.o -o exec -g
clear:
	rm *.o