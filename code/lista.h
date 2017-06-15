#ifndef LISTA_H
#define LISTA_H


/*Assinaturas das funções de manipulação da lista*/
#include "arvore.h"

/*---------------------------------------------------------------------------------------------------------*/
/*struct para nodo da lista*/
typedef struct nodo{
    Tree  *personagem;
    struct nodo* prox;
    struct nodo *ant;
}Nodo;

/*struct para tipo lista*/
typedef struct lista{
    Nodo* cabeca;
}Lista;


Lista* cria_lista();          /*funcao que cria a lista vazia*/
int vazia_lista(nodo* n);     /*funcao que verifica se a lista está vazia*/
void insere_lista(Lista* l, int posicao, Tree* personagem);     /*funcao que insere um novo nodo na lista*/
void remove_lista(Lista *l, int posicao);                       /*funcao que remove um nodo da lista*/
void free_lista(Lista *l);          /*funcao que libera a memoria alocada pela lista*/


#endif
