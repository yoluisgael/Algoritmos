#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define TAM 4

struct Pila{
	int arreglo[TAM];
	int *ptrCima, **ptrCima2;
};

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
    miPtrPila->ptrCima2 = &miPtrPila->ptrCima;
	miPtrPila->ptrCima = miPtrPila->arreglo;
	int miDato;
	for(;;){
		switch(menu()){
			case 1:
				if(pilaLlena(miPtrPila)==1)
				printf("\n Pila esta llena !!!");
				else{
					printf("\n Ingrese un dato entero: ");
					scanf("%d",&miDato);
					meterPila(miPtrPila,miDato);
				}
				break;
			case 2:
				if(pilaVacia(miPtrPila)==1)
				printf("\n La pila esta vacia \n !!!");
				else
				printf("%d", sacarPila(miPtrPila));
				break;
			case 3:
				printf("\n La pila tiene %d elementos", numElem(miPtrPila));
				break;
			case 4:
				exit(0);
			default:
				printf("\n Intente otra vez, Ingrese del 1 al 4 \n");
		}
	}
	return 0;
}

void meterPila(struct Pila * ptrPila, int dato){
	**ptrPila->ptrCima2=dato;
	*ptrPila->ptrCima2 = *ptrPila->ptrCima2 + 1;
}

int sacarPila(struct Pila * ptrPila){
	*ptrPila->ptrCima2 = *ptrPila->ptrCima2 - 1;
	return(**ptrPila->ptrCima2);
}

int pilaLlena(struct Pila * ptrPila){
	if(*ptrPila->ptrCima2==&ptrPila->arreglo[TAM])
	return 1;
	else
	return 0;
}

int pilaVacia(struct Pila * ptrPila){
	if(*ptrPila->ptrCima2==ptrPila->arreglo)
	return 1;
	else 
	return 0;
}

int numElem(struct Pila * ptrPila){
	return(int)(*ptrPila->ptrCima2 - ptrPila->arreglo);
}

int menu(){
	int eleccion;
	__fpurge(stdin);
	printf("\n Ingrese 1 para meter en la Pila ");
	printf("\n Ingrese 2 para sacar de la Pila ");
	printf("\n Ingrese 3 para el numero de elementos en la Pila ");
	printf("\n Ingrese 4 para salir \n");
	scanf("%d",&eleccion);
	return (eleccion);
}