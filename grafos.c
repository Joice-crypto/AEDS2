#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "grafos.h"
#include "dados.h"



Grafo *criaGrafo(int dir, int qv)
{
    Grafo *g = (Grafo *)malloc(sizeof(Grafo)); // alocando espaço pro eu grafo
    g->dir = dir;
    g->qv = 0;

    return g;
}

void criaVert(Grafo *g, int qv, char estado)
{

    Vertice *ver = (Vertice *)malloc(sizeof(Vertice));

    ver->id = g->qv;
    ver->qv = 0;
    ver->estado = estado;

    g->vertices[g->qv++] = ver;
}

void criaAresta(Grafo *g, int u, int v) // u é a origem  // v é o destino
{

    if (u < 0 || u >= g->qv)
        return;
    if (v < 0 || v >= g->qv)
        return;

    Vertice *orig = (Vertice *)malloc(sizeof(Vertice));
    Vertice *dest = (Vertice *)malloc(sizeof(Vertice));

    orig->id = u;
    orig->prox = dest->prox;

    orig = g->vertices[u];
    dest = g->vertices[v];

    orig->vizinhos[orig->qv++] = dest;
    dest->vizinhos[dest->qv++] = orig;
}

void imprimeListasAdj(Grafo *g)
{

    Vertice *v = (Vertice *)malloc(sizeof(Vertice));
    printf("\nListas de adjacência:\n");
    for (int i = 0; i < g->qv; i++)
    {

        v = g->vertices[i];
        printf("\n\nAdjacentes de %d:\n ", v->id);

        for (int j = 0; j < v->qv; j++)
        {
            printf(" vertice: %d, estado: %c;\n", v->vizinhos[j]->id, v->vizinhos[j]->estado);
        }
    }

    printf("\n");
}

void liberaGrafo(Grafo *g)
{
    for (int i = 0; i < g->qv; i++)
    {
        Vertice *p = g->vertices[i], *q;
        while (p != NULL)
        {
            q = p;
            p = p->vizinhos;
            free(q);
        }
    }
    free(g->vertices);
    free(g);
}