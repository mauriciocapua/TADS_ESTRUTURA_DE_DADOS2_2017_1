#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv)
{

    lista *lista1 = (lista * ) malloc (sizeof(lista));  //aloca a lista
    lista *lista2 = (lista * ) malloc (sizeof(lista));

    lista *lista_strings = (lista * ) malloc (sizeof(lista));
    cria_listaDE(lista1);   //inicia a lista vazia
    cria_listaDE(lista2);

    printf("Criada a lista\n");

    char str1[] = "bla";
    char str2[] = "haha";
    char tmp[] = "";

    converter_lista(lista1, str1, 0);
    printf("\n");
    converter_lista(lista2, str2,0);

    printf("\n");

    int opcao = -1;

    do
    {
        printf("\n1-Converter String para lista\n2-Retornar lista para String\n3-Comparar listas\n4-Concatena duas listas\n5-Remover vogais\n9-voltar\nInforme o numero da opção desejada: ");
        scanf("%u", &opcao);

        switch (opcao)
        {
        case 1:
            converter_lista(lista1, str1, 0);
            mostra_lista(lista1);
            break;
        case 2:
            strcpy(tmp, converte_str(lista1));
            printf("%s \n",tmp);
            break;
        case 3:
            strcmpl(lista1,lista2);
            break;
        case 4:
            mostra_lista(strconcat(lista1,lista2));
            break;

        case 5:
            removeVogais(lista1);
            break;
            printf("\n");
        }
    }
    while (opcao != 9);

    return (EXIT_SUCCESS);
}
