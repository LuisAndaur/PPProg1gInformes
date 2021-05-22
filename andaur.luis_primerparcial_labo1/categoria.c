#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "categoria.h"


int mostrarCategorias(eCategoria categorias[], int tamcat){
    int retorno = 0;
    if(categorias!=NULL && tamcat>0){
        printf("===================\n");
        printf("LISTA DE CATEGORIAS\n");
        printf("===================\n");
        printf("ID      Descripcion\n");
        for(int i=0;i<tamcat;i++){
            mostrarCategoria(categorias[i]);
        }
        printf("\n");
        retorno = 1;
    }
    return retorno;
}

void mostrarCategoria(eCategoria unaCategoria){
    printf("%d    %s\n", unaCategoria.id, unaCategoria.descripcion);
}

int cargarDescripcionCategoria(int idCategoria, eCategoria categorias[], int tamcat, char descripcion[]){
    int retorno = 0;
    if(idCategoria>4999 && idCategoria<5005 && categorias!=NULL && tamcat>0 && descripcion!=NULL){
        for(int i=0;i<tamcat;i++){
            if(categorias[i].id == idCategoria){
                strcpy(descripcion, categorias[i].descripcion);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}




