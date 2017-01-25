/*Trabalho Pratico 0 de AEDS2 *** Guilherme Saulo Alves *** 09 de Setembro de 2013 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "geometria.h"

//cria uma coordenada de ponto (x,y)
void criaPonto(ponto *p, double x, double y){
   (*p).x=x;
   (*p).y=y;
}

// retorna TRUE se os pontos forem identicos
int pontoCoincide(ponto P, ponto Q){
   if((P.x==Q.x) && (P.y==Q.y))	return 1;
   else	return 0;
}

//imprime a coordenada de ponto (x,y)
void imprimePonto(ponto P){
   printf("(%lf,%lf)", P.x, P.y);
}

//cria uma coordenada para cada vertice (x,y) da linha
void criaLinha(linha *l, int numVertices, ponto *vertices){
   (*l).l[numVertices].x=(*vertices).x;
   (*l).l[numVertices].y=(*vertices).y;
}

// verifica se a linha poligonal tem interseção com o polígono
int linhaInterceptaPoligono(linha L, poligono P){
   int i,j;
   double det, s, t;
   for(i=0; i<L.numVertices-1; i++){   //semireta linha
      for(j=0; j<P.numVertices-1; j++){   //semireta poligono
         det=(P.p[j+1].x - P.p[j].x) * (L.l[i+1].y - L.l[i].y) - (P.p[j+1].y - P.p[j].y) * (L.l[i+1].x - L.l[i].x);
         s=(((P.p[j+1].x - P.p[j].x) * (P.p[j].y - L.l[i].y)) - ((P.p[j+1].y - P.p[j].y) * (P.p[j].x - L.l[i].x))) / det;
         t=(((L.l[i+1].x - L.l[i].x) * (P.p[j].y - L.l[i].y)) - ((L.l[i+1].y - L.l[i].y) * (P.p[j].x - L.l[i].x))) / det;
         if((s>=0 && s<=1) && (t>=0 && t<=1))
            return 1;   //ha intersecao
      }
   }
   return 0; //sem intersecao
}

// verifica se a linha é simples (sem auto-interseções)
int linhaSimples(linha L){
   int i,j;
   double det, s, t;
   for(i=0; i<L.numVertices-1; i++){   //semireta 1
      for(j=0; j<L.numVertices-1; j++){   //semireta 2
         det=(L.l[j+1].x - L.l[j].x) * (L.l[i+1].y - L.l[i].y) - (L.l[j+1].y - L.l[j].y) * (L.l[i+1].x - L.l[i].x);
         s=(((L.l[j+1].x - L.l[j].x) * (L.l[j].y - L.l[i].y)) - ((L.l[j+1].y - L.l[j].y) * (L.l[j].x - L.l[i].x))) / det;
         t=(((L.l[i+1].x - L.l[i].x) * (L.l[j].y - L.l[i].y)) - ((L.l[i+1].y - L.l[i].y) * (L.l[j].x - L.l[i].x))) / det;
         if((s>0 && s<=1) && (t>0 && t<=1))
            return 1;   //ha intersecao
      }
   }
   return 0;   //sem intersecao
}

//cria uma coordenada para cada vertice (x,y) do poligono
void criaPoligono(poligono *p, int numVertices, ponto *vertices){
   (*p).p[numVertices].x=(*vertices).x;
   (*p).p[numVertices].y=(*vertices).y;
}

// verifica se o ponto está no interior do polígono
int pontoEmPoligono(ponto P, poligono Pol){
   int i, aux=0;
   double det, s, t;
   ponto paux;
   paux.x=INT_MAX;   //estende o x para criar um semireta
   paux.y=P.y;  //mantem o y
   for(i=0; i<Pol.numVertices-1; i++){
      det=(Pol.p[i+1].x - Pol.p[i].x) * (paux.y - P.y) - (Pol.p[i+1].y - Pol.p[i].y) * (paux.x - P.x);
      s=(((Pol.p[i+1].x - Pol.p[i].x) * (Pol.p[i].y - P.y)) - ((Pol.p[i+1].y - Pol.p[i].y) * (Pol.p[i].x - P.x))) / det;
      t=(((paux.x - P.x) * (Pol.p[i].y - P.y)) - ((paux.y - P.y) * (Pol.p[i].x - P.x))) / det;
      if((s>=0 && s<=1) && (t>=0 && t<=1))
         aux++; //contador de intersercoes
   }
   if(aux%2!=0)
      return 1; //dentro
   else
      return 0; //fora
}

// verifica se o polígono é simples (sem auto-interseções)
int poligonoSimples(poligono Pol){
   int i,j;
   double det, s, t;
   for(i=0; i<Pol.numVertices-1; i++){   //reta 1
      for(j=0; j<Pol.numVertices-1; j++){   //reta 2
         det=(Pol.p[j+1].x - Pol.p[j].x) * (Pol.p[i+1].y - Pol.p[i].y) - (Pol.p[j+1].y - Pol.p[j].y) * (Pol.p[i+1].x - Pol.p[i].x);
         s=(((Pol.p[j+1].x - Pol.p[j].x) * (Pol.p[j].y - Pol.p[i].y)) - ((Pol.p[j+1].y - Pol.p[j].y) * (Pol.p[j].x - Pol.p[i].x))) / det;
         t=(((Pol.p[i+1].x - Pol.p[i].x) * (Pol.p[j].y - Pol.p[i].y)) - ((Pol.p[i+1].y - Pol.p[i].y) * (Pol.p[j].x - Pol.p[i].x))) / det;
         if((s>0 && s<=1) && (t>0 && t<=1))
            return 1;   //ha intersecao
      }
   }
   return 0; //sem intersecao
}



