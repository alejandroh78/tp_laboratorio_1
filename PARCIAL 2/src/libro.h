#ifndef estructura_H_INCLUDED
#define estructura_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include "editorial.h"

typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    int  precio;
    int idEditorial;
}eLibro;

/** \brief  obtiene espacio en memoria para una nueva estructura de libro
 *
 * \return eLibro* retorna NULL si hubo un error sino retorna la direccion de memoria dinamica
 *
 */
eLibro* libro_new();

/** \brief  asigna parametros a una estructura
 *
 * \param pIdLibro int* ID del libro
 * \param pTitulo char[] titulo del libro
 * \param pAutor char[] autor del libro
 * \param pPrecio int* precio del libro
 * \param pIdEditorial int* id de la editorial
 * \return eEditorial* retorna NULL si hubo un error sino retorna la direccion de memoria dinamica
 *
 */
eLibro* libro_newParametros(int* pIdLibro, char pTitulo[], char pAutor[], int* pPrecio, int* pIdEditorial);

/** \brief setea el ID a una estructura libro
 *
 * \param this eLibro* estructura editorial.
 * \param pId int ID a setear
 * \return int retorna 0 si hubo error sino setea el ID
 *
 */
int libro_setId(eLibro* this, int pId);

/** \brief obtiene el id del libro de una estructura libro.
 *
 * \param this eLibro* estructura libro
 * \param pId int id del libro
 * \return int retorna 0 si hubo error sino retorna 1 si pudo carga el id
 *
 */
int libro_getId(eLibro* this, int* pId);

/** \brief setea el titulo del libro estructura libro
 *
 * \param this eLibro* estructura libro.
 * \param pTitulo[] char titulo del libro a setear
 * \return int retorna 0 si hubo error sino setea el ID
 *
 */
int libro_setTitulo(eLibro* this, char pTitulo[]);

/** \brief obtiene el titulo del libro de una estructura libro.
 *
 * \param this eLibro* estructura libro
 * \param pTitulo[] char titulo del libro
 * \return int retorna 0 si hubo error sino retorna 1 si pudo carga el id
 *
 */
int libro_getTitulo(eLibro* this, char pTitulo[]);

/** \brief setea el ID a una estructura libro
 *
 * \param this eLibro* estructura libro.
 * \param pAutor[] char autor del libro a setear
 * \return int retorna 0 si hubo error sino setea el ID
 *
 */
int libro_setAutor(eLibro* this, char pAutor[]);

/** \brief obtiene el autor del libro de una estructura libro.
 *
 * \param this eLibro* estructura libro
 * \param pAutor[] char autor del libro
 * \return int retorna 0 si hubo error sino retorna 1 si pudo carga el id
 *
 */
int libro_getAutor(eLibro* this, char pAutor[]);

/** \brief setea el precio a una estructura libro
 *
 * \param this eLibro* estructura libro.
 * \param pPrecio int precio del libro a setear
 * \return int retorna 0 si hubo error sino setea el ID
 *
 */
int libro_setPrecio(eLibro* this, int pPrecio);

/** \brief obtiene el precio libro de una estructura libro.
 *
 * \param this eLibro* estructura libro
 * \param pPrecio int precio del libro
 * \return int retorna 0 si hubo error sino retorna 1 si pudo carga el id
 *
 */
int libro_getPrecio(eLibro* this, int* pPrecio);

/** \brief setea el id de la editorial a una estructura libro
 *
 * \param this eLibro* estructura libro.
 * \param pIdEditorial int ID de la editorial a setear
 * \return int retorna 0 si hubo error sino setea el ID
 *
 */
int libro_setIdEditorial(eLibro* this, int pIdEditorial);

/** \brief obtiene el id de la editorial de una estructura libro.
 *
 * \param this eLibro* estructura libro
 * \param pIdEditorial int id de la editorial del libro
 * \return int retorna 0 si hubo error sino retorna 1 si pudo carga el id
 *
 */
int libro_getIdEditorial(eLibro* this, int* pIdEditorial);

int libro_CompararPorNombre(void* pElement1, void* pElement2);
int editorial_filtroMinotauro(void* this);
int editorial_filtroPlanetaSigloXXI(void* this);
void calcularDescuento(void* emp);

#endif
