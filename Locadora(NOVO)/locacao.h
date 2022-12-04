struct st_locacao{
	int cod;
	char pago[10];
	char inicioLoc[20];
	char fimLoc [20];
	int codGuerreiro;
	int codDragao;
	
};
typedef struct st_locacao Locacao;
int inicializarLocacao();
int encerraLocacao();
int salvarLocacao(Locacao c);
int QuantidadeLocacao();
int obterLocacaoPeloIndice(int indice, Locacao* l);
int obterLocacaoPeloCodigo(int codigo, Locacao* l);
int ApagarLocacaoPeloCodigo(int codigo);
int aumentarTamanhoL();
int reduzirTamanhoL();
int RETORNAMAXL();
int alterarLocacao(int codigo, Locacao l);
