	//Biblioteca da Aula 3 Arvore Binária
	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	#include <stdbool.h>

	#define max(A,B) ((A>B) ? (A):(B))

struct noArvore
{
	int n;
	int fatbal;
	struct noArvore *esq;
	struct noArvore *dir;

};

typedef struct noArvore NoArv;
typedef NoArv* NoArvPtr;

NoArvPtr criaNo(int);
void mostraNo(NoArvPtr);
void mostraPreOrdem(NoArvPtr);
void mostraInOrdem(NoArvPtr);
void mostraPosOrdem(NoArvPtr);
void insereNo(NoArvPtr *, int);
int excluirNo(NoArvPtr *, int);
void sucessor(NoArvPtr *, NoArvPtr *);
void anterior(NoArvPtr *, NoArvPtr *);
void mostraEmNivel(NoArvPtr,int);
int calculaFatorBalanceamento(NoArvPtr);
void rotacaoSimplesDireita(NoArvPtr *);
void rotacaoDuplaEsquerda(NoArvPtr *);
void rotacaoDuplaDireita(NoArvPtr *);



NoArvPtr criaNo(int v)
{
	NoArv* noaux = (NoArv*) malloc (sizeof(NoArv));
	if(noaux != NULL)
	{
		noaux->n = v;
		noaux->fatbal = 0;
		noaux->esq = NULL;
		noaux->dir = NULL;
		return noaux;
	}
	else
	{
		printf("ERRO - Problema na Alocação!!");
		return NULL;
	}
}

int noFatBal(NoArvPtr no){
	if(no ==NULL)
		return 0;
	else
		return no->fatbal;
}

void rotacaoSimplesEsquerda(NoArvPtr *raiz){
	NoArvPtr temp =(*raiz)->dir;
	(*raiz)->dir = temp->esq;
	temp->esq = (*raiz);
	(*raiz) = temp;
}

void rotacaoSimplesDireita(NoArvPtr *raiz){
	NoArvPtr temp =(*raiz)->esq;
	(*raiz)->esq = temp->dir;
	temp->dir = (*raiz);
	(*raiz) = temp;
}

void rotacaoDuplaEsquerda(NoArvPtr *raiz){
	rotacaoSimplesDireita(&(*raiz)->dir);
	rotacaoSimplesEsquerda(raiz);
}

void rotacaoDuplaDireita(NoArvPtr *raiz){
	rotacaoSimplesEsquerda(&(*raiz)->esq);
	rotacaoSimplesDireita(raiz);
}

int buscaNo(NoArvPtr raiz, int vl)
{
	if (raiz == NULL)
	{
		return 0;
	}
	else
	{

		if(vl < raiz->n)
		{
	            //printf("Esquerda >> ");
			buscaNo(raiz->esq, vl);
		}
		else
		{
			if(vl > raiz->n)
			{
	                //printf("Direita  >> ");
				buscaNo(raiz->dir, vl);
			}
			else
			{
				return 1;
			}
		}

	}
}


void sucessor(NoArvPtr *aux, NoArvPtr *aux2)
{
	if((*aux2)->dir != NULL)
	{
		sucessor(aux, &((*aux2)->dir));
	}
	else
	{
		(*aux)->n = (*aux2)->n;
		(*aux) = (*aux2);
		(*aux2) = (*aux2)->esq;
	}
}

void anterior(NoArvPtr *aux, NoArvPtr *aux2)
{
	if((*aux2)->esq != NULL)
	{
		anterior(aux, &((*aux2)->esq));
	}
	else
	{
		(*aux)->n = (*aux2)->n;
		(*aux) = (*aux2);
		(*aux2) = (*aux2)->dir;
	}
}

void mostraNo(NoArvPtr no)
{
	if(no == NULL)
		printf( " NULL");
	else
		printf("valor = %d e fatbal = %d \n",no->n,no->fatbal);
}

void mostraEmNivel(NoArvPtr raiz, int h){
	if(raiz != NULL){
		printf ("Arvore Nivel %d = ",h);
		mostraNo(raiz);
		h++;
		mostraEmNivel(raiz->esq, h);
		mostraEmNivel(raiz->dir, h);
	}
}

int calculaFatorBalanceamento(NoArvPtr raiz)
{
	int fatEsq, fatDir;
	if (raiz == NULL) {
		return 0;
	} else {
		fatEsq = calculaFatorBalanceamento(raiz->esq);
		fatDir = calculaFatorBalanceamento(raiz->dir);
		raiz->fatbal = fatDir - fatEsq;
		if (fatEsq > fatDir) {
			return fatEsq + 1;
		} else {
			return fatDir + 1;
		}
	}
}

int balancear(NoArvPtr *raiz){
	if(*raiz == NULL) {
		return 0;
	}
	if (noFatBal(*raiz) == -2){
		if (noFatBal((*raiz)->esq) < 1){
			rotacaoSimplesDireita(raiz);
		} else {
			rotacaoDuplaEsquerda(raiz);
		}
		calculaFatorBalanceamento(*raiz);
		balancear(&(*raiz));
		return 2;
	} else if (noFatBal(*raiz) == 2) {
		if (noFatBal((*raiz)->dir) > -1){
			rotacaoSimplesEsquerda(raiz);
		} else {
			rotacaoDuplaDireita(raiz);
		}
		calculaFatorBalanceamento(*raiz);
		balancear(&(*raiz));
		return 2;
	} else if (noFatBal((*raiz)->esq) < -1 || noFatBal((*raiz)->esq) > 1){
		balancear(&(*raiz)->esq);
	} else if (noFatBal((*raiz)->dir) < -1 || noFatBal((*raiz)->dir) > 1){
		balancear(&(*raiz)->dir);
	} else {
		return 1;
	}

	calculaFatorBalanceamento(*raiz);
	balancear(&(*raiz));
	return 2;
}

void insereNo(NoArvPtr *raiz, int vl){  
	if (*raiz == NULL){
		*raiz = criaNo(vl);
		printf("Inserido ");
	}else{

		if(vl < (*raiz)->n){
	            //printf("Esquerda >> ");
			insereNo(&((*raiz)->esq), vl);
		}else{
			if(vl > (*raiz)->n){
	                //printf("Direita  >> ");
				insereNo(&((*raiz)->dir), vl);
			}else{
				printf ("Repetido\n");

			}
		}

	}

	calculaFatorBalanceamento(*raiz);
	balancear(&(*raiz));
}



int excluirNo(NoArvPtr *raiz, int vl){
	if (raiz == NULL){
		return 0;
	} else if (vl < (*raiz)->n){
		excluirNo(&(*raiz)->esq,vl);
	} else if (vl > (*raiz)->n){
		excluirNo(&(*raiz)->dir,vl);
	} else {
		NoArvPtr aux = *raiz;
		if (aux->dir == NULL){
			*raiz = aux->esq;
		} else if (aux->esq == NULL){
			*raiz = aux->dir;
		} else {
	            //sucessor(&aux, &aux->esq);
			anterior(&aux, &aux->dir);
		}
	}
	calculaFatorBalanceamento(*raiz);
	balancear(&(*raiz));
	return 1;
}