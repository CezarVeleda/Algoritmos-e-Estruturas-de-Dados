#include <stdio.h>
#include <stdlib.h>
#define CAPACIDADE 5
typedef struct FilaMatchmaking{
    int ids_jogadores[CAPACIDADE];
    int inicio;
    int fim;
    int quantidade;
}FilaMatchmaking;

void inicializarFila(FilaMatchmaking *f){
    f->inicio = 0;
    f->fim = 0;
    f->quantidade = 0;
}

void entrarNaFila(FilaMatchmaking *f, int id_jogador){
    if(f->quantidade == CAPACIDADE){
        printf("Fila cheia, aguarde !");
        return;
    }

    f->ids_jogadores[f->fim] = id_jogador;
    printf("Jogador ID %d entrou na fila.\n", id_jogador);

    f->fim++;
    f->quantidade++;
}

void chamarParaPartida(FilaMatchmaking *f){
    if(f->quantidade == 0){
        printf("Fila vazia! Ninguem buscando partida.\n");
        return;
    }
    
    int id_chamado = f->ids_jogadores[f->inicio];
    printf(">> Partida Encontrada! Jogador ID %d indo pro servidor.\n", id_chamado);

    f->inicio++;
    f->quantidade--;
}
void espiarProximo(FilaMatchmaking *f){
    if(f->quantidade == 0){
        printf("A fila esta vazia, chefe!\n");
        return;
    }
    int id_Proximo = f->ids_jogadores[f->inicio];
    printf("O ID do proximo jogador é: %d", id_Proximo);
}

int main(){
    FilaMatchmaking filaCS;
    inicializarFila(&filaCS);
    printf("--- Matchmaking Iniciado ---\n");

    entrarNaFila(&filaCS, 101);
    entrarNaFila(&filaCS, 102); 
    entrarNaFila(&filaCS, 103);
    espiarProximo(&filaCS);
    printf("\n--- Abrindo Vagas no Servidor ---\n");
    chamarParaPartida(&filaCS); // Pela regra FIFO, OBRIGATORIAMENTE tem que sair o 101
    chamarParaPartida(&filaCS);
}