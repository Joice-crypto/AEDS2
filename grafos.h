#ifndef GRAFOS_H
#define GRAFOS_H
#include "dados.h"

#define max 50

typedef struct TVertice Vertice;
typedef struct TGrafo Grafo;

typedef struct TGrafo
{
  Vertice *lista;
  Vertice *vertices[max];
  int dir; //0 não direcionado
  int qv;
} Grafo;

typedef struct TVertice
{
  Vertice *vizinhos[max]; // vizinho so no vertice
  int id;                 //id do vértice
  int qv;
  Vertice *prox;
  char estado; //estado do vertice
} Vertice;

Grafo *criaGrafo(int dir, int qv);
void inicializaMatrizAdj(Grafo *g);
void criaAresta(Grafo *g, int v, int u);
void imprimeListasAdj(grafo);
void liberaGrafo(Grafo *g);
void fazvizinhos(char estado, Grafo *g, int u, int v);
void imprimeVert(Grafo *g);
void criaVert(Grafo *g, int qv, char estado);

#endif //
