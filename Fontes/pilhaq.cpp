#include "pilhaq.h"
#include <stdio.h>
#include <stdlib.h>

/*Funções auxiliares, tanto para a função do Quicksort, que necessita de uma pilha que não a do sistema, devido
 *ao grande número de recursões a serem chamadas para os 100.000 elementos.
 *Também está aqui a função para inserir em uma lista encadeada ordenada, usada na função do Bucketsort, visto que
 *seus 'buckets' são organizados através destas listas.
 **/

//Função que insere um elemento no topo de uma pilha e retorna o "novo topo"
pilhaq* insere_pilha(pilhaq *p, int a, int b){
    pilhaq *paux;

    paux=(pilhaq*)malloc(sizeof(pilhaq));
    paux->ini=a;
    paux->fim=b;

    if(p==NULL){
            p=paux;
            p->baixo=NULL;
    }
    else{
            paux->baixo=p;
            p=paux;
    }


    return p;
}

//Função que retira um item do topo da pilha e retorna o "novo topo"
pilhaq* desempilha(pilhaq *p, int *a, int *b){
    pilhaq *paux;

    if(p==NULL) return NULL;

    *a=p->ini;
    *b=p->fim;

    paux=p->baixo;

    free(p);
    return paux;
}


//Função que insere um elemento em uma lista, mantendo a ordenação prévia dela (crescente)
lista *inserir_lista_ordenada(int c, lista *list){
    lista *aux=list, *aux2;

    if(list==NULL){
        list=(lista*)malloc(sizeof(lista));
        list->chave=c;
        list->ant=NULL;
        list->prox=NULL;
        return list;
    }
    else{
        while(aux!=NULL){
            if(aux->chave >= c){
                aux2=(lista*)malloc(sizeof(lista));
                aux2->chave=c;
                aux2->ant=aux->ant;
                aux2->prox=aux;
                aux->ant=aux2;
                if(aux2->ant!=NULL){
                    aux2->ant->prox=aux2;
                    return list;
                }
                return aux2;
            }
            else{
                aux2=aux;
                aux=aux->prox;

            }
        }
        aux=(lista*)malloc(sizeof(lista));
        aux->chave=c;
        aux->ant=aux2;
        aux->prox=NULL;
        aux2->prox=aux;
        return list;
    }
}
