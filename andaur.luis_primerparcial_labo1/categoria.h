#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eCategoria;


#endif // CATEGORIA_H_INCLUDED


/** \brief Muestra todas las categorias
 *
 * \param categorias[] eCategoria array de categorias
 * \param tamcat int tamaño del array de categorias
 * \return int int retorna 1 si hay categorias para mostrar sino 0
 *
 */
int mostrarCategorias(eCategoria categorias[], int tamcat);

/** \brief Muestra una sola categoria
 *
 * \param unaCategoria eCategoria array de una categoria
 * \return void
 *
 */
void mostrarCategoria(eCategoria unaCategoria);

/** \brief Carga la descripcion de la categoria recibiendo su id
 *
 * \param idCategoria int id de la categoria a buscar
 * \param categorias[] eCategoria array de categorias
 * \param tamcat int tamaño del array de categorias
 * \param descripcion[] char donde se guarda el nombre de la categoria
 * \return int int retorna 1 si hay categorias cargadas sino 0
 *
 */
int cargarDescripcionCategoria(int idCategoria, eCategoria categorias[], int tamcat, char descripcion[]);




