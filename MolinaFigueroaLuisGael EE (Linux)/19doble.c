#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#define TAM 3

struct dato{
	char nombre[10];
	int edad;
};

struct datos{
	struct dato arreglo[TAM];
	struct dato *ptrA, **ptrB;
};
int main() {
	struct datos Var;
	struct datos *ptrE, **ptrF;
    ptrF = &ptrE;
	ptrE = &Var;
    (*ptrF)->ptrB = &(*ptrF)->ptrA;
	for(*(*ptrF)->ptrB=&(*ptrF)->arreglo[0];*(*ptrF)->ptrB<=&(*ptrF)->arreglo[TAM-1];*(*ptrF)->ptrB = *(*ptrF)->ptrB + 1){
		printf("\n Ingrese el nombre (cadena)[%d]: ",(int)((*(*ptrF)->ptrB)-((*ptrF)->arreglo)+1));
		fgets((*(*ptrF)->ptrB)->nombre, 10, stdin);
		printf("\n Ingrese la edad (entero)[%d]: ", (int)((*(*ptrF)->ptrB)-((*ptrF)->arreglo)+1));
		scanf("%d", &(*(*ptrF)->ptrB)->edad);
		__fpurge(stdin);
	}
	
	for(*(*ptrF)->ptrB=&(*ptrF)->arreglo[0];*(*ptrF)->ptrB<=&(*ptrF)->arreglo[TAM-1];*(*ptrF)->ptrB = *(*ptrF)->ptrB + 1){
		printf("\n La celda %d con direccion %p tiene nombre %s con direccion %p",\
		(int)((*(*ptrF)->ptrB)-((*ptrF)->arreglo)+1), *(*ptrF)->ptrB,(*(*ptrF)->ptrB)->nombre, &(*(*ptrF)->ptrB)->nombre);
		printf("\n La celda %d con direccion %p tiene edad %d con direccion %p",\
		(int)((*(*ptrF)->ptrB)-((*ptrF)->arreglo)+1), *(*ptrF)->ptrB,(*(*ptrF)->ptrB)->edad, &(*(*ptrF)->ptrB)->edad);	
	}
	return 0;
}