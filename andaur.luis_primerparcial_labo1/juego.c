#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "juego.h"


int mostrarJuegos(eJuego juegos[], int tamjue,eCategoria categorias[], int tamcat){
    int retorno = 0;
    if(juegos!=NULL && tamjue>0 && categorias!=NULL && tamcat>0){
        printf("=====================================\n");
        printf("            LISTA DE JUEGOS          \n");
        printf("=====================================\n");
        printf("ID    Categoria  Descripcion  Importe\n");
        for(int i=0;i<tamjue;i++){
            mostrarJuego(juegos[i], categorias, tamcat);
        }
        printf("\n");
        retorno = 1;
    }
    return retorno;
}

void mostrarJuego(eJuego unJuego, eCategoria categorias[], int tamcat){
    char descripcionCategoria[21];
    if(cargarDescripcionCategoria(unJuego.idCategoria,categorias,tamcat,descripcionCategoria)==1){
        printf("%4d %10s   %10s  $%.2f\n", unJuego.codigo,descripcionCategoria, unJuego.descripcion, unJuego.importe);
    }
}

int buscarJuego(eJuego juegos[], int tamjue, int idJuego){
    int indice = -1;
    if(juegos!=NULL && tamjue>0 && idJuego>0)
    {
        for(int i=0;i<tamjue;i++)
        {
            if(juegos[i].codigo == idJuego)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int cargarDescripcionJuego(int idJuego, eJuego juegos[], int tamjue, char descripcion[]){
    int retorno = 0;
    if(idJuego>999 && idJuego<1005 && juegos!=NULL && tamjue>0 && descripcion!=NULL){
        for(int i=0;i<tamjue;i++){
            if(juegos[i].codigo == idJuego){
                strcpy(descripcion, juegos[i].descripcion);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int cargarPrecioJuego(int idJuego, eJuego juegos[], int tamjue, float* precio){
    int retorno = 0;
    if(idJuego>999 && idJuego<1005 && juegos!=NULL && tamjue>0 && precio!=NULL){
        for(int i=0;i<tamjue;i++){
            if(juegos[i].codigo == idJuego){
                *precio = juegos[i].importe;
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}

int cargarCategoriaPorId(eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat, int idJuego, char descripcionCategoria[]){
    int retorno = 0;
    int indice;
    if(juegos!=NULL && categorias!=NULL && descripcionCategoria!= NULL && tamjue>0 && tamcat>0){
        indice = buscarJuego(juegos, tamjue, idJuego);
        if(indice!=-1){
            if(cargarDescripcionCategoria(juegos[indice].idCategoria, categorias, tamcat, descripcionCategoria)){
            retorno = 1;
            }
        }
    }
    return retorno;
}

