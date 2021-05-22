#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "localidad.h"


int mostrarLocalidades(eLocalidad localidades[], int tamloc){
    int retorno = 0;
    if(localidades!=NULL && tamloc>0){
        printf("====================\n");
        printf("LISTA DE LOCALIDADES\n");
        printf("====================\n");
        printf("ID      Descripcion\n");
        for(int i=0;i<tamloc;i++){
            mostrarLocalidad(localidades[i]);
        }
        printf("\n");
        retorno = 1;
    }
    return retorno;
}

void mostrarLocalidad(eLocalidad unaLocalidad){
    printf("%d    %s\n", unaLocalidad.id, unaLocalidad.descripcion);
}

int cargarDescripcionLocalidad(int idLocalidad, eLocalidad localidades[], int tamloc, char descripcion[]){
    int retorno = 0;
    if(idLocalidad>2999 && idLocalidad<3005 && localidades!=NULL && tamloc>0 && descripcion!=NULL){
        for(int i=0;i<tamloc;i++){
            if(localidades[i].id == idLocalidad){
                strcpy(descripcion, localidades[i].descripcion);
                retorno = 1;
                break;
            }
        }
    }
    return retorno;
}
