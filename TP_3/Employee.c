#include "Employee.h"


int employee_getId(Employee* this, int* id)
{
    int retorno = 0;

    if(this != NULL)
    {
        *id = this->id;
        retorno = 1;
    }

    return retorno;
}

int employee_setId(Employee* this, int id)
{
    int retorno = 0;

    if(this != NULL && id > 0 && id <= EMPLOYEE_MAX_Q_EMPLEADOS) //FALTA DEFINE ID ID MINIMO Y MAXIMO
    {
        this->id = id;
        retorno = 1;
    }

    return retorno;
}

int employee_getNombre(Employee* this, char nombre[])
{
    int retorno = 0;

    if(this != NULL && this->nombre !=NULL)
    {
        strcpy(nombre, this->nombre);
        retorno = 1;
    }

    return retorno;
}

int employee_setNombre(Employee* this, char nombre[])
{
    int retorno = 0;

    if(this != NULL && this->nombre !=NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }

    return retorno;

}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = 0;

    if(this != NULL && horasTrabajadas >= 0 && horasTrabajadas <= EMPLOYEE_MAX_HORAS_TABAJADAS) //METER DEFINE MAXIMO DE HORAS TRABAJADAS
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }

    return retorno;
}

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = 0;

    if(this != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }

    return retorno;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = 0;

    if(this != NULL && sueldo >= 0 && sueldo <= EMPLOYEE_MAX_SUELDO)   //METER DEFINE MAXIMO SUELDO
    {
        this->sueldo = sueldo;
        retorno = 1;
    }

    return retorno;
}
Employee* employee_new()
{
    Employee* auxEmployee;

    auxEmployee = (Employee*)malloc(sizeof(Employee));

    return auxEmployee;
}

Employee* employee_newParametrosIdNombreHorasSueldo(int* id, char nombre[], int* horasTrabajadas, int* sueldo)
{

    Employee* auxEmployee = employee_new();

    if(auxEmployee != NULL
       && (!employee_setId(auxEmployee, *id)
       || !employee_setNombre(auxEmployee, nombre)
       || !employee_setHorasTrabajadas(auxEmployee, *horasTrabajadas)
       || !employee_setSueldo(auxEmployee, *sueldo)))
    {
    	employee_delete(auxEmployee);
    	auxEmployee = NULL;
    }

    return auxEmployee;
}


void employee_delete(Employee* this)
{
    free(this);
}

int employee_getNextId(LinkedList* pArrayListEmployee)
{
    int idEmpleado = -1;
    int cantidadEmpleados = 0;
    int i;
    int contador = 0;
    Employee* auxEmployee;

    if(pArrayListEmployee != NULL)
    {
    	cantidadEmpleados = ll_len(pArrayListEmployee);

        if(cantidadEmpleados > 0)
        {
            for(i = 0; i < cantidadEmpleados; i++)
            {
            	auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);

                if(auxEmployee != NULL)
                {
                    if(contador == 0)
                    {
                    	idEmpleado = auxEmployee->id;
                    }
                    else
                    {
                        if(auxEmployee->id > idEmpleado && auxEmployee->id < EMPLOYEE_MAX_Q_EMPLEADOS)
                        {
                        	idEmpleado = auxEmployee->id;
                        }
                    }
                    contador++;
                }
            }
        }

        if(contador > 0)
        {
        	idEmpleado++;
        }
        else
        {
        	idEmpleado = 1;
        }
    }

    return idEmpleado;
}

void mostrarEmpleado(Employee* this){

    if(this!=NULL){
        printf("%4d %15s %8d %14.d\n",this->id,this->nombre,this->horasTrabajadas,this->sueldo);
    }else{
        printf("No hay empleados para mostrar\n");
    }
}

int mostrarEmpleadoConCabecera(Employee* this)
{
    int retorno = -1;
    int id;
    char nombre[EMPLOYEE_MAX_NOMBRE];
    int horasTrabajadas;
    int sueldo;

    if(this != NULL
       && employee_getId(this, &id)
       && employee_getNombre(this, nombre)
       && employee_getHorasTrabajadas(this, &horasTrabajadas)
       && employee_getSueldo(this, &sueldo))
    {
        printf("\n");
        printf("  ID         NOMBRE          HORAS       SUELDO     \n");
        printf("****************************************************\n");
        printf(" %4d  %12s  %12d  %12d \n", id, nombre,  horasTrabajadas, sueldo);
        retorno = 1;
    }

    return retorno;
}



int employeeCompararPorId(void* pElement1, void* pElement2)
{
    int retorno;
    int comparacion;

    Employee* auxEmployee1 = (Employee*)pElement1;
    Employee* auxEmployee2 = (Employee*)pElement2;

    if(auxEmployee1 != NULL && auxEmployee2 != NULL)
    {
    	comparacion = auxEmployee1->id - auxEmployee2->id;

        if(comparacion > 0)
        {
        	retorno = 1;
        }
        else
        {
            if(comparacion < 0)
            {
            	retorno = -1;
            }
            else
            {
            	retorno = 0;
            }
        }
    }

    return retorno;
}

int employeeCompararPorNombre(void* pElement1, void* pElement2)
{
    int retorno;
    Employee* auxEmployee1 = (Employee*)pElement1;
    Employee* auxEmployee2 = (Employee*)pElement2;

    if(auxEmployee1 != NULL && auxEmployee2 != NULL)
    {
    	retorno = strcmp(auxEmployee1->nombre, auxEmployee2->nombre);
    }

    return retorno;
}

int employeeCompararPorHorasTrabajadas(void* pElement1, void* pElement2)
{
    int retorno;
    int comparacion;
    Employee* auxEmployee1 = (Employee*)pElement1;
    Employee* auxEmployee2 = (Employee*)pElement2;

    if(auxEmployee1 != NULL && auxEmployee2 != NULL)
    {
    	comparacion = auxEmployee1->horasTrabajadas - auxEmployee2->horasTrabajadas;

        if(comparacion > 0)
        {
        	retorno = 1;
        }
        else
        {
            if(comparacion < 0)
            {
            	retorno = -1;
            }
            else
            {
            	retorno = 0;
            }
        }
    }

    return retorno;
}

int employeeCompararPorSueldo(void* pElement1, void* pElement2)
{
    int retorno;
    int comparacion;
    Employee* auxEmployee1 = (Employee*)pElement1;
    Employee* auxEmployee2 = (Employee*)pElement2;

    if(auxEmployee1 != NULL && auxEmployee2 != NULL)
    {
    	comparacion = auxEmployee1->sueldo- auxEmployee2->sueldo;

        if(comparacion > 0)
        {
        	retorno = 1;
        }
        else
        {
            if(comparacion < 0)
            {
            	retorno = -1;
            }
            else
            {
            	retorno = 0;
            }
        }
    }

    return retorno;
}
