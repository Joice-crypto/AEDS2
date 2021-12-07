#ifndef DADOS_H
#define DADOS_H

#define max 50
#include "grafos.h"
#include <stdbool.h>

typedef struct TGrafo Grafo;

typedef struct TEvent
{ // evento que vai ficar no lugar do arquivo XML
       char mystate;
       char estado_vizinho;
       char acao;
       float prob; // probabilidade dele acontecer
       int t;
       bool repeat; // se o repeat for verdadeiro então ele vai inserir novamente na heap

} Event;

int Funinfeccao(Grafo *g, char estado, Event infec);
int inicializaInf(Grafo *g, char estado, Event infec);
int FunRecuperacao(Grafo *g, char estado, Event recup);

#endif