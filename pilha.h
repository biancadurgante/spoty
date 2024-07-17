//tem as structs e o cabeçalho das funcoes



struct desc_Pilha{   //descritor
struct nodo_LSE *Fundo;  //aponta pro começo que quando tem um elemento só também é o topo
struct nodo_LSE *Topo;
int tamanho;
};

void limpar_buffer();
struct desc_Pilha * nova_pilha();  //cria a pilha
//struct nodo_Pilha * cria_no(struct musica *novamusica);    //recebe o meu dado, no caso a minha musica e cria um nó
int pilha_vazia(struct desc_Pilha *nova_pilha); //testa se a pilha esta vazia
struct desc_Pilha * insere_pilha(struct desc_Pilha *nova_pilha, struct nodo_LSE *no); //insere na minha pilha
struct desc_Pilha * removepilha(struct desc_Pilha *nova_pilha); //remove e retorna o no
void imprimePilha(struct desc_Pilha *nova_pilha);
void imprimetopopilha(struct desc_Pilha *nova_pilha);
