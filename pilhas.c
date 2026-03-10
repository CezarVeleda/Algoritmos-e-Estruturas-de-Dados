#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define CAPACIDADE 5

typedef struct Carregador{
    int balas[CAPACIDADE];
    int topo;
} Carregador;

//push
void inserirBala(Carregador *c, int danoBala){
    if(c->topo == CAPACIDADE -1){
        printf("Click, Carregador cheio , ultimo projetil inserido\n");
        return;
    }
    c->topo++;
    c->balas[c->topo] = danoBala;
    printf("Bala de dano %d inserida no slot %d", danoBala, c->topo);
}

//pop
void atirar(Carregador *c){
    if(c->topo == -1){
        printf("Sem munição");
        return;
    }
    int balaAtirada = c->balas[c->topo];
    c->topo--;
    printf("pow, tiro disparado com dano %d", balaAtirada);

}
int main(){
    Carregador *minhaArma = (Carregador*) malloc(sizeof(Carregador));
    minhaArma->topo = -1;

    printf("--- Recarregando ---\n");
    inserirBala(minhaArma, 30);
    inserirBala(minhaArma, 45);
    inserirBala(minhaArma, 50);
    printf("\n--- Atirando ---\n");
    atirar(minhaArma);
    atirar(minhaArma);

    free(minhaArma);
    return 0;
}