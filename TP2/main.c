#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore.h"

//Trabalho Pratico 2 de AEDS2 *** Guilherme Saulo Alves *** 19 de Novembro de 2013

int main(int argc, char **argv){

    /*....................declaração das variaveis e processos iniciais......................*/

    char opcao; //armazena os caracteres # & @

    TipoItem item;  //cria um item para ler da entrada uma chave
    TipoArvore arvore;

    arvore=NULL;  //inicializa a arvore pela raiz nula

    /*.................................entrada e saida.......................................*/

    while((scanf("%s", item.Chave)) > 0){ //enquanto nao acabar o arquivo, de forma analoga a EOF

        opcao=item.Chave[0];  //le o primeira caracter da string
        ExtraiPalavra(item.Chave);  //chama a funcao para tirar caracter especiais e letras maiusculas da chave

        switch(opcao){
            case '#': //chama busca
                if(Busca(item.Chave, &arvore)==1)
                    printf("true\n");  //busca com sucesso
                else
                    printf("false\n");  //busca fracassou
                break;
            case '@':  //chama funcao remover
                Remove(item.Chave, &arvore);
                break;
            case '&':
                Imprime(&arvore); //chama funcao imprimir
                break;
            default:
                Insere(&item, &arvore); //insere a palavra na arvore
        }
    }

    return 0;
}
