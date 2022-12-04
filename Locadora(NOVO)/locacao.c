#include "locacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int MAX_LOCACAO = 5;
int qtdLocacao = 0;
int codigoAtualL = 1;

Locacao *listaDeLocacao;

int inicializarLocacao(){
	
	listaDeLocacao = (Locacao*) malloc (MAX_LOCACAO * sizeof(Locacao));
	if (listaDeLocacao == NULL){
		return 0;
	}
	
	
	int i;
	for (i = 0; i < MAX_LOCACAO; i++){
		listaDeLocacao[i].cod = 0;
		listaDeLocacao[i].pago[0] = '\0';
		listaDeLocacao[i].fimLoc[0] = '\0';
		listaDeLocacao[i].inicioLoc[0] = '\0';
		listaDeLocacao[i].codGuerreiro = '\0';
		listaDeLocacao[i].codDragao = '\0';
	}
		listaDeLocacao[0].cod = codigoAtualL;
		strcpy(listaDeLocacao[0].pago, "S");
		strcpy(listaDeLocacao[0].fimLoc, "20/10");
		strcpy(listaDeLocacao[0].inicioLoc, "10/10");
		listaDeLocacao[0].codGuerreiro = 1;
		listaDeLocacao[0].codDragao = 1;
		qtdLocacao++;
		codigoAtualL++;
}
int encerraLocacao(){
	
	free(listaDeLocacao);
}
int salvarLocacao(Locacao c){
	
		if (qtdLocacao < MAX_LOCACAO){
		c.cod = codigoAtualL++;
		listaDeLocacao[qtdLocacao] = c;
		qtdLocacao++;
		
		return 1; // funcionou
	}
	
	else
		return 0; //falhou
	
	
}
int QuantidadeLocacao(){
	return qtdLocacao;
}
int obterLocacaoPeloIndice(int indice, Locacao* l){
	*l = listaDeLocacao[indice];
	return 1;
	
}
int obterLocacaoPeloCodigo(int codigo, Locacao* l){
	
	int i;
	for (i=0; i <qtdLocacao; i++){
		*l = listaDeLocacao[i];
		if (l->cod == codigo){
			return 1;
		}
		
	}
	return 0;
	}

int ApagarLocacaoPeloCodigo(int codigo){
	int i;
	for(i=0; i <qtdLocacao; i++){
		if (listaDeLocacao[i].cod == codigo){
			listaDeLocacao[i] = listaDeLocacao[qtdLocacao-1];
			listaDeLocacao[qtdLocacao - 1].cod = 0;
			qtdLocacao--;
			return 1; //funcionou
		}
	}
}

int aumentarTamanhoL(){
	if (qtdLocacao == MAX_LOCACAO){
		MAX_LOCACAO += 2;
		Locacao* novaListaA = (Locacao*) realloc (listaDeLocacao, MAX_LOCACAO * sizeof(Locacao));
		if(novaListaA != NULL){
			listaDeLocacao =  novaListaA;
			free(novaListaA);
			novaListaA = NULL;
			return 1;
		}
		
	}
	}
	
int reduzirTamanhoL(){
	if (qtdLocacao < (MAX_LOCACAO * 0.4)){
		MAX_LOCACAO = qtdLocacao +2;
		Locacao* novaListaR = (Locacao*) realloc (listaDeLocacao, MAX_LOCACAO * sizeof(Locacao));
		if(novaListaR != NULL){
			listaDeLocacao = novaListaR;
			free(novaListaR);
			novaListaR = NULL;
			return 1;
		}
		
	}
	
}

int RETORNAMAXL(){
	return MAX_LOCACAO;
}


int alterarLocacao(int codigo, Locacao l){
	int i;
	for (i=0; i <qtdLocacao; i++){
		Locacao h = listaDeLocacao[i];
		if(listaDeLocacao[i].cod > 0){
			if (h.cod == codigo){
			listaDeLocacao[i] = l;
			return 1;
			}
		}
	}
		
	return 0;
}
