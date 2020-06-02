#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto.h"

struct estrut{
    CLIENTE dados;
    struct estrut *next;
};

typedef struct estrut ELEM;

Lista *cria(){
    Lista *list;
    list = (Lista*) malloc(sizeof(Lista));
    if(list != NULL){
        *list=NULL;
    }
    return list;
}

int insere(Lista *list, CLIENTE cl){
    if(list==NULL){
        return 0;
    }
    ELEM *node=(ELEM*) malloc(sizeof(ELEM));
    if(node==NULL){
        return 0;
    }
    node->dados=cl;
    node->next = NULL;
    if((*list)==NULL){
        *list=node;
    }else{
        ELEM *auxnode = *list;
        while(auxnode->next != NULL){
            auxnode = auxnode->next;
        }
        auxnode->next = node;
    }
    return 1;
}

int remov(Lista *list, int cli){
    if(list==NULL){
        return 0;
    }
    ELEM *prev, *node = *list;
    while(node!=NULL && node->dados.codigo != cli){
        prev = node;
        node = node->next;
    }

    if(node==NULL){
        return 0;
    }
    if(node==NULL){
        return 0;
    }
    if(node==*list){
        *list = node->next;
    }else{
        prev->next=node->next;
    }
    free(node);
    return 1;
}

int consulta_nome(Lista *list, char* nome, CLIENTE *cli){
    if(list==NULL){
        return 0;
    }
    ELEM *node=*list;
    while(node !=NULL && strcmp(node->dados.nome, nome)!=0){
        node=node->next;
    }
    if(node==NULL){
        return 0;
    }else{
        *cli=node->dados;
        return 1;
    }
}

int consulta_pos(Lista *list, int pos, CLIENTE *cli){
    if(list==NULL || pos<=0){
        return 0;
    }
    ELEM *node = *list;
    int i=1;
    while(node!=NULL && i< pos){
        node = node->next;
        i++;
    }
    if(node == NULL){
        return 0;
    }else{
        *cli = node->dados;
        return 1;
    }
}

int consulta_ident(Lista *list, int ident, CLIENTE *cli){
    if(list==NULL){
        return 0;
    }
    ELEM *node=*list;
    while(node !=NULL && node->dados.codigo !=ident){
        node=node->next;
    }
    if(node==NULL){
        return 0;
    }else{
        *cli=node->dados;
        return 1;
    }
}

int edita(Lista *list, int ident, CLIENTE cli){
    if(list==NULL){
        return 0;
    }
    ELEM *node=*list;
    while(node !=NULL && node->dados.codigo !=ident){
        node=node->next;
    }
    if(node==NULL){
        return 0;
    }else{
        node->dados=cli;
        return 1;
    }
}
