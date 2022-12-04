#include "elemento.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int MAX_ELEMENTO = 5;
int qtdElementos = 0;
int codigoAtualE = 1;

Elemento *listaDeElementos;

int inicializarElementos(){
	
	listaDeElementos = (Elemento*) malloc (MAX_ELEMENTO * sizeof(Elemento));
	if (listaDeElementos == NULL){
		return 0;
	}
	
	
		int i;
	for (i = 0; i < MAX_ELEMENTO; i++)
		{
			listaDeElementos[i].cod = 0;
			strcpy(listaDeElementos[i].nome, "");
			strcpy(listaDeElementos[i].vulnerabilidade, "");

	}
	strcpy(listaDeElementos[0].nome, "Ar");
	strcpy(listaDeElementos[0].vulnerabilidade, "Terra");
	listaDeElementos[0].cod = codigoAtualE;
	qtdElementos++;
	codigoAtualE++;
	
	strcpy(listaDeElementos[1].nome, "Raio");
	strcpy(listaDeElementos[1].vulnerabilidade, "Plasma");
	listaDeElementos[1].cod = codigoAtualE;
	qtdElementos++;
	codigoAtualE++;
}
int encerraElementos(){
	free(listaDeElementos);
}
int salvarElemento(Elemento c){
	
		if (qtdElementos<MAX_ELEMENTO){
		c.cod = codigoAtualE++;
		listaDeElementos[qtdElementos] = c;
		qtdElementos++;
		return 1; // funcionou
	}
	
	else
		return 0; //falhou
	
	
}
int QuantidadeElementos(){
	return qtdElementos;
}
int obterElementoPeloIndice(int indice, Elemento* e){
	*e = listaDeElementos[indice];
	return 1;
}
int obterElementoPeloCodigo(int codigo, Elemento* e){
	
	int i;
	for (i=0; i <qtdElementos; i++){
		*e = listaDeElementos[i];
		if (e->cod == codigo){
			return 1;
			}
		}
	return 0;
	}
	
int ApagarElementoPeloCodigo(int codigo){
		int i;
	for(i=0; i <qtdElementos; i++){
		if (listaDeElementos[i].cod == codigo){
			listaDeElementos[i] = listaDeElementos[qtdElementos-1];
			listaDeElementos[qtdElementos - 1].cod = 0;
			qtdElementos--;
			return 1; //funcionou
		}
	}
	return 0; //falhou
}

int aumentarTamanhoE(){
	if (qtdElementos == MAX_ELEMENTO){
		MAX_ELEMENTO += 2;
		Elemento* novaListaA = (Elemento*) realloc (listaDeElementos, MAX_ELEMENTO * sizeof(Elemento));
		if(novaListaA != NULL){
			listaDeElementos =  novaListaA;
			free(novaListaA);
			novaListaA = NULL;
			return 1;
		}
		
	}
	}
	
int reduzirTamanhoE(){
	if (qtdElementos < (MAX_ELEMENTO * 0.4)){
		MAX_ELEMENTO = qtdElementos +2;
		Elemento* novaListaR = (Elemento*) realloc (listaDeElementos, MAX_ELEMENTO * sizeof(Elemento));
		if(novaListaR != NULL){
			listaDeElementos = novaListaR;
			free(novaListaR);
			novaListaR = NULL;
			return 1;
		}
		
	}
	
}

int RETORNAMAXE(){
	return MAX_ELEMENTO;
}


int alterarElemento(int codigo, Elemento e){
	
	int i;
	for (i=0; i <qtdElementos; i++){
		Elemento h = listaDeElementos[i];
		if (h.cod == codigo){
			listaDeElementos[i] = e;
			return 1;
		}
		
	}
	return 0;
}

