#ifndef editorial_H_INCLUDED
#define editorial_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>
#include "libro.h"

typedef struct
{
    int idEditorial;
    char nombre[128];
}eEditorial;

/** \brief  obtiene espacio en memoria para una nueva estructura de editorial
 *
 * \return eEditorial* retorna NULL si hubo un error sino retorna la direccion de memoria dinamica
 *
 */
eEditorial* editorial_new();

/** \brief  asigna parametros a una estructura
 *
 * \param pIdEditorial int* ID
 * \param pNombre char[] Nombre
 * \return eEditorial* retorna NULL si hubo un error sino retorna la direccion de memoria dinamica
 *
 */
eEditorial* editorial_newParametros(int* pIdEditorial, char pNombre[]);

/** \brief setea el ID a una estructura editorial
 *
 * \param this eEditorial* estructura editorial.
 * \param id int ID a setear
 * \return int retorna 0 si hubo error sino setea el ID
 *
 */
int editorial_setIdEditorial(eEditorial* this, int pIdEditorial);

/** \brief obtiene el id de la editorial de una estructura libro.
 *
 * \param this eEditorial* estructura editorial
 * \param pIdEditorial int id de la editorial
 * \return int retorna 0 si hubo error sino retorna 1 si pudo carga el id
 *
 */
int editorial_getIdEditorial(eEditorial* this, int* pIdEditorial);

/** \brief setea el nombre a una estructura Editorial.
 *
 * \param this eEditorial* estructura editorial.
 * \param pNombre[] char nombre a setear
 * \return int retorna 0 si hubo error sino setea el ID
 *
 */
int editorial_setNombre(eEditorial* this, char* pNombre);

/** \brief obtiene el nombre de la editorial de una estructura editorial.
 *
 * \param this eEditorial* estructura editorial
 * \param nombre[] char nombre
 * \return int retorna 0 si hubo error sino retorna 1 si pudo carga el nombre
 *
 */
int editorial_getNombre(eEditorial* this, char* pNombre);


#endif
