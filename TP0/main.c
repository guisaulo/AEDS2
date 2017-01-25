/*Trabalho Pratico 0 de AEDS2 *** Guilherme Saulo Alves *** 09 de Setembro de 2013 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "geometria.h"

int main(int argc, char *argv[]){
/*...........................declaração das variaveis......................*/
   int numPontos, numLinhas, numPoligonos, numVerticesLinha, numVerticesPoligono, numTeste, idTeste, i, j, aux1, aux2;
   double a, b;
   ponto *pt, *vertLinha, *vertPoligono;
   linha *li;
   poligono *po;
   char *opcao;
/*.............................ponto.......................................*/
   scanf("%d", &numPontos);   //lê o número de pontos
   pt=malloc(numPontos*sizeof(ponto));   //cria vetor de ponto dinamicamente
   for(i=0; i<numPontos; i++){     //lê cada coordenada e cria ponto
      scanf("%lf %lf", &a, &b);
      criaPonto(&pt[i],a,b);
   }
/*.............................linha........................................*/
   scanf("%d", &numLinhas);  //lê número de linhas
   li=malloc(numLinhas*sizeof(linha));   //cria vetor de linha dinamicamente
   for(i=0; i<numLinhas; i++){
      scanf("%d", &numVerticesLinha);   //lê número de vertices da linha i
      li[i].numVertices=numVerticesLinha;   //grava o numero de vertices da linha i
      vertLinha=malloc(numVerticesLinha*sizeof(ponto));   //cria vetor de vertices dinamicamente
      for(j=0; j<numVerticesLinha; j++){   //lê cada vertice e cria ponto
         scanf("%lf %lf", &a, &b);
         criaPonto(&vertLinha[j],a,b);
         criaLinha(&li[i], j, &vertLinha[j]);   //cria linha com a sequencia de vertices
      }
   }
/*............................poligono......................................*/
   scanf("%d", &numPoligonos);  //lê número de poligonos
   po=malloc(numPoligonos*sizeof(poligono));   //cria vetor de poligono dinamicamente
   for(i=0; i<numPoligonos; i++){
      scanf("%d", &numVerticesPoligono);   //lê número de vertices do poligono i
      po[i].numVertices=numVerticesPoligono;   //grava o numero de vertices do poligono i
      vertPoligono = malloc(numVerticesPoligono*sizeof(ponto));   //cria vetor de vertices dinamicamente
      for(j=0; j<numVerticesPoligono; j++){   //lê cada vertice e cria ponto
         scanf("%lf %lf", &a, &b);
         criaPonto(&vertPoligono[j],a,b);
         criaPoligono(&po[i], j, &vertPoligono[j]);
      }
   }
/*............................testes.......................................*/
   scanf("%d", &numTeste);   //quantidade de testes
   opcao=malloc(numTeste*sizeof(char));   //cria vetor de teste dinamicamente
   for(i=0; i<numTeste; i++){   //lê o id do teste
      scanf("%d", &idTeste);
      scanf("%s", opcao);   //salva a string na estrutura teste[id]
      if(strcmp(opcao,"LINSIMP")==0){   //Verificar se a linha [aux1] é simples
         scanf("%d", &aux1);
         if(linhaSimples(li[aux1-1])==0)
            printf("Linha %d: simples\n", aux1);
         else
            printf("Linha %d: nao simples\n", aux1);
      }
      else if(strcmp(opcao,"POLSIMP")==0){   //Verificar se o poligono [aux1] é simples
         scanf("%d", &aux1);
         if(poligonoSimples(po[aux1-1])==0)
            printf("Poligono %d: simples\n", aux1);
         else
            printf("Poligono %d: nao simples\n", aux1);
      }
      else if(strcmp(opcao,"LINPOL")==0){    //Verificar se a linha [aux1] intercepta o poligono [aux2]
         scanf("%d %d", &aux1, &aux2);
         if(linhaInterceptaPoligono(li[aux1-1], po[aux2-1])==1)
            printf("Linha %d: intercepta o poligono %d\n", aux1, aux2);
         else
            printf("Linha %d: nao intercepta o poligono %d\n", aux1, aux2);
      }
      else if(strcmp(opcao,"PTOPOL")==0){    //Verificar se o ponto [aux1] está dentro do polígono [aux2]
         scanf("%d %d", &aux1, &aux2);
         if(pontoEmPoligono(pt[aux1-1], po[aux2-1])==1)
            printf("Ponto %d: dentro do poligono %d\n", aux1, aux2);
         else
            printf("Ponto %d: fora do poligono %d\n", aux1, aux2);
      }
   }
/*.......................libera memoria alocada e fecha arquivos.........*/
   free(pt);
   free(vertLinha);
   free(vertPoligono);
   free(li);
   free(po);
   free(opcao);

   return 0;
}



