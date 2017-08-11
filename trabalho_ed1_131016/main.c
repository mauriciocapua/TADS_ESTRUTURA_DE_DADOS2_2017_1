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

    converter_lista(lista1, str1);
    converter_lista(lista2, str2);

    printf("\n");

    int opcao = -1;
    while (opcao != 0)
    {
        //system("clear");
        printf("1-Funcoes Strings\n2-Funcoes Listas\n0-sair\nInforme o numero da opção desejada: ");
        scanf("%u", &opcao);

        switch (opcao)
        {
        case 1:
            //system("clear");
            do
            {
                printf("\n1-Converter String para lista\n2Retornar lista para String-\n3-Comparar listas\n4-Concatena duas listas\n5-Remover vogais\n9-voltar\nInforme o numero da opção desejada: ");
                scanf("%u", &opcao);

                switch (opcao)
                {
                case 1:
                    converter_lista(lista1, str1);
                    mostra_lista(lista1);
                    break;
                case 2:
                    strcpy(tmp, converte_str(lista1));
                    printf("%s",tmp);
                    break;
                case 3:
                    strcmpl(lista1,lista2);
                    break;
                case 4:
                    mostra_lista(strconcat(lista1,lista2));
                    break;
                }
                case 5:
                removeVogais(lista1);
                    break;
                printf("\n");
            }
            while (opcao != 9);
            break;
        case 2:
            // system("clear");
            do
            {
                printf("1-Insere no inicio\n2-Insere no fim\n3-Mostra Lista\n4-Mostra Lista Invertida\n5-Remover por nome\n6-Remover no inicio\n7-Remover no fim\n0-sair\nInforme o numero da opcao desejada: ");
                scanf("%u", &opcao);

                switch (opcao)
                {
                case 1:
                    insere_letra_inicio(lista1,cria_letra());
                    break;
                case 2:
                    insere_letra_fim(lista1,cria_letra());
                    break;
                case 3:
                    printf("lista1: ");
                    mostra_lista(lista1);
                    printf("\nlista2: ");
                    mostra_lista(lista2);
                    break;
                case 4:
                    mostra_lista_invertida(lista1);
                    break;
                case 5:
                    remove_posicao(lista1);
                    break;
                case 6:
                    remove_inicio(lista1);
                    break;
                case 7:
                    remove_fim(lista1);
                    break;
                }
                printf("\n");
            }
            while (opcao != 9);
            break;

        }


    }

    return (EXIT_SUCCESS);
}
