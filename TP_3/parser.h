#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "Employee.h"

/** \brief recorre datos de la estructura Employee desde el archivo texto csv y los agrega al LinkedList
*
 * \param pFile FILE* puntero al archivo
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int Cantidad de estructuras de tipo Empleado parseadas desde archivo de texto.
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee);

/** \brief recorre datos de la estructura Employee desde el archivo binario y los agrega al LinkedList
*
 * \param pFile FILE* puntero al archivo
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int Cantidad de estructuras de tipo Empleado parseadas desde archivo de texto.
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee);

#endif // PARSER_H_INCLUDED
