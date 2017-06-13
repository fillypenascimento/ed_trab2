#include "preenchimento.h"
#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Tentando criar agora o meu código

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

  for(i=0;i<16;i++){
    printf("\nPai: %d,  Mae: %d\n", combinacoes[i][0], combinacoes[i][1]);
  }

  printf("\nFIM\n");

}

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


/*void insere_filho(Tree *nodo, Tree*nodo2, Lista* l){

    int i = 0;
    Nodo* atual = l->cabeca;
    while(atual!=NULL){
      atual = atual->proximo
      i++;
    }
    int j;
  	srand(time(NULL));
  	j=rand()%(i+1);
  	printf("Número aleatório: %d.\n", j);



    if(nodo->left == NULL && nodo->right == NULL)
        return;

    /*
    if(strcmp(nodo->info->carac,"cabelos") == 0 || strcmp(nodo->info->carac,"olhos") == 0)
        Nodo* no = nodo;
    */

/*   if(strcmp(nodo->left->info->carac,"VAZIO") == 0 && strcmp(nodo->right->info->carac,"VAZIO") == 0)
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
        insere_filho(nodo->left,nodo);
        insere_filho(nodo->right,nodo);
    }


}*/
