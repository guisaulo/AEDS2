#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvore.h"

//Verifica se a árvore está vazia, retornando 1, ou se contém algum elemento, retornando 0
int Vazia(TipoArvore arvore){

    return (arvore==NULL);
}

//Faz a inserção de um novo nó na árvore binária de busca mantendo seus critérios.
void Insere(TipoItem *x, Apontador *no){

    int compara;

    if(Vazia(*no)){ //caso a a arvore esteja vazia(apontador para NULL) cria o nó
        *no=(Apontador)malloc(sizeof(No)); //aloca espaço na memoria para um nó
        (*no)->Esq=NULL;
        (*no)->Dir=NULL;
        (*no)->Item=*x;
        (*no)->Item.Num=1; //incrementa uma ocorrencia
        printf("insere %s\n", (*no)->Item.Chave); //imprime conforme enunciado
        return;
    }

    compara=strcmp(x->Chave,(*no)->Item.Chave); //Compara recebe 0 caso as strings forem iguais, -1 quando as string1 é menor que string2, 1 caso a string1 é maior que string2

    if(compara==-1) //menor, chama filho da esquerda
        Insere(x, &(*no)->Esq); //Repitr o processo recursivamente, até que a chave procurada seja encontrada ou um nó folha é atingido.
    if(compara==1) //maior, chama filho da direita
        Insere(x, &(*no)->Dir); //Repitr o processo recursivamente, até que a chave procurada seja encontrada ou um nó folha é atingido.
    if(compara==0){ //igual
        (*no)->Item.Num++;  //incrementa uma ocorrencia, pois a palavra ja existe
        printf("incrementa %s\n", (*no)->Item.Chave); //imprime conforme enunciado
    }
}

//Faz a busca de uma determinada palavra-chave retornando 0 caso não encontre e 1 caso contrário
int Busca(TipoChave c, Apontador *no){

    int compara;

    if(Vazia(*no)){
        return 0;  //arvore esta sem nenhuma palavra, busca falhou
    }

    compara=strcmp(c, (*no)->Item.Chave);  //Compara recebe 0 caso as strings forem iguais, -1 quando as string1 é menor que string2, 1 caso a string1 é maior que string2

    if(compara==-1){  //menor, busca no filho da esquerda
        printf("%s %d\n", (*no)->Item.Chave, (*no)->Item.Num);  //imprime o caminho
        return Busca(c, &(*no)->Esq); //Repitr o processo recursivamente, até que a chave procurada seja encontrada ou um nó folha é atingido.

    }
    if(compara==1){ //maior, busca no filho da direita
        printf("%s %d\n", (*no)->Item.Chave, (*no)->Item.Num);  //imprime o caminho
        return Busca(c, &(*no)->Dir); //Repitr o processo recursivamente, até que a chave procurada seja encontrada ou um nó folha é atingido.
    }
    if(compara==0){
        printf("%s %d\n", (*no)->Item.Chave, (*no)->Item.Num);  //imprime o caminho
        return 1;   //achou
    }

    return 0;
}

//Essa função é ativada quando o nó que contém a chave a ser retirada possui 2 descendentes
void Antecessor (Apontador q, Apontador *r){

    if((*r)->Dir != NULL){
        Antecessor(q, &(*r)->Dir);  //substituído pelo registro mais à esquerda na subárvore direita.
        return;
    }
    q->Item=(*r)->Item;
    q=*r;
    *r=(*r)->Esq; //substituido pelo registro da esquerda
    free(q); //libera o nó retirado
}

//Faz a remoção de uma palavra-chave c.
void Remove(TipoChave c, Apontador *no){

    int compara;
    Apontador Aux;

    if(*no==NULL){  //caso a arvore esteja vazia
        printf("remove false %s\n", c); //imprime conforme enunciado
        return;
    }

    compara=strcmp(c,(*no)->Item.Chave);  //Compara recebe 0 caso as strings forem iguais, -1 quando as string1 é menor que string2, 1 caso a string1 é maior que string2

    if(compara==-1){ //menor, busca no filho da esquerda
        Remove(c, &(*no)->Esq);
        return;
    }

    if(compara==1){  //maior, busca no filho da direita
        Remove(c, &(*no)->Dir);
        return;
    }

    if((*no)->Dir==NULL){ //chegou no nó folha
        Aux=*no;
        *no=(*no)->Esq;
        printf("remove true %s\n", Aux->Item.Chave); //imprime conforme enunciado
        free(Aux);
        return;
    }

    if((*no)->Esq != NULL){ //só é ativado quando o nó que contém a chave possui 2 descendentes.
        Antecessor(*no, &(*no)->Esq);
        printf("remove true %s\n", c); //imprime conforme enunciado
        return;
    }

    Aux=*no;
    *no=(*no)->Dir;
    printf("remove true %s\n", Aux->Item.Chave); //imprime conforme enunciado
    free(Aux);

}

//Imprime todas as palavras da árvore em ordem alfabética e sua ocorrência no texto.
void Imprime(Apontador *no){

    if((*no)==NULL)
        return;

    Imprime(&(*no)->Esq); //caminha na subárvore esquerda na ordem central e visita a raiz;
    printf("%s %d\n", (*no)->Item.Chave, (*no)->Item.Num); //imprime em ordem alfabetica
    Imprime(&(*no)->Dir); //caminha na subárvore direita na ordem central.
}

//A função retira caracter especiais e letras maiusculas da chave conforme enunciado
void ExtraiPalavra(char *chave) {

    char *aux1=chave, *aux2=chave; //criar strings para manipulacao dos caracteres

	while(*aux1){	//enquanto a string nao acabar, ler letra por letra
		if(isupper((unsigned char)*aux1)){	//A função isupper retorna um valor diferente de zero se c é uma letra maiúscula ou retorna zero caso contrário.
          	*aux2++ = tolower((unsigned char)*aux1);    //faz o caracter ficar minusculo
          	aux1++;
       	}
		else if(ispunct((unsigned char)*aux1))	//A funçao ispunct retorna um valor diferente de zero se c é um caracter de pontuacao ou retorna zero caso contrário
			aux1++;     //pula esta letra.
      	else if(aux1==aux2){  //caso nao tenha caracter especiais
        	aux1++;           //Incrementa ambos os ponteiros.
          	aux2++;
       	}
       	else
			*aux2++ = *aux1++;  //transfere as letras
    }
    *aux2 = 0;	//por fim na string aux que sera a nova chave
}
