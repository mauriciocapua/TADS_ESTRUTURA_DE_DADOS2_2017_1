#include <stdio.h>
#include <stdlib.h>

struct noArvore
{
    int n;
    struct noArvore *esq;
    struct noArvore *dir;
};

typedef struct noArvore NoArv;

NoArv* criaNo(int v)
{
    NoArv* noaux = (NoArv*) malloc (sizeof(NoArv));

    noaux->n = v;
    noaux->esq = NULL;
    noaux->dir = NULL;
    return noaux;
}

void inserirEsq(NoArv *arv, NoArv *filho)
{
    NoArv *tmp;
    if (arv != NULL)
    {
        tmp = arv;
        while (tmp->esq != NULL)
        {
            tmp = tmp->esq;
        }
        tmp->esq = filho;
    }
    else
    {
        printf("Erro arvore vazias\n");
    }

}

void inserirDir(NoArv *arv, NoArv *filho)
{
    NoArv *tmp;
    if (arv != NULL)
    {
        tmp = arv;
        while (tmp->dir != NULL)
        {
            tmp = tmp->dir;
        }
        tmp->dir = filho;
    }
    else
    {
        printf("Erro arvore vazias\n");
    }

}

void mostraNo(NoArv* no)
{
    printf("Numero = %d\n",no->n);
}

void mostraNosEsq(NoArv* arv)
{
    NoArv *tmp;
    if (arv != NULL)
    {
        tmp = arv;
        while (tmp->esq != NULL)
        {
            mostraNo(tmp);
            tmp = tmp->esq;
        }
        mostraNo(tmp);
    }
    else
    {
        printf("Erro arvore vazias\n");
    }
}

void mostraNosDir(NoArv* arv)
{
    NoArv *tmp;
    if (arv != NULL)
    {
        tmp = arv;
        while (tmp->dir != NULL)
        {
            mostraNo(tmp);
            tmp = tmp->dir;
        }
        mostraNo(tmp);
    }
    else
    {
        printf("Erro arvore vazias\n");
    }
}

void preOrdem(NoArv* arv)
{
    if(arv!=NULL)
    {
        printf("%d \n", arv->n);
        preOrdem(arv->esq);
        preOrdem(arv->dir);
    }
}

void inOrdem(NoArv* arv)
{
    if(arv!=NULL)
    {
        inOrdem(arv->esq);
        printf("%d \n", arv->n);
        inOrdem(arv->dir);
    }
}

void posOrdem(NoArv* arv)
{
    if(arv!=NULL)
    {
        posOrdem(arv->esq);
        posOrdem(arv->dir);
        printf("%d \n", arv->n);
    }
}

void removeFolhaspreordem(NoArv* arv)
{
    NoArv *tmp;

    if(arv!=NULL)
    {
        printf("%d \n", arv->n);

        tmp = arv->esq;
        if(arv->esq!=NULL)
        {
            if(tmp->esq==NULL && tmp->dir==NULL)
            {
                arv->esq=NULL;
            }
        }
        if(arv->dir!=NULL)
        {
            tmp = arv->dir;
            if(tmp->esq==NULL && tmp->dir==NULL)
            {
                arv->dir=NULL;

            }
        }
        removeFolhaspreordem(arv->esq);
        removeFolhaspreordem(arv->dir);


    }
}

