
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "ArrayEmployees.h"
#include <string.h>
#include <ctype.h>

/// @fn int menuPrincipal()
/// @brief muestra el menu principal de opciones
///
/// @return retorna la opcion elegida
int menuPrincipal();

/// @fn int menuModificacion()
/// @brief muestra el menu de opciones de modificacion de un empleado
///
/// @return retorna la opcion elegida
int menuModificacion();

/// @fn int menuPrincipalReportes(Employee*, int, eSector*, int)
/// @brief  menu de opciones de reportes
///
/// @param list
/// @param lengthEmp
/// @param sectors
/// @param lengthSec
/// @return retorna la opcion elegida
int menuPrincipalReportes(Employee* list, int lengthEmp, eSector* sectors, int lengthSec);

#endif /* MENU_H_ */
