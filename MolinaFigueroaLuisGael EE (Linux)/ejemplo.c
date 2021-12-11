#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int main() {
	int arreglo[TAM];
	int *ptr1, **ptr2;
	ptr1 = arreglo;
	for (ptr2 = &ptr1; *ptr2 < &arreglo[TAM]; *ptr2++){
		printf("\n Ingrese un dato entero: ");	
		scanf("%d", *ptr2);
	}
	ptr1 = arreglo;
	for(ptr2 = &ptr1; *ptr2 < &arreglo[TAM]; *ptr2 = *ptr2 + 1)
	printf("\n En la celda %d esta el valor %d con direccion %ls ",(int)(*ptr2-arreglo), **ptr2, *ptr2);
	return 0;
}