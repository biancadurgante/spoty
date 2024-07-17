#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "fila.h"
#include "acervo.h"

struct desc_Pilha * nova_pilha(){  //cria e malloca o descritor
    struct desc_Pilha *novapilha = (struct desc_Pilha *)malloc(sizeof(struct desc_Pilha));
    novapilha->Fundo=NULL;
    novapilha->tamanho=0;
    novapilha->Topo=NULL;
    return novapilha;
}


/*
struct nodo_Pilha * cria_no(struct musica *novamusica){    //recebe o meu dado, no caso a minha musica e cria um nó
    struct nodo_Pilha *novoNo = (struct nodo_Pilha *)malloc(sizeof(struct nodo_Pilha));
    novoNo->info=novamusica;
    novoNo->prox=NULL;
    return novoNo;
}*/

int pilha_vazia(struct desc_Pilha *nova_pilha){
    int verificador=0;
    if (nova_pilha->tamanho==0){
        verificador=1;
        return verificador; //precisa retornar aqui pra ter o valor do teste
    }
    return verificador;
}

struct desc_Pilha * insere_pilha(struct desc_Pilha *nova_pilha, struct nodo_LSE *no){
    
    struct nodo_LSE *aux = nova_pilha->Topo;
    int teste=0;
    teste=pilha_vazia(nova_pilha);
   
    
    if(teste==1){  //insere na pilha vazia
       nova_pilha->Fundo=no;
       nova_pilha->Topo=no;
       nova_pilha->tamanho++;
    }
    else{
        no->prox=nova_pilha->Topo;
        nova_pilha->Topo=no;
        nova_pilha->tamanho++;
    }

    return nova_pilha;
    
}

struct desc_Pilha * removepilha(struct desc_Pilha *nova_pilha){
    struct nodo_LSE *removido=NULL;
    int teste=0;

    teste=pilha_vazia(nova_pilha);
    if(teste==1){
        printf("\n------------------------------------------------");
        printf("\nPilha vazia!\n");
        printf("\n------------------------------------------------");
    }
    else{
        removido=nova_pilha->Topo;
        nova_pilha->Topo=removido->prox;
        nova_pilha->tamanho--;
    }
    return nova_pilha;  
}

void imprimePilha(struct desc_Pilha *nova_pilha){
        struct nodo_LSE *aux=nova_pilha->Topo;

    while(aux != NULL){
        printf("\n------------------------------------------------");
        printf("\nNome: %s ", aux->info->titulo);
        printf("Artista: %s ", aux->info->artista);
        printf("Trecho: %s ", aux->info->letra);
        printf("Codigo: %d\n ", aux->info->codigo);
        printf("Execucoes: %d ", aux->info->execucoes);
        printf("\n------------------------------------------------\n");
    
        aux=aux->prox;
    }
}

void imprimetopopilha(struct desc_Pilha *nova_pilha){
        struct nodo_LSE *aux=nova_pilha->Topo;
        printf("\n------------------------------------------------");
        printf("\nTopo da lista:\n");
        printf("\nNome: %s", aux->info->titulo);
        printf("Artista: %s", aux->info->artista);
        printf("Trecho: %s", aux->info->letra);
        printf("Codigo: %d\n", aux->info->codigo);
        printf("\n------------------------------------------------");

    }
