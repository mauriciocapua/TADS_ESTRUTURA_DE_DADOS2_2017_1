//Biblioteca da Aula 3 Arvore Binária
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib_arvBin_env.h"

void main()
{

    int i, item, valor;
    NoArvPtr arv1 = NULL;

    srand(time(NULL));
    printf("Os números inseridos na árvore são: \n ");

    /*for (i=0; i<10; i++){
    	item = rand()%15;
    	printf(" %2d >> ",item);
    	insereNo(&arv1,item);
    }*/
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


    //printf("\n\nMostra Arvore em Pré - Ordem \n");
    // mostraPreOrdem(arv1);

    printf("\n\nMostra Arvore em In - Ordem \n");
    mostraInOrdem(arv1);

//	 printf("\n\nMostra Arvore em Pós - Ordem \n");
//	 mostraPosOrdem(arv1);
//	 printf("\n\n");

    printf("\nInforme um valor para busca:");
    scanf("%d",&valor);

    if(buscaNo(arv1, valor))
    {
        printf(" Encontrado < valor %d >",valor);
        if(excluirNo(&arv1,valor))
        {
            printf("\n Removido - < valor %d >\n",valor);
            printf("\nMostra Arvore em In - Ordem = Após Exclusão\n ");
            mostraInOrdem(arv1);
            printf("\n");

        }
        else
        {
            printf(" Nao pode ser excluido %d\n",valor);

        }
    }
    else
    {
        printf(" Não Encontrado < valor %d >\n",valor);
        printf("\nMostra Arvore em In - Ordem = Após Exclusão\n ");
        mostraInOrdem(arv1);
        printf("\n");
    }
}
