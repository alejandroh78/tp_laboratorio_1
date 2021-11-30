#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "libro.h"

/** \brief recorre datos de la estructura desde el archivo texto csv y los agrega al LinkedList
*
 * \param pFile FILE* puntero al archivo
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int Cantidad de estructuras de tipo libro parseadas desde archivo de texto.
 *
 */
int parser_FromTextLibro(FILE* pFile, LinkedList* pArrayList);
/** \brief recorre datos de la estructura  desde el archivo texto csv y los agrega al LinkedList
*
 * \param pFile FILE* puntero al archivo
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int Cantidad de estructuras de tipo editorial parseadas desde archivo de texto.
 *
 */
int parser_FromText_Editorial(FILE* pFile, LinkedList* pArrayList);


#endif // PARSER_H_INCLUDED
