#include "dragao.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int MAX_DRAGAO = 5;
int qtdDragoes = 0;
int codigoAtualD = 1;

Dragao *listaDeDragoes;

int inicializarDragao(){
	
	listaDeDragoes = (Dragao*) malloc (MAX_DRAGAO * sizeof (Dragao));
	if(listaDeDragoes == NULL){
		return 0;
	}
	
	int i;
	for (i=0; i<MAX_DRAGAO;i++){
	listaDeDragoes[i].cod = codigoAtualD;
	listaDeDragoes[i].idade = 0;
	listaDeDragoes[i].nome[0] = '\0';
	listaDeDragoes[i].unidadesEmEstoque = 0;
	listaDeDragoes[i].valorDiario = 0;
	listaDeDragoes[i].idElemento =0;
	}
	
	listaDeDragoes[0].cod = codigoAtualD;
	listaDeDragoes[0].idade = 10;
	strcpy(listaDeDragoes[0].nome,"Brutos");
	listaDeDragoes[0].unidadesEmEstoque = 2;
	listaDeDragoes[0].valorDiario = 100;
	listaDeDragoes[0].idElemento = 1;
	qtdDragoes++;
	codigoAtualD++;
	
	listaDeDragoes[1].cod = codigoAtualD;
	listaDeDragoes[1].idade = 20;
	strcpy(listaDeDragoes[1].nome,"Tormenta");
	listaDeDragoes[1].unidadesEmEstoque = 3;
	listaDeDragoes[1].valorDiario = 200;
	listaDeDragoes[1].idElemento = 2;
	qtdDragoes++;
	codigoAtualD++;
	
	listaDeDragoes[2].cod = codigoAtualD;
	listaDeDragoes[2].idade = 30;
	strcpy(listaDeDragoes[2].nome,"Teste");
	listaDeDragoes[2].unidadesEmEstoque = 4;
	listaDeDragoes[2].valorDiario = 300;
	listaDeDragoes[2].idElemento = 1;
	qtdDragoes++;
	codigoAtualD++;
	
	
}
int encerraDragao(){
	
	free(listaDeDragoes);
	
}
int salvarDragao(Dragao c, int encontrado){
	
	if (qtdDragoes<MAX_DRAGAO && encontrado != 0){
		c.cod = codigoAtualD++;
		listaDeDragoes[qtdDragoes] = c;
		qtdDragoes++;
		
		return 1; // funcionou
	}
	
	else
		return 0; //falhou
}

int QuantidadeDragoes(){
	return qtdDragoes;
}
int obterDragaoPeloIndice(int indice, Dragao* d){
	*d = listaDeDragoes[indice];
	return 1;
}
int obterDragaoPeloCodigo(int codigo, Dragao* d){
	
	int i;
	for (i=0; i <qtdDragoes; i++){
		*d = listaDeDragoes[i];
		if (d->cod == codigo){
			return 1;
		}
	}
	return 0;
	}
int ApagarDragaoPeloCodigo(int codigo){
		int i;
	for(i=0; i <qtdDragoes; i++){
		if (listaDeDragoes[i].cod == codigo){
			listaDeDragoes[i] = listaDeDragoes[qtdDragoes-1];
			listaDeDragoes[qtdDragoes - 1].cod = 0;
			qtdDragoes--;
			return 1; //funcionou
		}
	}
	return 0; //falhou
}

int diminuirUnidade(int codigo){
	
	int i;
	for (i=0; i <qtdDragoes; i++){
		Dragao d = listaDeDragoes[i];
		if (d.cod == codigo){
			listaDeDragoes[i].unidadesEmEstoque--;
			return 1;
		}
	}
	return 0;
}

int aumentarUnidadeDrag(int codigo){
	int i;
	for (i=0; i <qtdDragoes; i++){
		Dragao d = listaDeDragoes[i];
		if (d.cod == codigo){
			listaDeDragoes[i].unidadesEmEstoque++;
			return 1;
		}
	}
	return 0;
	
}

int aumentarTamanhoD(){
	if (qtdDragoes == MAX_DRAGAO){
		MAX_DRAGAO += 2;
		Dragao* novaListaA = (Dragao*) realloc (listaDeDragoes, MAX_DRAGAO * sizeof(Dragao));
		if(novaListaA != NULL){
			listaDeDragoes =  novaListaA;
			free(novaListaA);
			novaListaA = NULL;
			return 1;
		}
		
	}
	}
	
int reduzirTamanhoD(){
	if (qtdDragoes < (MAX_DRAGAO * 0.4)){
		MAX_DRAGAO = qtdDragoes +2;
		Dragao* novaListaR = (Dragao*) realloc (listaDeDragoes, MAX_DRAGAO * sizeof(Dragao));
		if(novaListaR != NULL){
			listaDeDragoes = novaListaR;
			free(novaListaR);
			novaListaR = NULL;
			return 1;
		}
		
	}
	
}

int RETORNAMAXD(){
	return MAX_DRAGAO;
}

int alterarDragao(int codigo, Dragao d){
	
	int i;
	for (i=0; i <qtdDragoes; i++){
		Dragao h = listaDeDragoes[i];
		if (h.cod == codigo){
			listaDeDragoes[i] = d;
			return 1;
		}
		
	}
	return 0;
}

