#ifndef GRAFOS_H
#define GRAFOS_H


typedef struct TGrafo{
  int dir;       		//0 não direcionado, 1 direcionado, -1 grafo nao criado
  int qv;    		    //quantidade de vértices
  int **matrizadj; //matriz de adjacência alocada dinamicamente
} Grafo;


Grafo* criaGrafo(int dir, int qv);
void inicializaMatrizAdj(Grafo* g);
void criaAresta(Grafo* g, int u, int v, int peso);
void imprimeMatrizAdj(Grafo* g);
void liberaGrafo(Grafo *g);


#endif //
