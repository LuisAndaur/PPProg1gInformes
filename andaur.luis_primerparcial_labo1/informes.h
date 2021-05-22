#include "clientes.h"
#include "alquileres.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED

int clientesAvellaneda(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc);

int alquilanDamasLanus(eAlquiler alquileres[],int tamalq,eJuego juegos[],int tamjue, eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc);

int mostrarJuegosMesa(eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat);

int mostraralquilerPorCliente(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat,eLocalidad localidades[],int tamloc);

int clientesNoAlquilaron(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat,eLocalidad localidades[],int tamloc);

int juegosNoAlquilados(eAlquiler alquileres[], int tamalq,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat);

int juegosAlquiladosPorMujeres(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat,eLocalidad localidades[],int tamloc);

int JuegoMasAlquiladoPorHombres(eAlquiler alquileres[], int tamalq,eCliente clientes[], int tamcli,eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat,eLocalidad localidades[],int tamloc);
