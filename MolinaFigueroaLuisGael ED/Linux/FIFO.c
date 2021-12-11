#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define TAM 5

struct Pila{
	int arreglo[TAM];
	int *ptrCima;
    int *ptrSacar;
};

void resetearCima(struct Pila * ptrPila);
void resetearSacar(struct Pila * ptrPila);
void meterPila(struct Pila * ptrPila, int dato);
int sacarPila(struct Pila * ptrPila);
int pilaLlena(struct Pila * ptrPila);
int pilaVacia(struct Pila * ptrPila);
int numElem(struct Pila * ptrPila);
int menu();

int main(int argc, char *argv[]) {
	struct Pila pila;
	struct Pila *miPtrPila;
	miPtrPila = &pila;
	miPtrPila->ptrCima = miPtrPila->arreglo;
    miPtrPila->ptrSacar = miPtrPila->arreglo;
	int miDato;
	for(;;){
		switch(menu()){
			case 1:
                if(pilaLlena(miPtrPila) == 1)
                printf("\nLa pila está llena!!");
                else {
                    printf("\nIngrese un dato entero: ");
                    scanf("%d",&miDato);
                    meterPila(miPtrPila,miDato);
                    resetearCima(miPtrPila);
                }
				break;
			case 2:
				if(pilaVacia(miPtrPila)==1)
				printf("\nLa pila esta vacia \n !!!");
				else{
				    printf("%d", sacarPila(miPtrPila));
                    resetearSacar(miPtrPila);
                }
				break;
			case 3:
				printf("\nLa pila tiene %d elementos", numElem(miPtrPila));
				break;
			case 4:
				exit(0);
			default:
				printf("\nIntente otra vez, Ingrese del 1 al 4 \n");
		}
	}
	return 0;
}

void resetearCima(struct Pila * ptrPila){
	if(ptrPila->ptrCima==&ptrPila->arreglo[TAM] + 1)
    ptrPila->ptrCima = ptrPila->arreglo;
}

void resetearSacar(struct Pila * ptrPila){
	if(ptrPila->ptrSacar==&ptrPila->arreglo[TAM] + 1)
    ptrPila->ptrSacar = ptrPila->arreglo;
}

void meterPila(struct Pila * ptrPila, int dato){
	*ptrPila->ptrCima = dato;
	ptrPila->ptrCima = ptrPila->ptrCima + 1;
}

int sacarPila(struct Pila * ptrPila){
    int temp = *ptrPila->ptrSacar;
    (ptrPila->ptrSacar)++;
	return temp;
}

int pilaVacia(struct Pila * ptrPila){
	if(ptrPila->ptrSacar==ptrPila->ptrCima)
	return 1;
	else 
	return 0;
}

int pilaLlena(struct Pila * ptrPila){
    if((ptrPila->ptrCima + 1) == ptrPila->ptrSacar || ptrPila->ptrCima == &ptrPila->arreglo[TAM] && ptrPila->ptrSacar == ptrPila->arreglo)
    return 1;
    else
    return 0;
}

int numElem(struct Pila * ptrPila){
    if(ptrPila->ptrCima > ptrPila->ptrSacar)
	return(int)(ptrPila->ptrCima - ptrPila->ptrSacar);
    else if(ptrPila->ptrSacar > ptrPila->ptrCima)
    return(TAM - (int)(ptrPila->ptrSacar - ptrPila->ptrCima));
    else
    return 0;
}

int menu(){
	int eleccion;
	__fpurge(stdin);
	printf("\nIngrese 1 para meter en la Pila ");
	printf("\nIngrese 2 para sacar de la Pila ");
	printf("\nIngrese 3 para el numero de elementos en la Pila ");
	printf("\nIngrese 4 para salir\n");
	scanf("%d",&eleccion);
	return (eleccion);
}