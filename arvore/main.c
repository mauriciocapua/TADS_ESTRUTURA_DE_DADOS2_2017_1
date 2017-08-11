#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"


void main(){

	 NoArv *raiz = criaNo(5);
	 NoArv *f3 = criaNo(3);
	 NoArv *f4 = criaNo(4);
	 NoArv *f1 = criaNo(1);
	 NoArv *f6 = criaNo(6);
	 NoArv *f7 = criaNo(7);
	 NoArv *f9 = criaNo(9);
	 NoArv *f11 = criaNo(11);

	 inserirEsq(f3,f1);
	 inserirDir(f3,f4);
	 inserirEsq(raiz,f3);

	 inserirDir(f9,f11);

	 inserirEsq(f7,f6);
	 inserirDir(f7,f9);
	 inserirDir(raiz,f7);

//	 printf("Mostra Raiz \n");
//	 mostraNo(raiz);
//	 printf("Mostra Raiz, Nós e folhas esquerda \n");
//	 mostraNosEsq(raiz);
//
//	 printf("Mostra Raiz, Nós e folhas direita \n");
//	 mostraNosDir(raiz);

//   preOrdem(raiz);
//    printf("\n");
//    inOrdem(raiz);
//    printf("\n");
//   posOrdem(raiz);


     removeFolhaspreordem(raiz);
}
