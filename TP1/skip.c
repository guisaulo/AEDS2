#include <stdio.h>
#include <stdlib.h>
#include "skip.h"

//inicia a lista criando sua estrutura básica de funcionamento
void FLVazia(TipoLista *Lista){

    int i;
    Lista->Primeiro=(Apontador)malloc(sizeof(TipoCelula));
    Lista->Ultimo=Lista->Primeiro;
    for(i=0; i<=NIVEIS; i++)
        Lista->Primeiro->Prox[i]=NULL;   //fazem todos os niveis apontarem para NULL

}

//verifica se a lista está vazia, retornando 0, ou se contém algum elemento, retornando 1
int Vazia(TipoLista Lista){

    return (Lista.Primeiro==Lista.Ultimo);
}

//busca um elEmento pela sua chave, retornando 1 caso o elemento seja encontrado e 0 caso contrario
int Busca(TipoChave chave, TipoLista *L, Apontador *ListaH, int imprimir){

    int h,contador=0;
    Apontador x;

    x=L->Primeiro;	// primeiro elemento (cabeça ou head)
    for(h=NIVEIS; h>=0; h--){   //começa pesquisando no nivel mais superior
        while((x->Prox[h] != NULL)&&(x->Prox[h]->Item.Chave < chave)){   //Se o próximo elemento for NULL ou a chave for maior que o elemento de busca, descemos um nivel

            if(imprimir==1){   //caso em que desejamos imprimir o caminho até a chave
                if(x==L->Primeiro){
                    printf("head %d\n",h);	//imprime a cabeça, caso ela nao esteja apontando pra NULL, ou seja menor que a chave
                    contador++;
					 }
					 else{
                    printf("%d %d\n", x->Item.Chave,h);   //imprime o nivel, caso ele nao esteja apontando pra NULL, ou seja menor que a chave
               	  contador++;
                }            
				}
            x=x->Prox[h];	//atualizamos o proximo
        }
        if((imprimir==1)&&(contador=1)){
            if(x==L->Primeiro)
                printf("head %d\n",h);   //imprime a cabeça, caso ela esteja apontando pra NULL, ou seja maior que a chave
            else
                printf("%d %d\n", x->Item.Chave,h);   //imprime o nivel, caso ele nao esteja apontando pra NULL, ou seja menor que a chave
        }
        ListaH[h]=x;  //o ponteiro para o próximo elemento é guardado

    }
    h++; //quando sai do loop h=-1, logo somamos 1, para ele ficar h=0, pois isso é necessario para a continuacao do condigo abaixo

    if((x->Prox[h] != NULL)&&(x->Prox[h]->Item.Chave==chave)){  //caso achemos a chave
		  if(imprimir==1)
           printf("%d %d\n", x->Prox[h]->Item.Chave,h);   //caso a chave procurada esse encontrada, é impresso a chave no nivel 0
        return 1;   //chave encontrada
    }
    else
        return 0; //chave nao encontrada
}

//insere o item x na Skip List
int Insere(TipoItem x, int h, TipoLista *Lista){

    int i;
    Apontador lh[NIVEIS+1], novo;   //cria um vetor de listah que contenha o ponteiro para o próximo elemento de cada nivel e uma nova celula

    if(Busca(x.Chave, Lista, lh, 0)==0){   //caso nao contenha a chave na lista
        novo=(Apontador)malloc(sizeof(TipoCelula));   //alocamos memoria pra uma nova celula
        novo->Item=x;
        for(i=h; i>=0; i--){   //começa inserindo pelo nivel h que é lido no arquivo até a camada 0
            novo->Prox[i]=lh[i]->Prox[i];
            lh[i]->Prox[i]=novo;
        }
        return 1;   //sucesso
    }
    else
        return 0;   //caso ja tenha a chave na skip list, item nao inserido
}

//remove o elemento indicado com a chave na Skip List
int Remove(TipoChave chave, TipoLista *L){

    int i;
    Apontador lh[NIVEIS+1], aux[NIVEIS+1];   //cria um vetor de listah que contenha o ponteiro para o próximo elemento de cada nivel e uma celula auxiliar para removela

    if(Busca(chave, L, lh, 0)==1){   //caso a chave esteja na lista
        for(i=NIVEIS; i>=0; i--){   //começa retirando do nivel mais superior
            if(lh[i]->Prox[i]!=NULL){   //retiramos apenas no niveis em que o proximo seja diferente de NULL
                aux[i]=lh[i]->Prox[i];
                lh[i]->Prox[i]=aux[i]->Prox[i];
            }
        }
        return 1;   //sucesso
    }
    else
        return 0;   //caso a chave nao esteja na lista, falha ae remover
}

//lista todos os elementos no nível hierárquico h
void Imprime(TipoLista Lista, int h){

    Apontador temp;
    temp=Lista.Primeiro->Prox[h];
    while(temp != NULL){  //imprime ate chegar a ultima posicao da camada escolhida
        printf("%d %d\n", temp->Item.Chave, h);
        temp=temp->Prox[h];  //atualiza o proximo a imprimir
    }
}

//lista todos os elementos por nível hierárquico
void ImprimeTodos(TipoLista Lista){

    int i;

    for(i=NIVEIS; i>=0; i--)   //começa imprimindo o nivel mais superior ate o 0
        Imprime(Lista,i);   //chama funcao imprime
}
