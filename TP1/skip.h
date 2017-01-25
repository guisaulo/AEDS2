#ifndef SKIP_H_INCLUDED
#define SKIP_H_INCLUDED

#define NIVEIS 4

//estrutura interna padrao, vista em sala de aula
typedef int TipoChave;

typedef struct{
    TipoChave Chave;
}TipoItem;

typedef struct TipoCelula *Apontador;

typedef struct TipoCelula{
    TipoItem Item;
    Apontador Prox[5]; //apontador para cada nivel
}TipoCelula;

typedef struct{
    Apontador Primeiro, Ultimo;
}TipoLista;

void FLVazia(TipoLista *Lista);

int Vazia(TipoLista Lista);

int Busca(TipoChave chave, TipoLista *L, Apontador *ListaH, int imprimir);

int Insere(TipoItem x, int h, TipoLista *Lista);

int Remove(TipoChave chave, TipoLista *L);

void Imprime(TipoLista Lista, int h);

void ImprimeTodos(TipoLista Lista);

#endif // SKIP_H_INCLUDED
