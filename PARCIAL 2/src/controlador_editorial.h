#ifndef controlador_editorial_H_INCLUDED
#define controlador_editorial_H_INCLUDED

#include "LinkedList.h"

/** \brief carga los datos desde el archivo csv texto.
 *
 * \param path char* ruta del archivo
 * \param this LinkedList* estructura de tipo LinkedList
 * \return int cantidad de empleados que se cargaron en memoria dinamica
 *
 */
int controller_loadFromText_Editorial(char* path, LinkedList* this);


#endif
