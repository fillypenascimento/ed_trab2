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

/*função para liberar a arvore de um personagem*/
void free_personagem(Tree* personagem){
	if(personagem->left != NULL && personagem->right != NULL){
			free_personagem(personagem->left);
			free_personagem(personagem->right);
	}
	else{
		free(personagem);
	}
}

/*função principal*/
int main(){

	Lista* l = cria_lista();		/*ponteiro que recebe a lista vazia criada pela funcao cria_lista*/
	int** combinacoes = (int**) malloc(16*sizeof(int*));    /*vetor de ponteiros para inteiros que armazenará as combinações já feitas*/
	preenche_combinacoes(combinacoes);				/*função que preenche o vetor de combinações*/

	int posicao_lista=0;
	int i;


	/*preenchimeto dos 4 personagens primordiais*/
	Tree* personagem;
	for(i=0;i<4;i++){
		personagem = cria_arvore_personagem(i+1);			/*cria a arvore do personagem*/
		insere(personagem,NULL);											/*funcao que insere as caracteristicas aleatorias nos nos folhas*/
		insere_lista(l, posicao_lista, personagem);		/*funcao que insere o personagem na lista*/
		posicao_lista++;
		imprime(personagem);													/*funcao que imprime a arvore do personagem*/
		//imprime_personagem(personagem);							/*funcao que imprime o personagem graficamente*/
		printf("\n\n");
		getchar();
	}


	/*funcao para os personagens frutos do cruzamento de outros dois personagens*/
	for(i=4;i<16;i++){
		personagem = cria_arvore_personagem(i+1);				/*cria a arvore do personagem*/
		seleciona_pais(personagem, l, combinacoes, i);	/*seleciona os pais do personagem e faz o cruzamento*/
		insere_lista(l, posicao_lista, personagem);			/*funcao que insere o personagem na lista*/
		posicao_lista++;
		imprime(personagem);														/*funcao que imprime a arvore do personagem*/
		//imprime_personagem(personagem);								/*funcao que imprime o personagem graficamente*/
		printf("\n\n");
		getchar();
	}

	/*loop para liberar a matriz de combinacoes*/
	for(i=0;i<16;i++){
		free(combinacoes[i]);
	}
	free(combinacoes);

	Nodo* atual = l->cabeca;


	/*loop para liberar todos os prsonagens da lista*/
 	i=1;
	while(atual!=NULL && atual->personagem != NULL){
		free_personagem(atual->personagem);							/*funcao que libera a arvore do personagem*/
		atual->personagem = NULL;
		i++;
		atual=atual->prox;
	}

	free_lista(l);						/*funcao que libera a lista duplamente encadeada*/


	printf("\n\n");

    return 0;
}
