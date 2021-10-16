#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED


typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

typedef struct
{
    int idSector;
    char nameSector[30];

}eSector;

/// @fn int getNewEmployeeId()
/// @brief generar un nuevo ID de Empleados.
///
/// @return el id para cada Empleado.
int getNewEmployeeId();

/// @fn int initEmployees(Employee[], int)
/// @brief Funcion que blanquea las posiciones el array Empleados
///         colocando un flag isEmpty en TRUE.
///
/// @param list Employee Direccion de memoria del inicio del array de Empleados.
/// @param tam tamaño del array
/// @return
int initEmployees(Employee list[],int tam);

/// @fn int addEmployee(Employee[], int, int, char[], char[], float, int)
/// @brief agrega un Empleado con los valores cargados como parametros en el primer lugar vacio de la lista ingresada.
///
/// @param list Employee Direccion de memoria del inicio del array de Empleados
/// @param len Longitud del array
/// @param id ID del Empleado
/// @param name char Nombre del Empleado.
/// @param lastName char Apellido del Empleado.
/// @param salary float Salario del Empleado.
/// @param sector ID sector del Empleado.
/// @return
int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector);

/// @fn int findEmployeeById(Employee[], int, int)
/// @brief  obtiene el indice del array de Empleados del ID ingresado como parametro
///
/// @param list Employee Direccion de memoria del inicio del array de Empleados
/// @param len int Longitud del array
/// @param id Campo ID del Empleado a buscar
/// @return
int findEmployeeById(Employee list[], int len, int id);

/// @fn int removeEmployee(Employee[], int, int)
/// @brief borra un Empleado de una lista utilizando el ID informando
///
/// @param list Employee Direccion de memoria del inicio del array de Empleados.
/// @param tam int Longitud del array de Empleados.
/// @param id int Campo ID del Empleado a borrar.
/// @return  -1 Si hubo un error para borrar el Empleado / 0 si se borro el empleado
int removeEmployee(Employee list[],int tam, int id);

/// @fn void printEmployee(Employee, eSector[], int)
/// @brief muestra un empleado con formato por pantalla
///
/// @param list Employee Tipo de Dato de Empleado
/// @param sec array con el listado de sectores
/// @param tamSec longitud del array de sectores
void printEmployee(Employee list, eSector sec[], int tamSec);

/// @fn int printEmployees(Employee[], int, eSector[], int)
/// @brief muestra el listado de empleados por pantalla
///
/// @param list Employee array de Empleados
/// @param tam Longitud del array de Empleados
/// @param sector eSector array de sectores
/// @param tamSec  Longitud del array de Sectores
/// @return retorna -1 si no se pudo mostrar / 0 si se mostro el listado
int printEmployees(Employee list[], int tam, eSector sector[], int tamSec);

/// @fn int printSectors(eSector[], int)
/// @brief muestra el listado de sectores por pantalla
///
/// @param sector array de sectores
/// @param tamSec longitud del array de sectores
/// @return retorna la cantidad de sectores
int printSectors(eSector sector[], int tamSec);

/// @fn int findSectorById(eSector[], int, int)
/// @brief
///
/// @param list array de sectores
/// @param tam longitud del array de sectores
/// @param id id del sector
/// @return
int findSectorById(eSector list[], int tam,int id);

/// @fn int checkEmployeesExists(Employee[], int)
/// @brief verifica si un empleado esta cargado
///
/// @param list array de empleados
/// @param tam longitud array de empleado
/// @return retorna 1 si esta ingresado / 0 si no esta ingresado
int checkEmployeesExists(Employee list[], int tam);

/// @fn void swapEmployees(Employee*, int, int, int)
/// @brief  ordernar el array
///
/// @param list array de empleado
/// @param length longitud del array de empleado
/// @param i posicion de i
/// @param j posicion de j
void swapEmployees(Employee* list, int length, int i, int j);

/// @fn int sortEmployeesByName(Employee*, int, int)
/// @brief  ordenar el array por nombre del empleado
///
/// @param list array de empleado
/// @param lengthEmp longitud del array de empleado
/// @param order orden 1 asc 2 desc
/// @return
int sortEmployeesByName(Employee* list, int lengthEmp, int order);

/// @fn void reportTotalEmployeeCalc(Employee[], int, eSector[], int)
/// @brief muestra por pantalla
/// Total de sueldos
/// Promedio de Sueldos
/// Total de empleados que superan el salario promedio
///
/// @param list array de empleados
/// @param tam longitud del array de empleados
/// @param sector array de sectores
/// @param tamSec longitud del array de sectores
void reportTotalEmployeeCalc(Employee list[], int tam, eSector sector[], int tamSec);

#endif
