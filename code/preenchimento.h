#ifndef PREENCHIMENTO_H
#define PREENCHIMENTO_H



#include "criador.h"
#include "lista.h"
#include "arvore.h"

void insere(Tree*, Tree*);
void preenche_combinacoes(int**);
int verifica_combinacoes(int**, int);
Tree* seleciona_pais(Tree*, Lista*, int**, int);
Tree* busca(Lista*, int);
void cruzamento(Tree*, Tree*, Tree*);
void imprime(Tree*);

void mutacao_cor(Tree*);
Genetica* seleciona_cor_olhos(Tree*, Tree*);

Genetica* seleciona_tipo_olhos(Tree*, Tree*);
void mutacao_olhos_tipo(Tree*);

Genetica* seleciona_cor_cabelos(Tree*, Tree*);
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
