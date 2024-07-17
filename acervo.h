struct musica {
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
};

struct nodo_LSE {
    struct nodo_LSE *prox;
    struct musica *info;
};

struct desc_LSE {
    struct nodo_LSE *LSE;
    int tamanho;
};

struct desc_LSE * nova_lista();  // cria e malloca o descritor
struct musica * criaMusica(char * artista, int codigo, char * titulo, char * letra);  // cria e malloca o meu dado, a musica
struct desc_LSE * insere_lista(struct desc_LSE *nova_lista, struct musica * musica, int posicao);
int lista_vazia(struct desc_LSE *nova_lista);
struct nodo_LSE * cria_no(struct musica *novamusica);  // recebe o meu dado, no caso a minha musica e cria um nó
void imprimelista(struct desc_LSE *nova_lista);
void limpar_buffer();
void quebraFrase(char *frase, int n, struct desc_LSE * acervo, struct musica * novaMusica);
struct desc_fila * playaleatoria(struct desc_LSE * acervo, struct desc_fila *nova_fila, int tamanhoplay);
struct nodo_LSE * buscaposicao(struct desc_LSE * acervo, int posicao);
struct desc_Pilha * playpessoal(struct desc_LSE * acervo, struct desc_Pilha *nova_pilha, int tamanhoplaypessoal);
void buscatitulo(struct desc_LSE *acervo, int tamanho);
void buscaartista(struct desc_LSE *acervo, int tamanho);
void salvaPlaylistaleatoria(struct desc_fila *nova_fila, int tamanho);   //funcao salva arquivo texto
void salvaPlaylistpessoal(struct desc_Pilha *nova_Pilha, int tamanho);   //funcao salva arquivo texto
void salvaacervo(struct desc_LSE *nova_lista, int tamanho);   //funcao salva arquivo texto
