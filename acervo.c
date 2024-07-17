#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acervo.h"

struct desc_LSE * nova_lista(){  //cria e malloca o descritor
        printf("Entrou na funcao malloca descritor");

    struct desc_LSE *novalista = (struct desc_LSE *)malloc(sizeof(struct desc_LSE));
      if (novalista == NULL) {
        printf("Erro ao alocar memória para o descritor\n");
        exit(1);
    }
    novalista->LSE = NULL;
    novalista->tamanho = 0;
    printf("Descritor criado com sucesso\n");
    return novalista;
}
struct musica * criaMusica(char * artista, int codigo, char * titulo, char * letra) {  // cria e malloca o meu dado, a musica
    struct musica *novamusica = (struct musica *)malloc(sizeof(struct musica));
    if (novamusica == NULL) {
        printf("Erro ao alocar memória para a música\n");
        exit(1);
    }
    strcpy(novamusica->titulo, titulo);
    strcpy(novamusica->artista, artista);
    strcpy(novamusica->letra, letra);
    novamusica->codigo = codigo;
    return novamusica;
}


struct nodo_LSE * cria_no(struct musica *novamusica){    //recebe o meu dado, no caso a minha musica e cria um nó
    struct nodo_LSE *novoElemento = (struct nodo_LSE *)malloc(sizeof(struct nodo_LSE));
	    printf("Entrou na insere cria no");

    novoElemento->info=novamusica;
	novoElemento->prox =  NULL;
	return novoElemento;
}

int lista_vazia(struct desc_LSE *nova_lista){
    int verificador=0;
    if (nova_lista->tamanho==0){
        verificador=1;
        return verificador; //precisa retornar aqui pra ter o valor do teste
    }
    return verificador;
}

struct desc_LSE * insere_lista(struct desc_LSE *nova_lista, struct musica * musica, int posicao){
    int i;
    struct nodo_LSE *no = cria_no(musica);
    struct nodo_LSE *aux = nova_lista->LSE;
    int teste=0;
    teste=lista_vazia(nova_lista);

    printf("Entrou na insere antes de inserir");
    if(teste==1){  //insere na lista vazia no começo, nao importa posicao
        nova_lista->LSE=no;
        nova_lista->tamanho++;
        printf("Entrou na insere lista vazia");

        return nova_lista;
    }
    else{ //inserir no comeco lista nao vazia, posicao 0
        if(posicao==0){
			no->prox=aux;
			nova_lista->LSE=no;
			nova_lista->tamanho++;
            printf("Entrou na insere posicao 0");
			return nova_lista;
    }

    
        //inserir no meio
		if(posicao >0 && posicao < nova_lista->tamanho){
				while(i<posicao){
					aux=aux->prox;
					i++;
				}
				no->prox=aux->prox;
                aux->prox=no;
				nova_lista->tamanho++;
				return nova_lista;
		}

        //inserir no fim
		if(posicao>0 && posicao==nova_lista->tamanho || posicao>0 && posicao>nova_lista->tamanho){
				while(aux->prox != NULL){
					aux=aux->prox;
				}
				aux->prox=no;
				nova_lista->tamanho++;
                return nova_lista;
				
	}
}
}

void imprimelista(struct desc_LSE *nova_lista){
        struct nodo_LSE *aux=nova_lista->LSE;

    while(aux != NULL){
        printf("\n------------------------------------------------");
        printf("\nNome: %s", aux->info->titulo);
        printf("Artista: %s", aux->info->artista);
        printf("Trecho: %s", aux->info->letra);
        printf("Codigo: %d\n", aux->info->codigo);
        printf("\n------------------------------------------------\n");
    
        aux=aux->prox;
    }
}

void limpar_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) { }
}