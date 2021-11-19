#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "grafos.h"
#include "dados.h"

int evento (){

    srand(time(NULL)); 

    // aqui vou chamar o evento 
    Event *infeccao = (Event*) malloc(sizeof(Event)); // cria o evento de infeccao 

     strcpy(infeccao->name,"infection");

     infeccao->timedelay = 1;

}

int heap(){

   




}