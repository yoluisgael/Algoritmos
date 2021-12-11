#include <stdio.h>
#include <stdlib.h>

struct datoEst{
	float arreglo[100];
	float *ptr;
	int tam;
	float media;
	float desvStd;
};

void calcEst(struct datoEst **ptrS);

int main(int argc, char *argv[]) {
	struct datoEst varS, *miptrS, **miptrS2;
	miptrS=&varS;
    miptrS2=&miptrS;
	calcEst(miptrS2);
	printf("\n La media de %d datos es %.2f \n", (*miptrS2)->tam, (*miptrS2)->media);
	printf("\n La desviacion estandar de %d datos es %.2f \n", (*miptrS2)->tam, (*miptrS2)->desvStd);
	return 0;
}

void calcEst(struct datoEst **ptrS){
	float suma=0;
	printf("\n Ingrese cuantos datos desea meter: \t");
	scanf("%d", &(*ptrS)->tam);
	for((*ptrS)->ptr = (*ptrS)->arreglo; (*ptrS)->ptr < &(*ptrS)->arreglo[(*ptrS)->tam]; (*ptrS)->ptr++){
		printf("\n Ingrese un numero %d: \t",(int)((*ptrS)->ptr-(*ptrS)->arreglo));
		scanf("%f",(*ptrS)->ptr);
	}
	for((*ptrS)->ptr=(*ptrS)->arreglo; (*ptrS)->ptr<&(*ptrS)->arreglo[(*ptrS)->tam];(*ptrS)->ptr++)
	suma = suma + *(*ptrS)->ptr;
	(*ptrS)->media=suma/((*ptrS)->tam);
	suma = 0;
	for((*ptrS)->ptr=(*ptrS)->arreglo; (*ptrS)->ptr<&(*ptrS)->arreglo[(*ptrS)->tam];(*ptrS)->ptr++)
	suma = suma + pow((*ptrS)->media-*(*ptrS)->ptr,2);
	(*ptrS)->desvStd = pow(suma/((*ptrS)->tam),0.5);
}