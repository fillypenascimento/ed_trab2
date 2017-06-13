#include "lista.h"
#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

Lista* cria_lista(){

    Lista *l;

    l = (Lista *) malloc(sizeof(Lista));
    l->cabeca = (Nodo *) malloc(sizeof(Nodo));
    l->cabeca->personagem = (Tree *) malloc(sizeof(Tree));
    l->cabeca->prox = NULL;
    l->cabeca->ant = NULL;

    return l;
}

int vazia_lista(Lista* l){

    return(l->cabeca == NULL);

}

void insere_lista(Lista* l, int posicao, Tree* personagem){

    if(vazia_lista(l)){
      Nodo* insere = (Nodo*) malloc(sizeof(Nodo));
      insere->personagem = personagem;
      insere->ant=NULL;
      insere->prox=NULL;
      l->cabeca = insere;
      printf("\n Inseri na cabeça da lista.\n");
      return;
    }


    if(posicao==0){
      Nodo* insere = (Nodo*) malloc(sizeof(Nodo));
      insere->personagem = personagem;
      insere->ant=NULL;
      insere->prox=l->cabeca;
      l->cabeca->ant = insere;
      l->cabeca = insere;
      return;
    }

    Nodo* insere = (Nodo*) malloc(sizeof(Nodo));
    insere->personagem = personagem;
    insere->ant=NULL;
    insere->prox=NULL;
    Nodo* atual = l->cabeca;
    int i=0;

    for(i=0;i<posicao-1;i++){
        if(atual==NULL){
            return;
        }
        else{
            atual=atual->prox;
        }
    }

    if(atual->prox==NULL){
        atual->prox = insere;
        insere->ant = atual;
    }
    else{
        insere->prox=atual->prox;
        atual->prox->ant=insere;
        insere->ant=atual;
        atual->prox=insere;
    }
    printf("\n\n Inseri em outra posição da lista.\n");

}
void remove_lista(Lista* l, int posicao){

    Nodo *l2 = l->cabeca;

    if(vazia_lista(l))
        return;

    for(int i=0; i < posicao; ++i)
    {
        if(l2 == NULL)
            return;
        l2 = l2->prox;
    }

    if(l2->prox == NULL && l2->ant == NULL)
        l->cabeca = NULL;
    else if(l2->prox == NULL)
        l2->ant->prox = NULL;
    else if(l2->ant == NULL)
    {
        l2->prox->ant = NULL;
        l->cabeca = l2->prox;
    }
    else
    {
        l2->ant->prox = l2->prox;
        l2->prox->ant = l2->ant;
    }
    free(l2);
    l2 = NULL;
}


void free_lista(Lista *l){

    Nodo* aux = l->cabeca;

    while(aux != NULL)
    {
        remove_lista(l,0);
        aux = l->cabeca;
    }
}
