struct st_guerreiro{
	int cod;
	char nome [20];
	char reino [20];
	char titulo [20];
	
};
typedef struct st_guerreiro Guerreiro;

int inicializarGuerreiros();
int encerraGuerreiros();
int salvarGuerreiro(Guerreiro c);
int QuantidadeGuerreiros();
int obterGuerreiroPeloIndice(int indice, Guerreiro* g);
int obterGuerreiroPeloCodigo(int codigo, Guerreiro* g);
int ApagarGuerreiroPeloCodigo(int codigo);
int aumentarTamanhoG();
int reduzirTamanhoG();
int RETORNAMAXG();
int alterarGuerreiro(int codigo, Guerreiro g);
