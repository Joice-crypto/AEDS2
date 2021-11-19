#ifndef DADOS_H 
#define DADOS_H

#include "grafos.h"

typedef struct TEvent { // evento que vai ficar no lugar do arquivo XML

       char name[50]; // nome do evento

       float timedelay;   //tempo em que ele sera executado  

       float time;    

       int prob; // probabilidade dele acontecer

       int repeat; // se o repeat for verdadeiro então ele vai inserir novamente na heap

} Event; 







#endif