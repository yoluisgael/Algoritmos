#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM 30

struct Numeros{
    char digitos[5];
};

struct Pila{
    struct Numeros numeros[TAM];
    char *ptrCima;
};

void meterPila(struct Pila * ptrPila, char dato);
char sacarPila(struct Pila * ptrPila);

int main(){
    char P[TAM];
    char c = ')';
    int A, B;
    struct Pila pila, *miPtrPila;
    miPtrPila = &pila;
    printf("\nIngresar operación postfija: ");
    gets(P);
    strncat(P, &c, 1);
    printf("%s", P);
    for(int i = 0; P[i] != '\0'; i++){
        if(P[i] == '+' || P[i] == '-' || P[i] == '*' || P[i] == '/' || P[i] == '^'){
            switch (P[i]){
                case '+':
                    A = (int)sacarPila(miPtrPila);
                    B = (int)sacarPila(miPtrPila);
                    meterPila(miPtrPila, B+A);
                    break;
                case '-':
                    A = (int)sacarPila(miPtrPila);
                    B = (int)sacarPila(miPtrPila);
                    meterPila(miPtrPila, B-A);
                    break;
                case '*':
                    A = (int)sacarPila(miPtrPila);
                    B = (int)sacarPila(miPtrPila);
                    meterPila(miPtrPila, B*A);
                    break;
                case '/':
                    A = (int)sacarPila(miPtrPila);
                    B = (int)sacarPila(miPtrPila);
                    meterPila(miPtrPila, B/A);
                    break;
                case '^':
                    A = (int)sacarPila(miPtrPila);
                    B = (int)sacarPila(miPtrPila);
                    meterPila(miPtrPila, pow(B, A));
                    break;
            }
        }
        else{
            meterPila(miPtrPila, P[i]);
        }
        printf("%c", *miPtrPila->ptrCima);
    }
    printf("El resultado es : %d", (int)sacarPila(miPtrPila));
    return 0;
}

void meterPila(struct Pila * ptrPila, char dato){
    *ptrPila->ptrCima = dato;
    (ptrPila->ptrCima)++;
}

char sacarPila(struct Pila * ptrPila){
    ptrPila->ptrCima = 0;
    (ptrPila->ptrCima)--;
    return *ptrPila->ptrCima;
}