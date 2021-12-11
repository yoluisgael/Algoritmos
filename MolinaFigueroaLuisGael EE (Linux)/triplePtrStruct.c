#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

struct persona{
    char nombre[30];
    int edad;
    float estatura;
    char sexo;
};

int main(){
    struct persona arreglo[3];
    struct persona *ptr1;
    struct persona **ptr2;
    ptr1 = arreglo;
    for(ptr2 = &ptr1;*ptr2 < &arreglo[3]; *ptr2 = *ptr2 + 1){
        printf("\nIngrese el nombre [%d]: ", (int)(*ptr2 - arreglo));
        fgets((*ptr2)->nombre, 30, stdin);
        printf("\nIngrese la edad [%d]: ", (int)(*ptr2 - arreglo));
        scanf("%d", &(*ptr2) -> edad);
        printf("\nIngrese la estatura [%d]: ", (int)(*ptr2 - arreglo));
        scanf("%f", &(*ptr2) -> estatura);
        printf("\nIngrese el sexo [%d]: ", (int)(*ptr2 - arreglo));
        scanf("%c", &(*ptr2) -> sexo);
        __fpurge(stdin);
        (*ptr2) -> sexo = getchar();
        __fpurge(stdin);
    }

    printf("\nEl tamaño de la estrcuctura es %ld", sizeof(struct persona));
    printf("\nEl tamaño del arreglo es %ld", sizeof(arreglo));
    printf("\nEl arreglo está en la dirección %p", &arreglo[0]);

    for(*ptr2 = arreglo; *ptr2 < &arreglo[3]; *ptr2 = *ptr2 + 1){
        printf("\nEn la celda %d está el nombre de %s con dirección %p", (int)(*ptr2-arreglo), (*ptr2)->nombre, &(*ptr2)->nombre);
        printf("\nEn la celda %d está la edad %d con dirección %p", (int)(*ptr2-arreglo), (*ptr2)->edad, &(*ptr2)->edad);
        printf("\nEn la celda %d está la estatura %f con dirección %p", (int)(*ptr2-arreglo), (*ptr2)->estatura, &(*ptr2)->estatura);
        printf("\nEn la celda %d está el sexo de %c con dirección %p", (int)(*ptr2-arreglo), (*ptr2)->sexo, &(*ptr2)->sexo);
    }
    return 0;
}