#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acervo.h"
#include "fila.h"
#include "pilha.h"

struct desc_LSE * nova_lista() {  // cria e malloca o descritor
    struct desc_LSE *novalista = (struct desc_LSE *)malloc(sizeof(struct desc_LSE));
    if (novalista == NULL) {
        printf("\nErro ao alocar memória para o descritor\n");
        exit(1);
    }
    novalista->LSE = NULL;
    novalista->tamanho = 0;
    return novalista;
}

struct musica * criaMusica(char * artista, int codigo, char * titulo, char * letra) {  // cria e malloca o meu dado, a musica
    struct musica *novamusica = (struct musica *)malloc(sizeof(struct musica));
    if (novamusica == NULL) {
        printf("\nErro ao alocar memória para a música\n");
        exit(1);
    }
    strcpy(novamusica->titulo, titulo);
    strcpy(novamusica->artista, artista);
    strcpy(novamusica->letra, letra);
    novamusica->codigo = codigo;
    return novamusica;
}

struct nodo_LSE * cria_no(struct musica *novamusica) {  // recebe o meu dado, no caso a minha musica e cria um nó
    struct nodo_LSE *novoElemento = (struct nodo_LSE *)malloc(sizeof(struct nodo_LSE));
    if (novoElemento == NULL) {
        printf("\nErro ao alocar memória para o nó\n");
        exit(1);
    }
    novoElemento->info = novamusica;
    novoElemento->prox = NULL;
    return novoElemento;
}

int lista_vazia(struct desc_LSE *nova_lista) {
    return nova_lista->tamanho == 0;
}

struct desc_LSE * insere_lista(struct desc_LSE *nova_lista, struct musica * musica, int posicao) {
    struct nodo_LSE *no = cria_no(musica);
    struct nodo_LSE *aux = nova_lista->LSE;
    int i = 0;

    if (lista_vazia(nova_lista)) {  // insere na lista vazia no começo, nao importa posicao
        nova_lista->LSE = no;
        nova_lista->tamanho++;
        return nova_lista;
    } else {  // inserir no começo lista nao vazia, posicao 0
        if (posicao == 0) {
            no->prox = aux;
            nova_lista->LSE = no;
            nova_lista->tamanho++;
            return nova_lista;
        }

        // inserir no meio
        if (posicao > 0 && posicao < nova_lista->tamanho) {
            while (i < posicao - 1) {
                aux = aux->prox;
                i++;
            }
            no->prox = aux->prox;
            aux->prox = no;
            nova_lista->tamanho++;
            return nova_lista;
        }

        // inserir no fim
        if (posicao >= nova_lista->tamanho) {
            while (aux->prox != NULL) {
                aux = aux->prox;
            }
            aux->prox = no;
            nova_lista->tamanho++;
            return nova_lista;
        }
    }
    return nova_lista;
}

void imprimelista(struct desc_LSE *nova_lista) {
    struct nodo_LSE *aux = nova_lista->LSE;

    while (aux != NULL) {
        printf("\n------------------------------------------------");
        printf("\nNome: %s ", aux->info->titulo);
        printf("Artista: %s ", aux->info->artista);
        printf("Trecho: %s ", aux->info->letra);
        printf("Codigo: %d\n ", aux->info->codigo);
        printf("Execucoes: %d ", aux->info->execucoes);
        printf("\n------------------------------------------------\n");
        aux = aux->prox;
    }
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

struct nodo_LSE * buscaposicao(struct desc_LSE * acervo, int posicao){

    struct nodo_LSE * aux = acervo->LSE; //cria o auxiliar e já aponta para o descritor pq eu sempre vou retornar um no do meu acervo
    int i=0;
    
    if(posicao > acervo->tamanho){
        printf("Posicao invalida!");
        aux=NULL; //se a posicao for maior que o acervo eu invalido o no e retorno ele vazio
        return aux;
    }
    else{

        for (i=0; i<posicao; i++){
            aux = aux->prox;

        }
            return aux;
    }
}


//cria a playlist pela fila
struct desc_fila * playaleatoria(struct desc_LSE * acervo, struct desc_fila *nova_fila, int tamanhoplay){
    int i; 
    int posicao = 0;
    struct musica *musica = NULL;

    struct nodo_LSE *aleatorio = NULL;
    //aleatorio=cria_no(musica); //malloca o meu no pra eu poder receber o no da funcao posicao

      //quando randomposicao for igual a posicao do acervo
    for (i=0; i<tamanhoplay; i++){
       posicao = rand()%acervo->tamanho;
       //aleatorio=cria_no(musica); //malloca o meu no pra eu poder receber o no da funcao posicao
       aleatorio=cria_no(buscaposicao(acervo, posicao)->info); //malloca o meu no pra eu poder receber o no da funcao posicao
       //aleatorio=buscaposicao(acervo, posicao);
       nova_fila=insere_fila(nova_fila, aleatorio);
    }
    return nova_fila;
}

struct desc_Pilha * playpessoal(struct desc_LSE * acervo, struct desc_Pilha *nova_pilha, int tamanhoplaypessoal){

    int i=0;
    int posicao=0;
    struct musica *musica=NULL;
    struct nodo_LSE *pessoal = NULL;

        for (i=0; i<tamanhoplaypessoal; i++){
        printf("Digite a posicao da musica que deseja adicionar na sua playlist: \n");
        scanf ("%d", &posicao);
        if (posicao>acervo->tamanho){
            printf("Posicao invalida\n");
            i--;
        }
        else{
            pessoal=cria_no(buscaposicao(acervo, posicao)->info);
            nova_pilha=insere_pilha(nova_pilha, pessoal);
        }
        }
        return nova_pilha;

}

void buscatitulo(struct desc_LSE *acervo, int tamanho) {
    struct nodo_LSE *aux = acervo->LSE;
    char titulo[256];
    int i;

    printf("Informe o título: ");
    setbuf(stdin, NULL);
    fgets(titulo, 256, stdin);
    titulo[strcspn(titulo, "\n")] = '\0';

    for (i = 0; i < tamanho; i++) {
        if (strcmp(titulo, aux->info->titulo) == 0) {
            printf("\n------------------------------------------------");
            printf("\nNome: %s ", aux->info->titulo);
            printf("Artista: %s ", aux->info->artista);
            printf("Trecho: %s ", aux->info->letra);
            printf("Codigo: %d\n ", aux->info->codigo);
            printf("Execucoes: %d ", aux->info->execucoes);
            printf("\n------------------------------------------------\n");
            return;  // Encerra a busca ao encontrar o título
        }
        aux = aux->prox;
    }

    printf("Título não encontrado.\n");
}

void buscaartista(struct desc_LSE *acervo, int tamanho) {
    struct nodo_LSE *aux = acervo->LSE;
    char artista[256];
    int encontrou = 0;

    printf("Informe o artista: ");
    setbuf(stdin, NULL);
    fgets(artista, 256, stdin);
    artista[strcspn(artista, "\n")] = '\0';

    while (aux != NULL) { 
        if (strcmp(artista, aux->info->artista) == 0) {
            printf("\n------------------------------------------------");
            printf("\nNome: %s ", aux->info->titulo);
            printf("Artista: %s ", aux->info->artista);
            printf("Trecho: %s ", aux->info->letra);
            printf("Codigo: %d\n ", aux->info->codigo);
            printf("Execucoes: %d ", aux->info->execucoes);
            printf("\n------------------------------------------------\n");
            encontrou = 1;
        }
        aux = aux->prox;
    }

    if (encontrou!=1) {
        printf("Artista não encontrado.\n");
    }
}

void salvaPlaylistaleatoria(struct desc_fila *nova_fila, int tamanho){   //funcao salva arquivo texto
    FILE *arquivo;
    int i=0;
    struct nodo_LSE *aux = nova_fila->head;

    if((arquivo=fopen("playlist_aleatoria.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo.\n");
    }
        fprintf(arquivo, "%d\n", tamanho);
        for(i=0; i<tamanho; i++){
            fprintf(arquivo, "Nome: %s ", aux->info->titulo);
            fprintf(arquivo, "Artista: %s ", aux->info->artista);
            fprintf(arquivo, "Trecho: %s ", aux->info->letra);
            fprintf(arquivo, "Codigo: %d\n ", aux->info->codigo);
            aux=aux->prox;
        }
    fclose(arquivo);
    }

    void salvaPlaylistpessoal(struct desc_Pilha *nova_Pilha, int tamanho){   //funcao salva arquivo texto
    FILE *arquivo;
    int i=0;
    struct nodo_LSE *aux = nova_Pilha->Topo;

    if((arquivo=fopen("playlist_pessoal.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo.\n");
    }
        fprintf(arquivo, "%d\n", tamanho);
        for(i=0; i<tamanho; i++){
            fprintf(arquivo, "Nome: %s ", aux->info->titulo);
            fprintf(arquivo, "Artista: %s ", aux->info->artista);
            fprintf(arquivo, "Trecho: %s ", aux->info->letra);
            fprintf(arquivo, "Codigo: %d\n ", aux->info->codigo);
            aux=aux->prox;
        }
    fclose(arquivo);
    }

    void salvaacervo(struct desc_LSE *nova_lista, int tamanho){   //funcao salva arquivo texto
    FILE *arquivo;
    int i=0;
    struct nodo_LSE *aux = nova_lista->LSE;

    if((arquivo=fopen("acervo.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo.\n");
    }
        fprintf(arquivo, "%d\n", tamanho);
        for(i=0; i<tamanho; i++){
            fprintf(arquivo, "Nome: %s ", aux->info->titulo);
            fprintf(arquivo, "Artista: %s ", aux->info->artista);
            fprintf(arquivo, "Trecho: %s ", aux->info->letra);
            fprintf(arquivo, "Codigo: %d ", aux->info->codigo);
            fprintf(arquivo, "Execucoes: %d\n", aux->info->execucoes);
            aux=aux->prox;
        }
    fclose(arquivo);
    }