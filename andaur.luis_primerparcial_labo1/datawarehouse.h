#include "clientes.h"
#include "alquileres.h"
#include "juego.h"
#include "categoria.h"

#ifndef DATAWAREHOUSE_H_INCLUDED
#define DATAWAREHOUSE_H_INCLUDED



#endif // DATAWAREHOUSE_H_INCLUDED

/** \brief Hardcodeo de juegos
 *
 * \param juegos[] eJuego
 * \param tamjue int
 * \return int int retorna 1 si hay juegos para mostrar sino 0
 *
 */
int hardcodearJuego(eJuego juegos[], int tamjue);

/** \brief Hardcodeo de categorias
 *
 * \param categorias[] eCategoria
 * \param tamcat int
 * \return int int retorna 1 si hay categorias para mostrar sino 0
 *
 */
int hardcodearCategoria(eCategoria categorias[], int tamcat);

int hardcodearClientes(eCliente clientes[], int tamcli, int* cantidadClientes, int* id, int cantHard);

int hardcodearAlquiler(eAlquiler alquileres[], int tamalq, int* cantidadAlquileres, int* id, int cantHard);

int hardcodearLocalidad(eLocalidad localidades[], int tamloc);
