typedef struct cliente{
    int codigo, telefone, celular;
    char nome[50];
    char empresa[50];
    char departamento[50];
    char email[50];
}CLIENTE;

typedef struct estrut *Lista;

Lista *cria();

int insere(Lista *list, CLIENTE cl);

int remov(Lista *list, int cli);

int consulta_nome(Lista *list, char* nome, CLIENTE *cli);

int consulta_pos(Lista *list, int pos, CLIENTE *cli);

int consulta_ident(Lista *list, int ident, CLIENTE *cli);

int edita(Lista *list, int ident, CLIENTE cli);


