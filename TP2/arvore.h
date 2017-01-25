/*------------------variaveis globais definidas-----------------------*/

#define Max_Alfabeto 255

/*-------------------declaração das estruturas------------------------*/

typedef char TipoChave[Max_Alfabeto]; //armazena a palavra

typedef struct {
    TipoChave Chave;
    int Num;  //contador de ocorrencias de uma palavra na arvore
} TipoItem;

typedef struct No* Apontador;

typedef struct No {
    TipoItem Item;
    Apontador Esq, Dir;  //apontadores para o filho da esquerda e da direita
} No;

typedef Apontador TipoArvore;

/*------------------declaração das funções---------------------------*/

int Vazia(TipoArvore arvore);

void Insere(TipoItem *x, Apontador *no);

int Busca(TipoChave c, Apontador *no);

void Remove(TipoChave c, Apontador *no);

void Antecessor (Apontador q, Apontador *r);

void Imprime(Apontador *no);

void ExtraiPalavra(char *chave);
