
#include "LinkedList.h"

/** \brief carga los datos desde el archivo csv texto.
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int cantidad de empleados que se cargaron en memoria dinamica
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief carga los datos desde el archivo binario.
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int cantidad de empleados que se cargaron en memoria dinamica
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief alta de Empleado
 *
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int retorna 0 si hubo error sino retorna 1 si se dio de alta
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int retorna 0 si hubo error sino retorna 1 si se modifico
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief baja de empleado
 *
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \returnc
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief mostrar lista de empleados
 *
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int retorna -1 si hubo error sino retorna 1 si se mostro
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief ordenar los datos de empleados
 *
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int retorna 0
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief guarda los datos en el archivo modo texto csv
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int retorna 0 si hubo error al grabar los datos sino retorna 1 si se grabaron los datos en el archivo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief guarda los datos en el archivo modo binario
 *
 * \param path char* Path de ubicacion del archivo binario.
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \return int retorna 0 si hubo error al grabar los datos sino retorna 1 si se grabaron los datos en el archivo
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief busca el indice del empleado por ID
 *
 * \param pArrayListEmployee LinkedList* estructura de tipo LinkedList
 * \param id int ID del Empleado a buscar.
 * \return int retorna -1 si no existe el ID del empleado sino retorna el ID del empleado buscado
 *
 */
int  buscarIndexPorEmployeeID(LinkedList* pArrayListEmployee, int id);
