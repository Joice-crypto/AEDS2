#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "grafos.h"
#include "dados.h"

// FILE *cenario6B;
int main()
{
    // cenario6B = fopen("cenario6B.txt", "w");
    char estado[3] = {'S', 'I', 'R'}; // meus estados

    
#define GRID 5
    int dir = 0; // o meu grafo sera sempre não direcionado

    Event event_queue[] = {
        {estado[0], estado[1], estado[1], 0.84, 1, true}, // Infection
        {estado[1], -1, estado[2], 0.12, 5, true}         // Recovery
    };

    Grafo *grafo = criaGrafo(dir, GRID); // a quantidade de vertices vai ser dado por GRID

    // Inicializa os vértices
    for (int i = 0; i < GRID * GRID; i++)
    {

        criaVert(grafo, GRID, estado[0]); // todos os vertices estão sucetiveis no inicio
    }

    // inicializa as arestas no metodo de GRADE
    for (int j = 0; j < GRID * GRID; j++)
    {

        if ((j + 1) % GRID != 0)
        {
            criaAresta(grafo, j, j + 1);

        }
        if (j < GRID * (GRID - 1))
        {
            criaAresta(grafo, j, j + GRID);
        }
    }

    imprimeListasAdj(grafo);
    inicializaInf(grafo, estado[2], event_queue[0]); // vai infectar um vertice

    printf("--------------------------------------------\n");



    // ****************** EXECUTAR OS EVENTOS ***********************

    for (int l = 1; l < 30; l++) // vai representar os meus dias
    {
        // int t = 3;
        // int t2 = 7;
        printf("\nDia:%d\n", l);
        Funinfeccao(grafo, estado[0], event_queue[0]);

        if (l % 5 == 0)
        {
            FunRecuperacao(grafo, estado[1], event_queue[1]);
        }

        // if (l % t == 0) // vou rodar a função de recuperação de 3 em 3 dias
        // {
        //     Funinfeccao(grafo, estado[0], event_queue[0]);
        //     // t+3;
        // }

        // if (l % t2 == 0) // vou rodar meu evento de recuperação de 7 em 7 dias
        // {
        //     FunRecuperacao(grafo, estado[1], event_queue[1]);
        // }

        for (int i = 0; i < grafo->qv; i++)
        {
            printf("Vertice (%d) = %c\n", i, grafo->vertices[i]->estado);
        }
    }

    return 0;
}
