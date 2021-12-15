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
void mayores(struct nodo* ref, int num);
void menores(struct nodo* ref, int num);
int sumaMayores(struct nodo* ref, int num);
int sumaMenores(struct nodo* ref, int num);

int main(){
    int dato;
    struct nodo** referencia;
    struct nodo* raiz = NULL;
    referencia = &raiz;
    for(;;)
    switch(menu()){
        case 0:
        exit(0);
        break;
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
        case 15:
        printf("Valor: ");
        scanf("%d", &dato);
        mayores(*referencia, dato);
        printf("\n");
        break;
        case 16:
        printf("Valor: ");
        scanf("%d", &dato);
        menores(*referencia, dato);
        printf("\n");
        break;
        case 17:
        printf("Valor: ");
        scanf("%d", &dato);
        printf("La suma de nodos mayores a %d es: %d\n\n", dato, sumaMayores(*referencia, dato));
        break;
        case 18:
        printf("Valor: ");
        scanf("%d", &dato);
        printf("La suma de nodos menores a %d es: %d\n\n", dato, sumaMenores(*referencia, dato));
        break;
        default:
        printf("Opcion no valida\n\n");
        break;
    }
    return 0;
}

int menu(){
    int num;
    printf("0. Salir\t\t10. Numero de hojas\n1. Ingresar dato\t11. Numero de nodos internos\n2. Buscar nodo\t\t12. Suma total\n3. Imprimir arbol\t13. Suma de hojas\n4. Preorden\t\t14. Suma de internos\n5. Postorden\t\t15. Nodos mayores a\n6. Inorden\t\t16. Nodos menores a\n7. Minimo\t\t17. Suma de mayores a\n8. Maximo\t\t18. Suma de menores a\n9. Numero de nodos\n");
    scanf("%d", &num);
    printf("\n");
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

void mayores(struct nodo* ref, int num){
    if(ref == NULL)
    return;
    else if(ref->dato > num){
        mayores(ref->izq, num);
        printf("%d\n", ref->dato);
        mayores(ref->der, num);
    } 
    else
    mayores(ref->der, num);
}

void menores(struct nodo* ref, int num){
    if(ref == NULL)
    return;
    else if(ref->dato < num){
        menores(ref->izq, num);
        printf("%d\n", ref->dato);
        menores(ref->der, num);
    } 
    else
    menores(ref->izq, num);
}

int sumaMayores(struct nodo* ref, int num){
    int i;
    if(ref == NULL)
    return 0;
    else if(ref->dato > num)
    i = ref->dato + sumaMayores(ref->izq, num) + sumaMayores(ref->der, num);
    else
    i = sumaMayores(ref->der, num);
    return i;
}

int sumaMenores(struct nodo* ref, int num){
    int i;
    if(ref == NULL)
    return 0;
    else if(ref->dato < num)
    i = ref->dato + sumaMenores(ref->izq, num) + sumaMenores(ref->der, num); 
    else
    i = sumaMenores(ref->izq, num);
    return i;
}