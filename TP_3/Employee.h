#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include <string.h>

#define EMPLOYEE_MAX_NOMBRE 128
#define EMPLOYEE_MAX_Q_EMPLEADOS 1500
#define EMPLOYEE_MAX_HORAS_TABAJADAS 500
#define EMPLOYEE_MAX_SUELDO 8000000

typedef struct
{
    int id;
    char nombre[EMPLOYEE_MAX_NOMBRE];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief  obtiene espacio en memoria para una nueva estructura de Empleado
 *
 * \return Employee* retorna NULL si hubo un error sino retorna la direccion de memoria dinamica
 *
 */
Employee* employee_new();

/** \brief  asigna parametros a una estructura
 *
 * \param idStr char* ID
 * \param nombreStr char* Nombre
 * \param horasTrabajadasStr char* Horas Trabajadas
 * \return Employee* retorna NULL si hubo un error sino retorna la direccion de memoria dinamica
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);

/** \brief  asigna parametros a una estructura
 *
 * \param id int* ID
 * \param nombre[] char Nombre
 * \param horasTrabajadas int* Horas Trabajadas
 * \param sueldo int* Sueldo
 * \return Employee* retorna NULL si hubo un error sino retorna la direccion de memoria dinamica
 *
 */

Employee* employee_newParametrosIdNombreHorasSueldo(int* id, char nombre[], int* horasTrabajadas, int* sueldo);

/** \brief libera de memoria el empleado
 *
 * \param this Employee* direccion de memoria del empleado.
 */
void employee_delete(Employee* this);


/** \brief btiene el proximo ID de Empleado de un arreglo LinkedList.
 *
 * \param LinkedList* estructura de tipo LinkedList
 * \return idEmpleado int retorna -1 si hubo error sino retorna el id generado
 *
 */
int employee_getNextId(LinkedList* pArrayListEmployee);

/** \brief setea el ID a una estructura Empleado.
 *
 * \param this Employee* estructura Empleado.
 * \param id int ID a setear
 * \return int retorna 0 si hubo error sino setea el ID
 *
 */
int employee_setId(Employee* this,int id);

/** \brief obtiene el id del empleado de una estructura Empleado.
 *
 * \param this sEmployee* estructura Empleado
 * \param id int id del empleado
 * \return int retorna 0 si hubo error sino retorna 1 si pudo carga el id
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief setea el nombre a una estructura Empleado.
 *
 * \param this Employee* estructura Empleado.
 * \param nombre[] char nombre a setear
 * \return int int retorna 0 si hubo error sino setea el nombre
 *
 */
int employee_setNombre(Employee* this,char nombre[]);

/** \brief obtiene el nombre del empleado de una estructura Empleado.
 *
 * \param this sEmployee* estructura Empleado
 * \param nombre[] char nombre
 * \return int retorna 0 si hubo error sino retorna 1 si pudo carga el nombre
 *
 */
int employee_getNombre(Employee* this,char nombre[]);

/** \brief setea cantidad de horas trabajadas a una estructura Empleado.
 *
 * \param this Employee* estructura Empleado.
 * \param horasTrabajadas int Cantidad Horas trabajadas a setear
 * \return int int retorna 0 si hubo error sino setea el Cantidad Horas trabajadas
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief obtiene la cantidad de horas trabajadas del empleado de una estructura Empleado.
 *
 * \param this sEmployee* estructura Empleado
 * \param horasTrabajadas int cantidad de horas trabajadas del empleado
 * \return int retorna 0 si hubo error sino retorna 1 si pudo carga la cantidad de horas trabajadas del empleado
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief setea sueldo a una estructura Empleado.
 *
 * \param this Employee* estructura Empleado.
 * \param sueldo int sueldo trabajadas a setear
 * \return int retorna 0 si hubo error sino setea el sueldo
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief obtiene el sueldo del empleado de una estructura Empleado.
 *
 * \param this sEmployee* estructura Empleado
 * \param sueldo int sueldo
 * \return int retorna 0 si hubo error sino retorna 1 si pudo cargar el sueldo
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief imprime los datos del empleado
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * int retorna 0 si no pudo mostrar los datos sino 1 si pudo mostrarlo
 *
 */
void mostrarEmpleado(Employee* this);

/** \brief imprime los datos del empleado con cabecera
 *
 * \param this sEmployee* Direccion de memoria de un Empleado.
 * int retorna 0 si no pudo mostrar los datos sino 1 si pudo mostrarlo
 *
 */

int mostrarEmpleadoConCabecera(Employee* this);

/** \brief compara el ID  entre dos estructuras Employee*
 *
 * \param pElement1 void* puntero void a la estructura
 * \param pElement2 void* puntero void a la estructura
 * \return int retorna 0 si es el mismo id. -1 si es menor. 1 si es mayor.
 *
 */
int employeeCompararPorId(void* pElement1, void* pElement2);

/** \brief compara el nombre entre dos estructuras Employee*
 *
 * \param pElement1 void* puntero void a la estructura
 * \param pElement2 void* puntero void a la estructura
 * \return int retorna 0 si es el mismo id. -1 si es menor. 1 si es mayor.
 *
 */
int employeeCompararPorNombre(void* pElement1, void* pElement2);

/** \brief compara cantidad de horas trabajadas entre dos estructuras Employee*
 *
 * \param pElement1 void* puntero void a la estructura
 * \param pElement2 void* puntero void a la estructura
 * \return int retorna 0 si es el mismo id. -1 si es menor. 1 si es mayor.
 *
 */
int employeeCompararPorHorasTrabajadas(void* pElement1, void* pElement2);

/** \brief compara sueldo entre dos estructuras Employee*
 *
 * \param pElement1 void* puntero void a la estructura
 * \param pElement2 void* puntero void a la estructura
 * \return int retorna 0 si es el mismo id. -1 si es menor. 1 si es mayor.
 *
 */
int employeeCompararPorSueldo(void* pElement1, void* pElement2);
#endif // employee_H_INCLUDED
