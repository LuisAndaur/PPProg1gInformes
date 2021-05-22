#include "fecha.h"
#include "juego.h"
#include "clientes.h"
#include "categoria.h"

#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED

typedef struct{
    int codigo;
    int codigoJuego;
    int codigoCliente;
    int isEmpty;
    eFecha fecha;
}eAlquiler;

#endif // ALQUILERES_H_INCLUDED

/** \brief Recorre el array e inicializa la bandera isEmpty en 1
 *
 * \param alquileres[] eAlquiler array de alquileres
 * \param tamalq int tamaño del array de alquileres
 * \return int retorna 1 si tuvo exito y 0 si hubo error
 *
 */
int inicializarAlquileres(eAlquiler alquileres[], int tamalq);

/** \brief Busca un espacio libre en el array
 *
 * \param alquileres[] eAlquiler array de alquileres
 * \param tamalq int tamaño del array de alquileres
 * \return int Retorna el indice del espacio libre sino -1
 *
 */
int buscarLibreAlquiler(eAlquiler alquileres[], int tamalq);

/** \brief Da de alta un alquiler
 *
 * \param alquileres[] eAlquiler array alquiler
 * \param tamalq int tamaño del array alquiler
 * \param idAlquiler int* puntero de id alquiler
 * \param clientes[] eCliente array cliente
 * \param tamcli int tamaño del array cliente
 * \param juegos[] eJuego array juego
 * \param tamjue int tamaño del array juego
 * \param categorias[] eCategoria array categoria
 * \param tamcat int tamaño del array categoria
 * \return int retorna 1 si el alta fue exitosa o 0 si no lo fue
 *
 */
int altaAlquiler(eAlquiler alquileres[], int tamalq, int* idAlquiler, eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat, eLocalidad localidades[], int tamloc);

/** \brief Recorre y muestra los alquileres que estan cargados
 *
 * \param alquileres[] eAlquiler array de alquileres
 * \param tamalq int tamaño del array de alquileres
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array de clientes
 * \param juegos[] eJuego array de juegos
 * \param tamjue int tamaño del array de juegos
 * \param categorias[] eCategoria array de categorias
 * \param tamcat int tamaño del array de categorias
 * \return int retorna 0 si hay alquileres cargados sino 1
 *
 */
int mostrarAlquileres(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat,eLocalidad localidades[],int tamloc);

/** \brief Muestra un solo alquiler
 *
 * \param unAlquiler eAlquiler array de un alquiler
 * \param tamalq int tamaño del array de alquileres
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array de clientes
 * \param juegos[] eJuego array de juegos
 * \param tamjue int tamaño del array de juegos
 * \param categorias[] eCategoria array de categorias
 * \param tamcat int tamaño del array de categorias
 * \return void
 *
 */
void mostrarAlquiler(eAlquiler unAlquiler, int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat,eLocalidad localidades[],int tamloc);

/** \brief Recibe un id y recorre el array de alquileres buscandolo
 *
 * \param alquileres[] eAlquiler array de alquileres
 * \param tamalq int tamaño del array de alquileres
 * \param idBuscar int* referencia del id a buscar
 * \return int retorna el indice si encontro el alquiler o -1 si no existe
 *
 */
int buscarAlquiler(eAlquiler alquileres[], int tamalq, int* idBuscar);

/** \brief Recibe un id y recorre el array de alquileres buscandolo si lo
encuentra cambia la bandera isEmpty a 1
 *
 * \param alquileres[] eAlquiler array de alquileres
 * \param tamalq int tamaño del array de alquileres
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array de clientes
 * \param juegos[] eJuego array de juegos
 * \param tamjue int tamaño del array de juegos
 * \param categorias[] eCategoria array de categorias
 * \param tamcat int tamaño del array de categorias
 * \param idBuscar int* referencia del id a buscar para dar de baja los alquilesres de ese id
 * \param cantidadAlquileres int* referencia de la cantidad de alquileres
 * \return int retorna 1 si la baja fue exitosa o 0 si no tenia alquileres
 *
 */
int bajaAlquiler(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat,int* idBuscar,int* cantidadAlquileres);
