#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Employee.h"
#include "input.h"


int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int id;
    char nombre[EMPLOYEE_MAX_NOMBRE];
    int horasTrabajadas;
    int sueldo;

    int contador = 0;
    char buffer[4][EMPLOYEE_MAX_NOMBRE];
    Employee* auxEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]) == 4
               && inputStringToInt(buffer[0], &id)
               && buffer[1] != NULL
			   && strcpy(nombre,buffer[1])
			   && inputStringToInt(buffer[2], &horasTrabajadas)
               && inputStringToInt(buffer[3], &sueldo)
            )
            {
            	auxEmployee = employee_newParametrosIdNombreHorasSueldo(&id, buffer[1], &horasTrabajadas, &sueldo);

                if(auxEmployee != NULL && ll_len(pArrayListEmployee) < EMPLOYEE_MAX_Q_EMPLEADOS
                					   && ll_add(pArrayListEmployee, (Employee*)auxEmployee) == 0)
                {
                	contador++;
                }
            }
        }
    }

    return contador;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    int contador = 0;
    Employee auxEmployeeEstatico;
    Employee* auxEmployeeDinamico = NULL;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if(fread((Employee*)&auxEmployeeEstatico, sizeof(Employee), 1, pFile) == 1)
            {
            	auxEmployeeDinamico = employee_newParametrosIdNombreHorasSueldo(&(auxEmployeeEstatico.id),
            			auxEmployeeEstatico.nombre, &(auxEmployeeEstatico.horasTrabajadas), &(auxEmployeeEstatico.sueldo));


                if(auxEmployeeDinamico != NULL
                   && ll_len(pArrayListEmployee) < EMPLOYEE_MAX_Q_EMPLEADOS
                   && ll_add(pArrayListEmployee, (Employee*)auxEmployeeDinamico) == 0)
                {
                	contador++;
                }
            }
        }
    }

    return contador;
}
