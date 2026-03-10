#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[15];
    int dano;
}Arma;

int main(){
    Arma *ak_47 = (Arma*) malloc(sizeof(Arma));
    if(ak_47 == NULL){
        printf("Não foi possivel criar o item");
        return 1;
    }
    strcpy(ak_47->nome, "AK-47");
    ak_47->dano = 36;

    printf("Dados da arma %s, DANO: %d",ak_47->nome, ak_47->dano);
    free(ak_47);
    return 0;
}