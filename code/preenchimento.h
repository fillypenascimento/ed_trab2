#ifndef PREENCHIMENTO_H
#define PREENCHIMENTO_H

/*biblioteca de funcoes que irao preencher novo personagem*/

#include "criador.h"
#include "lista.h"
#include "arvore.h"

void insere(Tree*, Tree*);        /*funcao que insere as caracteristicas aleatorias para os 4 personagens primordiais, recebe duas arvores*/
void preenche_combinacoes(int**); /*funcao que preenche a matriz de combinacoes, recebe a matriz de combinacoes*/
int verifica_combinacoes(int**, int);/*funcao que verifica a unicidade de cada combinação garantindo que não haverá repeticoes de cruzamento*/
Tree* seleciona_pais(Tree*, Lista*, int**, int);    /*funcao que seleciona os pais de um personagem buscando suas arvores na lista e realizando o cruzamento para gerar um filho*/
Tree* busca(Lista*, int);   /*funcao que busca na lista a arvore de um personagem para realizar o cruzamento*/
void cruzamento(Tree*, Tree*, Tree*);   /*realiza o cruzamento de dois personagens e atribui ao filho*/
void imprime(Tree*);      /*funcao que imprime a arvore do personagem considerando suas dominancias*/

/*funcoes mutação: selecionam uma caracteristica aleatoria para a genetica de um personagem*/
/*funcao tipo seleciona: escolhem o gene dominante do pai para o filho*/

void mutacao_cor(Tree*);
Genetica* seleciona_cor(Tree*, Tree*);

Genetica* seleciona_tipo_olhos(Tree*, Tree*);
void mutacao_olhos_tipo(Tree*);

Genetica* seleciona_tipo_cabelos(Tree*, Tree*);
void mutacao_cabelos_tipo(Tree*);

Genetica* seleciona_calca_pernas(Tree*, Tree*);
void mutacao_pernas_calca(Tree*);

Genetica* seleciona_botas_pernas(Tree*, Tree*);
void mutacao_pernas_botas(Tree*);

Genetica* seleciona_raca_tronco(Tree*, Tree*);
void mutacao_tronco_raca(Tree*);

Genetica* seleciona_camisa_tronco(Tree*, Tree*);
void mutacao_tronco_camisa(Tree*);

#endif
