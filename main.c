#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "grafos.h"
#include "dados.h"

int main(){
    int qv; 
    int dir = 0; // o meu grafo sera sempre não direcionado
    printf("Qual a quantidade de vertices do grafo:\n"); 
    scanf("%d", &qv);
    

    Grafo* grafo = criaGrafo(dir,qv); 
    int u = 0, v;
    int peso;  
    int sair;
    while(sair != 1){
        printf("Digite o vertice de origem");
    scanf("%d", &u);
    printf("Digite o vertice de destino");
    scanf("%d", &v);
    printf("Digite o peso da aresta"); 
    scanf("%d", &peso);
    printf("Deseja sair? (1):Sim");
    scanf("%d", &sair);
    criaAresta(grafo,u,v,peso);  
    }

           
    
    imprimeMatrizAdj(grafo);

   
    return 0; 
}