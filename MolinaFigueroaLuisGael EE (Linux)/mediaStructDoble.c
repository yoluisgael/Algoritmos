#include <stdio.h>
#include <stdlib.h>

struct datoEst{
	float arreglo[100];
	float *ptr, **ptr2;
	int tam;
	float media;
	float desvStd;
};

void calcEst(struct datoEst *ptrS);

int main(int argc, char *argv[]) {
	struct datoEst varS, *miptrS;
	miptrS=&varS;
	miptrS->ptr2=&miptrS->ptr;
	calcEst(miptrS);
	printf("\n La media de %d datos es %.2f \n", miptrS->tam, miptrS->media);
	return 0;
}

void calcEst(struct datoEst *ptrS){
	float suma=0;
	printf("\n Ingrese cuantos datos desea meter: \t");
	scanf("%d", &ptrS->tam);
	for(*ptrS->ptr2=ptrS->arreglo; *ptrS->ptr2<&ptrS->arreglo[ptrS->tam];*ptrS->ptr2=*ptrS->ptr2+1){
		printf("\n Ingrese un numero %d: \t",(int)(*ptrS->ptr2-ptrS->arreglo));
		scanf("%f",*ptrS->ptr2);
	}
	for(*ptrS->ptr2=ptrS->arreglo; *ptrS->ptr2<&ptrS->arreglo[ptrS->tam];*ptrS->ptr2=*ptrS->ptr2+1)
	suma=suma+**ptrS->ptr2;
	ptrS->media=suma/(ptrS->tam);
	suma=0;
}