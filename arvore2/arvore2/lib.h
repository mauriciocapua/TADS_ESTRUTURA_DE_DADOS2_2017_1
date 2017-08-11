
//Biblioteca da Aula 3 Arvore Binária
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct noArvore{
       int n;
       struct noArvore *esq;
       struct noArvore *dir;
};

typedef struct noArvore NoArv;
typedef NoArv * NoArvPtr;

NoArv* criaNo(int v);
void mostraNo(NoArvPtr);
void mostraPreOrdem(NoArvPtr);
void mostraInOrdem(NoArvPtr);
void mostraPosOrdem(NoArvPtr);
//void insereNo(NoArvPtr *, int n); //ponterio de Ponteiro


NoArvPtr criaNo(int v){
	 NoArv* noaux = (NoArv*) malloc (sizeof(NoArv));
	 if(noaux != NULL){
		 noaux->n = v;
		 noaux->esq = NULL;
		 noaux->dir = NULL;
		 return noaux;
	}else{
		printf("ERRO - Problema na Alocação!!");
		return NULL;
	}

}

void mostraNo(NoArvPtr no){
	printf(" %d -",no->n);
}

void mostraPreOrdem(NoArvPtr raiz){

	if(raiz != NULL) {
		mostraNo(raiz);
		mostraPreOrdem(raiz->esq);
		mostraPreOrdem(raiz->dir);
	}
}

void mostraInOrdem(NoArvPtr raiz){
	if(raiz != NULL) {
		mostraInOrdem(raiz->esq);
		mostraNo(raiz);
		mostraInOrdem(raiz->dir);
	}
}

void mostraPosOrdem(NoArvPtr raiz){
	if(raiz != NULL) {
		mostraPosOrdem(raiz->esq);
		mostraPosOrdem(raiz->dir);
		mostraNo(raiz);
	}
}

/*
void insereNo(NoArvPtr raiz, int vl){
	if (raiz == NULL){
		raiz = criaNo(vl);
		printf("Inserido\n");
	}else{

		if(vl < raiz->n){
			printf("Esquerda >> ");
			insereNo(raiz->esq, vl);
		}else{
			if(vl > raiz->n){
				printf("Direita  >> ");
				insereNo(raiz->dir, vl);
			}else{
				printf ("Valor_Repetido\n");
			}
		}

	}
}


*/

void insereNo(NoArvPtr *raiz, int vl){
	if (*raiz == NULL){
		*raiz = criaNo(vl);
		printf("Inserido\n");
	}else{

		if(vl < (*raiz)->n){
			printf("Esquerda >> ");
			insereNo(&((*raiz)->esq), vl);
		}else{
			if(vl > (*raiz)->n){
				printf("Direita  >> ");
				insereNo(&((*raiz)->dir), vl);
			}else{
				printf ("Valor_Repetido\n");
			}
		}

	}
}


int buscaNo(NoArvPtr raiz, int vl){
	if (raiz == NULL){
		return 0;
	}else{

		if(vl < raiz->n){
			printf("Esquerda >> ");
			buscaNo(raiz->esq, vl);
		}else{
			if(vl > raiz->n){
				printf("Direita  >> ");
				buscaNo(raiz->dir, vl);
			}else{
				return 1;
			}
		}

	}
}
