#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#include "clientes.h"
#include "categoria.h"
#include "juego.h"
#include "alquileres.h"
#include "informes.h"
#include "localidad.h"
#include "datawarehouse.h"

#define TAMJUE 5
#define TAMCAT 5
#define TAMLOC 5

#define TAMCLI 100
#define TAMALQ 100

char menu();
int menuInformes();

int main()
{
    eJuego juegos[TAMJUE];
    eCategoria categorias[TAMCAT];
    eLocalidad localidades[TAMLOC];

    eCliente clientes[TAMCLI];
    eAlquiler alquileres[TAMALQ];

    char respuesta = 'n';
    int idClientes = 7000;
    int idAlquileres = 4000;
    int cantidadClientes = 0;
    int cantidadAlquileres = 0;
    int idBuscar = 0;
    int opcion;

    inicializarCliente(clientes, TAMCLI);
    inicializarAlquileres(alquileres, TAMALQ);

    hardcodearJuego(juegos,TAMJUE);
    hardcodearCategoria(categorias,TAMCAT);
    hardcodearLocalidad(localidades,TAMLOC);
    hardcodearClientes(clientes,TAMCLI,&cantidadClientes,&idClientes,15);
    hardcodearAlquiler(alquileres,TAMALQ,&cantidadAlquileres,&idAlquileres,15);



    do{
        switch(menu()){
            case 'A':
                //ALTA CLIENTES
                if(cantidadClientes<TAMCLI){
                    altaCliente(clientes, TAMCLI,&idClientes,localidades,TAMLOC);
                    cantidadClientes++;
                }
                else{
                    printf("\nEl sistema esta completo.\n");
                }
                break;

            case 'B':
                //MODIFICAR CLIENTES
                if(cantidadClientes>0){
                    modificarClientes(clientes, TAMCLI,localidades,TAMLOC);
                }
                else{
                    printf("\nNo hay clientes en el sistema para modificar.\n\n");
                }
                break;

            case 'C':
                //BAJA CLIENTES
                if(cantidadClientes>0){
                   bajaCliente(clientes, TAMCLI,&idBuscar,localidades,TAMLOC);
                   bajaAlquiler(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT,&idBuscar,&cantidadAlquileres);
                   cantidadClientes--;
                }
                else{
                    printf("\nNo hay clientes en el sistema para dar de baja.\n\n");
                }
                break;

            case 'D':
                //LISTAR CLIENTES
                if(cantidadClientes>0){
                    system("cls");
                    ordenarClientes(clientes, TAMCLI,localidades,TAMLOC);
                    mostrarClientes(clientes, TAMCLI,localidades,TAMLOC);
                }
                else{
                    printf("\nNo hay clientes cargados en el sistema.\n\n");
                }
                break;

            case 'E':
                //ALTA alquileres
                if(cantidadAlquileres<TAMALQ && cantidadClientes>0){
                    altaAlquiler(alquileres, TAMALQ,&idAlquileres,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
                    cantidadAlquileres++;
                }
                else{
                    printf("\nNo hay clientes cargados para hacer un alquiler o el sistema esta completo.\n\n");
                }
                break;

            case 'F':
                //lista alquileres
                if(cantidadAlquileres>0){
                    system("cls");
                    mostrarAlquileres(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
                }
                else{
                    printf("\nNo hay alquileres para mostrar.\n\n");
                }
                break;

            case 'G':
                //INFORMES
                if(cantidadAlquileres>0 || cantidadClientes>0){
                    do{
                        switch(menuInformes()){
                            case 1:
                                system("cls");
                                clientesAvellaneda(clientes,TAMCLI,localidades,TAMLOC);
                                break;
                            case 2:
                                system("cls");
                                alquilanDamasLanus(alquileres,TAMALQ,juegos,TAMJUE,clientes,TAMCLI,localidades,TAMLOC);
                                break;
                            case 3:
                                system("cls");
                                mostrarJuegosMesa(juegos,TAMJUE,categorias,TAMCAT);
                                break;
                            case 4:
                                system("cls");
                                mostraralquilerPorCliente(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
                                break;
                            case 5:
                                system("cls");
                                clientesNoAlquilaron(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
                                break;
                            case 6:
                                system("cls");
                                juegosNoAlquilados(alquileres,TAMALQ,juegos,TAMJUE,categorias,TAMCAT);
                                break;
                            case 7:
                                system("cls");
                                juegosAlquiladosPorMujeres(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
                                break;
                            case 8:
                                system("cls");
                                JuegoMasAlquiladoPorHombres(alquileres,TAMALQ,clientes,TAMCLI,juegos,TAMJUE,categorias,TAMCAT,localidades,TAMLOC);
                                break;
                            case 9:
                                break;
                            case 10:
                                break;
                            case 11:
                                opcion=11;
                                break;
                        }
                        if(opcion!=11){
                            system("pause");
                        }
                    }while(opcion!=11);
                }else{
                    printf("\nNo hay clientes ni alquileres para hacer informes.\n\n");
                }
                break;

            case 'H':
                printf("Seguro desea salir? s-n: ");
                fflush(stdin);
                scanf("%c", &respuesta);
                respuesta = tolower(respuesta);
                while(respuesta!='s' && respuesta!='n'){
                    printf("ERROR: Ingrese s-n: ");
                    fflush(stdin);
                    scanf("%c", &respuesta);
                    respuesta = tolower(respuesta);
                }
                break;

            default:
                printf("La opcion ingresada es incorrecta.\n");
                break;
        }
    system("pause");
    }while(respuesta == 'n');

    return 0;
}

char menu(){
    char opcion;

    system("cls");
    printf("|| ALQUILERES DE JUEGOS INFANTILES ||\n\n");
    printf("A- ALTA clientes\n");
    printf("B- MODIFICAR clientes\n");
    printf("C- BAJA clientes\n");
    printf("D- LISTAR Clientes\n");
    printf("E- ALTA Alquileres\n");
    printf("F- LISTAR Alquileres\n");
    printf("G- INFORMES\n");
    printf("H- SALIR\n");
    printf("\n\nIngrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion = toupper(opcion);
    while(opcion!='A' && opcion!='B' && opcion!='C' && opcion!='D' && opcion!='E' && opcion!='F' && opcion!='G' && opcion!='H'){
        printf("ERROR: Ingrese una opcion correcta: ");
        fflush(stdin);
        scanf("%c", &opcion);
        opcion = toupper(opcion);
    }
    return opcion;
}

int menuInformes(){
    int opcion;

    system("cls");
    printf("|| INFORMES ||\n\n");
    printf("1- Cantidad de clientes de avellaneda.\n");
    printf("2- Clientes de Lanus que alquilan Damas.\n");
    printf("3- Mostrar juegos de categoria mesa.\n");
    printf("4- Mostrar alquiler por cliente seleccionado.\n");
    printf("5- Listar clientes que no alquilaron juegos.\n");
    printf("6- Listar juegos que no se alquilaron.\n");
    printf("7- Juegos alquilados por mujeres.\n");
    printf("8- Mostrar los juegos mas alquilados por hombres.\n");
    printf("9- \n");
    printf("10- \n");
    printf("11- SALIR\n");
    printf("\n\nIngrese opcion: ");
    scanf("%d", &opcion);
    while(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4 && opcion!=5 && opcion!=6 && opcion!=7 && opcion!=8 && opcion!=9 && opcion!=10 && opcion!=11){
        printf("ERROR: Ingrese una opcion correcta: ");
        scanf("%d", &opcion);
    }
    return opcion;
}
