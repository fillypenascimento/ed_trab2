#include "lista.h"
#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

/*funcao que cria a lista vazia e retorna o ponteiro dela*/
Lista* cria_lista(){

    Lista *l;

    l = (Lista *) malloc(sizeof(Lista));
    l->cabeca = NULL;

    return l;
}
/*---------------------------------------------------------------------------------------------------------*/
/*funcao que verifica se a lista está vazia*/
int vazia_lista(Nodo* n){
  return(n == NULL);
}
/*---------------------------------------------------------------------------------------------------------*/
/*funcao que insere um personagem na lista*/
void insere_lista(Lista* l, int posicao, Tree* personagem){

    Nodo* insere = (Nodo*) malloc(sizeof(Nodo));      /*aloca um novo nodo na lista para armazenar o personagem*/
    insere->personagem = personagem;
    insere->ant=NULL;
    insere->prox=NULL;
    Nodo* atual = l->cabeca;
    Nodo *aux;

    /*trata caso de lista vazia*/
    if(vazia_lista(l->cabeca)){
      l->cabeca = insere;
      return;
    }

    /*loop para andar na lista até a posicao que se quer inserir*/
    for(int i=0;i<posicao;i++){
      aux = atual;
      atual = atual->prox;

      if(atual == NULL)
          break;
    }


    if(atual == NULL){      /*caso seja o ultimo elemento*/
      aux->prox = insere;
      insere->ant = aux;
    }
    else if(atual == l->cabeca){     /*caso seja o primeiro elemento*/
      insere->prox=atual;
      atual->ant=insere;
    }
    else{              /*caso seja uma posicao qualquer da lista*/
      insere->prox=atual;
      insere->ant=atual->ant;
      atual->ant->prox=insere;
      atual->ant=insere;
    }
}
/*---------------------------------------------------------------------------------------------------------*/
/*funcao para remover nodo da lista dada uma posicao*/
void remove_lista(Lista* l, int posicao){

    Nodo *l2 = l->cabeca;

    if(vazia_lista(l2))         /*verifica se a lista esta vazia*/
        return;

    for(int i=0; i < posicao; ++i){     /*loop para andar na lista até o lugar de remover*/
        if(l2 == NULL)
            return;
        l2 = l2->prox;
    }

    if(l2->prox == NULL && l2->ant == NULL)     /*caso seja o primeiro elemento e só tenha um elemento*/
      l->cabeca = NULL;
    else if(l2->prox == NULL)       /*caso seja o ultimo*/
      l2->ant->prox = NULL;
    else if(l2->ant == NULL){        /*caso seja o primeiro e tenham outros depois dele*/
      l2->prox->ant = NULL;
      l->cabeca = l2->prox;
    }
    else{   /*para um elemento qualquer no meio da lista*/
      l2->ant->prox = l2->prox;
      l2->prox->ant = l2->ant;
    }
    free(l2);       /*libera o nodo*/
    l2 = NULL;
}
/*---------------------------------------------------------------------------------------------------------*/
/*funcao que libera a memoria alocada para a lista*/
void free_lista(Lista *l){
    Nodo* aux = l->cabeca;

    while(aux != NULL){
      remove_lista(l,0);
      aux = l->cabeca;
    }
}
