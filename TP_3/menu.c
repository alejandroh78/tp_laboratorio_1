#include "menu.h"

int menuPrincipal(int* opcion)
{
    int retorno = -1;

    system("cls");

    printf("********************************************************************************\n");
    printf("*                                MENU PRINCIPAL                                *\n");
    printf("********************************************************************************\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).    \n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).  \n");
    printf("3. Alta de Empleado                                                             \n");
    printf("4. Modificar datos de Empleado                                                  \n");
    printf("5. Baja de Empleado                                                             \n");
    printf("6. Listar Empleados                                                             \n");
    printf("7. Ordenar Empleados                                                            \n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).      \n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario).    \n");
    printf("10. Salir del programa                                                          \n\n");

    if(!inputNumberInt(opcion, "Elija una opcion del menu: ", "Error, Elija una opcion del menu: ", 1, MENU_PRINCIPAL_Q))
    {
    	retorno = 0;
    }

    return retorno;
}

int menuOrdenamiento(int* opcion)
{
    int retorno = -1;

    system("cls");

    printf("*********************************************\n");
    printf("*         MENU PARA ORDENAR LOS DATOS       *\n");
    printf("*********************************************\n");
    printf("1. Ordenar por ID                             \n");
    printf("2. Ordenar por Nombre                         \n");
    printf("3. Ordenar por Horas Trabajadas               \n");
    printf("4. Ordenar por Salario                        \n");
    printf("5. Volver al menu principal                   \n\n");

    if(!inputNumberInt(opcion, "Elija una opcion del menu: ", "Error, Elija una opcion del menu: ", 1, MENU_ORDENAMIENTO_Q))
    {
    	retorno = 0;
    }

    return retorno;
}

int menuEdicion(int* opcion)
{
    int retorno = -1;
    printf("****************************************************\n");
    printf("*         MODIFICACION DE DATOS EL EMPLEADO        *\n");
    printf("****************************************************\n");
    printf("1. Editar Nombre                             \n");
    printf("2. Editar Horas Trabajadas                   \n");
    printf("3. Editar Sueldo                             \n");
    printf("4. Grabar las modificaciones                 \n");
    printf("5. Volver al Menu Principal                  \n\n");

    if(!inputNumberInt(opcion, "Elija una opcion del menu: ", "Error, Elija una opcion del menu: ", 1, MENU_EDICION_Q))
    {
    	retorno = 0;
    }

    return retorno;
}
