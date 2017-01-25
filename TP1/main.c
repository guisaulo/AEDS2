#include <stdio.h>
#include <stdlib.h>
#include "skip.h"

//Trabalho Pratico 1 de AEDS2 *** Guilherme Saulo Alves *** 20 de Novembro de 2013

int main(int argc, char **argv){

    /*....................declaração das variaveis e processos iniciais......................*/

    int nivel;	  //nivel que ira inserir uma chave(0 a 4)
    char opcao;   //I-(Inserir) R-(Remover) B-(Busca) P-(Imprime Nivel h) A-(Imprime Todos Nivel)

    TipoItem item;   //cria tipo item para ler do arquivo um item.chave
    TipoLista lista;   //cria lista do skip list
    Apontador listah[NIVEIS+1];   //criar um vetor de ponteiros

    FLVazia(&lista);   //faz a slip list ficar vazia

    /*.................................entrada e saida.......................................*/

    while(scanf("%c", &opcao) > 0){   //condicao para ir lendo as entradas do arquivo
        switch(opcao){
            case 'I':   //inserir
                scanf(" %d %d", &item.Chave, &nivel);   //lê a chave que quer inserir e o nivel hierarquico
                if(Insere(item, nivel, &lista)==1)
                    printf("true\n");   //inserido com sucesso
                else
                    printf("false\n");   //falha ao inserir
                break;
            case 'R':   //remover
                scanf(" %d", &item.Chave);   //lê a chave a remover
                if(Remove(item.Chave, &lista)==1)
                    printf("true\n");   //removido com sucesso
                else
                    printf("false\n");   //falha ao remover
                break;
            case 'B':   //busca
                scanf(" %d",&item.Chave);
                if(Busca(item.Chave, &lista, listah, 1)==1)
                    printf("true\n");   //busca realizada com sucesso
                else
                    printf("false\n");	  //busca falhou
                break;
            case 'P':	//imprime nivel hierarquico h
                scanf(" %d", &nivel);   //lê o nivel
                Imprime(lista, nivel);   //imprime o nivel
                break;
            case 'A':	//imprime todos niveis
                ImprimeTodos(lista);
                break;
        }
    }

    return 0;
}
