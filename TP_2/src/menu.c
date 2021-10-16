#include "menu.h"


int menuPrincipal()
{
    int opcion;

    opcion = 0;
    system("cls");
    system("color 03");
    printf("***********************************************************************************************************\n");
    printf("                                    Menu Principal \n");
    printf("***********************************************************************************************************\n");
    printf("1)ALTA EMPLEADO\n");
    printf("2)MODIFICAR EMPLEADO\n");
    printf("3)BAJA EMPLEADO\n");
    printf("4)INFORMES\n");
    printf("5)SALIR\n");

    inputNumberInt(&opcion, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 5);

    return opcion;
}


int menuModificacion()
{
    int opcion;
    printf("***********************************************************************************************************\n");
    printf("Opciones disponibles para modificar el empleado\n");
    printf("***********************************************************************************************************\n");
    printf("1)Modificar Nombre\n");
    printf("2)Modificer apellido\n");
    printf("3)Modificar salario\n");
    printf("4)Modificer sector\n\n");

    inputNumberInt(&opcion, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 5);

    return opcion;


}


int menuPrincipalReportes(Employee* list, int lengthEmp, eSector* sectors, int lengthSec){

    int validation=0;
    int opcionMenu = 0;

    printf("***********************************************************************************************************\n");
    printf("                                    Menu de Reportes \n");
    printf("***********************************************************************************************************\n");
    printf("1- Empleados por orden alfabetico asc\n");
    printf("2- Empleados por orden alfabetico desc\n");
    printf("3- Reporte total y promedio de salarios\n\n");

    inputNumberInt(&opcionMenu, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 3);

    switch(opcionMenu){
        case 1:
        	sortEmployeesByName(list,lengthEmp,1);

            printf("***********************************************************************************************************\n");
            printf("                                    Empleados por orden alfabetico asc \n");
            printf("***********************************************************************************************************\n");
            printEmployees(list,lengthEmp,sectors,lengthSec);
            break;
        case 2:
        	sortEmployeesByName(list,lengthEmp,2);
            printf("***********************************************************************************************************\n");
            printf("                                    Empleados por orden alfabetico desc \n");
            printf("***********************************************************************************************************\n");

            printEmployees(list,lengthEmp,sectors,lengthSec);
            break;
        case 3:
        	reportTotalEmployeeCalc(list, lengthEmp, sectors,lengthSec);
            break;
        default:
            printf("Opcion invalida..!!");
            system("pause");
            validation=-1;
            break;
    }
    return validation;
}
