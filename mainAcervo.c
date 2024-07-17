#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "acervo.h"
#include "fila.h"
#include "pilha.h"
#include <time.h>

void quebraFrase(char *frase, int i, struct desc_LSE *acervo, struct musica *novaMusica);

int main() {
    srand(time(NULL));
    int i = 0;
    char linha, frase[256];
    struct musica *novaMusica = NULL;
    struct desc_LSE *acervo = NULL;
    struct desc_fila *playlistaletoria = NULL;
    struct desc_Pilha *playlistpessoal = NULL;


    //descritores
    
    playlistaletoria = nova_fila();
    playlistpessoal = nova_pilha();
    acervo = nova_lista();  // cria e malloca o descritor


    //outras variaveis
    int menu, menubusca;
    int acervospoty;

    // leitura do arquivo texto
    FILE *arquivo = fopen("musicas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro no arquivo.\n");
        return 1;
    }

    //aqui eu pego a primeira linha para ler certo as musicas
	fscanf(arquivo,"%d",&acervospoty); 
	printf("O tamanho do seu acervo de musicas e: %d\n", acervospoty);
    
    // leu o arquivo
    while ((linha = fgetc(arquivo)) != EOF) {
        if (linha != '\n') { // caractere diferente de \n guarda em frase
            if (i < sizeof(frase) - 1) {
                frase[i] = linha;
                i++;
            } 

        } else {
            if (i > 0) {
                frase[i] = '\0';
                quebraFrase(frase, i, acervo, novaMusica);
                i = 0; // reset para próxima linha
            }
        }
    }

    if (i > 0) {
        frase[i] = '\0';
        quebraFrase(frase, i, acervo, novaMusica);
    }

    fclose(arquivo);

    do {
    printf("\n------------------------------SEJA BEM VINDO AO SEU SPOTY------------------------------\n");
    printf("Escolha uma das opcoes: \n");
    printf("(1) Mostrar o acervo\n(2) Busca\n(3) Criar playlist\n(4) Executar playlist\n(0) Para sair\n");
    scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\nO tamanho do seu acervo eh: %d", acervo->tamanho);
                imprimelista(acervo);
                break;
            
            case 2:
                printf("\n(1) Busca por Codigo\n(2) Busca por Titulo\n(3) Busca por Artista\n");
                scanf("%d", &menubusca);
                
                switch(menubusca){
                    case 1:
                    int buscacodigo;
                    printf("Digite o codigo da musica: \n");
                    scanf ("%d", &buscacodigo);
            
                    struct nodo_LSE *aux = acervo->LSE;

                    while (aux != NULL) {
                        if(aux->info->codigo==buscacodigo){
                            printf("\n------------------------------------------------");
                            printf("\nNome: %s", aux->info->titulo);
                            printf("Artista: %s", aux->info->artista);
                            printf("Trecho: %s", aux->info->letra);
                            printf("Codigo: %d\n", aux->info->codigo);
                            printf("Execucoes: %d", aux->info->execucoes);
                            printf("\n------------------------------------------------\n");
                        }
                        aux = aux->prox;
                    }

                    break;

                    case 2:
                    buscatitulo(acervo, acervospoty);

                    break;

                    case 3:
                    buscaartista(acervo, acervospoty);

                    break;

                    default:
                    break;

                }
                
                break; //break do menu principal

            case 3:
                int tipoplay, tamanhoplay, tamanhoplaypessoal;
                printf("(1) Playlist aleatoria\n(2) Playlist pessoal\n");
                scanf("%d", &tipoplay);
               switch(tipoplay){

                case 1:
                    printf("Digite o tamanho da playlist:\n");
                    scanf("%d", &tamanhoplay);
                    playlistaletoria=playaleatoria(acervo, playlistaletoria, tamanhoplay);
                    imprimefila(playlistaletoria);
                    salvaPlaylistaleatoria(playlistaletoria, tamanhoplay);   //funcao salva arquivo texto

                break;

                case 2:
                    printf("Digite o tamanho da playlist:\n");
                    scanf("%d", &tamanhoplaypessoal);
                    playlistpessoal=playpessoal(acervo, playlistpessoal, tamanhoplaypessoal);
                    imprimePilha(playlistpessoal);
                    salvaPlaylistpessoal(playlistpessoal, tamanhoplaypessoal);   //funcao salva arquivo texto


                break;

                default:
                break;
               }
            break;


            case 4:
              int tipoexec, i=0;

                printf("Escolha a playlist que deseja executar: \n");
                printf("(1) Aleatoria\n(2) Pessoal\n");
                scanf("%d", &tipoexec);
                //printf("O tamanho da sua playlist eh: %d", playlistaletoria->tamanho);
                    switch (tipoexec){

                        case 1:
                            while(playlistaletoria->tamanho>0){
                            playlistaletoria->head->info->execucoes ++;
                            playlistaletoria = removefila(playlistaletoria);
                            salvaacervo(acervo, acervospoty);   //funcao salva arquivo texto

                            }  
                        break;

                        case 2:
                            while(playlistpessoal->tamanho>0){
                                playlistpessoal->Topo->info->execucoes ++;
                                playlistpessoal=removepilha(playlistpessoal);
                                salvaacervo(acervo, acervospoty);   //funcao salva arquivo texto

                            }
                            break;
                        
                        default:
                        break;
                    }

            break;
                
            default:
            break;
        
        }
    } while (menu != 0);

    return 0;
}


// vai gerar o meu dado pra preencher o nó pra colocar na lista que vai ser o meu acervo
void quebraFrase(char *frase, int i, struct desc_LSE * acervo, struct musica * novaMusica) {
    char titulo[256], artista[256], letra[256];

    strcpy(artista, strtok(frase, ";"));
    int codigo = atoi(strtok(NULL, ";"));
    strcpy(titulo, strtok(NULL, ";"));
    strcpy(letra, strtok(NULL, ";"));
    novaMusica = criaMusica(artista, codigo, titulo, letra);

    insere_lista(acervo, novaMusica, 0);
}
