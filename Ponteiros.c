#include <stdio.h>

// === PARTE 1: declaração e operadores básicos ===

int main() {
    int x = 42;
    int y = 7;

    int* p; // declara um ponteiro para int (ainda não inicializado!)
    p = &x; // p recebe o ENDEREÇO de x

    printf("%p \n", p); // imprime o endereço ex: 0x7fff5e100
    printf("%d \n", *p); // derreferencia: imprime 42'

    *p = 100; // muda o valor de x através do ponteiro
    printf("%d \n", x); // x agora é 100 !!

    // === PARTE 2: ponteiro para ponteiro ===

    int** pp = &p; //pp guarda o endereço de p
    printf("%d \n", **pp); // ** = dois níveis de derreferencia -> 100

    // === PARTE 3: passagem por referência ===

    dobrar(&x);
    printf("%d \n", x); // x agora é 200

    return 0;
}

void dobrar(int* n) {
    *n = *n * 2; // modifica a variavels ORIGINAL do chamador
}