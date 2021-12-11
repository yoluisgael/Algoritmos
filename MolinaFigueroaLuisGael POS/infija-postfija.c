#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 30

struct Pila{
    char arreglo[20];
    char *ptrCima;
};

int pilaVacia(struct Pila * ptrPila);
void meterPila(struct Pila * ptrPila, char dato);
char sacarPila(struct Pila * ptrPila);
void quitarParentesis(char *c);

int main(){
    char Q[TAM];
    char P[TAM], *ptrP;
    struct Pila pila, *miPtrPila;
    char c = ')';
    ptrP = P;
    miPtrPila = &pila;
    miPtrPila->ptrCima = miPtrPila->arreglo;
    printf("\nIngresar operaci%cn infija: ", 162);
    fflush(stdin);
    gets(Q);                                              //Se lee la cadena de la operación
    strncat(Q, &c, 1);                                    //Y se le agrega un ')' al final
    meterPila(miPtrPila, '(');
    for(int i = 0; Q[i] != '\0'; i++){                    //Se comienzan a checar los valores de Q 
        if(Q[i]=='(')                                     //Si es '(' se mete a la pila
        meterPila(miPtrPila, Q[i]);
        else if(Q[i]=='^'){                               //Si es '^' únicamente saca de la pila otros operadores de potencia. Luego se mete a la pila
            while(*(miPtrPila->ptrCima - 1) == '^'){
                *ptrP = sacarPila(miPtrPila);
                ptrP++;
            }
            meterPila(miPtrPila, Q[i]);
        }
        else if(Q[i]=='*' || Q[i]=='/'){                  //Si es multiplicación o división, saca esas mismas y potencias. Luego se mete a la pila
            while(*(miPtrPila->ptrCima - 1) == '^' || *(miPtrPila->ptrCima - 1) == '*' || *(miPtrPila->ptrCima - 1) == '/'){
                *ptrP = sacarPila(miPtrPila);
                ptrP++;
            }
            meterPila(miPtrPila, Q[i]);
        }
        else if(Q[i]=='+' || Q[i]=='-'){                  //Si es suma o resta saca todos los operadores. Luego se mete a la pila
            while(*(miPtrPila->ptrCima - 1) == '^' || *(miPtrPila->ptrCima - 1) == '*' || *(miPtrPila->ptrCima - 1) == '/' || *(miPtrPila->ptrCima - 1) == '+' || *(miPtrPila->ptrCima - 1) == '-'){
                *ptrP = sacarPila(miPtrPila);
                ptrP++;
            } 
            meterPila(miPtrPila, Q[i]);
        }
        else if(Q[i]==')'){                               //Si es ')' se sacan todos los operadores al resultado hasta '(', quita ese valor en la pila,
            while(*miPtrPila->ptrCima != '('){            //regresa el puntero al último valor de P y también quita ese valor
                *ptrP = sacarPila(miPtrPila);
                ptrP = ptrP + 1;
            }
            *miPtrPila->ptrCima = 0;
            ptrP--;
            *ptrP = 0;
        }
        else{                                             //Si es cualquier otro caracter, lo añade al resultado
            *ptrP = Q[i];
            ptrP++;
        }
    }
    if(*(ptrP - 1) == '('){                               //Checa si el último valor de P es un paréntesis y lo remueve
        ptrP--;
        *ptrP = 0;
    }
    printf("Operaci%cn postfija: %s", 162, P);
    return 0;
}

void meterPila(struct Pila * ptrPila, char dato){
    *ptrPila->ptrCima = dato;
    (ptrPila->ptrCima)++;
}

char sacarPila(struct Pila * ptrPila){
    *ptrPila->ptrCima = 0;
    (ptrPila->ptrCima)--;
    return *ptrPila->ptrCima;
}