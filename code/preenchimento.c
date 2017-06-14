#include "preenchimento.h"
#include "lista.h"
#include "criador.h"
#include "arvore.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Tentando criar agora o meu código

void imprime(Tree *personagem){

    if(personagem == NULL)
        return;
    if(personagem->left == NULL && personagem->right == NULL)
        return;

        if(strcmp(personagem->info->carac,"formato") == 0)
        {
            printf("formato: ");

            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->id <= personagem->right->info->id)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);

        }
        else if(strcmp(personagem->info->carac,"cor") == 0 && personagem->left->info->dom <= 4)
        {
            printf("olhos cor: ");

            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        else if(strcmp(personagem->info->carac,"cor") == 0 && personagem->left->info->dom >= 7)
        {
            printf("cabelos cor: ");

            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        else if(strcmp(personagem->info->carac,"camisa") == 0)
        {
            printf("camisa: ");

            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        else if(strcmp(personagem->info->carac,"tipo") == 0)
        {
            printf("tipo: ");

            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        else if(strcmp(personagem->info->carac,"calcas") == 0)
        {
            printf("membros calcas: ");

            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        else if(strcmp(personagem->info->carac,"botas") == 0)
        {
            printf("botas: ");

            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        else if(strcmp(personagem->info->carac,"raca") == 0)
        {
            printf("tronco raca: ");

            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        else
        {
            if(strcmp(personagem->info->carac,"personagem") == 0)
                printf("-Identificacao: %d--Pai: %d--Mae: %d-----\n",personagem->info->id,personagem->info->pai,personagem->info->mae);

            imprime(personagem->left);
            imprime(personagem->right);
        }
}
/*-----------------------------------------------------------------------------------------------------*/
void mutacao_cor(Tree* personagem){
  if(strcmp(personagem->info->carac,"cor")!=0 && personagem->left != NULL){
    mutacao_cor(personagem->left);
    mutacao_cor(personagem->right);
  }
  if(strcmp(personagem->info->carac,"cor")==0){
    if(personagem->left->info->dom <= 4){
      personagem->left->info = cria_tipo_olhos();
      personagem->right->info = cria_tipo_olhos();
      personagem->info->mutante = 1;
    }
    else{
      personagem->left->info = cria_cor_cabelos();
      personagem->right->info = cria_cor_cabelos();
      personagem->info->mutante = 1;
    }
  }
}
/*-----------------------------------------------------------------------------------------------------*/
Genetica* seleciona_cor_olhos(Tree* personagem, Tree* pai){
  if((strcmp(personagem->info->carac,"cor")!=0) && personagem->left != NULL){
    seleciona_cor_olhos(personagem->left, pai->left);
    seleciona_cor_olhos(personagem->right, pai->right);
  }
  if(strcmp(personagem->info->carac,"cor")==0){
    if(pai->left->info->dom <= 4){

      if(pai->left->info->dom < pai->right->info->dom){

        if(personagem->left->info->dom == 0){
            personagem->left->info = pai->left->info;
        }
        else{
            personagem->right->info = pai->left->info;
        }

      }
      else if(pai->right->info->dom < pai->left->info->dom){

        if(personagem->left->info->dom == 0){
            personagem->left->info = pai->right->info;
        }
        else{
            personagem->right->info = pai->right->info;
        }

      }
      else{

        if(personagem->left->info->dom == 0){
            personagem->left->info = pai->right->info;
        }
        else{
            personagem->right->info = pai->right->info;
        }

      }
    }
  }
}
/*-----------------------------------------------------------------------------------------------------*/
void mutacao_olhos_tipo(Tree* personagem){
  if(strcmp(personagem->info->carac,"formato")!=0 && personagem->left != NULL){
    mutacao_olhos_tipo(personagem->left);
    mutacao_olhos_tipo(personagem->right);
  }
  if(strcmp(personagem->info->carac,"formato")==0){
    personagem->left->info = cria_tipo_olhos();
    personagem->right->info = cria_tipo_olhos();
    personagem->info->mutante = 1;
  }
}
/*-----------------------------------------------------------------------------------------------------*/
Genetica* seleciona_tipo_olhos(Tree* personagem, Tree* pai){
  if((strcmp(personagem->info->carac,"formato")!=0) && personagem->left != NULL){
    seleciona_tipo_olhos(personagem->left, pai->left);
    seleciona_tipo_olhos(personagem->right, pai->right);
  }
  if(strcmp(personagem->info->carac,"formato")==0){
    if(pai->left->info->dom < pai->right->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->left->info;
      }
      else{
        personagem->right->info = pai->left->info;
      }

    }
    else if(pai->right->info->dom < pai->left->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
    else{

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
  }
}
/*-----------------------------------------------------------------------------------------------------*/
void mutacao_cabelos_tipo(Tree* personagem){
  if(strcmp(personagem->info->carac,"tipo")!=0 && personagem->left != NULL){
    mutacao_cabelos_tipo(personagem->left);
    mutacao_cabelos_tipo(personagem->right);
  }
  if(strcmp(personagem->info->carac,"tipo")==0){
    personagem->left->info = cria_tipo_cabelos();
    personagem->right->info = cria_tipo_cabelos();
    personagem->info->mutante = 1;
  }
}
/*-----------------------------------------------------------------------------------------------------*/
Genetica* seleciona_tipo_cabelos(Tree* personagem, Tree* pai){
  if((strcmp(personagem->info->carac,"tipo")!=0) && personagem->left != NULL){
    seleciona_tipo_cabelos(personagem->left, pai->left);
    seleciona_tipo_cabelos(personagem->right, pai->right);
  }
  if(strcmp(personagem->info->carac,"tipo")==0){
    if(pai->left->info->dom < pai->right->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->left->info;
      }
      else{
        personagem->right->info = pai->left->info;
      }

    }
    else if(pai->right->info->dom < pai->left->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
    else{

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
  }
}
/*-----------------------------------------------------------------------------------------------------*/
Genetica* seleciona_cor_cabelos(Tree* personagem, Tree* pai){
  if((strcmp(personagem->info->carac,"cor")!=0) && personagem->left != NULL){
    seleciona_cor_cabelos(personagem->left, pai->left);
    seleciona_cor_cabelos(personagem->right, pai->right);
  }
  if(strcmp(personagem->info->carac,"cor")==0){
    if(pai->left->info->dom >= 7){

      if(pai->left->info->dom < pai->right->info->dom){

        if(personagem->left->info->dom == 0){
            personagem->left->info = pai->left->info;
        }
        else{
            personagem->right->info = pai->left->info;
        }

      }
      else if(pai->right->info->dom < pai->left->info->dom){

        if(personagem->left->info->dom == 0){
            personagem->left->info = pai->right->info;
        }
        else{
            personagem->right->info = pai->right->info;
        }

      }
      else{

        if(personagem->left->info->dom == 0){
            personagem->left->info = pai->right->info;
        }
        else{
            personagem->right->info = pai->right->info;
        }

      }
    }
  }
}
/*-----------------------------------------------------------------------------------------------------*/
void mutacao_pernas_calca(Tree* personagem){
  if(strcmp(personagem->info->carac,"calcas")!=0 && personagem->left != NULL){
    mutacao_pernas_calca(personagem->left);
    mutacao_pernas_calca(personagem->right);
  }
  if(strcmp(personagem->info->carac,"calcas")==0){
    personagem->left->info = cria_calca_membros();
    personagem->right->info = cria_calca_membros();
    personagem->info->mutante = 1;
  }
}
/*-----------------------------------------------------------------------------------------------------*/
Genetica* seleciona_calca_pernas(Tree* personagem, Tree* pai){
  if((strcmp(personagem->info->carac,"calcas")!=0) && personagem->left != NULL){
    seleciona_calca_pernas(personagem->left, pai->left);
    seleciona_calca_pernas(personagem->right, pai->right);
  }
  if(strcmp(personagem->info->carac,"calcas")==0){
    if(pai->left->info->dom < pai->right->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->left->info;
      }
      else{
        personagem->right->info = pai->left->info;
      }

    }
    else if(pai->right->info->dom < pai->left->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
    else{

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
  }
}
/*-----------------------------------------------------------------------------------------------------*/
void mutacao_pernas_botas(Tree* personagem){
  if(strcmp(personagem->info->carac,"botas")!=0 && personagem->left != NULL){
    mutacao_pernas_botas(personagem->left);
    mutacao_pernas_botas(personagem->right);
  }
  if(strcmp(personagem->info->carac,"botas")==0){
    personagem->left->info = cria_botas_membros();
    personagem->right->info = cria_botas_membros();
    personagem->info->mutante = 1;
  }
}
/*-----------------------------------------------------------------------------------------------------*/
Genetica* seleciona_botas_pernas(Tree* personagem, Tree* pai){
  if((strcmp(personagem->info->carac,"botas")!=0) && personagem->left != NULL){
    seleciona_botas_pernas(personagem->left, pai->left);
    seleciona_botas_pernas(personagem->right, pai->right);
  }
  if(strcmp(personagem->info->carac,"botas")==0){
    if(pai->left->info->dom < pai->right->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->left->info;
      }
      else{
        personagem->right->info = pai->left->info;
      }

    }
    else if(pai->right->info->dom < pai->left->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
    else{

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
  }
}
/*-----------------------------------------------------------------------------------------------------*/
void mutacao_tronco_raca(Tree* personagem){
  if(strcmp(personagem->info->carac,"raca")!=0 && personagem->left != NULL){
    mutacao_tronco_raca(personagem->left);
    mutacao_tronco_raca(personagem->right);
  }
  if(strcmp(personagem->info->carac,"raca")==0){
    personagem->left->info = cria_raca_tronco();
    personagem->right->info = cria_raca_tronco();
    personagem->info->mutante = 1;
  }
}
/*-----------------------------------------------------------------------------------------------------*/
Genetica* seleciona_raca_tronco(Tree* personagem, Tree* pai){
  if((strcmp(personagem->info->carac,"raca")!=0) && personagem->left != NULL){
    seleciona_raca_tronco(personagem->left, pai->left);
    seleciona_raca_tronco(personagem->right, pai->right);
  }
  if(strcmp(personagem->info->carac,"raca")==0){
    if(pai->left->info->dom < pai->right->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->left->info;
      }
      else{
        personagem->right->info = pai->left->info;
      }

    }
    else if(pai->right->info->dom < pai->left->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
    else{

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
  }
}
/*-----------------------------------------------------------------------------------------------------*/
void mutacao_tronco_camisa(Tree* personagem){
  if(strcmp(personagem->info->carac,"camisa")!=0 && personagem->left != NULL){
    mutacao_tronco_camisa(personagem->left);
    mutacao_tronco_camisa(personagem->right);
  }
  if(strcmp(personagem->info->carac,"camisa")==0){
    personagem->left->info = cria_camisa_tronco();
    personagem->right->info = cria_camisa_tronco();
    personagem->info->mutante = 1;
  }
}
/*-----------------------------------------------------------------------------------------------------*/
Genetica* seleciona_camisa_tronco(Tree* personagem, Tree* pai){
  if((strcmp(personagem->info->carac,"camisa")!=0) && personagem->left != NULL){
    seleciona_camisa_tronco(personagem->left, pai->left);
    seleciona_camisa_tronco(personagem->right, pai->right);
  }
  if(strcmp(personagem->info->carac,"camisa")==0){
    if(pai->left->info->dom < pai->right->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->left->info;
      }
      else{
        personagem->right->info = pai->left->info;
      }

    }
    else if(pai->right->info->dom < pai->left->info->dom){

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
    else{

      if(personagem->left->info->dom == 0){
        personagem->left->info = pai->right->info;
      }
      else{
        personagem->right->info = pai->right->info;
      }

    }
  }
}
/*-----------------------------------------------------------------------------------------------------*/
void cruzamento(Tree* personagem, Tree* pai, Tree* mae){
  int i;
  srand(time(NULL));

  seleciona_cor_olhos(personagem->left, pai->left);
  seleciona_cor_olhos(personagem->left, mae->left);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_cor(personagem->left);
  }

  seleciona_tipo_olhos(personagem->left, pai->left);
  seleciona_tipo_olhos(personagem->left, mae->left);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_olhos_tipo(personagem->left);
  }

  seleciona_cor_cabelos(personagem->left, pai->left);
  seleciona_cor_cabelos(personagem->left, mae->left);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_cor(personagem->left);
  }

  seleciona_tipo_cabelos(personagem->left, pai->left);
  seleciona_tipo_cabelos(personagem->left, mae->left);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_cabelos_tipo(personagem->left);
  }

  seleciona_calca_pernas(personagem->right, pai->right);
  seleciona_calca_pernas(personagem->right, mae->right);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_pernas_calca(personagem->right);
  }

  seleciona_botas_pernas(personagem->right, pai->right);
  seleciona_botas_pernas(personagem->right, mae->right);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_pernas_botas(personagem->right);
  }

  seleciona_raca_tronco(personagem->right, pai->right);
  seleciona_raca_tronco(personagem->right, mae->right);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_tronco_raca(personagem->right);
  }

  seleciona_camisa_tronco(personagem->right, pai->right);
  seleciona_camisa_tronco(personagem->right, mae->right);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_tronco_camisa(personagem->right);
  }
}
/*-----------------------------------------------------------------------------------------------------*/
Tree* busca(Lista* l, int posicao){
  if(vazia_lista(l)){
    return NULL;
  }

  int i;

  Nodo* atual = l->cabeca;
  for(i=0;(i<posicao) && (atual != NULL);i++){
    atual=atual->prox;
  }

  if(atual==NULL){
    printf("Essa posição não existe.\n");
    return NULL;
  }

  return (atual->personagem);
}
/*-----------------------------------------------------------------------------------------------------*/
Tree* seleciona_pais(Tree* personagem, Lista* l, int** combinacoes, int posicao){
  int pai_pos = combinacoes[posicao][0];
  personagem->info->pai = combinacoes[posicao][0]+1;
  int mae_pos = combinacoes[posicao][1];
  personagem->info->mae = combinacoes[posicao][1]+1;

  Tree* pai = busca(l, pai_pos);
  Tree* mae = busca(l, mae_pos);

  cruzamento(personagem, pai, mae);

}
/*-----------------------------------------------------------------------------------------------------*/
int verifica_combinacoes(int** combinacoes, int posicao){
  int i;

  if(posicao<8){
    for(i=4;i<posicao;i++){
        if(((combinacoes[i][0]==combinacoes[posicao][0]) && (combinacoes[i][1]==combinacoes[posicao][1])) ||
          ((combinacoes[i][0]==combinacoes[posicao][1]) && (combinacoes[i][1]==combinacoes[posicao][0]))){
            return 1;
        }
    }
    return 0;
  }

  else if(posicao>=8){
    for(i=4;i<posicao;i++){
      if(((combinacoes[i][0]==combinacoes[posicao][0]) && (combinacoes[i][1]==combinacoes[posicao][1])) ||
        ((combinacoes[i][0]==combinacoes[posicao][1]) && (combinacoes[i][1]==combinacoes[posicao][0]))){
            return 1;
        }
    }
    return 0;
  }
}
/*-----------------------------------------------------------------------------------------------------*/
void preenche_combinacoes(int** combinacoes){
  int k;

  for(k=0;k<16;k++){
    combinacoes[k] = (int*) malloc(2*sizeof(int));
  }

  combinacoes[0][0] = 0;
  combinacoes[0][1] = 0;
  combinacoes[1][0] = 0;
  combinacoes[1][1] = 0;
  combinacoes[2][0] = 0;
  combinacoes[2][1] = 0;
  combinacoes[3][0] = 0;
  combinacoes[3][1] = 0;

  int j;
  int i;
  srand(time(NULL));

  int verifica = 1;
  for(i=4;i<8;i++){

    while(verifica != 0){
      combinacoes[i][0] = rand()%4;
      combinacoes[i][1] = rand()%4;

      j=verifica_combinacoes(combinacoes, i);
      if((combinacoes[i][0]==combinacoes[i][1]) || j==1){
        verifica = 1;
      }
      else{
        verifica = 0;
      }
    }
    verifica = 1;

  }


  verifica = 1;
  for(i=8;i<16;i++){

    while(verifica != 0){
      combinacoes[i][0] = rand()%8;
      combinacoes[i][1] = rand()%8;

      j=verifica_combinacoes(combinacoes, i);
      if((combinacoes[i][0]==combinacoes[i][1]) || j==1){
        verifica = 1;
      }
      else{
        verifica = 0;
      }
    }
    verifica = 1;

  }

  /*for(i=0;i<16;i++){
    printf("\nPai: %d,  Mae: %d\n", combinacoes[i][0], combinacoes[i][1]);
  }*/

  printf("\nFIM\n");

}
/*-----------------------------------------------------------------------------------------------------*/
void insere(Tree *nodo, Tree*nodo2){

    if(nodo->left == NULL && nodo->right == NULL)
        return;

    /*
    if(strcmp(nodo->info->carac,"cabelos") == 0 || strcmp(nodo->info->carac,"olhos") == 0)
        Nodo* no = nodo;
    */

    if(strcmp(nodo->left->info->carac,"VAZIO") == 0 && strcmp(nodo->right->info->carac,"VAZIO") == 0)
    {
        Genetica *genetic1, *genetic2;

        if(strcmp(nodo->info->carac,"formato") == 0)
        {
            genetic1 = cria_tipo_olhos();
            genetic2 = cria_tipo_olhos();
            nodo->left->info = genetic1;
            nodo->right->info = genetic2;
        }
        else if(strcmp(nodo->info->carac,"cor") == 0)
        {
            if(strcmp(nodo2->info->carac,"cabelos") == 0)
            {
                genetic1 = cria_cor_cabelos();
                genetic2 = cria_cor_cabelos();
                nodo->left->info = genetic1;
                nodo->right->info = genetic2;
            }
            else if(strcmp(nodo2->info->carac,"olhos") == 0)
            {
                genetic1 = cria_cor_olhos();
                genetic2 = cria_cor_olhos();
                nodo->left->info = genetic1;
                nodo->right->info = genetic2;
            }
        }
        else if(strcmp(nodo->info->carac,"camisa") == 0)
        {
            genetic1 = cria_camisa_tronco();
            genetic2 = cria_camisa_tronco();
            nodo->left->info = genetic1;
            nodo->right->info = genetic2;
        }
        else if(strcmp(nodo->info->carac,"tipo") == 0)
        {
            genetic1 = cria_tipo_cabelos();
            genetic2 = cria_tipo_cabelos();
            nodo->left->info = genetic1;
            nodo->right->info = genetic2;
        }
        else if(strcmp(nodo->info->carac,"calcas") == 0)
        {
            genetic1 = cria_calca_membros();
            genetic2 = cria_calca_membros();
            nodo->left->info = genetic1;
            nodo->right->info = genetic2;
        }
        else if(strcmp(nodo->info->carac,"botas") == 0)
        {
            genetic1 = cria_botas_membros();
            genetic2 = cria_botas_membros();
            nodo->left->info = genetic1;
            nodo->right->info = genetic2;
        }
        else if(strcmp(nodo->info->carac,"raca") == 0)
        {
            genetic1 = cria_raca_tronco();
            genetic2 = cria_raca_tronco();
            nodo->left->info = genetic1;
            nodo->right->info = genetic2;
        }
    }
    else
    {
        insere(nodo->left,nodo);
        insere(nodo->right,nodo);
    }


}
/*-----------------------------------------------------------------------------------------------------*/
