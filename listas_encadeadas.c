#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item{
    char nome[15];
    struct Item *proximo;
} Item;
int main(){
    Item *item1 = (Item*) malloc(sizeof(Item));
    Item *item2 = (Item*) malloc(sizeof(Item));
    Item *item3 = (Item*) malloc(sizeof(Item));

    strcpy(item1->nome, "M4A1");
    strcpy(item2->nome, "Colete Kevlar");
    strcpy(item3->nome, "Grana de Luz");
    item3->proximo =  NULL;

    item1->proximo = item2;
    item2->proximo = item3;

    Item *atual = item1;
    printf("Inventario: \n");
    
    while(atual != NULL){
        printf("- %s\n", atual->nome);
        atual = atual->proximo;
    }

    free(item1);
    free(item2);
    free(item3);
    return 0;
}