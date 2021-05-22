#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct{
    int id;
    char descripcion[21];
}eLocalidad;

#endif // LOCALIDAD_H_INCLUDED

int mostrarLocalidades(eLocalidad localidades[], int tamloc);

void mostrarLocalidad(eLocalidad unaLocalidad);

int cargarDescripcionLocalidad(int idLocalidad, eLocalidad localidades[], int tamloc, char descripcion[]);
