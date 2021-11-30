#ifndef controlador_libro_H_INCLUDED
#define controlador_libro_H_INCLUDED
#include "LinkedList.h"

/** \brief carga los datos desde el archivo csv texto.
 *
 * \param path char* ruta del archivo
 * \param this LinkedList* estructura de tipo LinkedList
 * \return int cantidad de empleados que se cargaron en memoria dinamica
 *
 */
int controller_loadFromTextLibro(char* path, LinkedList* this);

/** \brief mostrar listado de libros
 *
 * \param thisLibro LinkedList* estructura de tipo LinkedList libro
 * \param thisEditorial LinkedList* estructura de tipo LinkedList editorial
 * \return int retorna -1 si hubo error sino retorna 1 si se mostro
 *
 */
int controller_ListadoLibros(LinkedList* thisLibro, LinkedList* thisEditorial);

/** \brief guarda los datos en el archivo modo texto csv
 *
 * \param path char* ruta del archivo
 * \param this LinkedList* estructura de tipo LinkedList
 * \return int retorna 0 si hubo error al grabar los datos sino retorna 1 si se grabaron los datos en el archivo
 *
 */
int controller_saveAsText(char* path , LinkedList* this);

/** \brief ordenar los libros
 *
 * \param this LinkedList* estructura de tipo LinkedList
 * \return int retorna 0
 *
 */
int controller_sortLibro(LinkedList* this);

/** \brief filtra los libros de la editorial minoaturo y los graba en un csv
 *
 * \param this LinkedList* estructura de tipo LinkedList
 * \param this2 LinkedList* estructura de tipo LinkedList
 * \return int retorna -1 si hubo error al grabar los datos sino retorna la cantidad de registros
 *
 */
int controller_librosEditorialMinotauro(LinkedList* this,LinkedList* this2);
int controller_librosConDescuento(LinkedList* this,LinkedList* this2);
#endif
