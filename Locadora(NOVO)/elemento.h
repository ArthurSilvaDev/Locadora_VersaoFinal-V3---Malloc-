struct st_elemento{
	int cod;
	char nome [20];
	char vulnerabilidade [20];
	
};
typedef struct st_elemento Elemento;


int inicializarElementos();
int encerraElementos();
int salvarElemento(Elemento c);
int QuantidadeElementos();
int obterElementoPeloIndice(int indice, Elemento* e);
int obterElementoPeloCodigo(int codigo, Elemento* e);
int ApagarElementoPeloCodigo(int codigo);
void listarElementos();
int aumentarTamanhoE();
int reduzirTamanhoE();
int RETORNAMAXE();
int alterarElemento(int codigo, Elemento e);

