index:
	gcc acervo.c -c -g
	gcc mainAcervo.c acervo.o -o exec -g
clear:
	rm *.o