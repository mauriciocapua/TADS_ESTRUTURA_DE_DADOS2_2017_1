//Biblioteca da Aula 3 Arvore Binária
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib.h"




void main()
{

    int i,h=0, item, valor;
    NoArvPtr arv1 = NULL;

    printf("Os números inseridos na árvore são: \n ");

    insereNo(&arv1,70);
    printf(" %2d  \n ",70);
    insereNo(&arv1,50);
    printf(" %2d  \n ",50);
    insereNo(&arv1,40);
    printf(" %2d  \n ",40);
    insereNo(&arv1,55);
    printf(" %2d  \n ",55);
    insereNo(&arv1,90);
    printf(" %2d  \n ",90);
    insereNo(&arv1,80);
    printf(" %2d  \n ",80);
    insereNo(&arv1,95);
    printf(" %2d  \n ",95);
    insereNo(&arv1,100);
    printf(" %2d  \n ",100);
    insereNo(&arv1,30);
    printf(" %2d  \n ",30);
    insereNo(&arv1,101);
    printf(" %2d  \n ",101);
    insereNo(&arv1,102);
    printf(" %2d  \n ",102);
    insereNo(&arv1,103);
    printf(" %2d  \n ",103);



    printf("\n\nMostra Arvore em nivel \n");    
    mostraEmNivel(arv1, 0);
 
    do
    {

        printf("\nInforme um valor para remocao: -1 para sair \n");
        scanf("%d",&valor);
        if(buscaNo(arv1,valor)==1)
        {
            if(excluirNo(&arv1,valor)==1)
            {
                printf("\n Removido - < valor %d >\n",valor);
                printf("\nMostra Arvore em In - Ordem = Apos Exclusao\n ");
                mostraEmNivel(arv1, 0);
                printf("--------------------------------------------------\n");
            }
            else
            {
                printf(" Nao pode ser excluido %d\n",valor);
            }
        }
        else
        {
            printf(" Valor - %d - nao presente na arvore \n",valor);
        }
    }
    while(valor!=-1);
}
