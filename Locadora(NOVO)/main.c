#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "dragao.h"
#include "elemento.h"
#include "guerreiro.h"
#include "locacao.h"

void mostraMenu(){
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		printf(":::::::::::::::::MENU PRINCIPAL:::::::::::::::::::::\n\n");
		printf("0  - SAIR \n");
		printf("1  - GUERREIROS\n");
		printf("2  - DRAGÕES\n");
		printf("3  - ELEMENTOS DE DRAGÕES\n");
		printf("4  - LOCAÇÕES\n");
		printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("\n Digite a opção desejada: ");
	
}

void subMenu(){
		printf(":::::::::::::  LOCADORA  KALEESI  ::::::::::::::::::\n");
		printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
		printf("0  - SAIR \n");
		printf("1  - CADASTRAR\n");
		printf("2  - LISTAR\n");
		printf("3  - ALTERAR\n");
		printf("4  - PESQUISAR\n");
		printf("5  - EXCLUIR\n");
		printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("\n Digite a opção desejada: ");
	
	
}
// FUNCÕES PARA GUERREIRO --- INICIO
void cadastrarGuerreiro(){
	
	Guerreiro g;
	printf("\n CADASTRAR GUERREIRO \n\n");
	
	printf("Digite o NOME do guerreiro: ");
	fflush(stdin);
	scanf("%[^\n]s", g.nome);
	
	printf("Digite o REINO do guerreiro: ");
	fflush(stdin);
	scanf("%[^\n]s", g.reino);
	
	printf("Digite o TITULO do guerreiro: ");
	fflush(stdin);
	scanf("%[^\n]s", g.titulo);
	
	if(salvarGuerreiro(g) == 1){
		printf("\nO Gurreiro \"%s\" foi cadastrado com sucesso!\n", g.nome);
		aumentarTamanhoG();
		system("pause");
	}
	else{
		printf("O cadastro falhou!");
		system("pause");
	}
	system ("cls");
	
	
}


void listarGuerreiros(){
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 printf(":::::::::::  GUERREIROS CADASTRADOS  :::::::::::::::\n");
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	 
	 int i;
	 for (i =0; i<QuantidadeGuerreiros(); i++){
	 	Guerreiro g;
	 	if (obterGuerreiroPeloIndice(i, &g) == 1){
	 		printf("\nCódigo:%d | Nome: %s | Reino: %s | Titulo: %s |\n",
			 g.cod, 
			 g.nome,
			 g.reino,
			 g.titulo);
		 }
	 }
		printf("\n      Capacidade da lista: %d", RETORNAMAXG());
	 printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
}

void pesquisarGuerreiro(){
	int resposta;
	printf("\n PESQUISAR GUERREIRO \n\n");
	printf("Digite o código do guerreiro que procura: ");
	scanf("%d", &resposta);
	
	Guerreiro g;
	
	if (obterGuerreiroPeloCodigo(resposta, &g) == 1){
		printf("Código:%i Nome: %s  Reino: %s  Titulo: %s \n",
			 g.cod, 
			 g.nome,
			 g.reino,
			 g.titulo);
	}
	 else{
	 	printf("Código não encontrado!\n");
	 }
	system("pause");
	system("cls");
  }

void apagarGuerreiro(){
	listarGuerreiros();
	int codigo;
	printf("Digite o codigo do Guerreiro a ser apagado: ");
	scanf ("%d", &codigo);
	
	int ok = 0;
	int i;
	for (i = 0; i <= QuantidadeLocacao(); i++){
		Locacao y;
		obterLocacaoPeloCodigo(i, &y);
		if (y.codGuerreiro == codigo){
			printf("Este guerreiro possui locação ativa!\n");
			ok++;
			break;
		}
		
	}
	if(ok == 0){
		if (ApagarGuerreiroPeloCodigo(codigo)==1 ){
		printf("\nGuerreiro apagado com sucesso!\n");
		reduzirTamanhoG();
		}
	}	
	else {
		printf("\nFalha ao apagar o Guerreiro!\n");
	}
	
	system("pause");
	system("cls");
	
}

void alterarInfosGuerreiro(){
	
	listarGuerreiros();
	int resposta;
	int resposta2;
	printf("Digite o código do Guerreiro que deseja alterar:");
	scanf("%d", &resposta);
	system("cls");
	Guerreiro g;
	if(obterGuerreiroPeloCodigo(resposta, &g) == 1){
		printf("Código:%i Nome: %s  Reino: %s  Titulo: %s \n",
			g.cod, 
			g.nome,
			g.reino,
			g.titulo);
	printf("Oque você deseja alterar?\n 1- NOME \n 2- REINO \n 3- TITULO \nResposta: ");
	scanf("%d", &resposta2);
	
	switch(resposta2){
		
		case 1:
			printf("Digite o Nome: ");
			fflush(stdin);
			scanf("%[^\n]s", g.nome);
			break;
		case 2:
			printf("Digite o Reino: ");
			fflush(stdin);
			scanf("%[^\n]s", g.reino);
			break;
		case 3:
			printf("Digite o Título: ");
			fflush(stdin);
			scanf("%[^\n]s", g.titulo);
			break;
	}
	if(alterarGuerreiro(g.cod, g) == 1){
		printf("\nO Gurreiro \"%s\" foi alterado com sucesso!\n", g.nome);
		system("pause");
	}
	else{
		printf("A alteração falhou!");
		system("pause");
	}
	}
	else{
		printf("Código não encontrado!!\n");
		system("pause");
	}
}



// FUNCÕES PARA GUERREIRO --- FIM

// FUNCÕES PARA DRAGAO --- INICIO

void cadastrarDragao(){
	Dragao g;
	
	printf("\n CADASTRAR DRAGAO \n\n");
	
	printf("Digite o NOME do dragão: ");
	fflush(stdin);
	scanf("%[^\n]s", g.nome);
	
	printf("Digite a IDADE do dragão: ");
	scanf("%d", &g.idade);
	
	printf("Digite o VALOR DA DIÁRIA do dragão: R$ ");
	scanf("%f", &g.valorDiario);
	
	printf("Digite as UNIDADES EM ESTOQUE deste dragão: ");
	scanf("%d", &g.unidadesEmEstoque);
	
	
	// CADASTRAR ELEMENTO
	
	listarElementos();
	
	int resposta;
	printf("Digite o código do elemento do dragão: ");
	scanf("%d", &resposta);
	
	Elemento e;
	int encontrado = 0;

	if (obterElementoPeloCodigo(resposta, &e) == 1){
		g.idElemento = resposta;
		 encontrado ++;
	}
	 else{
	 	printf("Código não encontrado!\n");
	 }
	
	if(salvarDragao(g, encontrado)==1){
		printf("\nO Dragão \"%s\" foi cadastrado com sucesso!\n", g.nome);
		aumentarTamanhoD();
		system("pause");
	}
	else{
		printf("O cadastro falhou!");
		system("pause");
	}
	system ("cls");
	
	
}

void listarDragoes(){
	
 	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 printf("::::::::::::  DRAGÕES CADASTRADOS  :::::::::::::::::\n");
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	
		 int i;
	 for (i =0; i<QuantidadeDragoes(); i++){
	 	Dragao g;
	 	if (obterDragaoPeloIndice(i, &g) == 1){
	 		Elemento e;
			obterElementoPeloCodigo(g.idElemento, &e);
	 		printf("\nCódigo:%i | Nome: %s | Idade: %i | Diária: R$ %.2f | Estoque: %i | Elemento: %s | Vulnerabilidade: %s \n",
			 g.cod, 
			 g.nome,
			 g.idade,
			 g.valorDiario,
			 g.unidadesEmEstoque,
			 e.nome,
			 e.vulnerabilidade);
		 }
	 }
	 printf("\n      Capacidade da lista: %d", RETORNAMAXD());
	 printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	
}

void pesquisarDragoes(){
	 
	int resposta;
	printf("\n PESQUISAR DRAGÃO \n\n");
	printf("Digite o código do Dragão que procura: ");
	scanf("%d", &resposta);
	
	
	Dragao d;	
	if (obterDragaoPeloCodigo(resposta, &d) == 1){
	
	  	printf("\nCódigo:%i Nome: %s  Idade: %i  Diária: R$ %.2f  Estoque: %i \n",
			 d.cod, 
			 d.nome,
			 d.idade,
			 d.valorDiario,
			 d.unidadesEmEstoque);
	}
	 else {
	 	printf("Código não encontrado!\n");
	 }
	system("pause");
	system("cls");
	 
	
}

void apagarDragao(){
	listarDragoes();
	int codigo;
	printf("Digite o codigo do Dragão a ser apagado: ");
	scanf ("%d", &codigo);
	
	int ok = 0;
	int i;
	for (i = 0; i <= QuantidadeLocacao(); i++){
		Locacao y;
		obterLocacaoPeloCodigo(i, &y);
		if (y.codDragao == codigo){
			printf("Este Dragão possui locação ativa!\n");
			ok++;
			break;
		}
	}
	if(ok == 0){
		if(ApagarDragaoPeloCodigo(codigo)==1){
			printf("\nDragão apagado com sucesso!\n");
			reduzirTamanhoD();
		}
	}
	else {
		printf("\nFalha ao apagar o Dragão!\n");
	}
	system("pause");
	system("cls");
	
}

void alterarInfosDragao(){
	
	listarDragoes();
	int resposta;
	int resposta2;
	printf("Digite o código do Dragão que deseja alterar:");
	scanf("%d", &resposta);
	system("cls");
	Dragao d;
	if(obterDragaoPeloCodigo(resposta, &d) == 1){
		Elemento e;
	obterElementoPeloCodigo(d.idElemento, &e);
	
	printf("\nCódigo:%i Nome: %s  Idade: %i  Diária: R$ %.2f  Estoque: %i Elemento: %s Vulnerabilidade: %s \n \n",
			 d.cod, 
			 d.nome,
			 d.idade,
			 d.valorDiario,
			 d.unidadesEmEstoque,
			 e.nome,
			 e.vulnerabilidade);
	printf("Oque você deseja alterar?\n 1- NOME \n 2- IDADE \n 3- VALOR DIÁRIA \n 4- UNIDADES EM ESTOQUE \n 5- ELEMENTO \nResposta: ");
	scanf("%d", &resposta2);
	
	switch(resposta2){
		
		case 1:
			printf("Digite o Nome: ");
			fflush(stdin);
			scanf("%[^\n]s", d.nome);
			break;
		case 2:
			printf("Digite a Idade: ");
			scanf("%d", &d.idade);
			break;
		case 3:
			printf("Digite o Valor da Diária: R$ ");
			scanf("%f", &d.valorDiario);
			break;
		case 4: 
			printf("Digite as unidades em estoque: ");
			scanf("%d", &d.unidadesEmEstoque);
			break;
		case 5:
			listarElementos();
			printf("Digite o codigo do elemento: ");
			scanf("%d", &d.idElemento);
	}
	if(alterarDragao(d.cod, d) == 1){
		printf("\nO Dragão \"%s\" foi alterado com sucesso!\n", d.nome);
		system("pause");
	}
	else{
		printf("A alteração falhou!");
		system("pause");
	}
	}
	else{
		printf("Código não encontrado!! \n");
		system("pause");
	}
	
	
	
	
}

// FUNCÕES PARA DRAGAO --- FIM
// FUNÇÕES PARA ELEMENTO --- INICIO

void cadastrarElemento(){
		
	Elemento g;
	printf("\n CADASTRAR ELEMENTO \n\n");
	
	printf("Digite o NOME do elemento: ");
	fflush(stdin);
	scanf("%[^\n]s", g.nome);
	
	printf("Digite o VULNERABILIDADE do elemento: ");
	fflush(stdin);
	scanf("%[^\n]s", g.vulnerabilidade);
	
	
	if(salvarElemento(g) == 1){
		printf("\nO Elemento \"%s\" foi cadastrado com sucesso!\n", g.nome);
		aumentarTamanhoE();
		system("pause");
	}
	else{
		printf("O cadastro falhou!");
		system("pause");
	}
	system ("cls");
}

void listarElementos(){
	
 	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 printf("::::::::::::  ELEMENTOS CADASTRADOS  :::::::::::::::\n");
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	 
	  int i;
	 for (i =0; i<QuantidadeElementos(); i++){
	 	Elemento e;
	 	if (obterElementoPeloIndice(i, &e) == 1){
	 		printf("\nCódigo:%i | Nome: %s | Vulnerabilidade: %s \n",
			 e.cod, 
			 e.nome,
			 e.vulnerabilidade);
		 }
	 }
	 printf("\n      Capacidade da lista: %d", RETORNAMAXE());
	 printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 
}

void pesquisarElementos(){
		 
	int resposta;
	printf("\n PESQUISAR ELEMENTO \n\n");
	printf("Digite o código do Elemento que procura: ");
	scanf("%d", &resposta);
	
	
	Elemento e;
	if (obterElementoPeloCodigo(resposta, &e) == 1){
	
  		printf("\nCódigo:%i Nome: %s  Vulnerabilidade: %s \n",
			 e.cod, 
			 e.nome,
			 e.vulnerabilidade);
	}
	 else{
	 	printf("Código não encontrado!\n");
	 }
	system("pause");
	system("cls");	
}

void apagarElemento(){

	listarElementos();
	int codigo;
	printf("Digite o codigo do Elemento a ser apagado: ");
	scanf ("%d", &codigo);
	
	int ok = 0;
	int i;
	for (i = 0; i <= QuantidadeDragoes(); i++){
		Dragao y;
		obterDragaoPeloCodigo(i, &y);
		if (y.idElemento == codigo){
			printf("Existem dragões deste elemento com cadastro ativo!\nFavor apagar os dragões primeiro!\n");
			ok++;
			break;
		}
	}
	
	if(ok == 0){
		if(ApagarElementoPeloCodigo(codigo)==1){
			printf("\nElemento apagado com sucesso!\n");
			reduzirTamanhoE();
		}
	}
	else {
		printf("\nFalha ao apagar o Elemento!\n");
	}

	system("pause");
	system("cls");
	
}

void alterarInfosElemento(){
	
	listarElementos();
	int resposta;
	int resposta2;
	printf("Digite o código do Elemento que deseja alterar:");
	scanf("%d", &resposta);
	system("cls");
	Elemento e;
	if(obterElementoPeloCodigo(resposta, &e) == 1){
		printf("\nCódigo:%i Nome: %s  Vulnerabilidade: %s \n",
			 e.cod, 
			 e.nome,
			 e.vulnerabilidade);
	printf("Oque você deseja alterar?\n 1- NOME \n 2- VULNERABILIDADE \nResposta: ");
	scanf("%d", &resposta2);
	
	switch(resposta2){
		
		case 1:
			printf("Digite o Nome: ");
			fflush(stdin);
			scanf("%[^\n]s", e.nome);
			break;
		case 2:
			printf("Digite a Vulnerabilidade: ");
			fflush(stdin);
			scanf("%[^\n]s", e.vulnerabilidade);
			break;
	}
	if(alterarElemento(e.cod, e) == 1){
		printf("\nO Elemento \"%s\" foi alterado com sucesso!\n", e.nome);
		system("pause");
	}
	else{
		printf("A alteração falhou!");
		system("pause");
	}
	}
	else{
		printf("A Código não encontrado!!\n");
		system("pause");
	}
	
	
}

//FUNCÕES PARA ELEMENTO -- FIM

//FUNÇÕES PARA LOCAÇÃO -- INICIO
void realizarLocacao(){
	
	printf("\n CADASTRAR LOCAÇÃO \n");
	
	listarGuerreiros();
	
	Locacao l;
	
	printf("Digite o CÓDIGO DO GUERREIRO: ");
	scanf("%d", &l.codGuerreiro);
	
	system("cls");
	
	printf("\n CADASTRAR LOCAÇÃO \n");
	
	listarDragoes();
	
	printf("Digite o CODIGO DO DRAGAO: ");
	scanf("%d", &l.codDragao);
	
	system("cls");
	
	printf("\n CADASTRAR LOCAÇÃO \n");
	
	printf("Digite a DATA DE RETIRADA do dragão: ");
	fflush(stdin);
	scanf("%[^\n]s", l.inicioLoc);
	
	printf("Digite a DATA DE ENTREGA do dragão: ");
	fflush(stdin);
	scanf("%[^\n]s", l.fimLoc);
	
	printf("Pagamento realizado? (S/N): ");
	fflush(stdin);
	scanf("%[^\n]s", l.pago);
	
	
	if(salvarLocacao(l) == 1 && diminuirUnidade(l.codDragao)==1){
		printf("\nA Locação foi salva com sucesso ");
		aumentarTamanhoL();
		system("pause");
	}
	else{
		printf("O cadastro falhou!");
		system("pause");
	}
	system ("cls");

}

void listarLocacoes(){
	 
	 
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 printf("::::::::::::  LOCAÇÕES CADASTRADSS  :::::::::::::::\n");
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	 
	int i;
	for (i =0; i<QuantidadeLocacao(); i++){
	 	Locacao l;
	 	if (obterLocacaoPeloIndice(i, &l) == 1){
	 		Guerreiro g;
			obterGuerreiroPeloCodigo(l.codGuerreiro, &g);
			Dragao d;
	 		obterDragaoPeloCodigo(l.codDragao, &d);
	 		printf("\nCódigo:%i | Guerreiro: %s | Dragão: %s | Inicio: %s | Fim: %s | Pago: %s \n",
			 l.cod, 
			 g.nome,
			 d.nome,
			 l.inicioLoc,
			 l.fimLoc,
			 l.pago);
		 }
	 }
	 printf("\n      Capacidade da lista: %d", RETORNAMAXL());
	 printf("\n\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
	 
}

void pesquisarLocacao(){
			 
	int resposta;
	printf("\n PESQUISAR Locação \n\n");
	printf("Digite o código da Locação que procura: ");
	scanf("%d", &resposta);
	
	
	Locacao e;
	
	if (obterLocacaoPeloCodigo(resposta, &e) == 1){
		Guerreiro g;
		obterGuerreiroPeloCodigo(e.codGuerreiro, &g);
		Dragao d;
		obterDragaoPeloCodigo(e.codDragao, &d);
			printf("\nCódigo:%i | Guerreiro: %s | Dragão: %s | Inicio: %s | Fim: %s | Pago: %s \n",
			 e.cod, 
			 g.nome,
			 d.nome,
			 e.inicioLoc,
			 e.fimLoc,
			 e.pago);
  		
	}
	 else{
	 	printf("Código não encontrado!\n");
	 }
	system("pause");
	system("cls");	
	
}

void apagarLocacao(){
	
	listarLocacoes();
	int codigo;
	printf("Digite o codigo da Locação a ser apagado: ");
	scanf ("%d", &codigo);
	
	Locacao l;
	obterLocacaoPeloCodigo(codigo, &l);
	int codDrag = l.codDragao;
	if(ApagarLocacaoPeloCodigo(codigo)==1 && aumentarUnidadeDrag(codDrag) == 1){
		printf("\nLocação apagada com sucesso!\n");
		reduzirTamanhoL();
	}
	else {
		printf("\nFalha ao apagar a Locação!\n");
	}
	system("pause");
	system("cls");
	
	
}
void alterarInfosLocacao(){
	
	listarLocacoes();
	int resposta;
	int resposta2;
	printf("Digite o código da Locação que deseja alterar:");
	scanf("%d", &resposta);
	system("cls");
	Locacao l;
	if (obterLocacaoPeloCodigo(resposta, &l) == 1){
		Guerreiro g;
	obterGuerreiroPeloCodigo(l.codGuerreiro, &g);
	Dragao d;
	obterDragaoPeloCodigo(l.codDragao, &d);
	 		printf("\nCódigo:%i | Guerreiro: %s | Dragão: %s | Inicio: %s | Fim: %s | Pago: %s \n",
			 l.cod, 
			 g.nome,
			 d.nome,
			 l.inicioLoc,
			 l.fimLoc,
			 l.pago);
	printf("Oque você deseja alterar?\n 1- INICIO DA LOCAÇÃO \n 2- FIM DA LOCAÇÃO \n 3- PAGO? \n Para alterar o guerreiro ou o dragão, favor efetuar a devolução e realizar nova locação! \nResposta: ");
	scanf("%d", &resposta2);
	
	switch(resposta2){
		
		case 1:
			printf("Digite o Inicio da Locação ");
			fflush(stdin);
			scanf("%[^\n]s", l.inicioLoc);
			break;
		case 2:
			printf("Digite o Fim da Locação: ");
			fflush(stdin);
			scanf("%[^\n]s", l.fimLoc);
			break;
		case 3:
			printf("Foi realizado o Pagamento? ");
			fflush(stdin);
			scanf("%[^\n]s", l.pago);
			break;
	}
	if(alterarLocacao(l.cod, l) == 1){
		printf("A locação foi alterado com sucesso!\n");
		system("pause");
	}
	else{
		printf("A alteração falhou!");
		system("pause");
	
	}
	}
	else{
		printf("Código não encontrado!!\n");
		system("pause");
	}
}

// FUNÇÕES PARA LOCAÇÃO -- FIM

int main(int argc, char *argv[]) {
	
	// COLOCAR EM PORTUGUÊS
	setlocale(LC_ALL, "Portuguese");
	
	inicializarGuerreiros();
	inicializarDragao();
	inicializarElementos();
	inicializarLocacao();
	
	int menu = 0;
	system("cls");
	do{
		mostraMenu();
		scanf("%i", &menu);
		system ("cls");
		switch(menu){
			
			case 1:; //ESCOLHA GUERREIRO
				int menu1 = 0;
				system("cls");
				do{ // SUBMENU GUERREIRO
				   printf(":::::::::::::  SUB MENU GUERREIROS  ::::::::::::::::\n");
				   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
			       subMenu();
				   scanf("%i", &menu1);
				   system ("cls");
				   
				   switch(menu1){ 
				   	
				   	case 1:
				   		cadastrarGuerreiro();
				   		break;
			   		case 2:
			   			listarGuerreiros();
		   				system("pause");
			   			break;
			   		case 3:
			   			alterarInfosGuerreiro();
			   			break;
		   			case 4:
		   				pesquisarGuerreiro();
		   				break;
	   				case 5:
	   					apagarGuerreiro();
	   					break;
				   }
				   system("cls");
				}while(menu1 != 0);
				break;
				
			case 2:; // ESCOLHA DRAGÃO
				int menu2 = 0;
				system("cls");
				do{ // SUBMENU DRAGÃO
				   printf("::::::::::::::  SUB MENU DRAGÕES  ::::::::::::::::::\n");
				   printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
			       subMenu();
				   scanf("%i", &menu2);
				   system ("cls");
				   
				   switch(menu2){
				   	
				   	case 1:
				   		cadastrarDragao();
				   		break;
				   	;
				   	case 2:
				   		listarDragoes();
				   		system("pause");
				   		break;
				   	case 3:
				   		alterarInfosDragao();
			   			break;
			   		case 4:
			   			pesquisarDragoes();
			   			break;
		   			case 5:
		   				apagarDragao();
		   				break;
				   		
					
					} system("cls");
				}while(menu2 != 0);
				break;
				
				case 3:; // ESCOLHA ELEMENTO
				int menu3 = 0;
				system("cls");	
				
				do{//SUB MENUELEMENTOS
	   			printf("::::::::::::::  SUB MENU ELEMENTOS  ::::::::::::::::\n");
	   			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
       			subMenu();
	   			scanf("%i", &menu3);
 			   	system ("cls");
				
				switch(menu3){
					case 1:
						 cadastrarElemento();
						 break;
					
					case 2:
						listarElementos();
						system("pause");
						break;
					case 3:
						alterarInfosElemento();
			   			break;
					case 4:
						pesquisarElementos();
						break;
					case 5:
						apagarElemento();
						break;
					
				}
				system("cls");
				}while(menu3 != 0);
				break;
				
				case 4:;//ESCOLHA LOCAÇÕES
				int menu4 = 0;
				system("cls");
				do{ // SUB MENU LOCAÇÕES
 				printf("::::::::::::::  SUB MENU LOCAÇÕES  ::::::::::::::::\n");
	   			printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
       			subMenu();
	   			scanf("%i", &menu4);
 			   	system ("cls");
 			   	
 			   	switch(menu4){
 			   		case 1:
 			   			realizarLocacao();	
 			   			break;
 			   		
 			   		case 2:
 			   			listarLocacoes();
 			   			system("pause");
						break;
					case 3:
						alterarInfosLocacao();
			   			break;
					case 4:
						pesquisarLocacao();
						break;
					case 5:
						apagarLocacao();
						break;
					}
 			   	system("cls");
				}while(menu4 !=0);
				break;
				
					
			}
				
		
}while(menu != 0);


// Encerrar tudo:
encerraGuerreiros();
encerraElementos();
encerraDragao();
encerraLocacao();
printf("Obrigado por utilizar nossos serviços!");
	
	return 0;
}
