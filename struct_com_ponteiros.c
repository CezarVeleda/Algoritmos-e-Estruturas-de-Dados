/*
Structs são a base de quase toda estrutura de dados. Combinadas com ponteiros, permitem criar nós encadeados — o bloco fundamental de listas, árvores e grafos.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct No{
    int dado;
    struct No* proximo;
     //ponteiro para o PROXIMO nó (mesmo tipo)
}No;

No* criar_no(int valor){
    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){
        return NULL;
    }

    novo->dado = valor;
    novo->proximo = NULL;

    return novo;
}

int main(){
    //criando e encadeando manualmente os nós
    No* n1 = criar_no(10);
    No* n2 = criar_no(20);
    No* n3 = criar_no(30);
    No* n4 = criar_no(40);

    n1->proximo = n2;
    n2->proximo = n3;
    n3->proximo = n4;
    // n4->proximo ja é null por padrão la da função


    //percorrer a lista encadeada e imprimindo eles;

    No* atual = n1;
    while(atual != NULL){
        printf("%d", atual->dado);
        atual = atual->proximo; // avança para o proximo nó
    }

    //saida deve ser 10, 20, 30, 40

    //liberando todos os nós e na ordem correta:
    free(n1); free(n2); free(n3); free(n4);
    return 0;
}
