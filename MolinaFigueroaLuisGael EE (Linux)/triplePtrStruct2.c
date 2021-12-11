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
    struct persona ***ptr3;
    ptr1 = arreglo;
    ptr3 = &ptr2;
    for(*ptr3 = &ptr1; **ptr3 < &arreglo[3]; **ptr3 = **ptr3 + 1){
        printf("\nIngrese el nombre [%d]: ", (int)(**ptr3 - arreglo));
        fgets((**ptr3)->nombre, 30, stdin);
        printf("\nIngrese la edad [%d]: ", (int)(**ptr3 - arreglo));
        scanf("%d", &(**ptr3) -> edad);
        printf("\nIngrese la estatura [%d]: ", (int)(**ptr3 - arreglo));
        scanf("%f", &(**ptr3) -> estatura);
        printf("\nIngrese el sexo [%d]: ", (int)(**ptr3 - arreglo));
        scanf("%c", &(**ptr3) -> sexo);
        __fpurge(stdin);
        (**ptr3) -> sexo = getchar();
        __fpurge(stdin);
    }

    printf("\nEl tamaño de la estrcuctura es %ld", sizeof(struct persona));
    printf("\nEl tamaño del arreglo es %ld", sizeof(arreglo));
    printf("\nEl arreglo está en la dirección %p", &arreglo[0]);

    for(**ptr3 = arreglo; **ptr3 < &arreglo[3]; **ptr3 = **ptr3 + 1){
        printf("\nEn la celda %d está el nombre de %s con dirección %p", (int)(**ptr3-arreglo), (**ptr3)->nombre, &(**ptr3)->nombre);
        printf("\nEn la celda %d está la edad %d con dirección %p", (int)(**ptr3-arreglo), (**ptr3)->edad, &(**ptr3)->edad);
        printf("\nEn la celda %d está la estatura %f con dirección %p", (int)(**ptr3-arreglo), (**ptr3)->estatura, &(**ptr3)->estatura);
        printf("\nEn la celda %d está el sexo de %c con dirección %p", (int)(**ptr3-arreglo), (**ptr3)->sexo, &(**ptr3)->sexo);
    }
    return 0;
}