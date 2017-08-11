//Biblioteca da Aula 3 Arvore Binária
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct noArvore
{
    int n;
    struct noArvore *esq;
    struct noArvore *dir;
};

typedef struct noArvore NoArv;
typedef NoArv* NoArvPtr;

NoArvPtr criaNo(int v);
void mostraNo(NoArvPtr);
void mostraPreOrdem(NoArvPtr);
void mostraInOrdem(NoArvPtr);
void mostraPosOrdem(NoArvPtr);
void insereNo(NoArvPtr *, int);
int excluirNo(NoArvPtr *, int);
//void sucessor(NoArvPtr *, NoArvPtr *);
//void anterior(NoArvPtr *, NoArvPtr *);


NoArvPtr criaNo(int v)
{
    NoArv* noaux = (NoArv*) malloc (sizeof(NoArv));
    if(noaux != NULL)
    {
        noaux->n = v;
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

void mostraNo(NoArvPtr no)
{
    if(no == NULL)
        printf( " NULL");
    else
        printf(" %d -",no->n);
}

void mostraPreOrdem(NoArvPtr raiz)
{

    if(raiz != NULL)
    {
        mostraNo(raiz);
        mostraPreOrdem(raiz->esq);
        mostraPreOrdem(raiz->dir);
    }
}

void mostraInOrdem(NoArvPtr raiz)
{
    if(raiz != NULL)
    {
        mostraInOrdem(raiz->esq);
        mostraNo(raiz);
        mostraInOrdem(raiz->dir);
    }
}

void mostraPosOrdem(NoArvPtr raiz)
{
    if(raiz != NULL)
    {
        mostraPosOrdem(raiz->esq);
        mostraPosOrdem(raiz->dir);
        mostraNo(raiz);
    }
}

void insereNo(NoArvPtr *raiz, int vl)
{
    if (*raiz == NULL)
    {
        *raiz = criaNo(vl);
        printf("Inserido ");
    }
    else
    {

        if(vl < (*raiz)->n)
        {
            //printf("Esquerda >> ");
            insereNo(&((*raiz)->esq), vl);
        }
        else
        {
            if(vl > (*raiz)->n)
            {
                //printf("Direita  >> ");
                insereNo(&((*raiz)->dir), vl);
            }
            else
            {
                printf ("Repetido\n");

            }
        }

    }
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


NoArv *sucessor(NoArv **no)
{
    if((*no)->dir != NULL)
        return sucessor(&(*no)->dir);
    else
    {
        NoArv *aux = *no;
        if((*no)->esq != NULL)
            *no = (*no)->esq;
        else
            *no = NULL;
        return aux;
    }
}

NoArv *anterior(NoArv **no)
{
    if((*no)->esq != NULL)
        return anterior(&(*no)->esq);
    else
    {
        NoArv *aux = *no;
        if((*no)->dir != NULL)
            *no = (*no)->dir;
        else
            *no = NULL;
        return aux;
    }
}

int excluirNo(NoArv **r2, int n)
{
    if(*r2 == NULL)
    {
        printf("n nao existe");
        return;
    }
    if(n < (*r2)->n)
        excluirNo(&(*r2)->esq, n);
    else if(n > (*r2)->n)
        excluirNo(&(*r2)->dir, n);
    else
    {
        NoArv *pAux = *r2;
        if (((*r2)->esq == NULL) && ((*r2)->dir == NULL))
        {
            (*r2) = NULL;
        }
        else
        {
            if ((*r2)->esq == NULL)
            {
                (*r2) = (*r2)->dir;
                pAux->dir = NULL;
                pAux = NULL;
            }
            else
            {
                if ((*r2)->dir == NULL)
                {
                    (*r2) = (*r2)->esq;
                    pAux->esq = NULL;
                    pAux = NULL;
                }
                else
                {
                    pAux = sucessor(&(*r2)->esq);
                    pAux->esq = (*r2)->esq;
                    pAux->dir = (*r2)->dir;
                    (*r2)->esq = (*r2)->dir = NULL;
                    *r2 = pAux;
                    pAux = NULL;
                }
            }
        }
    }
}


