// malloc — aloca bloco na heap

#include <stdlib.h>
int main(){

    // aloca espaço para 5 inteiros na heap
    int* arr = (int*) malloc(5 * sizeof(int));

    // SEMPRE verifique se malloc retornou NULL (falha na alocação)
    if (arr == NULL) {
    printf("Erro: sem memória\n");
    return 1;
    }
    // use como um array normal
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10; // arr[i] equivale a *(arr + i)
    }

    free(arr); // Obrigatório pois devolve memoria ao sistema
    arr == NULL; // boa pratica: evita um ponteiro solto


    //calloc — aloca e inicializa com zero
    
    // calloc(n, tamanho) → aloca n elementos e zera tudo
    int* zeros = (int*) calloc(10, sizeof(int));
    // todos os 10 ints já começam em 0


    int* arr = (int*) malloc (5 * sizeof(int));
    // precisa de mais espaço

    //realloc pode mover o bloco, use ponteiro temporario

    int* tmp = (int*) realloc(arr, 10 * sizeof(int));

    if(tmp == NULL){
        //arr ainda é valido nesse caso
        free(arr); //libere antes de sair
        return 1;
    }
    arr = tmp; //atualiza o ponteiro

    /* Erros classicos:
    
    // 1. memory leak — alocou, nunca liberou
    int* p = malloc(100);  // sem free(p) → vazamento!

    // 2. double free — liberar duas vezes
    free(p); free(p);  // comportamento indefinido!

    // 3. usar depois de free
    free(p);
    p[0] = 5;  // comportamento indefinido!

    // 4. ponteiro não inicializado
    int* x;  // x contém lixo — não use sem inicializar!

    */
}