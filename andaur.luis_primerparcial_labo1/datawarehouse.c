#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datawarehouse.h"

#define TAMJUE 5
#define TAMCAT 5
#define TAMLOC 5

#define TAMCLI 30
#define TAMALQ 30


//juegos
int idJuego[TAMJUE] = {1000,1001,1002,1003,1004};
char descripcionJuego[TAMJUE][21] = {"Damas","Cartas","Ajedrez","Metegol","Magic"};
float precio[TAMJUE] = {250,300,400,350,150};
int idCategoriaJuegos[TAMJUE] = {5000,5001,5002,5003,5004};

int hardcodearJuego(eJuego juegos[], int tamjue){
    int retorno = -1;
    if(juegos!=NULL && tamjue>0){
        for(int i=0;i<tamjue;i++){
            juegos[i].codigo = idJuego[i];
            strcpy(juegos[i].descripcion,descripcionJuego[i]);
            juegos[i].importe = precio[i];
            juegos[i].idCategoria = idCategoriaJuegos[i];
        }
        retorno = 0;
    }
    return retorno;
}

//categoria
int idCategoria[TAMCAT] = {5000,5001,5002,5003,5004};
char descripcionCategoria[TAMCAT][21] = {"Mesa","Azar","Estrategia", "Salon", "Magia"};

int hardcodearCategoria(eCategoria categorias[], int tamcat){
    int retorno = -1;
    if(categorias!=NULL && tamcat>0){
        for(int i=0;i<tamcat;i++){
            categorias[i].id = idCategoria[i];
            strcpy(categorias[i].descripcion,descripcionCategoria[i]);
        }
        retorno = 0;
    }
    return retorno;
}

//localidad
int idLocalidad[TAMLOC] = {3000,3001,3002,3003,3004};
char descripcionLocalidad[TAMLOC][21] = {"Lanus","Gerli","Avellaneda", "Moron", "Temperley"};

int hardcodearLocalidad(eLocalidad localidades[], int tamloc){
    int retorno = -1;
    if(localidades!=NULL && tamloc>0){
        for(int i=0;i<tamloc;i++){
            localidades[i].id = idLocalidad[i];
            strcpy(localidades[i].descripcion,descripcionLocalidad[i]);
        }
        retorno = 0;
    }
    return retorno;
}


//CLIENTES PARA PRUEBA
//int id[30]={7000,7001,7002,7003,7004,7005,7006,7007,7008,7009,7010,7011,7012,7013,7014,7015,7016,7017,7018,7019};
char nombre[TAMCLI][51] = {"Pablo","Ernesto","Juana","Paula","Lucia","Nicolas","Aaron","Ana","Manuel","Vanesa","Lorena","Guillermo","Iganacio","Pilar","Carmen","Jose","Amalia","Lucila","Lautaro"};
char apellido[TAMCLI][51] = {"Perez","Gomez","Gomez","Alvarez","Fertoli","Cruz","Alvarez","Vera","Armani","Borre","Santos","Girotti","Simon","Casco","Angileri","Bologna","Lux","Montiel","Pezzela"};
char sexo[TAMCLI] = {'m','m','f','f','f','m','m','f','m','f','f','m','m','f','f','m','f','f','m'};
char telefono[TAMCLI][51] = {"5257836","8752055","6415953","7691954","7755407","5418356","5590633","9850816","6813614","6422127","8860560","9199104","6813614","7439909","5418356","8513050","7343414","3587706","8237121"};
int idLocalidadCliente[TAMCLI]={3004,3002,3002,3000,3004,3001,3001,3003,3002,3000,3000,3001,3002,3004,3002,3004,3001,3003,3002,3001};

int hardcodearClientes(eCliente clientes[], int tamcli, int* cantidadClientes, int* id, int cantHard){
    int retorno = -1;
    if(clientes!=NULL && tamcli>0 && id!=NULL && cantidadClientes!=NULL && cantHard>0){
        for(int i=0;i<cantHard;i++){
            clientes[i].codigo = *id;
            (*id)++;
            strcpy(clientes[i].nombre,nombre[i]);
            strcpy(clientes[i].apellido,apellido[i]);
            clientes[i].sexo = sexo[i];
            clientes[i].idLocalidad = idLocalidadCliente[i];
            strcpy(clientes[i].telefono,telefono[i]);
            clientes[i].isEmpty = 0;
            (*cantidadClientes)++;
        }
        retorno = 0;
    }
    return retorno;
}

//ALQUILERES PARA PRUEBA
//int id[TAMTRA]={4000,4001,4002,4003,4004,4005,4006,4007,4008,4009,4010,4011,4012,4013,4014,4015,4016,4017,4018,4019};
int idClientes[TAMALQ]={7005,7008,7002,7006,7004,7012,7006,7013,7007,7009,7000,7001,7011,7004,7012,7004,7011,7003,7008,7010};
int idJuegos[TAMALQ] = {1002,1002,1002,1003,1001,1003,1002,1003,1004,1000,1000,1003,1001,1002,1002,1002,1002,1003,1000};
eFecha fechas[TAMALQ]={
    {2,4,2021},
    {23,10,2021},
    {21,5,2021},
    {3,12,2021},
    {2,1,2021},
    {7,4,1921},
    {23,10,2021},
    {28,5,2021},
    {30,12,2021},
    {2,11,1921},
    {2,4,2021},
    {25,1,2021},
    {21,5,2021},
    {26,4,2021},
    {18,10,2021},
    {21,5,2021},
    {26,4,2021},
    {18,10,2021},
    {21,5,2021},
    {6,3,2021},
};

int hardcodearAlquiler(eAlquiler alquileres[], int tamalq, int* cantidadAlquileres, int* id, int cantHard){
    int retorno = -1;
    if(alquileres!=NULL && tamalq>0 && id!=NULL && cantidadAlquileres!=NULL && cantHard>0){
        for(int i=0;i<cantHard;i++){
            alquileres[i].codigo = *id;
            (*id)++;
            alquileres[i].codigoCliente = idClientes[i];
            alquileres[i].codigoJuego = idJuegos[i];
            alquileres[i].fecha = fechas[i];
            alquileres[i].isEmpty = 0;
            (*cantidadAlquileres)++;
        }
        retorno = 0;
    }
    return retorno;
}

