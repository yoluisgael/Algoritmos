#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define TAM 5

struct dato{
    char nombre[10];
    int edad;
};

struct datos{
    struct dato arreglo[TAM];
    int i;
};

int main(){
    struct datos var;
    for(var.i = 0; var.i < TAM - 1; var.i++){
        printf("\nIngrese el nombre (cadena): ");
        fgets(var.arreglo[var.i].nombre, 10, stdin);
        printf("\nIngrese la edad: ");
        scanf("%d", &var.arreglo[var.i].edad);
        __fpurge(stdin);
    }
    for(var.i = 0; var.i < TAM - 1; var.i++){
        printf("\nLa celda %d con dirección %p tiene nombre %s con dirección %p",
        var.i + 1, &var.arreglo[var.i], var.arreglo[var.i].nombre, &var.arreglo[var.i].nombre);
        printf("\nLa celda %d con dirección %p tiene edad %d con dirección %p",
        var.i + 1, &var.arreglo[var.i], var.arreglo[var.i].edad, &var.arreglo[var.i].nombre);
    }
    return 0;
}