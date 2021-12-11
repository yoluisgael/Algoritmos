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

int main(int argc, char *argv[]) {
	struct datos Var;
    Var.ptrB = &Var.ptrA;
	for(*Var.ptrB=&Var.arreglo[0]; *Var.ptrB<=&Var.arreglo[TAM-1]; *Var.ptrB = *Var.ptrB+1){
		printf("\n Ingrese el nombre (cadena):");
		fgets((*Var.ptrB)->nombre,10,stdin);
		printf("\n Ingrese la edad (entero):");
		scanf("%d",&(*Var.ptrB)->edad);
		__fpurge(stdin);
	}
    for(*Var.ptrB=&Var.arreglo[0]; *Var.ptrB<=&Var.arreglo[TAM-1]; *Var.ptrB = *Var.ptrB+1){
    	printf("\n La celda %d con direccion %p tiene nombre %s con direccion %p",\
		(int)((*Var.ptrB)-(Var.arreglo)+1),&(*Var.ptrB), (*Var.ptrB)->nombre, &(*Var.ptrB)->nombre);
		printf("\n La celda %d con direccion %p tiene edad %d con direccion %p",\
		(int)((*Var.ptrB)-(Var.arreglo)+1),&(*Var.ptrB), (*Var.ptrB)->edad, &(*Var.ptrB)->edad);
	}
	return 0;
}