/*
 ============================================================================
 Name        : Trabajo practico 2
 Author      : Alejandro Holik
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "input.h"
#include "ArrayEmployees.h"

#define TAMEMP 1000
#define TAMSEC 5
#define OCUPADO 1
#define VACIO 0


int main()
{

	setbuf(stdout, NULL);

    Employee employee[TAMEMP];
    Employee employeeAux;
    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "IT DESARROLLO"},
        {3, "IT PRODUCCION"},
        {4, "IT QA"},
        {5, "HELP DESK"},

    };


    char checkContinuar;
    int flag1=0;
    int idBaja;
    int idModificar;
    int indice;
    int opcionModificacion;
    int opcionMenu;

    initEmployees(employee,TAMEMP);

    do
    {


    	opcionMenu = menuPrincipal();
    	flag1=1;
    	 switch(opcionMenu)
        {
        case 1:
            system("cls");
            printf("***********************************************************************************************************\n");
            printf("                                    Alta de Empleado \n");
            printf("***********************************************************************************************************\n");
             inputString(employeeAux.name, "Ingrese el nombre: ","Error, vuelva a ingresa el Nombre:", 1, 51);
             inputString(employeeAux.lastName, "Ingrese el apellido: ","Error, vuelva a ingresa el Nombre:", 1, 51);
             inputNumberFloat(&employeeAux.salary, "Ingrese el sueldo [hasta $20.000.000]: ", "Error, Ingrese el sueldo [hasta $20.000.000]: ", 1, 20000000 );

             printf("\n");
             printSectors(sectores, TAMSEC);
             printf("\n");

             inputNumberInt(&employeeAux.sector, "Ingrese el codigo de sector: ", "Error, Ingrese el codigo de sector: ", 1, 5);

             if (addEmployee(employee, TAMEMP, getNewEmployeeId(),employeeAux.name, employeeAux.lastName, employeeAux.salary, employeeAux.sector)==0)
             {
            	 printf("Empleado cargado con exito.\n");
            	 flag1=1;
             }
             system("pause");

            break;
        case 2:
            system("cls");
            if(flag1==0 || checkEmployeesExists(employee, TAMEMP)==0)
            {
                printf("Error ! Modificacion de empleados, primero debe dar de alta empleados.\n");
                system("pause");
                break;
            }
            else
            {
                system("cls");
                printf("***********************************************************************************************************\n");
                printf("                                    Menu Modificacion de Empleados \n");

            	printEmployees(employee, TAMEMP, sectores,TAMSEC);
            	printf("\n");
            	inputNumberInt(&idModificar, "Ingrese el ID del empleado a modificar: ", "Error, Ingrese el ID del empleado a modificar: ", 1000, 2000);

                indice=findEmployeeById(employee, TAMEMP, idModificar);
                if(indice==-1)
                {
                    printf("El codigo de empleado no existe.\n");
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("***********************************************************************************************************\n");
                    printf("                                    Menu Modificacion de Empleados \n");
                    printf("***********************************************************************************************************\n");
                    printf("  ID             Nombre     	     Apellido    	   Salario      ID Sector                    Sector\n");
                    printf("***********************************************************************************************************\n");
                    printEmployee(employee[indice],sectores, TAMSEC);

                    printf("\n\n");
                    printf("Confirme si el empleado seleccionado es el que desea modificar:\n\n");

                    checkContinuar=checkContinue();


                    if(checkContinuar=='S')
                    {
                    	system("cls");
                        printf("***********************************************************************************************************\n");
                        printf("                                    Menu Modificacion de Empleados \n");
                        printf("***********************************************************************************************************\n");
                        printf("  ID             Nombre     	     Apellido    	   Salario      ID Sector                    Sector\n");
                        printf("***********************************************************************************************************\n");
                        printEmployee(employee[indice],sectores, TAMSEC);
                        printf("\n\n");
                        opcionModificacion = menuModificacion();
                        switch(opcionModificacion)
                        {
                        case 1:
                            inputString(employee[indice].name, "Ingrese el nombre: ","Error, vuelva a ingresa el Nombre:", 1, 51);
                            printf("Nombre modificado con exito:\n");
                            printEmployee(employee[indice], sectores, TAMSEC);
                            break;
                        case 2:
                        	inputString(employee[indice].lastName, "Ingrese el apellido: ","Error, vuelva a ingresa el Nombre:", 1, 51);
                        	printf("Apellido modificado con exito:\n");
                        	printEmployee(employee[indice], sectores, TAMSEC);
                            break;
                        case 3:
                            inputNumberFloat(&employee[indice].salary, "Ingrese el sueldo [hasta $20.000.000]: ", "Error, Ingrese el sueldo [hasta $20.000.000]: ", 1, 20000000 );
                            printf("Salario modificado con exito:\n");
                            printEmployee(employee[indice], sectores, TAMSEC);
                            break;
                        case 4:
                        	 printSectors(sectores, TAMSEC);
                         	 inputNumberInt(&idModificar, "Ingrese el codigo de sector: ", "Error, Ingrese el codigo de sector: ", 1, 5);
                        	 printf("Sector cambiado con exito:\n");
                        	 printEmployee(employee[indice], sectores, TAMSEC);
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }

                }


            }
            system("pause");
            break;
        case 3:
            system("cls");
            if(checkEmployeesExists(employee, TAMEMP)==0)
            {
                printf("Error ! Baja de empleados, primero debe dar de alta empleados.\n");
                system("pause");
                break;

            }
            else
            {
                printf("***********************************************************************************************************\n");
                printf("                                    Menu Baja de Empleados \n");
            	printEmployees(employee, TAMEMP, sectores,TAMSEC);
            	inputNumberInt(&idBaja, "Ingrese el ID del empleado a dar de baja: ", "Error, Ingrese el ID del empleado a dar de baja: ", TAMEMP, 2000);

                indice=findEmployeeById(employee, TAMEMP, idBaja);

                if(indice==-1)
                {
                    printf("El codigo de empleado no existe\n");

                }
                else
                {
                    printf("EMPLEADO A DAR DE BAJA: \n");
                    printEmployee(employee[indice], sectores, TAMSEC);
                    printf("ESTE EMPLEADO SE DARA DE BAJA DE FORMA PERMANENTE.\n");
                    checkContinuar=checkContinue();
                    if(checkContinuar=='S')
                    {
                        if(removeEmployee(employee, TAMEMP, idBaja)==-1)
                        {
                            printf("No se pudo realizar la baja del empleado.\n");
                        }
                        else
                        {
                        	printf("La baja se realizo correctamente.\n");
                        }
                    }
                    else
                    {
                        printf("Baja del empleado cancelado.\n");
                        system("pause");
                        break;
                    }


                }

            }

            system("pause");
            break;

        case 4:
            system("cls");

            if(checkEmployeesExists(employee, TAMEMP)==0)
            {
                printf("Error ! Reportes, primero debe dar de alta empleados porque no hay informacion en el sistema.\n");
                system("pause");
                break;

            }
            else
            {
                system("cls");
                menuPrincipalReportes(employee, TAMEMP, sectores, TAMSEC);
            }

            system("pause");

            break;

        case 5:

			system("cls");
			printf("Gracias por utilizar TP 2\n\n");
			system("pause");

            break;

        }


    }
   while( opcionMenu!=5 );



    return 0;
}
