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

/*void preenche_personagem(Tree* personagem){
	int i=1;
}*/



int main(){

	Lista* l = (Lista*) malloc(sizeof(Lista));
	int** combinacoes = (int**) malloc(16*sizeof(int*));
	preenche_combinacoes(combinacoes);

	int posicao_lista=0;

	int i;
	srand(time(NULL));
	i=rand()%5;
	printf("Número aleatório: %d.\n", i);

	/*Criamos uma arvore de personagem para testes */
	/*Lembre-se que ela recebe o id do personagem */

	Tree* personagem;
	for(i=0;i<4;i++){
		personagem = cria_arvore_personagem(i);
		insere(personagem,NULL);
		insere_lista(l, 	posicao_lista, personagem);
		posicao_lista++;
		imprime_arvore(personagem);
		imprime_personagem(personagem);
	}

	//for(i=4;i<16;i++){
		personagem = cria_arvore_personagem(i);
		seleciona_pais(personagem, l, combinacoes, i);
		insere_lista(l, posicao_lista, personagem);
		imprime_arvore(personagem);
	//}

	/*
	//Personagem Aleatório 1
	Tree* personagem1 = cria_arvore_personagem(1);
	insere(personagem1,NULL
	insere_lista(l, 	posicao_lista, personagem1);
	posicao_lista++;imprime_arvore(personagem1);
	imprime_personagem(personagem1);

	//Personagem Aleatório 2
	Tree* personagem2 = cria_arvore_personagem(0);
	insere(personagem2,NULL);
	insere_lista(l, posicao_lista, personagem2);
	posicao_lista++;
	imprime_arvore(personagem2);
	imprime_personagem(personagem2);

	//Personagem Aleatório 3
	Tree* personagem3 = cria_arvore_personagem(0);
	insere(personagem3,NULL);
	insere_lista(l, posicao_lista, personagem3);
	posicao_lista++;
	imprime_arvore(personagem3);
	imprime_personagem(personagem3);

	//Personagem Aleatório 4
	Tree* personagem4 = cria_arvore_personagem(0);
	insere(personagem4,NULL);
	insere_lista(l, posicao_lista, personagem4);
	posicao_lista++;
	imprime_arvore(personagem4);
	imprime_personagem(personagem4);
	*/
	//Personagem 5


	//printf("\nO personagem impresso graficamente nao corresponde ao personagem vazio impresso de forma textual");
	printf("\n\n");



	/*Caso queira testar a biblioteca grafica */
	//imprime_personagem_aleatorio();
    return 0;
}
