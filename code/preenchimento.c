#include "preenchimento.h"
#include "lista.h"
#include "criador.h"
#include "arvore.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*funcao que imprime a arvore do personagem considerando suas dominancias*/
void imprime(Tree *personagem){

    if(personagem == NULL)          /*para o caso de a arvore passada ser NULL*/
        return;
    if(personagem->left == NULL && personagem->right == NULL)     /*caso seja um no folha*/
        return;

        /*imprime o formato do cabelo dominante*/
        if(strcmp(personagem->info->carac,"formato") == 0)
        {
            printf("formato: ");
            /*flag para mutante*/
            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->id <= personagem->right->info->id)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);

        }
        /*imprime a cor dos olhos dominante*/
        else if(strcmp(personagem->info->carac,"cor") == 0 && personagem->left->info->dom <= 4)
        {
            printf("olhos cor: ");

            /*flag para mutante*/
            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        /*imprime a cor do cabelo dominante*/
        else if(strcmp(personagem->info->carac,"cor") == 0 && personagem->left->info->dom >= 7)
        {
            printf("cabelos cor: ");
            /*flag para mutante*/
            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        /*imprime a camisa dominante*/
        else if(strcmp(personagem->info->carac,"camisa") == 0)
        {
            printf("camisa: ");

            /*flag para mutante*/
            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        /*imprime o tipo do cabelo dominante*/
        else if(strcmp(personagem->info->carac,"tipo") == 0)
        {
            printf("tipo: ");

            /*flag para mutante*/
            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        /*imprime as calcas dominante*/
        else if(strcmp(personagem->info->carac,"calcas") == 0)
        {
            printf("membros calcas: ");

            /*flag para mutante*/
            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        /*imprime a bota dominante*/
        else if(strcmp(personagem->info->carac,"botas") == 0)
        {
            printf("botas: ");

            /*flag para mutante*/
            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        /*imprime a raca dominante*/
        else if(strcmp(personagem->info->carac,"raca") == 0)
        {
            printf("tronco raca: ");

            /*flag para mutante*/
            if(personagem->info->mutante == 1)
                printf("MUTANTE ");

            if(personagem->left->info->dom <= personagem->right->info->dom)
                printf("%s\n",personagem->left->info->carac);
            else
                printf("%s\n",personagem->right->info->carac);
        }
        else
        {
          /*imprime o personagem bem como seu id, pai e mae*/
            if(strcmp(personagem->info->carac,"personagem") == 0)
                printf("-Identificacao: %d--Pai: %d--Mae: %d-----\n",personagem->info->id,personagem->info->pai,personagem->info->mae);

            imprime(personagem->left);
            imprime(personagem->right);
        }
}
/*-----------------------------------------------------------------------------------------------------*/
/*escolhe caracteristicas aleatorias para a cor de olhos ou de cabelos*/
void mutacao_cor(Tree* personagem){
  if(strcmp(personagem->info->carac,"cor")!=0 && personagem->left != NULL){
    mutacao_cor(personagem->left);
    mutacao_cor(personagem->right);
  }
  if(strcmp(personagem->info->carac,"cor")==0){
    if(personagem->left->info->dom <= 4 && personagem->right->info->dom <= 4){
      personagem->left->info = cria_cor_olhos();
      personagem->right->info = cria_cor_olhos();
      personagem->info->mutante = 1;
    }
    else if(personagem->left->info->dom >=7 && personagem->right->info->dom >=7){
      personagem->left->info = cria_cor_cabelos();
      personagem->right->info = cria_cor_cabelos();
      personagem->info->mutante = 1;
    }
  }
}
/*-----------------------------------------------------------------------------------------------------*/
/*seleciona para o personagem filho a caracteristica de cor dominante do pai*/
Genetica* seleciona_cor(Tree* personagem, Tree* pai){
  if((strcmp(personagem->info->carac,"cor")!=0) && personagem->left != NULL){
    seleciona_cor(personagem->left, pai->left);
    seleciona_cor(personagem->right, pai->right);
  }
  else if(strcmp(personagem->info->carac,"cor")==0){
    if(pai->left->info->dom <= 4 && pai->right->info->dom <=4){

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
      else if(pai->right->info->dom == pai->left->info->dom){

        if(personagem->left->info->dom == 0){
            personagem->left->info = pai->right->info;
        }
        else{
            personagem->right->info = pai->right->info;
        }

      }
    }

    else if(pai->left->info->dom >= 7 && pai->right->info->dom >=7){

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
      else if(personagem->left->info->dom == personagem->right->info->dom){

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
/*escolhe caracteristicas aleatorias para o tipo dos olhos*/
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
/*seleciona para o personagem filho a caracteristica de tipo de olhos dominante do pai*/
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
/*escolhe caracteristicas aleatorias para o tipo do cabelo*/
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
/*seleciona para o personagem filho a caracteristica de tipo de cabelo dominante do pai*/
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
/*-----------------------------------------------------------------------ffff--------------------------*/
/*escolhe caracteristicas aleatorias para a calca*/
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
/*seleciona para o personagem filho a caracteristica  calca dominante do pai*/
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
/*escolhe caracteristicas aleatorias para as botas*/
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
/*seleciona para o personagem filho a bota domminante do pai*/
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
/*escolhe caracteristicas aleatorias para a raca*/
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
/*seleciona para o personagem filho a caracteristica dominante de raca do pai*/
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
/*escolhe caracteristicas aleatorias para a camisa*/
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
/*seleciona para o personagem filho a caracteristica dominante de tronco do pai*/
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
/*realiza o cruzamento de dois personagens e atribui ao filho*/
void cruzamento(Tree* personagem, Tree* pai, Tree* mae){
  int i;
  srand(time(NULL));

  /*serao chamadas as funcoes que selecionam a caracteristica dominante de um pai e aplicam ao filho */
  /*é também considerada a possibilidade de mutação para cada caracteristica apresentada*/
  /*probabilidade de mutacao calculada pela funcao rand() e dentro do limite de 20% de possibilidade*/
  /*todos os blocos abaixo possuem as caracteristicas citadas acima*/


  /*seleciona cor de olhos*/
  seleciona_cor(personagem->left, pai->left);
  seleciona_cor(personagem->left, mae->left);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_cor(personagem->left);
  }

  /*seleciona tipo de olhos*/
  seleciona_tipo_olhos(personagem->left, pai->left);
  seleciona_tipo_olhos(personagem->left, mae->left);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_olhos_tipo(personagem->left);
  }

  /*seleciona cor de cabelos*/
  seleciona_cor(personagem->left, pai->left);
  seleciona_cor(personagem->left, mae->left);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_cor(personagem->left);
  }

  /*seleciona tipo de cabelos*/
  seleciona_tipo_cabelos(personagem->left, pai->left);
  seleciona_tipo_cabelos(personagem->left, mae->left);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_cabelos_tipo(personagem->left);
  }

  /*seleciona calcas*/
  seleciona_calca_pernas(personagem->right, pai->right);
  seleciona_calca_pernas(personagem->right, mae->right);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_pernas_calca(personagem->right);
  }

  /*seleciona botas*/
  seleciona_botas_pernas(personagem->right, pai->right);
  seleciona_botas_pernas(personagem->right, mae->right);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_pernas_botas(personagem->right);
  }

  /*seleciona raca*/
  seleciona_raca_tronco(personagem->right, pai->right);
  seleciona_raca_tronco(personagem->right, mae->right);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_tronco_raca(personagem->right);
  }

  /*seleciona tronco*/
  seleciona_camisa_tronco(personagem->right, pai->right);
  seleciona_camisa_tronco(personagem->right, mae->right);
  i=rand()%101;
  //printf("\n\nprobabilidade de mutação: %d\n", i);
  if(i<=20){
    mutacao_tronco_camisa(personagem->right);
  }
}
/*-----------------------------------------------------------------------------------------------------*/
/*funcao que busca na lista a arvore de um personagem para realizar o cruzamento*/
Tree* busca(Lista* l, int posicao){
  if(vazia_lista(l->cabeca)){
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
/*funcao que seleciona os pais de um personagem buscando suas arvores na lista e realizando o cruzamento para gerar um filho*/
Tree* seleciona_pais(Tree* personagem, Lista* l, int** combinacoes, int posicao){

  /*selecionam as posicoes que serao passadas para funcao percorrer a lista e selecionar a respectiva arvore de um pa*/
  int pai_pos = combinacoes[posicao][0];
  personagem->info->pai = combinacoes[posicao][0]+1;
  int mae_pos = combinacoes[posicao][1];
  personagem->info->mae = combinacoes[posicao][1]+1;

  /*busca pai e mae do personagem na matriz de combinacoes*/
  Tree* pai = busca(l, pai_pos);
  Tree* mae = busca(l, mae_pos);

  /*funcao que realiza o cruzamento de dois personagens*/
  cruzamento(personagem, pai, mae);

}
/*-----------------------------------------------------------------------------------------------------*/
/*funcao que verifica a unicidade de cada combinação garantindo que não haverá repeticoes de cruzamento, ex: pai 1, mae 2 e pai 1, mae 2; ou pai 1, mae 2 e pai 2, mae 1; */
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
/*funcao que preenche a matriz de combinacoes*/
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

}
/*-----------------------------------------------------------------------------------------------------*/
/*funcao que insere as caracteristicas aleatorias para os 4 personagens primordiais, recebe duas arvores*/
/*a primeira arvore é a que estamos querendo alterar e a segunda é pai da primeira, apenas para monitoramento*/
void insere(Tree *nodo, Tree*nodo2){

    if(nodo->left == NULL && nodo->right == NULL)
        return;

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
