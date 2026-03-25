#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    if(n<=0){
        prinft("Erro, o tamanho deve ser maior que zero");
        return 1;
    }

    int* arr = (int*) malloc(n * sizeof(int));

    if(arr==NULL){
        printf("Erro ao alocar memoria");
        return 1;
    }

    for(int i = 0; i < n; i++){
        printf("Digite o valor para a posição [%d] do array: ", i);
        scanf("%d", &arr[i]);
    }

    int soma = 0;
    for(int i = 0; i < n; i++){
        soma += arr[i];
    }
    printf("A soma é  = %d", soma);
    
    free(arr);
    arr = NULL;
    return 0;
}