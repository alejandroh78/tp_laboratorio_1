#ifndef MENU_H_
#define MENU_H_

#include "input.h"

#define MENU_PRINCIPAL_Q 7
#define MENU_ORDENAMIENTO_Q 2


/** \brief menu principal del programa.
*
* \param opcion int* Opcion elegida del menu.
* \return int error retorna -1 sino retorna la opcion elegida en el menu.
*/
int menuPrincipal(int* opcion);

/** \brief menu de ordenamiento del arreglo.
*
* \param opcion int* Opcion elegida del menu.
* \return int error retorna -1 sino retorna la opcion elegida en el menu.
*
*/
int menuOrdenamiento(int* opcion);

/** \brief menu de edicion para un Empleado
*
* \param opcion int* Opcion elegida del menu.
* \return int error retorna -1 sino retorna la opcion elegida en el menu.
*/


#endif /* MENU_H_ */
