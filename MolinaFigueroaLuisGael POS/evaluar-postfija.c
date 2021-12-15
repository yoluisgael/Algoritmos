#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TAM 30

struct Pila{
    int numeros[TAM];
    int *ptrCima;
};

void meterPila(struct Pila* ptrPila, int dato);
int sacarPila(struct Pila* ptrPila);
int crearNum(struct Pila* ptrNum);

int main(){
    char P[TAM];
    char c = ')';
    int A, B, cierto;
    struct Pila pila, *miPtrPila, numeros, *miPtrNum;
    miPtrPila = &pila;
    miPtrPila->ptrCima = &miPtrPila->numeros[0];
    miPtrNum = &numeros;
    miPtrNum->ptrCima = &miPtrNum->numeros[0];
    printf("\nIngresar operacion postfija: ");
    gets(P);
    strncat(P, &c, 1);
    printf("Se agrega un parentesis a la cadena; %s\n", P);
    for(int i = 0; P[i] != ')'; i++){
        printf("P[%d] = %c\t", i, P[i]);
        if(P[i] == '+' || P[i] == '-' || P[i] == '*' || P[i] == '/' || P[i] == '^'){
            printf("\n");
            A = sacarPila(miPtrPila);
            B = sacarPila(miPtrPila);
            printf("A = %d\tB = %d\n", A, B);
            switch(P[i]){
                case '+':
                meterPila(miPtrPila, B+A);
                break;
                case '-':
                meterPila(miPtrPila, B-A);
                break;
                case '*':
                meterPila(miPtrPila, B*A);
                break;
                case '/':
                meterPila(miPtrPila, B/A);
                break;
                case '^':
                meterPila(miPtrPila, pow(B,A));
                break;  
            }
        }
        else if(P[i] == '1' || P[i] == '2' || P[i] == '3' || P[i] == '4' || P[i] == '5' || P[i] == '6' || P[i] == '7' || P[i] == '8' || P[i] == '9' || P[i] == '0'){
            meterPila(miPtrNum, (int)P[i]-48);
            cierto = 1;
        }
        else if(P[i] == ',' && cierto == 1){
            meterPila(miPtrPila, crearNum(miPtrNum));
            cierto = 0;
        } else
        printf("\n");
    }
    printf("El resultado es : %d", sacarPila(miPtrPila));
    return 0;
}

void meterPila(struct Pila * ptrPila, int dato){
    *ptrPila->ptrCima = dato;
    printf("Se metio el valor: %d\n", *ptrPila->ptrCima);
    (ptrPila->ptrCima)++;
}

int sacarPila(struct Pila * ptrPila){
    (ptrPila->ptrCima)--;
    return *ptrPila->ptrCima;
}

int crearNum(struct Pila* ptrNum){
    int numero = 0;
    for(int i = 1; ptrNum->ptrCima != &ptrNum->numeros[0]; i = i*10){
        (ptrNum->ptrCima)--;
        numero = numero + *ptrNum->ptrCima * i;
    }
    printf("Se creo el numero: %d\n", numero);
    return numero;
}