#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main() {
	int arreglo[TAM];
	int *ptr1, **ptr2, ***ptr3;
	ptr1 = arreglo;
    ptr2 = &ptr1;
	for (ptr3 = &ptr2; **ptr3 < &arreglo[TAM]; **ptr3 = **ptr3 + 1){
		printf("\n Ingrese un dato entero: ");	
		scanf("%d", **ptr3);
	}
	ptr1 = arreglo;
	for (ptr3 = &ptr2; **ptr3 < &arreglo[TAM]; **ptr3 = **ptr3 + 1)
	printf("\n En la celda %d esta el valor %d con direccion %ls ",(int)(**ptr3-arreglo), ***ptr3, **ptr3);
	return 0;
}