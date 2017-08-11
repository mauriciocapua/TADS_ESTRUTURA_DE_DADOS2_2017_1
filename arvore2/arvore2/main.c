#include lib.h

void main(){

	 int i, item, valor;
	 NoArvPtr arv1 = NULL;

	 srand(time(NULL));
	 printf("Os números inseridos na árvore são: \n");

	 for (i=0; i<10; i++){
	 	item = rand()%15;
	 	printf(" %2d >> ",item);
	 	insereNo(&arv1,item);
	 }
	 printf("\n\nMostra Arvore em Pré - Ordem \n");
	 mostraPreOrdem(arv1);

 	 printf("\n\nMostra Arvore em In - Ordem \n");
	 mostraInOrdem(arv1);

 	 printf("\n\nMostra Arvore em Pós - Ordem \n");
	 mostraPosOrdem(arv1);
	 printf("\n\n");

	 printf("Informe um valor para busca:");
	 scanf("%d",&valor);

	 if(buscaNo(arv1, valor))
	 	printf(" Encontrado < valor %d >:\n",valor);
	 else
	 	printf(" Não Encontrado < valor %d >:\n",valor);
}
