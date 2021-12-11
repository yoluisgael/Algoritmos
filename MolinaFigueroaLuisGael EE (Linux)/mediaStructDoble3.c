#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct datoEst{
	float arreglo[100];
	float *ptr, **ptr2;
	int tam;
	float media;
	float desvStd;
};

void calcEst(struct datoEst **ptrS);

int main(int argc, char *argv[]) {
	struct datoEst varS, *miptrS, **miptrS2;
	miptrS=&varS;
    miptrS2=&miptrS;
    (*miptrS2)->ptr2 = &(*miptrS2)->ptr;
	calcEst(miptrS2);
	printf("\n La media de %d datos es %.2f \n", (*miptrS2)->tam, (*miptrS2)->media);
	printf("\n La desviacion estandar de %d datos es %.2f \n", (*miptrS2)->tam, (*miptrS2)->desvStd);
	return 0;
}

void calcEst(struct datoEst **ptrS){
	float suma=0;
	printf("\n Ingrese cuantos datos desea meter: \t");
	scanf("%d", &(*ptrS)->tam);
	for(*(*ptrS)->ptr2 = (*ptrS)->arreglo; *(*ptrS)->ptr2 < &(*ptrS)->arreglo[(*ptrS)->tam]; *(*ptrS)->ptr2 = *(*ptrS)->ptr2 + 1){
		printf("\n Ingrese un numero %d: \t",(int)(*(*ptrS)->ptr2-(*ptrS)->arreglo));
		scanf("%f",*(*ptrS)->ptr2);
	}
	for(*(*ptrS)->ptr2=(*ptrS)->arreglo; *(*ptrS)->ptr2<&(*ptrS)->arreglo[(*ptrS)->tam];*(*ptrS)->ptr2 = *(*ptrS)->ptr2 + 1)
	suma = suma + **(*ptrS)->ptr2;
	(*ptrS)->media=suma/((*ptrS)->tam);
	suma = 0;
	for(*(*ptrS)->ptr2=(*ptrS)->arreglo; *(*ptrS)->ptr2<&(*ptrS)->arreglo[(*ptrS)->tam];*(*ptrS)->ptr2 = *(*ptrS)->ptr2 + 1)
	suma = suma + pow((*ptrS)->media-**(*ptrS)->ptr2,2);
	(*ptrS)->desvStd = pow(suma/((*ptrS)->tam),0.5);
}