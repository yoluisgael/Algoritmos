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
void buscar(struct nodo** ref, int dato);
void imprimir(struct nodo* ref, int contador);
void preorden(struct nodo* ref);
void postorden(struct nodo* ref);
void inorden(struct nodo* ref);
int minimo(struct nodo* ref);
int maximo(struct nodo* ref);
int numero(struct nodo* ref);
int numeroHojas(struct nodo* ref);
int numeroInternos(struct nodo* ref);
int sumaTotal(struct nodo* ref);
int sumaHojas(struct nodo* ref);
int sumaInternos(struct nodo* ref);

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
        buscar(referencia, dato);
        break;
        case 3: 
        imprimir(*referencia, 1);
        printf("\n\n");
        break;
        case 4:
        printf("Preorden: ");
        preorden(*referencia);
        printf("\n\n");
        break;
        case 5:
        printf("Postorden: ");
        postorden(*referencia);
        printf("\n\n");
        break;
        case 6:
        printf("Inorden : ");
        inorden(*referencia);
        printf("\n\n");
        break;
        case 7:
        if(*referencia != NULL)
        printf("Minimo: %d\n\n", minimo(*referencia));
        else
        printf("El arbol esta vacio\n\n");
        break;
        case 8:
        if(*referencia != NULL)
        printf("Maximo: %d\n\n", maximo(*referencia));
        else
        printf("El arbol esta vacio\n\n");
        break;
        case 9:
        printf("El numero de nodos es: %d\n\n", numero(*referencia));
        break;
        case 10:
        printf("El numero de hojas es: %d\n\n", numeroHojas(*referencia));
        break;
        case 11:
        printf("El numero de nodos internos es: %d\n\n", numeroInternos(*referencia));
        break;
        case 12:
        printf("La suma total es: %d\n\n", sumaTotal(*referencia));
        break;
        case 13:
        printf("La suma de nodos hoja es: %d\n\n", sumaHojas(*referencia));
        break;
        case 14:
        printf("La suma de nodos internos es: %d\n\n", sumaInternos(*referencia));
        break;
        default:
        exit(0);
        break;
    }
    return 0;
}

int menu(){
    int num;
    printf("1. Ingresar dato\n2. Buscar nodo\n3. Imprimir arbol\n4. Preorden\n5. Postorden\n6. Inorden\n7. Minimo\n8. Maximo\n9. Numero de nodos\n10. Numero de hojas\n11. Numero de nodos internos\n12. Suma Total\n13. Suma de hojas\n14. Suma de internos\nPresione cualquier otro para salir\n");
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
    printf("Ya existe el valor\n\n");
}

void buscar(struct nodo** ref, int dato){
    if(*ref == NULL)
    printf("No existe el valor\n\n");
    else if(dato == (*ref)->dato)
    printf("El valor existe\n\n");
    else if(dato > (*ref)->dato)
    buscar(&(*ref)->der, dato);
    else
    buscar(&(*ref)->izq, dato);
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

void preorden(struct nodo* ref){
    if(ref == NULL)
    return;
    printf("%d ", ref->dato);
    preorden(ref->izq);
    preorden(ref->der);
}

void postorden(struct nodo* ref){
    if(ref == NULL)
    return;
    printf("%d ", ref->dato);
    postorden(ref->der);
    postorden(ref->izq);
}

void inorden(struct nodo* ref){
    if(ref == NULL)
    return;
    inorden(ref->izq);
    printf("%d ", ref->dato);
    inorden(ref->der);
}

int minimo(struct nodo* ref){
    if(ref->izq == NULL)
    return ref->dato;
    minimo(ref->izq);
}

int maximo(struct nodo* ref){
    if(ref->der == NULL)
    return ref->dato;
    maximo(ref->der);
}

int numero(struct nodo* ref){
    int i;
    if(ref == NULL)
    return 0;
    i = 1 + numero(ref->izq) + numero(ref->der);
    return i;
}

int numeroHojas(struct nodo* ref){
    int i;
    if(ref == NULL)
    return 0;
    if(ref->der == NULL && ref->izq == NULL)
    return 1;
    i = numeroHojas(ref->izq) + numeroHojas(ref->der);
    return i;
}

int numeroInternos(struct nodo* ref){
    int i;
    if(ref == NULL)
    return 0;
    if(ref->der == NULL && ref->izq == NULL)
    return 0;
    i = 1 + numeroInternos(ref->izq) + numeroInternos(ref->der);
    return i;
}

int sumaTotal(struct nodo* ref){
    int i;
    if(ref == NULL)
    return 0;
    i = ref->dato + sumaTotal(ref->izq) + sumaTotal(ref->der);
    return i;
}

int sumaHojas(struct nodo* ref){
    int i;
    if(ref == NULL)
    return 0;
    if(ref->der == NULL && ref->izq == NULL)
    return ref->dato;
    i = sumaHojas(ref->izq) + sumaHojas(ref->der);
    return i;
}

int sumaInternos(struct nodo* ref){
    int i;
    if(ref == NULL)
    return 0;
    if(ref->der == NULL && ref->izq == NULL)
    return 0;
    i = ref->dato + sumaInternos(ref->izq) + sumaInternos(ref->der);
    return i;
}