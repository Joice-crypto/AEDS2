#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafos.h"
#include "dados.h"

// char estado[3] = {'S', 'I', 'R'};

int inicializaInf(Grafo *g, char estado, Event infec)
{
    srand(time(NULL));
    int dia = 0;

    printf("\nDia:%d\n", dia);

    for (int i = 0; i < g->qv; i++) // vai percorrer todo os vertices
    {
        Vertice *v = g->vertices[i]; // os meus vertices

        if (v->id == 20)
        {
            v->estado = 'I';
        }
        if (v->id == 12)
        {
            v->estado = 'I';
        }

        // for (int j = 0; j < 12; j++) // 50% da população recuperada
        // {
        //      g->vertices[j]->estado = estado;
        // }

        printf("Vertice (%d) = %c\n", i, g->vertices[i]->estado);
    }
}

int Funinfeccao(Grafo *g, char estado, Event infec) // função de infectar os vertices
{

    for (int i = 0; i < g->qv; i++) // vai percorrer todo os vertices
    {
        int num = rand() % 100;

        Vertice *v = g->vertices[i]; // os meus vertices

        if (infec.mystate == v->estado) // se o vertice atual tem o mesmo estado do mystate (S)
        {

            bool tem_vizinho = false;
            int l;
            for (int j = 0; j < v->qv; j++)
            {
                if (v->vizinhos[j]->estado == infec.estado_vizinho) // se ele tem um vizinho infectado
                {
                    tem_vizinho = true;
                    l = v->vizinhos[j]->id; // vertice que esta infectado

                    if (num < infec.prob * 100) // gera o numero aleatorio
                    {

                        v->estado = infec.acao;
                    }
                }
            }
        }
    }
}

int FunRecuperacao(Grafo *g, char estado, Event recup) // função de recuperação
{

    for (int i = 0; i < g->qv; i++) // vai percorrer todo os vertices
    {
        int num = rand() % 100;
        Vertice *v = g->vertices[i]; // os meus vertices

        if (recup.mystate == v->estado) // se o vertice atual tem o mesmo estado do mystate ambos INF
        {
            if (num < recup.prob * 100) // gera o numero aleatorio
            {
                v->estado = recup.acao; // esse vertice vai ser recuperado
            }
        }
    }
}
