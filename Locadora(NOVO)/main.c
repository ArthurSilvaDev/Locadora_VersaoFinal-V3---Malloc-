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
		printf("2  - DRAG�ES\n");
		printf("3  - ELEMENTOS DE DRAG�ES\n");
		printf("4  - LOCA��ES\n");
		printf("\n::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
		printf("\n Digite a op��o desejada: ");
	
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
		printf("\n Digite a op��o desejada: ");
	
	
}
// FUNC�ES PARA GUERREIRO --- INICIO
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
	 		printf("\nC�digo:%d | Nome: %s | Reino: %s | Titulo: %s |\n",
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
	printf("Digite o c�digo do guerreiro que procura: ");
	scanf("%d", &resposta);
	
	Guerreiro g;
	
	if (obterGuerreiroPeloCodigo(resposta, &g) == 1){
		printf("C�digo:%i Nome: %s  Reino: %s  Titulo: %s \n",
			 g.cod, 
			 g.nome,
			 g.reino,
			 g.titulo);
	}
	 else{
	 	printf("C�digo n�o encontrado!\n");
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
			printf("Este guerreiro possui loca��o ativa!\n");
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
	printf("Digite o c�digo do Guerreiro que deseja alterar:");
	scanf("%d", &resposta);
	system("cls");
	Guerreiro g;
	if(obterGuerreiroPeloCodigo(resposta, &g) == 1){
		printf("C�digo:%i Nome: %s  Reino: %s  Titulo: %s \n",
			g.cod, 
			g.nome,
			g.reino,
			g.titulo);
	printf("Oque voc� deseja alterar?\n 1- NOME \n 2- REINO \n 3- TITULO \nResposta: ");
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
			printf("Digite o T�tulo: ");
			fflush(stdin);
			scanf("%[^\n]s", g.titulo);
			break;
	}
	if(alterarGuerreiro(g.cod, g) == 1){
		printf("\nO Gurreiro \"%s\" foi alterado com sucesso!\n", g.nome);
		system("pause");
	}
	else{
		printf("A altera��o falhou!");
		system("pause");
	}
	}
	else{
		printf("C�digo n�o encontrado!!\n");
		system("pause");
	}
}



// FUNC�ES PARA GUERREIRO --- FIM

// FUNC�ES PARA DRAGAO --- INICIO

void cadastrarDragao(){
	Dragao g;
	
	printf("\n CADASTRAR DRAGAO \n\n");
	
	printf("Digite o NOME do drag�o: ");
	fflush(stdin);
	scanf("%[^\n]s", g.nome);
	
	printf("Digite a IDADE do drag�o: ");
	scanf("%d", &g.idade);
	
	printf("Digite o VALOR DA DI�RIA do drag�o: R$ ");
	scanf("%f", &g.valorDiario);
	
	printf("Digite as UNIDADES EM ESTOQUE deste drag�o: ");
	scanf("%d", &g.unidadesEmEstoque);
	
	
	// CADASTRAR ELEMENTO
	
	listarElementos();
	
	int resposta;
	printf("Digite o c�digo do elemento do drag�o: ");
	scanf("%d", &resposta);
	
	Elemento e;
	int encontrado = 0;

	if (obterElementoPeloCodigo(resposta, &e) == 1){
		g.idElemento = resposta;
		 encontrado ++;
	}
	 else{
	 	printf("C�digo n�o encontrado!\n");
	 }
	
	if(salvarDragao(g, encontrado)==1){
		printf("\nO Drag�o \"%s\" foi cadastrado com sucesso!\n", g.nome);
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
	 printf("::::::::::::  DRAG�ES CADASTRADOS  :::::::::::::::::\n");
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	
		 int i;
	 for (i =0; i<QuantidadeDragoes(); i++){
	 	Dragao g;
	 	if (obterDragaoPeloIndice(i, &g) == 1){
	 		Elemento e;
			obterElementoPeloCodigo(g.idElemento, &e);
	 		printf("\nC�digo:%i | Nome: %s | Idade: %i | Di�ria: R$ %.2f | Estoque: %i | Elemento: %s | Vulnerabilidade: %s \n",
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
	printf("\n PESQUISAR DRAG�O \n\n");
	printf("Digite o c�digo do Drag�o que procura: ");
	scanf("%d", &resposta);
	
	
	Dragao d;	
	if (obterDragaoPeloCodigo(resposta, &d) == 1){
	
	  	printf("\nC�digo:%i Nome: %s  Idade: %i  Di�ria: R$ %.2f  Estoque: %i \n",
			 d.cod, 
			 d.nome,
			 d.idade,
			 d.valorDiario,
			 d.unidadesEmEstoque);
	}
	 else {
	 	printf("C�digo n�o encontrado!\n");
	 }
	system("pause");
	system("cls");
	 
	
}

void apagarDragao(){
	listarDragoes();
	int codigo;
	printf("Digite o codigo do Drag�o a ser apagado: ");
	scanf ("%d", &codigo);
	
	int ok = 0;
	int i;
	for (i = 0; i <= QuantidadeLocacao(); i++){
		Locacao y;
		obterLocacaoPeloCodigo(i, &y);
		if (y.codDragao == codigo){
			printf("Este Drag�o possui loca��o ativa!\n");
			ok++;
			break;
		}
	}
	if(ok == 0){
		if(ApagarDragaoPeloCodigo(codigo)==1){
			printf("\nDrag�o apagado com sucesso!\n");
			reduzirTamanhoD();
		}
	}
	else {
		printf("\nFalha ao apagar o Drag�o!\n");
	}
	system("pause");
	system("cls");
	
}

void alterarInfosDragao(){
	
	listarDragoes();
	int resposta;
	int resposta2;
	printf("Digite o c�digo do Drag�o que deseja alterar:");
	scanf("%d", &resposta);
	system("cls");
	Dragao d;
	if(obterDragaoPeloCodigo(resposta, &d) == 1){
		Elemento e;
	obterElementoPeloCodigo(d.idElemento, &e);
	
	printf("\nC�digo:%i Nome: %s  Idade: %i  Di�ria: R$ %.2f  Estoque: %i Elemento: %s Vulnerabilidade: %s \n \n",
			 d.cod, 
			 d.nome,
			 d.idade,
			 d.valorDiario,
			 d.unidadesEmEstoque,
			 e.nome,
			 e.vulnerabilidade);
	printf("Oque voc� deseja alterar?\n 1- NOME \n 2- IDADE \n 3- VALOR DI�RIA \n 4- UNIDADES EM ESTOQUE \n 5- ELEMENTO \nResposta: ");
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
			printf("Digite o Valor da Di�ria: R$ ");
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
		printf("\nO Drag�o \"%s\" foi alterado com sucesso!\n", d.nome);
		system("pause");
	}
	else{
		printf("A altera��o falhou!");
		system("pause");
	}
	}
	else{
		printf("C�digo n�o encontrado!! \n");
		system("pause");
	}
	
	
	
	
}

// FUNC�ES PARA DRAGAO --- FIM
// FUN��ES PARA ELEMENTO --- INICIO

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
	 		printf("\nC�digo:%i | Nome: %s | Vulnerabilidade: %s \n",
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
	printf("Digite o c�digo do Elemento que procura: ");
	scanf("%d", &resposta);
	
	
	Elemento e;
	if (obterElementoPeloCodigo(resposta, &e) == 1){
	
  		printf("\nC�digo:%i Nome: %s  Vulnerabilidade: %s \n",
			 e.cod, 
			 e.nome,
			 e.vulnerabilidade);
	}
	 else{
	 	printf("C�digo n�o encontrado!\n");
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
			printf("Existem drag�es deste elemento com cadastro ativo!\nFavor apagar os drag�es primeiro!\n");
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
	printf("Digite o c�digo do Elemento que deseja alterar:");
	scanf("%d", &resposta);
	system("cls");
	Elemento e;
	if(obterElementoPeloCodigo(resposta, &e) == 1){
		printf("\nC�digo:%i Nome: %s  Vulnerabilidade: %s \n",
			 e.cod, 
			 e.nome,
			 e.vulnerabilidade);
	printf("Oque voc� deseja alterar?\n 1- NOME \n 2- VULNERABILIDADE \nResposta: ");
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
		printf("A altera��o falhou!");
		system("pause");
	}
	}
	else{
		printf("A C�digo n�o encontrado!!\n");
		system("pause");
	}
	
	
}

//FUNC�ES PARA ELEMENTO -- FIM

//FUN��ES PARA LOCA��O -- INICIO
void realizarLocacao(){
	
	printf("\n CADASTRAR LOCA��O \n");
	
	listarGuerreiros();
	
	Locacao l;
	
	printf("Digite o C�DIGO DO GUERREIRO: ");
	scanf("%d", &l.codGuerreiro);
	
	system("cls");
	
	printf("\n CADASTRAR LOCA��O \n");
	
	listarDragoes();
	
	printf("Digite o CODIGO DO DRAGAO: ");
	scanf("%d", &l.codDragao);
	
	system("cls");
	
	printf("\n CADASTRAR LOCA��O \n");
	
	printf("Digite a DATA DE RETIRADA do drag�o: ");
	fflush(stdin);
	scanf("%[^\n]s", l.inicioLoc);
	
	printf("Digite a DATA DE ENTREGA do drag�o: ");
	fflush(stdin);
	scanf("%[^\n]s", l.fimLoc);
	
	printf("Pagamento realizado? (S/N): ");
	fflush(stdin);
	scanf("%[^\n]s", l.pago);
	
	
	if(salvarLocacao(l) == 1 && diminuirUnidade(l.codDragao)==1){
		printf("\nA Loca��o foi salva com sucesso ");
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
	 printf("::::::::::::  LOCA��ES CADASTRADSS  :::::::::::::::\n");
	 printf("::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
	 
	int i;
	for (i =0; i<QuantidadeLocacao(); i++){
	 	Locacao l;
	 	if (obterLocacaoPeloIndice(i, &l) == 1){
	 		Guerreiro g;
			obterGuerreiroPeloCodigo(l.codGuerreiro, &g);
			Dragao d;
	 		obterDragaoPeloCodigo(l.codDragao, &d);
	 		printf("\nC�digo:%i | Guerreiro: %s | Drag�o: %s | Inicio: %s | Fim: %s | Pago: %s \n",
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
	printf("\n PESQUISAR Loca��o \n\n");
	printf("Digite o c�digo da Loca��o que procura: ");
	scanf("%d", &resposta);
	
	
	Locacao e;
	
	if (obterLocacaoPeloCodigo(resposta, &e) == 1){
		Guerreiro g;
		obterGuerreiroPeloCodigo(e.codGuerreiro, &g);
		Dragao d;
		obterDragaoPeloCodigo(e.codDragao, &d);
			printf("\nC�digo:%i | Guerreiro: %s | Drag�o: %s | Inicio: %s | Fim: %s | Pago: %s \n",
			 e.cod, 
			 g.nome,
			 d.nome,
			 e.inicioLoc,
			 e.fimLoc,
			 e.pago);
  		
	}
	 else{
	 	printf("C�digo n�o encontrado!\n");
	 }
	system("pause");
	system("cls");	
	
}

void apagarLocacao(){
	
	listarLocacoes();
	int codigo;
	printf("Digite o codigo da Loca��o a ser apagado: ");
	scanf ("%d", &codigo);
	
	Locacao l;
	obterLocacaoPeloCodigo(codigo, &l);
	int codDrag = l.codDragao;
	if(ApagarLocacaoPeloCodigo(codigo)==1 && aumentarUnidadeDrag(codDrag) == 1){
		printf("\nLoca��o apagada com sucesso!\n");
		reduzirTamanhoL();
	}
	else {
		printf("\nFalha ao apagar a Loca��o!\n");
	}
	system("pause");
	system("cls");
	
	
}
void alterarInfosLocacao(){
	
	listarLocacoes();
	int resposta;
	int resposta2;
	printf("Digite o c�digo da Loca��o que deseja alterar:");
	scanf("%d", &resposta);
	system("cls");
	Locacao l;
	if (obterLocacaoPeloCodigo(resposta, &l) == 1){
		Guerreiro g;
	obterGuerreiroPeloCodigo(l.codGuerreiro, &g);
	Dragao d;
	obterDragaoPeloCodigo(l.codDragao, &d);
	 		printf("\nC�digo:%i | Guerreiro: %s | Drag�o: %s | Inicio: %s | Fim: %s | Pago: %s \n",
			 l.cod, 
			 g.nome,
			 d.nome,
			 l.inicioLoc,
			 l.fimLoc,
			 l.pago);
	printf("Oque voc� deseja alterar?\n 1- INICIO DA LOCA��O \n 2- FIM DA LOCA��O \n 3- PAGO? \n Para alterar o guerreiro ou o drag�o, favor efetuar a devolu��o e realizar nova loca��o! \nResposta: ");
	scanf("%d", &resposta2);
	
	switch(resposta2){
		
		case 1:
			printf("Digite o Inicio da Loca��o ");
			fflush(stdin);
			scanf("%[^\n]s", l.inicioLoc);
			break;
		case 2:
			printf("Digite o Fim da Loca��o: ");
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
		printf("A loca��o foi alterado com sucesso!\n");
		system("pause");
	}
	else{
		printf("A altera��o falhou!");
		system("pause");
	
	}
	}
	else{
		printf("C�digo n�o encontrado!!\n");
		system("pause");
	}
}

// FUN��ES PARA LOCA��O -- FIM

int main(int argc, char *argv[]) {
	
	// COLOCAR EM PORTUGU�S
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
				
			case 2:; // ESCOLHA DRAG�O
				int menu2 = 0;
				system("cls");
				do{ // SUBMENU DRAG�O
				   printf("::::::::::::::  SUB MENU DRAG�ES  ::::::::::::::::::\n");
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
				
				case 4:;//ESCOLHA LOCA��ES
				int menu4 = 0;
				system("cls");
				do{ // SUB MENU LOCA��ES
 				printf("::::::::::::::  SUB MENU LOCA��ES  ::::::::::::::::\n");
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
printf("Obrigado por utilizar nossos servi�os!");
	
	return 0;
}
