#include "localidad.h"

#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    int idLocalidad;
    int isEmpty;
}eCliente;

#endif // CLIENTES_H_INCLUDED

/** \brief Recorre el array e inicializa la bandera isEmpty en 1
 *
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array clientes
 * \return int retorna 1 si tuvo exito y 0 si hubo error
 *
 */
int inicializarCliente(eCliente clientes[], int tamcli);

/** \brief Busca un espacio libre en el array
 *
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array clientes
 * \return int Retorna el indice del espacio libre sino -1
 *
 */
int buscarLibreCliente(eCliente clientes[], int tamcli);

/** \brief Se da de alta a los clientes en un espacio vacio
 *
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array clientes
 * \param idCliente int* id asignado a cada alta pasado por referencia que se autoincrementa
 * \return int retorna 1 si el alta fue exitosa sino 0 si hubo error
 *
 */
int altaCliente(eCliente clientes[], int tamcli, int* idCliente, eLocalidad localidades[], int tamloc);

/** \brief Muestra todos los clientes cargados
 *
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array clientes
 * \return int retorna 0 si hay clientes y 1 si no hay cargados
 *
 */
int mostrarClientes(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc);

/** \brief Muestra un solo cliente
 *
 * \param unCliente eCliente array de un cliente
 * \return void
 *
 */
void mostrarCliente(eCliente unCliente, eLocalidad localidades[], int tamloc);

/** \brief Recibe un id y recorre el array de clientes buscandolo
 *
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array clientes
 * \param idBuscar int* referencia del id a buscar
 * \return int retorna el indice si encuentra el cliente sino -1
 *
 */
int buscarCliente(eCliente clientes[], int tamcli, int* idBuscar);

/** \brief Menu con las opciones para modificar
 *
 * \return char la opcion seleccionada
 *
 */
char menuModificar();

/** \brief Modifica los campos elegidos por el usuario del cliente
 *
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array clientes
 * \return int retorna 1 si hay clientes sino retorna 0
 *
 */
int modificarClientes(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc);

/** \brief Se da de baja al cliente que elije el usuario
 *
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array clientes
 * \param idBuscar int* referencia del id que desea dar de baja
 * \return int retorna 0 si hay clientes para mostrar sino 1
 *
 */
int bajaCliente(eCliente clientes[], int tamcli,int* idBuscar, eLocalidad localidades[], int tamloc);

/** \brief Ordena los clientes
 *
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array clientes
 * \return int retorna 1 si hay clientes para mostrar sino 0
 *
 */
int ordenarClientes(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc);

/** \brief Carga el nombre del cliente recibiendo su id
 *
 * \param idCliente int id del cliente
 * \param clientes[] eCliente array de clientes
 * \param tamcli int tamaño del array clientes
 * \param nombre[] char donde guardar el nombre del cliente
 * \param nombre[] char donde guardar el apellido del cliente
 * \return int int retorna 1 si coincide el id sino 0
 *
 */
int cargarDescripcionCliente(int idCliente, eCliente clientes[], int tamcli, char nombre[],char apellido[]);

int cargarLocalidadPorId(eCliente clientes[], int tamcli, eLocalidad localidades[], int tamloc, int idCliente, char descripcionLocalidad[]);
