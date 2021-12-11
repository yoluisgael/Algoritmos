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
	int i;
};
int main() {
	struct datos Var;
	struct datos *ptrE, **ptrF;
    ptrF = &ptrE;
	ptrE = &Var;
	for((*ptrF)->i=0;(*ptrF)->i<=TAM-1;(*ptrF)->i++){
		printf("\n Ingrese el nombre (cadena): ");
		fgets((*ptrF)->arreglo[(*ptrF)->i].nombre, 10, stdin);
		printf("\n Ingrese la edad (entero): ");
		scanf("%d", &(*ptrF)->arreglo[(*ptrF)->i].edad);
		__fpurge(stdin);
	}
	
	for((*ptrF)->i=0;(*ptrF)->i<=TAM-1;(*ptrF)->i++){
		printf("\n La celda %d con direccion %p tiene nombre %s con direccion %p",\
		(*ptrF)->i+1, &(*ptrF)->arreglo[(*ptrF)->i], (*ptrF)->arreglo[(*ptrF)->i].nombre, &(*ptrF)->arreglo[(*ptrF)->i].nombre);
		printf("\n La celda %d con direccion %p tiene edad %d con direccion %p",\
		(*ptrF)->i+1, &(*ptrF)->arreglo[(*ptrF)->i], (*ptrF)->arreglo[(*ptrF)->i].edad, &(*ptrF)->arreglo[(*ptrF)->i].edad);	
	}
	return 0;
}