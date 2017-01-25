/*Trabalho Pratico 0 de AEDS2 *** Guilherme Saulo Alves *** 09 de Setembro de 2013 */

//ponto, representado por coordenadas cartesianas x e y
typedef struct{
   double x;
   double y;
}ponto;

//linha, representada por uma sequencia de 2 a 100 pontos/vertices
typedef struct{
   ponto l[99];
   int numVertices;
}linha;

//poligono, representada por uma sequencia de 3 a 100 pontos/vertices
typedef struct{
   ponto p[99];
   int numVertices;
}poligono;

void criaPonto(ponto *p, double x, double y);

int pontoCoincide(ponto P, ponto Q);

void imprimePonto(ponto P);

void criaLinha(linha *l, int numVertices, ponto *vertices);

int linhaInterceptaPoligono(linha L, poligono P);

int linhaSimples(linha L);

void criaPoligono(poligono *p, int numVertices, ponto *vertices);

int pontoEmPoligono(ponto P, poligono Pol);

int poligonoSimples(poligono Pol);




