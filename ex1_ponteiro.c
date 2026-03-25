#include <stdio.h>
#include <stdlib.h>

void trocar(int* a, int* b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
    int x;
    int y;
    int* px;
    int* py;
    
    printf("ANTES: X = %d & Y = %d,", x , y);

    trocar(px, py);
    
    printf("DEPOIS: X = %d & Y = %d,", x , y);
    return 0;
}