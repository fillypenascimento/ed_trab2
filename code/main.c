#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "printPersonagem.h"
#include "arvore.h"
#include "criador.h"
#include "lista.h"
#include "preenchimento.h"

//oi

int main(){

	Lista* l = cria_lista();
	int** combinacoes = (int**) malloc(16*sizeof(int*));
	preenche_combinacoes(combinacoes);

	int posicao_lista=0;
	int i;
	/*int i;
	srand(time(NULL));
	i=rand()%5;
	printf("Número aleatório: %d.\n", i);*/

	Tree* personagem;
	for(i=0;i<4;i++){
		personagem = cria_arvore_personagem(i+1);
		insere(personagem,NULL);
		insere_lista(l, posicao_lista, personagem);
		posicao_lista++;
		imprime(personagem);
		//imprime_personagem(personagem);
		printf("\n\n");
	}

	for(i=4;i<16;i++){
		personagem = cria_arvore_personagem(i+1);
		seleciona_pais(personagem, l, combinacoes, i);
		insere_lista(l, posicao_lista, personagem);
		posicao_lista++;
		imprime(personagem);
		//imprime_personagem(personagem);
		printf("\n\n");
	}

	for(i=0;i<16;i++){
		free(combinacoes[i]);
		printf("\nLiberei a combinação %d\n", i);
	}
	free(combinacoes);
	printf("\nLiberei o vetor de combinacoes. %d\n", i);

	Nodo* atual = l->cabeca;

	for(i=0;i<16 && (atual!=NULL);i++){
		tree_free(atual->personagem);
		printf("\nLiberei o personagem %d\n", i);
		atual=atual->prox;
	}

	free_lista(l);


	printf("\n\n");



	/*Caso queira testar a biblioteca grafica */
	//imprime_personagem_aleatorio();
    return 0;
}
