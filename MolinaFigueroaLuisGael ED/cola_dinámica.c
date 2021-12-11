#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo{
	int dato;
	struct nodo *ptrSig;
};

struct nodo *crearNodo(int dato1){
	struct nodo *ptrN;
	ptrN = (struct nodo*)malloc(sizeof(struct nodo));
	ptrN->dato = dato1;
	ptrN->ptrSig = NULL;
	return ptrN;
}

void meterDato(struct nodo **ptrRef, int dato){
	struct nodo *ptrNuevo;
	ptrNuevo = crearNodo(dato);
	if(*ptrRef == NULL)
		*ptrRef = ptrNuevo;
	else{
		ptrNuevo->ptrSig = *ptrRef;
		*ptrRef = ptrNuevo;
	}
}

void sacarDato(struct nodo **ptrRef){
	struct nodo *ptrAv, *ptrRet;
	ptrRet = *ptrRef;
	if(*ptrRef == NULL)
		printf("\nLa estructura esta vacia ");
	else if(ptrRet->ptrSig == NULL){
		printf("\nEl dato recuperado (eliminado) es %d ", ptrRet->dato);
		free(ptrRet);
		*ptrRef = NULL;
	}
	else{
		for(ptrAv = ptrRet->ptrSig; ptrAv->ptrSig != NULL; ptrAv = ptrAv->ptrSig)
		ptrRet = ptrRet->ptrSig;
		ptrRet->ptrSig = NULL;
		printf("\nEl dato recuperado (eliminado) es %d ", ptrAv->dato);
		free(ptrAv);
	}
}

void imprimirContenido(struct nodo **ptrRef){
	struct nodo *ptrRecorrer;
	ptrRecorrer = *ptrRef;
	printf("\n");
	while(ptrRecorrer != NULL){
		printf("%d ", ptrRecorrer->dato);
		ptrRecorrer = ptrRecorrer->ptrSig;
	}
	printf("<-\n");
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
	int opcion, miDato;
	for(;;)
	switch(menu()){
		case 1:
			printf("\nIngrese un entero: ");
			scanf("%d", &miDato);
			meterDato(miPtrRef2, miDato);
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
			printf("\nIngrese del 1 al 4 unicamente ");
	}
	return 0;
}