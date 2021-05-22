#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"

int clientesAvellaneda(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc){
    int retorno = 0;
    int idBuscar = 3002;
    int contador = 0;
    if(clientes!=NULL && tamcli>0 && localidades!=NULL && tamloc>0 ){
        for(int i=0;i<tamcli;i++){
            if(!clientes[i].isEmpty && clientes[i].idLocalidad == idBuscar){
                contador++;
            }
        }
        retorno=1;
    }
    if(!retorno)
    {
        printf("\n\nNo hay clientes de Avellaneda.\n");
    }else{
        printf("\nHay %d clientes de Avellaneda.", contador);
    }
    printf("\n\n");
    return retorno;
}

int alquilanDamasLanus(eAlquiler alquileres[],int tamalq,eJuego juegos[],int tamjue, eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc){
    int retorno = 0;
    int idBuscar = 3000;
    int damas = 1000;
    int contador = 0;
    if(alquileres!=NULL && tamalq>0 && juegos!=NULL && tamjue>0 && clientes!=NULL && tamcli>0 && localidades!=NULL && tamloc>0 ){
        for(int i=0;i<tamcli;i++){
            if(!clientes[i].isEmpty && clientes[i].idLocalidad == idBuscar){
                for(int j=0;j<tamalq;j++){
                    if(!alquileres[j].isEmpty && alquileres[j].codigoCliente==clientes[i].codigo){
                        for(int x=0;x<tamjue;x++){
                            if(juegos[x].codigo == damas){
                                contador++;
                            }
                        }
                    }
                }
            }
        }
        retorno=1;

    }
    if(!retorno)
    {
        printf("\n\nNo hay juegos de la categoria mesa.\n");
    }else{
        printf("\nHay %d clientes de Lanus que alquilaron Damas.", contador);
    }
    printf("\n\n");
    return retorno;
}



int mostrarJuegosMesa(eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat){
    int retorno = 0;
    int mesa = 5000;
    if(juegos!=NULL && tamjue>0 && categorias!=NULL && tamcat>0){
        printf("JUEGOS DE LA CATEGORIA MESA\n");
        printf("ID    Categoria  Descripcion  Importe\n");
        for(int i=0;i<tamjue;i++){
            if(juegos[i].idCategoria == mesa){
                mostrarJuego(juegos[i],categorias,tamcat);
            }
        }
        retorno = 1;
    }
    if(!retorno)
    {
        printf("\n\nNo hay juegos de la categoria mesa.\n");
    }
    return retorno;
}

int mostraralquilerPorCliente(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat,eLocalidad localidades[],int tamloc){
    int retorno = 0;
    int idBuscar;
    char descripcionNombre[21];
    char descripcionApellido[21];
    printf("ALQUILER POR CLIENTE\n");
    mostrarClientes(clientes,tamcli,localidades,tamloc);
    getInt("Ingrese ID cliente: ", &idBuscar);
    while(buscarCliente(clientes,tamcli,&idBuscar)==-1){
       getInt("Reingrese ID cliente: ", &idBuscar);
    }

    if(alquileres!=NULL && tamalq>0  && clientes!=NULL && tamcli>0 && juegos!=NULL && tamjue>0 && categorias!=NULL && tamcat>0 && localidades!=NULL && tamloc>0){
        printf("\nLISTA DE ALQUILERES DEL CLIENTE SELECCIONADO\n");
        printf("Codigo    Categoria       Juego   IDCl      Nombre   Apellido   Localidad   Precio         Fecha\n");
        for(int i=0;i<tamalq;i++){
            if(!alquileres[i].isEmpty && alquileres[i].codigoCliente == idBuscar){
                mostrarAlquiler(alquileres[i],tamalq,clientes,tamcli,juegos,tamjue,categorias,tamcat,localidades,tamloc);
                retorno = 1;
            }
        }
    }
    if(!retorno)
    {
        cargarDescripcionCliente(idBuscar,clientes,tamcli,descripcionNombre, descripcionApellido);
        printf("\nEl cliente %d %s %s no tiene alquileres para mostrar.\n\n", idBuscar, descripcionNombre,descripcionApellido);
    }
    return retorno;

}

int clientesNoAlquilaron(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat,eLocalidad localidades[],int tamloc){
    int retorno = 0;
    int contadorAlquiler[tamcli];

    for(int i=0;i<tamcli;i++){
        contadorAlquiler[i]=0;
    }

    if(alquileres!=NULL && tamalq>0  && clientes!=NULL && tamcli>0 && juegos!=NULL && tamjue>0 && categorias!=NULL && tamcat>0 && localidades!=NULL && tamloc>0){
        for(int i=0;i<tamcli;i++){
            if(!clientes[i].isEmpty){
                for(int J=0;J<tamalq;J++){
                    if(!alquileres[J].isEmpty && alquileres[J].codigoCliente == clientes[i].codigo){
                        contadorAlquiler[i]++;

                    }
                }
            }
        }
        printf("\nLISTA DE CLIENTES QUE NO ALQUILARON\n");
        printf("Codigo   Nombre     Apellido    Localidad   Sexo   Telefono\n");
        for(int i=0;i<tamcli;i++){
            if(!clientes[i].isEmpty && contadorAlquiler[i]==0){
                mostrarCliente(clientes[i],localidades,tamloc);
                retorno = 1;
            }
        }
    }
    if(!retorno)
    {
        printf("\nTodos los clientes alquilaron algun juego.\n\n");
    }
    return retorno;

}

int juegosNoAlquilados(eAlquiler alquileres[], int tamalq,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat){
    int retorno = 0;
    int contadorjuegos[tamjue];

    for(int i=0;i<tamjue;i++){
        contadorjuegos[i]=0;
    }

    if(alquileres!=NULL && tamalq>0 && juegos!=NULL && tamjue>0 && categorias!=NULL && tamcat>0){
        for(int i=0;i<tamjue;i++){
            for(int J=0;J<tamalq;J++){
                if(!alquileres[J].isEmpty && alquileres[J].codigoJuego == juegos[i].codigo){
                    contadorjuegos[i]++;

                }
            }
        }
        printf("\nLISTA DE JUEGOS QUE NO ALQUILARON\n");
        printf("ID    Categoria  Descripcion  Importe\n");
        for(int i=0;i<tamjue;i++){
            if(contadorjuegos[i]==0){
                mostrarJuego(juegos[i],categorias,tamcat);
                retorno = 1;
            }
        }
    }
    if(!retorno)
    {
        printf("\nTodos los clientes alquilaron algun juego.\n\n");
    }
    return retorno;

}

int juegosAlquiladosPorMujeres(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat,eLocalidad localidades[],int tamloc){
    int retorno = 0;

    if(alquileres!=NULL && tamalq>0  && clientes!=NULL && tamcli>0 && juegos!=NULL && tamjue>0 && categorias!=NULL && tamcat>0 && localidades!=NULL && tamloc>0){
        printf("\nLISTA DE JUEGOS QUE ALQUILARON MUJERES\n");
        printf("Codigo    Categoria       Juego   IDCl      Nombre   Apellido   Localidad   Precio         Fecha\n");
        for(int i=0;i<tamcli;i++){
            if(!clientes[i].isEmpty && clientes[i].sexo=='f'){
                for(int J=0;J<tamalq;J++){
                    if(!alquileres[J].isEmpty && alquileres[J].codigoCliente == clientes[i].codigo){
                        mostrarAlquiler(alquileres[i],tamalq,clientes,tamcli,juegos,tamjue,categorias,tamcat,localidades,tamloc);
                        retorno = 1;
                    }
                }
            }
        }
    }
    if(!retorno)
    {
        printf("\nNinguna mujer alquilo algun juego.\n\n");
    }
    return retorno;

}

int JuegoMasAlquiladoPorHombres(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat,eLocalidad localidades[],int tamloc){
    int retorno = 0;
    int contadorJuegos[tamjue];
    int maximo;
    int flag = 1;

    for(int i=0;i<tamjue;i++){
        contadorJuegos[i] = 0;
    }

    if(alquileres!=NULL && tamalq>0  && clientes!=NULL && tamcli>0 && juegos!=NULL && tamjue>0 && categorias!=NULL && tamcat>0 && localidades!=NULL && tamloc>0){
        for(int i=0;i<tamjue;i++){
            for(int j=0;j<tamalq;j++){
                if(!alquileres[i].isEmpty){
                    for(int x=0;x<tamcli;x++){
                        if(!clientes[x].isEmpty && clientes[x].codigo==alquileres[j].codigoCliente && clientes[x].sexo=='m'){
                            contadorJuegos[i]++;
                        }
                    }
                }
            }
        }


        for(int i=0;i<tamjue;i++){
            if(flag || contadorJuegos[i]>maximo){
                maximo = contadorJuegos[i];
                flag = 0;
            }
        }

        printf("El juego/s favorito/s de los clientes es: ");
        for(int i=0;i<tamjue;i++){
            if(contadorJuegos[i]==maximo){
                printf("%s ", juegos[i].descripcion);
                retorno = 1;
            }
        }
        printf("\n\n");
    }
    if(retorno==0)
    {
        printf("\nNo hay juegos alquilados por hombres.\n\n");
    }
    return retorno;
}

