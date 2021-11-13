
#include <string.h>
#include "Controller.h"
#include "parser.h"
#include "Employee.h"
#include "menu.h"
#include "input.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{

    int retorno = 0;
    FILE* archivo = NULL;

    if(pArrayListEmployee != NULL)
    {
    	archivo = fopen(path, "r");

        if(archivo != NULL)
        {
        	retorno = parser_EmployeeFromText(archivo, pArrayListEmployee);
        }
    }

    fclose(archivo);

    return retorno;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    FILE* archivo = NULL;

    if(pArrayListEmployee != NULL)
    {
    	archivo = fopen(path, "rb");

        if(archivo != NULL)
        {
        	retorno = parser_EmployeeFromBinary(archivo, pArrayListEmployee);
        }
    }

    return retorno;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

	int id;
    char nombre[EMPLOYEE_MAX_NOMBRE];
    int horasTrabajadas;
    int sueldo;

    Employee* auxEmployee = NULL;

    if(pArrayListEmployee != NULL)
    {
        id = employee_getNextId(pArrayListEmployee);

        if(id != -1
           && !inputString(nombre, "Ingrese Nombre: ", "Error, Ingrese Nombre: ", 1,  EMPLOYEE_MAX_NOMBRE)
           && !inputNumberInt(&horasTrabajadas, "Ingrese Cantidad de Horas Trabajadas: ", "Error, Ingrese Cantidad de Horas Trabajadas: ", 0, EMPLOYEE_MAX_HORAS_TABAJADAS)
           && !inputNumberInt(&sueldo, "Ingrese Sueldo: ", "Error, Ingrese Sueldo: " , 0, EMPLOYEE_MAX_SUELDO))
        {
        	auxEmployee = employee_newParametrosIdNombreHorasSueldo(&id, nombre, &horasTrabajadas, &sueldo);

            if(auxEmployee != NULL && ll_add(pArrayListEmployee, (Employee*)auxEmployee) == 0)
            {
            	retorno = 1;
            }
        }
    }

    return retorno;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    int idEmpleado;
    int indexEmpleado;
    int idEmpleadoMax;

    int controlMenu;
    int opcionMenu;

    Employee* auxEmployee = employee_new();
    Employee* auxEmployeeModificado;

    if(pArrayListEmployee != NULL && auxEmployee != NULL)
    {
    	idEmpleadoMax = employee_getNextId(pArrayListEmployee) - 1;

        printf("\n");
        if(idEmpleadoMax > 0 && !inputNumberInt(&idEmpleado, "Ingrese el ID del Empleado que desea modificar: ", "Error, Ingrese el ID del Empleado que desea modificar: ", 1, idEmpleadoMax))
        {
        	indexEmpleado = buscarIndexPorEmployeeID(pArrayListEmployee, idEmpleado);

            if(indexEmpleado != -1)
            {
            	auxEmployee = (Employee*)ll_get(pArrayListEmployee, indexEmpleado);

                if(auxEmployee != NULL)
                {
                	auxEmployeeModificado = employee_newParametrosIdNombreHorasSueldo(&auxEmployee->id,
																						auxEmployee->nombre,
																						&auxEmployee->horasTrabajadas,
																						&auxEmployee->sueldo
																						);

                    do
                    {
                        system("cls");

                        if(mostrarEmpleadoConCabecera(auxEmployeeModificado) == 0)
                        {
                            break;
                        }

                        controlMenu = menuEdicion(&opcionMenu);

                        switch(opcionMenu)
                        {
                        case 1:
                            if(!inputString(auxEmployeeModificado->nombre, "Ingrese Nombre: ", "Error, Ingrese Nombre:", 1, EMPLOYEE_MAX_NOMBRE)
                               && employee_setNombre(auxEmployeeModificado, auxEmployeeModificado->nombre))
                            {
                                printf("Nombre actualizado, RECUERDE GRABAR LOS CAMBIOS, OPCION 4 ! \n");
                            }
                            break;
                        case 2:
                            if(!inputNumberInt(&auxEmployeeModificado->horasTrabajadas, "Ingrese Cantidad de Horas Trabajadas", "Error, Ingrese Cantidad de Horas Trabajadas", 0, EMPLOYEE_MAX_HORAS_TABAJADAS)
                               && employee_setHorasTrabajadas(auxEmployeeModificado, auxEmployeeModificado->horasTrabajadas))
                            {
                                printf("Horas Trabajadas actualizado, RECUERDE GRABAR LOS CAMBIOS, OPCION 4 ! \n");
                            }
                            break;
                        case 3:
                            if(!inputNumberInt(&auxEmployeeModificado->sueldo, "Ingrese Sueldo: ", "Error, Ingrese Sueldo:", 0, EMPLOYEE_MAX_SUELDO)
                               && employee_setSueldo(auxEmployeeModificado, auxEmployeeModificado->sueldo))
                            {
                                printf("Sueldo actualizado, RECUERDE GRABAR LOS CAMBIOS, OPCION 4 ! \n");
                            }
                            break;
                        case 4:
                            system("cls");

                            printf("Datos del Empleado antes de modificar\n");
                            if(mostrarEmpleadoConCabecera(auxEmployee))
                            {
                            	printf("\n");
                            	printf("Datos del Empleado modificado\n");
                                if(mostrarEmpleadoConCabecera(auxEmployeeModificado)
                                   && inputContinuar("Confirme si desea aplicar los cambios (S)i /  (N)o: ")
                                   && ll_set(pArrayListEmployee, indexEmpleado, (Employee*)auxEmployeeModificado) == 0)
                                {
                                	retorno = 1;
                                }
                            }
                            controlMenu = 1;
                            break;
                        case 5:
                        	controlMenu = 1;
                        	break;

                        }

                        if(opcionMenu < MENU_EDICION_Q)
                        {
                            pausa(MENSAJE_PAUSA);
                        }
                    }while(controlMenu == 0);
                }
            }
            else
            {
                printf("El ID del Empleado es inexistente \n");
            }
        }
    }

    return retorno;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 0;

    int idEmpleado;
    int indexEmpleado;
    int idEmpleadoMax;

	Employee* auxEmployee = employee_new();

	    if(pArrayListEmployee != NULL && auxEmployee != NULL)
	    {
	    	idEmpleadoMax = employee_getNextId(pArrayListEmployee) - 1;
	        printf("\n");

	        if(idEmpleadoMax > 0 && !inputNumberInt(&idEmpleado, "Ingrese el ID del Empleado que desea dar de baja: ", "Error, Ingrese el ID del Empleado que desea dar de baja: ", 1, idEmpleadoMax))
	        {
	        	indexEmpleado = buscarIndexPorEmployeeID(pArrayListEmployee, idEmpleado);

	            if(indexEmpleado != -1)
	            {
	            	auxEmployee = (Employee*)ll_get(pArrayListEmployee, indexEmpleado);

	                if(auxEmployee != NULL
	                   && mostrarEmpleadoConCabecera(auxEmployee)
	                   && inputContinuar("\n Confirme la baja el empleado (S)i / (N)o: "))
	                {
	                    if(ll_remove(pArrayListEmployee, indexEmpleado) == 0)
	                    {
	                    	retorno = 1;
	                    	employee_delete(auxEmployee);
	                        auxEmployee = NULL;
	                    }
	                }
	            }
	            else
	            {
	                printf("El ID del Empleado es inexistente\n");
	            }
	        }
	    }

	    return retorno;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int cantidadEmpleados;
    int i;

    if(pArrayListEmployee!=NULL){

    	retorno = 1;
        Employee* auxEmployee;

        cantidadEmpleados = ll_len(pArrayListEmployee);

        printf("%4s %14s %12s %12s\n","ID","NOMBRE","HORAS","SUELDO");
        printf("***************************************************\n");

        for(i=0; i<cantidadEmpleados; i++){
        	auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            mostrarEmpleado(auxEmployee);
        }
    }

    return retorno;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;

    int controlMenu;
    int opcionMenu;

    int opcionOrdenamiento;

    if(pArrayListEmployee != NULL)
    {
        if(ll_len(pArrayListEmployee) > 0)
        {
            do
            {
            	controlMenu = menuOrdenamiento(&opcionMenu);

                if((opcionMenu >= 1 && opcionMenu < MENU_ORDENAMIENTO_Q)
                   && !inputNumberInt(&opcionOrdenamiento, "Ingrese el orden de datos: [1] Asc - [0] Desc: ", "Error, Ingrese el orden de datos: [1] Asc - [0] Desc: ", 0, 1))
                {
                    printf("Procesando...al finalizar se informa resultado\n");

                    switch(opcionMenu)
                    {
                    case 1: //ID
                        if(ll_sort(pArrayListEmployee, employeeCompararPorId, opcionOrdenamiento) == 0)
                        {
                            printf("Los datos fueron ordenados por ID\n");
                        }
                        break;
                    case 2: //nombre
                        if(ll_sort(pArrayListEmployee, employeeCompararPorNombre, opcionOrdenamiento) == 0)
                        {
                            printf("Los datos fueron ordenados por Nombre\n");
                        }
                        break;
                    case 3: //horas trabajadas
                        if(ll_sort(pArrayListEmployee, employeeCompararPorHorasTrabajadas, opcionOrdenamiento) == 0)
                        {
                            printf("Los datos fueron ordenados por Horas Trabajadas\n");
                        }
                        break;
                    case 4: //sueldo
                        if(ll_sort(pArrayListEmployee, employeeCompararPorSueldo, opcionOrdenamiento) == 0)
                        {
                            printf("Los datos fueron ordenados por Sueldo\n");
                        }
                        break;
                    }
                }
                else
                {
                    if(opcionMenu == MENU_ORDENAMIENTO_Q)
                    {
                    	retorno = 1;
                        break;
                    }
                }

            }while(controlMenu == 0);
        }
    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivo = NULL;
    int retorno = 0;
    int cantidadEmpleados;
    int i;
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
    	cantidadEmpleados = ll_len(pArrayListEmployee);

    	archivo = fopen(path, "w");

        if(archivo != NULL && cantidadEmpleados > 0 && cantidadEmpleados <= EMPLOYEE_MAX_Q_EMPLEADOS
           && fprintf(archivo, "id,nombre,horasTrabajadas,sueldo\n") != -1)
        {
            for(i = 0; i < cantidadEmpleados; i++)
            {
            	auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

                if(auxEmployee == NULL
                   || fprintf(archivo, "%d,%s,%d,%d\n",
                		   auxEmployee->id,
						   auxEmployee->nombre,
						   auxEmployee->horasTrabajadas,
						   auxEmployee->sueldo) == -1)
                {
                    break;
                }
            }
        }

        if(i > 0 && i == cantidadEmpleados)
        {
        	retorno = 1;
        }
    }

    fclose(archivo);

    return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivo = NULL;
    int retorno = 0;
    int cantidadEmpleados;
    int i;
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
    	cantidadEmpleados = ll_len(pArrayListEmployee);

    	archivo = fopen(path, "wb");

        if(archivo != NULL && cantidadEmpleados > 0 && cantidadEmpleados <= EMPLOYEE_MAX_Q_EMPLEADOS)
        {
            for(i = 0; i < cantidadEmpleados; i++)
            {
            	auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

                if(auxEmployee == NULL || fwrite((Employee*)auxEmployee, sizeof(Employee), 1, archivo) != 1)
                {
                    break;
                }
            }
        }

        if(i > 0 && i == cantidadEmpleados)
        {
        	retorno = 1;
        }
    }

    fclose(archivo);

    return retorno;
}



int  buscarIndexPorEmployeeID(LinkedList* pArrayListEmployee, int id)
{
    int retorno = -1;
    int cantidadEmpleados;
    int i;
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
    	cantidadEmpleados = ll_len(pArrayListEmployee);

        if(cantidadEmpleados > 0)
        {
            for(i = 0; i < cantidadEmpleados; i++)
            {
            	auxEmployee = ll_get(pArrayListEmployee, i);

                if(auxEmployee != NULL && auxEmployee->id == id)
                {
                	retorno = i;
                    break;
                }
            }
        }
    }

    return retorno;
}
