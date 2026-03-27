//Usando a struct No do módulo, implemente: inserir_inicio(No** cabeca, int valor) que insere um nó no começo da lista, e liberar_lista(No* cabeca) que percorre e libera todos os nós. Teste com 5 inserções
#include <stdio.h>
#include <stdlib.h>

typedef struct No{
        int dado;
        struct No* proximo;
}No;

No* criar_no(int valor){
    No* no = (No*) malloc(sizeof(No));
    
    if(no == NULL){
        return 1;
    }

    no->dado = valor;
    no->proximo = NULL;
}

void inserir_inicio(No** cabeca, int valor){
    No* novo = criar_no(valor);
    if (novo == NULL) return;

    novo->proximo = *cabeca;
    *cabeca = novo;
}

void liberar_lista(No* cabeca){
    No* atual = cabeca;
    while(atual != NULL){
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}
int main() {
    No* lista = NULL; // Lista começa vazia

    // Teste com 5 inserções
    for(int i = 1; i <= 5; i++) {
        inserir_inicio(&lista, i * 10); 
        printf("Inserido: %d\n", i * 10);
    }

    // A lista será: 50 -> 40 -> 30 -> 20 -> 10 -> NULL
    
    liberar_lista(lista);
    return 0;
}