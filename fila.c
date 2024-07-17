#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"
#include "acervo.h"

struct desc_fila * nova_fila(){  //cria e malloca o descritor
    struct desc_fila *novafila = (struct desc_fila *)malloc(sizeof(struct desc_fila));
   
    novafila->head=NULL;
    novafila->tail=NULL;
    novafila->tamanho=0;
    return novafila; 
}

/*
struct nodo_LSE * cria_noFILA(){    //recebe o meu dado, no caso a minha musica e cria um nó
    struct nodo_LSE *novoNo = (struct nodo_LSE *)malloc(sizeof(struct nodo_LSE));
    novoNo->info=NULL;
    novoNo->prox=NULL;
    return novoNo;
}*/

int fila_vazia(struct desc_fila *nova_fila){
    int verificador=0;
    if (nova_fila->tamanho==0){
        verificador=1;
        return verificador; //precisa retornar aqui pra ter o valor do teste
    }
    return verificador;
}

struct desc_fila * insere_fila(struct desc_fila *nova_fila, struct nodo_LSE *no){
    
    struct nodo_LSE *aux=nova_fila->head;
    int teste=0;
    teste=fila_vazia(nova_fila);

    if(teste==1){  //insere na fila vazia
       nova_fila->tail=no;
       nova_fila->head=no;
    }
    else{  //insere sempre no tail (final)
        
        while(aux->prox!=NULL){
            aux=aux->prox;
        }
        aux->prox=no;
    }
    nova_fila->tamanho++;
    nova_fila->tail=no;
    return nova_fila;
    
}

void imprimefila(struct desc_fila *nova_fila){
        struct nodo_LSE *aux=nova_fila->head;

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

void imprimetopo(struct desc_fila *nova_fila){
        struct nodo_LSE *aux=nova_fila->head;
        printf("\n------------------------------------------------");
        printf("\nTopo da fila:");
        printf("\nNome: %s", aux->info->titulo);
        printf("Artista: %s", aux->info->artista);
        printf("Trecho: %s", aux->info->letra);
        printf("Codigo: %d\n", aux->info->codigo);
        printf("\n------------------------------------------------");

    }


struct desc_fila * removefila(struct desc_fila *nova_fila){
    struct nodo_LSE *aux=nova_fila->head;
    int teste=0;

    teste=fila_vazia(nova_fila);
    if(teste==1){
        printf("\n------------------------------------------------");
        printf("\nFila vazia!\n");
        printf("\n------------------------------------------------");
    }
    else{
        nova_fila->head=aux->prox;
        nova_fila->tamanho--;
    }
    return nova_fila;  
}
