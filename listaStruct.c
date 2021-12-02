#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dato {
    char nombre[30];
    int edad;
    float estatura;
    char sexo;
};

struct nodo{
	struct Dato dato;
	struct nodo *ptrSig;
};

struct nodo *crearNodo(struct Dato * ptrDato){
	struct nodo *ptrN;
	ptrN = (struct nodo*)malloc(sizeof(struct nodo));
    strcpy( ptrN->dato.nombre, ptrDato->nombre);
	ptrN->dato.edad = ptrDato->edad;
	ptrN->dato.estatura = ptrDato->estatura;
	ptrN->dato.sexo = ptrDato->sexo;
	ptrN->ptrSig = NULL;
	return ptrN;
}

void imprimir(struct nodo *ptrRef){
    printf("\nNombre: %s", ptrRef->dato.nombre);
    printf("\nEdad: %d", ptrRef->dato.edad);
    printf("\nEstatura: %.2f", ptrRef->dato.estatura);
    printf("\nSexo: %c\n", ptrRef->dato.sexo);
}

void meterDato(struct nodo **ptrRef, struct Dato * ptrDato){
	struct nodo *ptrNuevo;
	ptrNuevo = crearNodo(ptrDato);
	if(*ptrRef == NULL)
		*ptrRef = ptrNuevo;
	else{
		ptrNuevo->ptrSig = *ptrRef;
		*ptrRef = ptrNuevo;
	}
}

void sacarDato(struct nodo **ptrRef){
	struct nodo *ptrBasura;
	if(*ptrRef == NULL)
		printf("\nLa estructura esta vacia\n");
	else{
		ptrBasura = *ptrRef;
		*ptrRef = ptrBasura->ptrSig;
		imprimir(ptrBasura);
		free(ptrBasura);
	}
}

void imprimirContenido(struct nodo **ptrRef){
	struct nodo *ptrRecorrer;
	ptrRecorrer = *ptrRef;
	printf("\n");
	while(ptrRecorrer != NULL){
		imprimir(ptrRecorrer);
		ptrRecorrer = ptrRecorrer->ptrSig;
	}
	printf("\n");
}

int menu(){
	int opcion;
	printf("\nMENU PRINCIPAL");
	printf("\n1 para meter un dato a la estructura ");
	printf("\n2 para sacar el dato a la estructura ");
	printf("\n3 para ver el contenido de  la estructura ");
	printf("\n4 para salir del programa \n");
	scanf("%d", &opcion);
	return opcion;
}
int main(int argc, char *argv[]) {
	struct nodo *miPtrRef, **miPtrRef2;
	miPtrRef = NULL;
	miPtrRef2 = &miPtrRef;
	int opcion;
    struct Dato miDato, *ptrDato;
    ptrDato = &miDato;
	for(;;)
	switch(menu()){
		case 1:
			printf("\nIngresar nombre: ");
            fflush(stdin);
            gets(ptrDato->nombre);
            fflush(stdin);
            printf("Ingresar edad: ");
            scanf("%d", &(ptrDato->edad));
            printf("Ingresar estatura: ");
            scanf("%f", &(ptrDato->estatura));
            printf("Ingresar sexo: ");
            fflush(stdin);
            scanf("%c", &(ptrDato->sexo));
			meterDato(miPtrRef2, ptrDato);
			break;
		case 2:
			sacarDato(miPtrRef2);
			break;
		case 3:
			imprimirContenido(miPtrRef2);
			break;
		case 4:
			exit(0);
		default:
			printf("\nIngrese del 1 al 4 unicamente");
	}
	return 0;
}