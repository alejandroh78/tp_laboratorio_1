/*
 ============================================================================
 Name        : Trabajo practico 3
 Author      : Alejandro Holik
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

#define ARCHIVO_CSV "data.csv"
#define ARCHIVO_BIN "data.bin"

int main()
{
	setbuf(stdout, NULL);
	system("color 03");

	int opcionMenu = 0;
	int controlMenu;
	int cantidadEmpleados = 0;

    LinkedList* listaEmpleados = ll_newLinkedList(); //llamo el constructor

    do
      {
    	controlMenu = menuPrincipal(&opcionMenu);

        if(opcionMenu == MENU_PRINCIPAL_Q || opcionMenu == -1)
        {
        	printf("Gracias por utilizar el TP3 \n");
			pausa(MENSAJE_PAUSA);
			exit(EXIT_SUCCESS);

        }
        cantidadEmpleados = ll_len(listaEmpleados);

    	switch(opcionMenu)
    	{
		case 1: //CARGA CSV
			system("cls");

			cantidadEmpleados = controller_loadFromText(ARCHIVO_CSV, listaEmpleados);

			if(cantidadEmpleados > 0)
			{
				printf("Se cargaron %d Empleados desde el archivo en modo texto.\n", cantidadEmpleados);
				pausa(MENSAJE_PAUSA);
			}
			else
			{
				printf("Error en el archivo, no se puede cargar los datos de empleados.\n");
				pausa(MENSAJE_PAUSA);
			}
			break;

    	case 2: //CARGA BIN
    		cantidadEmpleados = controller_loadFromBinary(ARCHIVO_BIN, listaEmpleados);

            if(cantidadEmpleados > 0)
            {
                printf("Se cargaron %d Empleados desde el archivo binario.\n", cantidadEmpleados);
            }
            else
            {
                printf("No se puede cargar Empleados.\n");
            }

    		pausa(MENSAJE_PAUSA);

    		break;
    	case 3: //ALTA EMPLEADOS
            system("cls");
            printf("****************  ALTA DE EMPLEADOS  **************\n");
            printf("***************************************************\n");

            if(controller_addEmployee(listaEmpleados))
            {
                printf("Empleado grabado correctamente\n");
            }
            else
            {
                printf("Error en la carga del Empleado\n");

            }

            pausa(MENSAJE_PAUSA);

            break;
    	case 4: //MODIFICACION EMPLEADO
            system("cls");
            printf("***********  MODIFICACION DE EMPLEADOS  ***********\n");
            printf("***************************************************\n");

            if(cantidadEmpleados == 0)
            {
                printf("No hay Empleados cargados\n");
            }
            else
            {
                controller_ListEmployee(listaEmpleados);
                if(controller_editEmployee(listaEmpleados))
                {
                    printf("Empleado modificado\n");
                }
                else
                {
                    printf("Se cancelo la modificacion del empleado\n");
                }
            }

            pausa(MENSAJE_PAUSA);

            break;

    	case 5: //BAJA EMPLEADO
            if(cantidadEmpleados == 0)
            {
            	printf("No hay Empleados cargados\n");
            }
            else
            {
            	controller_ListEmployee(listaEmpleados);
                if(controller_removeEmployee(listaEmpleados))
                {
                    printf("Empleado dado de baja \n");
                 }
                else
                {
                    printf("Se cancelo la baja de empleados\n");
                }
            }

            pausa(MENSAJE_PAUSA);

            break;
    	case 6: //LISTADO EMPLEADO
    		system("cls");
            if(cantidadEmpleados == 0)
            {
                printf("**************  LISTADO DE EMPLEADOS  *************\n");
                printf("***************************************************\n");
                printf("No hay Empleados cargados\n");
            }
            else
            {
                printf("**************  LISTADO DE EMPLEADOS  *************\n");
                printf("***************************************************\n");
            	cantidadEmpleados = controller_ListEmployee(listaEmpleados);
            	printf("\n");
            }

            pausa(MENSAJE_PAUSA);

            break;


    	case 7: //ORDERNAR EMPLEADOS
            if(cantidadEmpleados == 0)
            {
                printf("No hay Empleados cargados \n");
            }
            else
            {
                if(!controller_sortEmployee(listaEmpleados))
                {
                    printf("Error al ordenar \n");
                }
            }

            pausa(MENSAJE_PAUSA);

    		break;
    	case 8: //GRABA CSV
            if(!controller_saveAsText(ARCHIVO_CSV, listaEmpleados))
            {
                printf("No se pudo guardar el archivo de texto \n");
            }
            else
            {
                printf("Archivo de texto guardado \n");
            }

            pausa(MENSAJE_PAUSA);

            break;
    	case 9: //GRABA BIN
            if(!controller_saveAsBinary(ARCHIVO_BIN, listaEmpleados))
            {
                printf("No se pudo guardar el archivo binario \n");
            }
            else
            {
                printf("Archivo binario guardado \n");
            }

            pausa(MENSAJE_PAUSA);

    		break;
    	}
      }while(controlMenu == 0);

    return 0;

}

