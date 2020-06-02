#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "projeto.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    char opt2;
    int i, x;
    int elementos_na_lista=0;//VARI�VEL QUE CONTROLA O N�MERO DE ELEMENTOS NA LISTA
    int opt=0;//VARI�VEL QUE CONTROLA AS OP��ES ESCOLHIDAS PELO USU�RIO
    int cod;//C�DIGO INSERIDO PARA PESQUISA
    Lista *list;
    FILE *f;
////////////////////////LISTA CRIADA//////////////////////////////
    list=cria();
    CLIENTE elemento;
///////////////////////--------------------///////////////////////

////////////////RECUPERANDO OS DADOS//////////////////////
    f=fopen("arquivo.txt","rb");
    if(f==NULL){
        printf("N�o foi poss�vel ler um arquivo, um novo ser� criado\n");
        system("pause");
        //exit(1);
    }
    else{
        while(feof(f)==0){//INSERE CADA ELEMENTO LIDO NA LISTA
            fread(&elemento, sizeof(CLIENTE),1,f);
            x=insere(list,elemento);
            elementos_na_lista++;
        }
        x=remov(list, elemento.codigo);//REMOVE O �LTIMO ELEMENTO QUE EST� DUPLICADO
        elementos_na_lista--;
    }
    int fclose(FILE *f);
///////////////---------------------//////////////////////////

    while(opt!=7){
        //////////////MENU////////////////////////
        system("cls");

        printf("////////////--------ACME S.A.--------////////////\n\n");
        printf("Registro de clientes\n");
        printf("Feito por Gabriel Santos S�\n\n");
        printf("1 - Inserir um cliente na lista\n");
        printf("2 - Editar um cliente da lista\n");
        printf("3 - Remover um cliente da lista\n");
        printf("4 - Relat�rio completo da lista\n");
        printf("5 - Relat�rio de clientes por c�digo identificador\n");
        printf("6 - Relat�rio de clientes por nome\n");
        printf("7 - Sair do programa\n\n");

        printf("Insira a op��o desejada: ");
        scanf("%d", &opt);
        /////////////-----------------------////////////////////////

        switch(opt){
            case 1:
                ///////////////OP��O DE INSER��O/////////////////////////
                system("cls");
                printf("\nInsira o c�digo do cliente: ");
                scanf("%d", &elemento.codigo);
                printf("\nInsira o nome do cliente: ");
                fflush(stdin);
                fgets(elemento.nome, 90, stdin);
                printf("\nInsira a empresa do cliente: ");
                fflush(stdin);
                fgets(elemento.empresa, 90, stdin);
                printf("\nInsira o departamento do cliente: ");
                fflush(stdin);
                fgets(elemento.departamento, 90, stdin);
                printf("\nInsira o email do cliente: ");
                fflush(stdin);
                fgets(elemento.email, 90, stdin);
                printf("\nInsira o celular do cliente: ");
                scanf("%d", &elemento.celular);
                printf("\nInsira o telefone do cliente: ");
                scanf("%d", &elemento.telefone);

                x=insere(list, elemento);

                if(x){
                    printf("Sucesso em inserir\n");
                    elementos_na_lista++;
                    system("pause");
                }else{
                    printf("Falha em inserir\n");
                    system("pause");
                }
                ///////////////////////////-----------////////////////////////////
                break;

            case 2:
                //////////////////OP��O EDI��O///////////////////////
                system("cls");
                printf("Insira o c�digo identificador do cliente a ser editado: ");
                scanf("%d", &cod);
                x=consulta_ident(list, cod, &elemento);
                system("cls");
                printf("\nNome: %s", elemento.nome);
                printf("\nEmpresa: %s", elemento.empresa);
                printf("\nDepartamento: %s", elemento.departamento);
                printf("\nEmail: %s", elemento.email);
                printf("\nCelular: %d", elemento.celular);
                printf("\nTelefone: %d\n", elemento.celular);
                printf("\n\nTem certeza que deseja editar esse cliente?\n");
                printf("S para sim\n");
                printf("N para n�o\n");
                fflush(stdin);
                scanf("%c", &opt2);
                if(opt2=='S'){
                    printf("\nInsira o c�digo do cliente: ");
                    scanf("%d", &elemento.codigo);
                    printf("\nInsira o nome do cliente: ");
                    fgets(elemento.nome, 90, stdin);
                    scanf("%s", elemento.nome);
                    printf("\nInsira a empresa do cliente: ");
                    scanf("%s", elemento.empresa);
                    fgets(elemento.empresa, 90, stdin);
                    printf("\nInsira o departamento do cliente: ");
                    fgets(elemento.departamento, 90, stdin);
                    printf("\nInsira o email do cliente: ");
                    fgets(elemento.email, 90, stdin);
                    printf("\nInsira o celular do cliente: ");
                    scanf("%d", &elemento.celular);
                    printf("\nInsira o telefone do cliente: ");
                    scanf("%d", &elemento.telefone);

                    x=edita(list, cod, elemento);

                    if(x){
                        printf("Sucesso em editar\n");
                        system("pause");
                    }else{
                        printf("Falha em editar\n");
                        system("pause");
                    }
                }else{
                    break;
                }
                //////////////////--------------------//////////////////////
                break;

            case 3:
                //////////////////REMO��O///////////////////////
                system("cls");
                printf("Insira o c�digo identificador do cliente a ser removido: ");
                scanf("%d", &cod);
                system("cls");
                printf("\nNome: %s", elemento.nome);
                printf("\nEmpresa: %s", elemento.empresa);
                printf("\nDepartamento: %s", elemento.departamento);
                printf("\nEmail: %s", elemento.email);
                printf("\nCelular: %d", elemento.celular);
                printf("\nTelefone: %d\n", elemento.celular);
                printf("\n\nTem certeza que deseja remover esse cliente?\n");
                printf("S para sim\n");
                printf("N para n�o\n");
                fflush(stdin);
                scanf("%c", &opt2);
                if(opt2=='S'){
                    x=remov(list, cod);
                    if(x){
                        system("cls");
                        printf("Cliente removido\n");
                        elementos_na_lista--;
                        system("pause");
                    }else{
                        system("cls");
                        printf("Imposs�vel remover cliente\n");
                        system("pause");
                    }
                }else{
                    break;
                }
                //////////////////--------------------///////////////////////
                break;

            case 4:
                //////////////////OP��O RELATORIO TOTAL///////////////////////
                system("cls");
                for(i=1;i<=elementos_na_lista;i++){
                    x=consulta_pos(list,i,&elemento);
                    printf("Elemento %d, C�digo: %d\n", i,elemento.codigo);
                }
                system("pause");
                //////////////////--------------------///////////////////////
                break;

            case 5:
                //////////////////OP��O RELATORIO IDENTF///////////////////////
                system("cls");
                printf("Insira o c�digo identificador do cliente: ");
                scanf("%d", &cod);
                x=consulta_ident(list, cod, &elemento);
                printf("\nNome: %s", elemento.nome);
                printf("\nEmpresa: %s", elemento.empresa);
                printf("\nDepartamento: %s", elemento.departamento);
                printf("\nEmail: %s", elemento.email);
                printf("\nCelular: %d", elemento.celular);
                printf("\nTelefone: %d\n", elemento.celular);
                system("pause");
                //////////////////--------------------///////////////////////
                break;

            case 6:
                //////////////////OP��O RELATORIO NOME///////////////////////
                system("cls");
                char nome[50];
                fflush(stdin);
                fgets(nome, 50, stdin);
                x=consulta_nome(list, nome, &elemento);
                printf("\nC�digo: %d", elemento.codigo);
                printf("\nEmpresa: %s", elemento.empresa);
                printf("\nDepartamento: %s", elemento.departamento);
                printf("\nEmail: %s", elemento.email);
                printf("\nCelular: %d", elemento.celular);
                printf("\nTelefone: %d\n", elemento.celular);
                system("pause");
                //////////////////--------------------///////////////////////
                break;

            case 7:
                break;

            default:
                printf("\nOp��o inv�lida, insira novamente");
                system("pause");
        }
    }

////////////////SALVANDO NO ARQUIVO///////////////////////////
    f=fopen("arquivo.txt","wb");
    if(f==NULL){
        printf("Imposs�vel abrir\n");
        system("pause");
        exit(1);
    }
    for(i=1;i<=elementos_na_lista;i++){
        x=consulta_pos(list,i,&elemento);
        fwrite(&elemento, sizeof(CLIENTE),1,f);
    }
    int fclose(FILE *f);
///////////////------------------//////////////////////////
}

