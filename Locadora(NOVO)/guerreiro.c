#include "guerreiro.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int MAX_GUERREIRO = 5;
int qtdGuerreiros = 0;
int codigoAtualG = 1;

Guerreiro *listaDeGuerreiros;

int inicializarGuerreiros(){
	
	listaDeGuerreiros = (Guerreiro*) malloc (MAX_GUERREIRO * sizeof(Guerreiro));
	if (listaDeGuerreiros == NULL){
		return 0;
	}
	
	int i;
	for (i = 0; i < MAX_GUERREIRO; i++)
		{
			
			listaDeGuerreiros[i].nome[0] = '\0';
			listaDeGuerreiros[i].reino[0] = '\0';
			listaDeGuerreiros[i].titulo[0] = '\0';
			listaDeGuerreiros[i].cod = 0;
			
	}
	strcpy(listaDeGuerreiros[0].nome,"Arthur");
	strcpy(listaDeGuerreiros[0].reino,"Osorius");
	strcpy(listaDeGuerreiros[0].titulo,"Rei");
	listaDeGuerreiros[0].cod = codigoAtualG;
	codigoAtualG++;
	qtdGuerreiros++;
	
	strcpy(listaDeGuerreiros[1].nome,"Philip");
	strcpy(listaDeGuerreiros[1].reino,"Winterfell");
	strcpy(listaDeGuerreiros[1].titulo,"Cavaleiro");
	listaDeGuerreiros[1].cod = codigoAtualG;
	codigoAtualG++;
	qtdGuerreiros++;
	
	
}	

int encerraGuerreiros(){
 free(listaDeGuerreiros);
 listaDeGuerreiros = NULL;
}

int salvarGuerreiro(Guerreiro c){
	
	if (qtdGuerreiros<MAX_GUERREIRO){
		c.cod = codigoAtualG++;
		listaDeGuerreiros[qtdGuerreiros] = c;
		qtdGuerreiros++;
		return 1; // funcionou
	}
	
	else
		return 0; //falhou
	
	
}

int QuantidadeGuerreiros(){
	
	return qtdGuerreiros;
}

int obterGuerreiroPeloIndice(int indice, Guerreiro* g){
	*g = listaDeGuerreiros[indice];
	return 1;
	
}

int obterGuerreiroPeloCodigo(int codigo, Guerreiro* g){
	
	int i;
	for (i=0; i <qtdGuerreiros; i++){
		*g = listaDeGuerreiros[i];
		if (g->cod == codigo){
			*g = listaDeGuerreiros[i];
			return 1;
		}
		
	}
	return 0;
	
}

int ApagarGuerreiroPeloCodigo(int codigo){
	int i;
	for(i=0; i <qtdGuerreiros; i++){
		if (listaDeGuerreiros[i].cod == codigo){
			listaDeGuerreiros[i] = listaDeGuerreiros[qtdGuerreiros-1];
			listaDeGuerreiros[qtdGuerreiros - 1].cod = 0;
			qtdGuerreiros--;
			return 1; //funcionou
		}
	}
	return 0; //falhou
}

int aumentarTamanhoG(){
	if (qtdGuerreiros == MAX_GUERREIRO){
		MAX_GUERREIRO += 2;
		Guerreiro* novaListaA = (Guerreiro*) realloc (listaDeGuerreiros, MAX_GUERREIRO * sizeof(Guerreiro));
		if(novaListaA != NULL){
			listaDeGuerreiros =  novaListaA;
			free(novaListaA);
			novaListaA = NULL;
			return 1;
		}
		
	}
	}
	
int reduzirTamanhoG(){
	if (qtdGuerreiros < (MAX_GUERREIRO * 0.4)){
		MAX_GUERREIRO = qtdGuerreiros +2;
		Guerreiro* novaListaR = (Guerreiro*) realloc (listaDeGuerreiros, MAX_GUERREIRO * sizeof(Guerreiro));
		if(novaListaR != NULL){
			listaDeGuerreiros = novaListaR;
			free(novaListaR);
			novaListaR = NULL;
			return 1;
		}
		
	}
	
}

int RETORNAMAXG(){
	return MAX_GUERREIRO;
}

int alterarGuerreiro(int codigo, Guerreiro g){
	
	int i;
	for (i=0; i <qtdGuerreiros; i++){
		Guerreiro h = listaDeGuerreiros[i];
		if (h.cod == codigo){
			listaDeGuerreiros[i] = g;
			return 1;
		}
		
	}
	return 0;
}
