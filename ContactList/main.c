#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "projeto.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    char opt2;
    int i, x;
    int elementos_na_lista=0;//VARIÁVEL QUE CONTROLA O NÚMERO DE ELEMENTOS NA LISTA
    int opt=0;//VARIÁVEL QUE CONTROLA AS OPÇÕES ESCOLHIDAS PELO USUÁRIO
    int cod;//CÓDIGO INSERIDO PARA PESQUISA
    Lista *list;
    FILE *f;
////////////////////////LISTA CRIADA//////////////////////////////
    list=cria();
    CLIENTE elemento;
///////////////////////--------------------///////////////////////

////////////////RECUPERANDO OS DADOS//////////////////////
    f=fopen("arquivo.txt","rb");
    if(f==NULL){
        printf("Não foi possível ler um arquivo, um novo será criado\n");
        system("pause");
        //exit(1);
    }
    else{
        while(feof(f)==0){//INSERE CADA ELEMENTO LIDO NA LISTA
            fread(&elemento, sizeof(CLIENTE),1,f);
            x=insere(list,elemento);
            elementos_na_lista++;
        }
        x=remov(list, elemento.codigo);//REMOVE O ÚLTIMO ELEMENTO QUE ESTÁ DUPLICADO
        elementos_na_lista--;
    }
    int fclose(FILE *f);
///////////////---------------------//////////////////////////

    while(opt!=7){
        //////////////MENU////////////////////////
        system("cls");

        printf("////////////--------ACME S.A.--------////////////\n\n");
        printf("Registro de clientes\n");
        printf("Feito por Gabriel Santos Sá\n\n");
        printf("1 - Inserir um cliente na lista\n");
        printf("2 - Editar um cliente da lista\n");
        printf("3 - Remover um cliente da lista\n");
        printf("4 - Relatório completo da lista\n");
        printf("5 - Relatório de clientes por código identificador\n");
        printf("6 - Relatório de clientes por nome\n");
        printf("7 - Sair do programa\n\n");

        printf("Insira a opção desejada: ");
        scanf("%d", &opt);
        /////////////-----------------------////////////////////////

        switch(opt){
            case 1:
                ///////////////OPÇÃO DE INSERÇÃO/////////////////////////
                system("cls");
                printf("\nInsira o código do cliente: ");
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
                //////////////////OPÇÃO EDIÇÃO///////////////////////
                system("cls");
                printf("Insira o código identificador do cliente a ser editado: ");
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
                printf("N para não\n");
                fflush(stdin);
                scanf("%c", &opt2);
                if(opt2=='S'){
                    printf("\nInsira o código do cliente: ");
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
                //////////////////REMOÇÃO///////////////////////
                system("cls");
                printf("Insira o código identificador do cliente a ser removido: ");
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
                printf("N para não\n");
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
                        printf("Impossível remover cliente\n");
                        system("pause");
                    }
                }else{
                    break;
                }
                //////////////////--------------------///////////////////////
                break;

            case 4:
                //////////////////OPÇÃO RELATORIO TOTAL///////////////////////
                system("cls");
                for(i=1;i<=elementos_na_lista;i++){
                    x=consulta_pos(list,i,&elemento);
                    printf("Elemento %d, Código: %d\n", i,elemento.codigo);
                }
                system("pause");
                //////////////////--------------------///////////////////////
                break;

            case 5:
                //////////////////OPÇÃO RELATORIO IDENTF///////////////////////
                system("cls");
                printf("Insira o código identificador do cliente: ");
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
                //////////////////OPÇÃO RELATORIO NOME///////////////////////
                system("cls");
                char nome[50];
                fflush(stdin);
                fgets(nome, 50, stdin);
                x=consulta_nome(list, nome, &elemento);
                printf("\nCódigo: %d", elemento.codigo);
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
                printf("\nOpção inválida, insira novamente");
                system("pause");
        }
    }

////////////////SALVANDO NO ARQUIVO///////////////////////////
    f=fopen("arquivo.txt","wb");
    if(f==NULL){
        printf("Impossível abrir\n");
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

