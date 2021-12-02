#include <stdio.h>
#include <stdlib.h>

struct nodo{
    struct nodo* izq;
    struct nodo* der;
    int dato;
};

int menu();
struct nodo* crearNodo(int dato);
void meterNodo(struct nodo** ref, int dato);
void suprimir(struct nodo** ref, int dato);
void imprimir(struct nodo* ref, int contador);

int main(){
    int dato;
    struct nodo** referencia;
    struct nodo* raiz = NULL;
    referencia = &raiz;
    for(;;)
    switch(menu()){
        case 1: 
        printf("Valor: ");
        scanf("%d", &dato);
        meterNodo(referencia, dato);
        break;
        case 2: 
        printf("Valor: ");
        scanf("%d", &dato);
        suprimir(referencia, dato);
        break;
        case 3: 
        imprimir(*referencia, 1);
        printf("\n");
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("Opcion no valida\n");
        break;
    }
    return 0;
}

int menu(){
    int num;
    printf("1. Ingresar dato\n2. Suprimir nodo\n3. Imprimir arbol\n4. Salir\n");
    scanf("%d", &num);
    return num;
}

struct nodo* crearNodo(int dato){
    struct nodo* ptrN = (struct nodo*)malloc(sizeof(struct nodo));
    ptrN->dato = dato;
    ptrN->izq = NULL;
    ptrN->der = NULL;
    return ptrN;
}

void meterNodo(struct nodo** ref, int dato){
    if(*ref == NULL)
    *ref = crearNodo(dato);
    else if(dato > (*ref)->dato)
    meterNodo(&(*ref)->der, dato);
    else if(dato < (*ref)->dato)
    meterNodo(&(*ref)->izq, dato);
    else
    printf("Ya existe el valor\n");
}

void suprimir(struct nodo** ref, int dato){
    if(*ref == NULL)
    printf("No existe el valor\n");
    else if(dato == (*ref)->dato)
    *ref = NULL;
    else if(dato > (*ref)->dato)
    suprimir(&(*ref)->der, dato);
    else
    suprimir(&(*ref)->izq, dato);
}

void imprimir(struct nodo* ref, int contador){
    int i, j;
    i = contador;
    if(ref == NULL)
    return;
    imprimir(ref->der, i+1);
    printf("\n");
    for(j=1;j<i;j++)
    printf("-");
    printf("%d", ref->dato);
    imprimir(ref->izq, i+1);
}