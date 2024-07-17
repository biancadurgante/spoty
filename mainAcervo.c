#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acervo.h"


void quebraFrase(char *frase, struct desc_LSE * acervo, struct musica * novaMusica);


int main(){

int i=0, tamanhoacervo; //guarda o tamanho de linhas do arquivo igual o mercado
char linha, frase[256]; //cada linha lida do arquivo até o barra n cai aqui e cada frase recebe a linha pra poder quebrar

struct musica * novaMusica = NULL;
struct desc_LSE * acervo = NULL;
struct nodo_LSE * elemento = NULL;
printf("Erro no arquivo.\n");
acervo = nova_lista();  //cria e malloca o descritor
 if (acervo == NULL) {
        printf("Erro ao criar lista.\n");
        return 1;
    }
int menu;
 // leitura do arquivo texto
    FILE *arquivo = fopen("musicas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro no arquivo.\n");
        return 1;
    }

    // leu o arquivo
    while ((linha = fgetc(arquivo)) != EOF) {
        if (linha != '\n') { // caractere diferente de \n guarda em frase
            frase[i] = linha;
            i++;
        } else {
            if (i > 0) {
                frase[i] = '\0';
                quebraFrase(frase, acervo, novaMusica);
                i = 0; // reset para próxima linha
            }
        }
    }

    if (i > 0) {
        frase[i] = '\0';
        quebraFrase(frase, acervo, novaMusica);
    }

    fclose(arquivo);
        

        printf("\n------------------------------SEJA BEM VINDO AO SEU SPOTY------------------------------\n");
        printf("Escolha uma das opcoes: \n");
        printf("(1) Para mostrar o acervo\n(0) Para sair\n");
        scanf("%d", &menu);
        do{
            switch(menu){
                
                case 1:

                    imprimelista(acervo);
                break;

                default:
                break;
            }



        } while (menu!=0);
     return 0;
}



//vai gerar o meu dado pra preencher o nó pra colocar na lista que vai ser o meu acervo

void quebraFrase(char *frase, struct desc_LSE * acervo, struct musica * novaMusica){
	char titulo [256], artista [256], letra[256];
	int posicao=0;
	//nodo * novoNodo = NULL;

	//printf("\n\n===================================\n");
	//printf("artista é: %s \n",strtok(frase,";"));
	strcpy(artista,strtok(frase,";"));
	//printf("codigo é: %s \n",strtok(NULL,";"));
	int codigo = atoi(strtok(NULL,";"));
	//printf("titulo é: %s \n",strtok(NULL,";"));
	strcpy(titulo,strtok(NULL,";"));
	//printf("letra é: %s \n",strtok(NULL,";")); 
	strcpy(letra,strtok(NULL,";"));

	novaMusica = criaMusica(artista, codigo, titulo, letra);
	//printf("===================================\n");
	
	insere_lista(acervo, novaMusica, posicao);

	return;
}