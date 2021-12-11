#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

struct Pila{
    int arreglo[5];
    int *ptr1, **ptr2;
};

void meterPila(struct Pila *ptr, int dato);
int checarLleno(struct Pila *ptr);

int main(){

}

void meterPila(struct Pila *ptr, int dato){
    **(*ptr) -> ptr2 = dato;
    *(*ptr) -> ptr2 = *(*ptr)->ptr2 - 1;
}

int checarLleno(struct Pila *ptr){
    if(*ptr->ptr2)
    return 0;
    else
    return 1;
}