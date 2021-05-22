#include "categoria.h"

#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED

typedef struct{
    int codigo;
    char descripcion[21];
    float importe;
    int idCategoria;
}eJuego;

#endif // JUEGO_H_INCLUDED

/** \brief Muestra todos los juegos
 *
 * \param juegos[] eJuego array de juegos
 * \param tamjue int tamaño del array de juegos
 * \param categorias[] eCategoria array de categorias
 * \param tamcat int tamaño del array de categorias
 * \return int int retorna 1 si hay juegos para mostrar sino 0
 *
 */
int mostrarJuegos(eJuego juegos[], int tamjue,eCategoria categorias[], int tamcat);

/** \brief Muestra un solo juego
 *
 * \param unJuego eJuego array de juego
 * \param categorias[] eCategoria array de categorias
 * \param tamcat int tamaño del array de categorias
 * \return void
 *
 */
void mostrarJuego(eJuego unJuego, eCategoria categorias[], int tamcat);

/** \brief Recibe un id y recorre el array de juegos buscandolo
 *
 * \param juegos[] eJuego array de juegos
 * \param tamjue int tamaño del array de juegos
 * \param idJuego int id a buscar
 * \return int retorna el indice si encuentra el juego sino -1
 *
 */
int buscarJuego(eJuego juegos[], int tamjue, int idJuego);

/** \brief Carga la descripcion del nombre del juego recibiendo su id
 *
 * \param idJuego int id del juego a buscar
 * \param juegos[] eJuego array de juegos
 * \param tamjue int tamaño del array de juegos
 * \param descripcion[] char donde se guarda el nombre del juego
 * \return int retorna 1 si existe el juego para mostrar sino 0
 *
 */
int cargarDescripcionJuego(int idJuego, eJuego juegos[], int tamjue, char descripcion[]);

/** \brief Carga el precio del juego recibiendo su id
 *
 * \param idJuego int id del juego a buscar
 * \param juegos[] eJuego array de juegos
 * \param tamjue int tamaño del array de juegos
 * \param precio float* referencia donde se guarda el precio del juego
 * \return int retorna 1 si existe el juego para mostrar sino 0
 *
 */
int cargarPrecioJuego(int idJuego, eJuego juegos[], int tamjue, float* precio);

/** \brief carga la descripcion de la categoria recibiendo atraves del array de juegos el id de la categoria
 *
 * \param juegos[] eJuego array de juegos
 * \param tamjue int tamaño del array de juegos
 * \param categorias[] eCategoria array de categorias
 * \param tamcat int tamaño del array de categorias
 * \param idJuego int id del juego a buscar
 * \param descripcionCategoria[] char donde se guarda el nombre de la categoria
 * \return int retorna 1 si existe el juego y categoria para mostrar sino 0
 *
 */
int cargarCategoriaPorId(eJuego juegos[], int tamjue, eCategoria categorias[], int tamcat, int idJuego, char descripcionCategoria[]);
