//tem as structs e o cabeçalho das funcoes




struct desc_fila{
struct nodo_LSE *head;
struct nodo_LSE *tail;
int tamanho;
};

struct nodo_fila * cria_noFILA();    //cria um no vazio pra eu receber a musica da direto do acervo

void limpar_buffer();
struct desc_fila * nova_fila();  //cria e malloca o descritor
int fila_vazia(struct desc_fila *nova_fila);
struct desc_fila * insere_fila(struct desc_fila *nova_fila, struct nodo_LSE *no);
void imprimefila(struct desc_fila *nova_fila);
void imprimetopo(struct desc_fila *nova_fila);
struct desc_fila * removefila(struct desc_fila *nova_fila);
