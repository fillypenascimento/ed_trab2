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

	Lista* l = (Lista*) malloc(sizeof(Lista));
	int** combinacoes = (int**) malloc(16*sizeof(int*));
	preenche_combinacoes(combinacoes);

	int posicao_lista=0;
	int i;
	/*int i;
	srand(time(NULL));
	i=rand()%5;
	printf("Número aleatório: %d.\n", i);*/

	/*Criamos uma arvore de personagem para testes */
	/*Lembre-se que ela recebe o id do personagem */

	Tree* personagem;
	for(i=0;i<4;i++){
		personagem = cria_arvore_personagem(i+1);
		insere(personagem,NULL);
		insere_lista(l, posicao_lista, personagem);
		posicao_lista++;
		imprime(personagem);
		imprime_personagem(personagem);
		printf("\n\n");
		personagem = NULL;
	}

	for(i=4;i<16;i++){
		personagem = cria_arvore_personagem(i+1);
		seleciona_pais(personagem, l, combinacoes, i);
		insere_lista(l, posicao_lista, personagem);
		posicao_lista++;
		imprime(personagem);
		imprime_personagem(personagem);
		printf("\n\n");
		personagem = NULL;
	}


	printf("\n\n");



	/*Caso queira testar a biblioteca grafica */
	//imprime_personagem_aleatorio();
    return 0;
}
