struct st_dragao{
	int cod;
	char nome[20];
	int idade;
	float valorDiario;
	int unidadesEmEstoque;
	int idElemento;
	
};
typedef struct st_dragao Dragao;

int inicializarDragao();
int encerraDragao();
int salvarDragao(Dragao c, int encontrado);
int QuantidadeDragoes();
int obterDragaoPeloIndice(int indice, Dragao* d);
int obterDragaoPeloCodigo(int codigo, Dragao* d);
int ApagarDragaoPeloCodigo(int codigo);
int diminuirUnidade(int codigo);
int aumentarUnidadeDrag(int codigo);
int aumentarTamanhoD();
int reduzirTamanhoD();
int RETORNAMAXD();
int alterarDragao(int codigo, Dragao d);
