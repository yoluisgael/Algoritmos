#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>

struct Dato{
    int edad;
    char nombre[30];
    float est;
    char sexo;
};

struct Pila{
	struct Dato arreglo[5];
	struct Dato *ptrA;
};

void meterPila(struct Pila * ptrPila, struct Dato * ptrDato);
void sacarPila(struct Pila * ptrPila, struct Dato * ptrDato);
int pilaLlena(struct Pila * ptrPila);
int pilaVacia(struct Pila * ptrPila);
int numElem(struct Pila * ptrPila);
int menu();

int main(int argc, char *argv[]) {
	struct Pila miPila, *miPtrS;
    struct Dato miDato, *miPtrDato;
	miPtrS = &miPila;
    miPtrDato = &miDato;
	miPtrS->ptrA = miPtrS->arreglo;
	for(;;){
		switch(menu()){
			case 1:
				if(pilaLlena(miPtrS)==1)
				printf("\n Pila esta llena !!!");
				else{
					printf("\n Ingrese la edad: ");
					scanf("%d",&(miPtrDato->edad));
                    printf("\n Ingrese el nombre: ");
                    __fpurge(stdin);
					fgets(miPtrDato->nombre, 30, stdin);
                    printf("\n Ingrese la estatura: ");
					scanf("%f",&(miPtrDato->est));
                    printf("\n Ingrese el sexo: ");
                    __fpurge(stdin);
					scanf("%c",&(miPtrDato->sexo));
					meterPila(miPtrS,miPtrDato);
				}
				break;
			case 2:
				if(pilaVacia(miPtrS)==1)
				printf("\n La pila esta vacia \n !!!");
				else{
                    sacarPila(miPtrS, miPtrDato);
                    printf("\nLa edad es: %d", miPtrDato->edad);
                    printf("\nEl nombre es: %s", miPtrDato->nombre);
                    printf("\nLa estatura es: %f", miPtrDato->est);
                    printf("\nEl sexo es: %c", miPtrDato->sexo);
                }
				break;
			case 3:
				printf("\n La pila tiene %d elementos", numElem(miPtrS));
				break;
			case 4:
				exit(0);
			default:
				printf("\n Intente otra vez, Ingrese del 1 al 4 \n");
		}
	}
	return 0;
}

void meterPila(struct Pila * ptrPila, struct Dato * ptrDato){
	ptrPila->ptrA->edad = ptrDato->edad;
    strcpy(ptrPila->ptrA->nombre, ptrDato->nombre);
    ptrPila->ptrA->est = ptrDato->est;
	ptrPila->ptrA->sexo = ptrDato->sexo;
	ptrPila->ptrA = ptrPila->ptrA + 1;
}

void sacarPila(struct Pila * ptrPila, struct Dato * ptrDato){
	ptrPila->ptrA = ptrPila->ptrA - 1;
    ptrDato->edad = ptrPila->ptrA->edad;
    strcpy(ptrDato->nombre, ptrPila->ptrA->nombre);
    ptrDato->est = ptrPila->ptrA->est;
	ptrDato->sexo = ptrPila->ptrA->sexo;
}

int pilaLlena(struct Pila * ptrPila){
	if(ptrPila->ptrA==&ptrPila->arreglo[5])
	return 1;
	else
	return 0;
}

int pilaVacia(struct Pila * ptrPila){
	if(ptrPila->ptrA==ptrPila->arreglo)
	return 1;
	else 
	return 0;
}

int numElem(struct Pila * ptrPila){
	return(int)(ptrPila->ptrA - ptrPila->arreglo);
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