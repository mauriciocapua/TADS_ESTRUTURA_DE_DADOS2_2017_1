#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct Letra
{
    char caracter;
    struct Letra *anterior;
    struct Letra *proximo;
} letra;

letra* cria_letra()
{
    letra *p_letra = (letra *) malloc (sizeof(letra));
    char tmp;
    printf("Informe o nome da letra:");
    scanf("%c",&p_letra->caracter);
    p_letra->caracter = tmp;
    p_letra->anterior = NULL;
    p_letra->proximo = NULL;

    return p_letra;
}

typedef struct ListaDE
{
    struct Letra *primeiro;
    struct Letra *ultimo;
    int qtd;
} lista;

void cria_listaDE(lista *p_lista)
{
    p_lista->primeiro = NULL;
    p_lista->ultimo = NULL;
    p_lista->qtd = 0;
}

letra* retorna_str(char carac)
{
    letra *tmp = (letra *) malloc (sizeof(letra));
    tmp->caracter = carac;
    tmp->anterior = NULL;
    tmp->proximo = NULL;

    return tmp;
}


lista* converter_lista(lista *p_lista, char *str)
{
    int i;
    for(i = 0; i < strlen(str); i++)
    {
        insere_letra_fim(p_lista,retorna_str(str[i]));
    }
    return p_lista;
}

char* converte_str(lista *p_lista)
{
    char *str = malloc(100);
    int qtd = p_lista->qtd;
    letra *tmp = p_lista->primeiro;
    int i;
    for( i= 0; i < qtd; i++)
    {
        str[i] = tmp->caracter;
        tmp = tmp->proximo;

    }
    return str;
}


void insere_letra_fim(lista *p_lista, letra *p_letra)
{
    if(p_lista->primeiro == NULL)
    {
        p_lista->primeiro = p_letra;
    }
    else
    {
        p_lista->ultimo->proximo = p_letra;
    }
    p_letra->anterior = p_lista->ultimo;
    p_letra->proximo = NULL;
    p_lista->ultimo = p_letra;

    p_lista->qtd++;
    printf ("inserido com sucesso \n") ;
}

void insere_letra_inicio(lista *p_lista, letra *p_letra)
{
    if(p_lista->primeiro == NULL)
    {
        p_lista->ultimo = p_letra;
    }
    else
    {
        p_letra->anterior = NULL;
        p_letra->proximo = p_lista->primeiro;
        p_lista->primeiro->anterior = p_letra;

    }
    p_lista->primeiro = p_letra;
    p_lista->qtd++;
    printf ("inserido com sucesso \n") ;
}

int insere_letra_posicao(lista *p_lista, letra *p_letra, int posicao)
{
    if (p_lista->qtd < posicao)
    {
        return 0;
    }
    else if (posicao == 0)
    {
        insere_letra_inicio(p_lista,p_letra);
        return 1;
    }
    else if (p_lista->qtd == posicao)
    {
        insere_letra_fim(p_lista,p_letra);
        return 1;
    }
    letra *tmp = p_lista->primeiro;
    posicao--;

    while (posicao > 0)
    {
        tmp = tmp->proximo;
        posicao--;
    };
    p_letra->anterior = tmp;
    p_letra->proximo = tmp->proximo;
    tmp->proximo = p_letra;
    p_lista->qtd++;
    return 1;
}




void mostra_lista(lista *p_lista)
{
    if (p_lista->primeiro == NULL)
        printf("Lista Vazia");
    else
    {
        letra *tmp = p_lista->primeiro;
        int i;
        for(i=1; i<=p_lista->qtd; i++)
        {
            printf("\nletra: %c", tmp->caracter);
            //putchar(tmp->caracter);
            tmp=tmp->proximo;
        }
        printf("\n");
    }
}

void mostra_lista_invertida(lista *p_lista)
{
    if (p_lista->primeiro == NULL)
        printf("Lista Vazia");
    else
    {
        letra *tmp = p_lista->ultimo;
        while(tmp != NULL)
        {
            printf("\nletra: %c",tmp->caracter);
            tmp=tmp->anterior;
        }
        printf("\n");
    }
}

void remove_fim(lista *p_lista)
{
    letra *tmp;
    tmp = p_lista->ultimo;

    if(p_lista->qtd == 0)
    {
        printf("Lista Vazia");

    }
    else if (p_lista->qtd == 1)
    {
        tmp->proximo = NULL;
        p_lista->primeiro = NULL;
        p_lista->ultimo = NULL;
        p_lista->qtd = 0;
        return tmp;
    }

    p_lista->ultimo = p_lista->ultimo->anterior;
    p_lista->ultimo->anterior->proximo = NULL;
    tmp->anterior == NULL;
    p_lista->qtd--;

}


void remove_inicio(lista *p_lista)
{
    if (p_lista->qtd == 0)
    {
        printf("lista vazia");
    }
    letra *tmp = p_lista->primeiro;
    p_lista->primeiro = tmp->proximo;
    p_lista->primeiro->anterior = NULL;

    if (p_lista->ultimo == tmp)
    {
        p_lista->primeiro = NULL;
        p_lista->ultimo = NULL;
    }

    tmp->proximo = NULL;
    p_lista->qtd--;

    return tmp;
}

void remove_posicao(lista *p_lista)
{
    int i;
    letra *tmp;

    if(p_lista->qtd == 0 && p_lista->primeiro == NULL )
    {
        printf("Lista Vazia");
    }
    else
    {
        int pos = retorna_posicao(p_lista);
        //int pos=1;
        printf("%d", pos);
        if(pos == 1)  /* remoção do 1° elemento */
        {
            remove_inicio(p_lista);
        }
        else if(pos == p_lista->qtd-1)   /* remoção do último elemento */
        {
            remove_fim(p_lista);
        }
        else if (pos==-1 || pos>p_lista->qtd)    /* remoção em outro lugar */
        {
            printf("não encontrado");
        }
        else
        {
            tmp = p_lista->primeiro;
            for(i=1; i<=pos; ++i)
            {
                tmp = tmp->proximo;
            }
            tmp->proximo == tmp->proximo->proximo;
            tmp->proximo->anterior == tmp;
            p_lista->qtd--;
        }
    }
//   else
//    {

//        if(pos==-1)
//        {
//            printf("valor não encontrado");
//        }


}

void remove_posicao2(lista *p_lista, int pos)
{
    int i;
    letra *tmp;

    if(p_lista->qtd == 0 && p_lista->primeiro == NULL )
    {
        printf("Lista Vazia");
    }
    else
    {

        if(pos == 1)  /* remoção do 1° elemento */
        {
            remove_inicio(p_lista);
        }
        else if(pos == p_lista->qtd-1)   /* remoção do último elemento */
        {
            remove_fim(p_lista);
        }
        else if (pos==-1 || pos>p_lista->qtd)    /* remoção em outro lugar */
        {
            printf("não encontrado");
        }
        else
        {
            tmp = p_lista->primeiro;
            for(i=1; i<=pos; ++i)
            {
                tmp = tmp->proximo;
            }
            tmp->proximo == tmp->proximo->proximo;
            tmp->proximo->anterior == tmp;
            p_lista->qtd--;
        }
    }


}

int retorna_posicao(lista *p_lista)
{
    char letraa[100];
    int contador = 1;
    printf("Informe o nome da letra a ser deletada:");
    scanf("%c",&letraa);

    letra *tmp = p_lista->primeiro;

    while ( tmp!=NULL )
    {

        if ( tmp->caracter == letraa)
        {
            return contador;
            break;
        }
        else
        {
            tmp = tmp->proximo;
            contador++;
        }

    }

    return contador;
}

lista *strconcat(lista *p_lista1, lista *p_lista2)
{
    lista *lista3 = (lista * ) malloc (sizeof(lista));
    cria_listaDE(lista3);
    letra *primeiraletra = NULL;
    letra *tmp = p_lista1->primeiro;
    if (tmp != NULL)
    {
        primeiraletra = retorna_str(tmp->caracter);
        insere_letra_fim(lista3,primeiraletra);
        int i;
        for(i = 1; i < p_lista1->qtd; i++)
        {
            insere_letra_fim(lista3,retorna_str(tmp->proximo->caracter));
            tmp = tmp->proximo;
        }
    }

    tmp = p_lista2->primeiro;

    if (tmp != NULL)
    {
        primeiraletra = retorna_str(tmp->caracter);
        insere_letra_fim(lista3,primeiraletra);
        int i;
        for( i = 1; i < p_lista2->qtd; i++)
        {
            insere_letra_fim(lista3,retorna_str(tmp->proximo->caracter));
            tmp = tmp->proximo;
        }
    }
    return lista3;
}

void strcmpl(lista *p_lista1, lista *p_lista2)
{
    char *str1 = converte_str(p_lista1);
    char *str2 = converte_str(p_lista2);
    int i = strcmp(str1, str2);
    if(i==-1)
    {
        printf("String de caracteres representada por l1 eh menor que a String representada por l2\n");
    }
    else if(i==0)
    {
        printf("l1 e l2 sao iguais\n");
    }
    else if(i==1)
    {
        printf("String representada por l1 eh maior que l2\n");
    }
}

int seVogal (letra *letra)
{
    if (letra->caracter == 'a' || letra->caracter == 'e' || letra->caracter == 'i' || letra->caracter == 'o' || letra->caracter == 'u'
            || letra->caracter == 'A' || letra->caracter == 'E' || letra->caracter == 'I' || letra->caracter == 'O' || letra->caracter == 'U')
    {
        return 1;
    }
    return 0;

}

lista *removeVogais (lista *p_lista)
{

    lista *l_vogais = (lista * ) malloc (sizeof(lista));
    cria_listaDE(l_vogais);
    l_vogais = p_lista;
    letra *tmp = l_vogais->primeiro;
    int i;
    for(i = 0; i < l_vogais->qtd; i++)
    {
        if(seVogal(tmp) == 0)
        {
            if (i == 0)
            {
                tmp = tmp->proximo;
            }
            remove_posicao2(l_vogais,i);
            i--;
        }
        if (i >= 0)
        {
            tmp = tmp->proximo;
        }
    }
    mostra_lista(l_vogais);
}




#endif // LIB_H_INCLUDED
