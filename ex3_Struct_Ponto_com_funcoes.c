#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct Ponto{
    float x;
    float y;
}Ponto;

Ponto* criar_Ponto(float x, float y){
    Ponto* ponto = (Ponto*) malloc(sizeof(Ponto));
    if(ponto == NULL){
        return NULL;
    }

    ponto->x = x;
    ponto->y = y;
    return ponto;
}

float distancia(Ponto* a, Ponto* b) {
    float dx = a->x - b->x;
    float dy = a->y - b->y;
    return sqrt(dx*dx + dy*dy);
}

void libera_ponto(Ponto *p){
    free(p);
}


int main(){
    return 0;
}