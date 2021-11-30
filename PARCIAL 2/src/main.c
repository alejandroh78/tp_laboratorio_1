#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "controlador_libro.h"
#include "controlador_editorial.h"
#include "LinkedList.h"
#include "input.h"
#include "libro.h"
#include "editorial.h"
#include "menu.h"

/*
PARCIAL 2
ALEJANDRO HOLIK
*/

int main()
{
	setbuf(stdout, NULL);
	system("color 03");

	int opcionMenu = 0;
	int controlMenu;
	int cantidadLibros=0;

	int cantidadEditoriales=0;

    LinkedList* editorial;
    LinkedList* libro;

    libro = ll_newLinkedList();
    editorial = ll_newLinkedList();

    cantidadLibros = ll_len(libro);
    cantidadEditoriales = ll_len(editorial);
    char archivoLibro[128];
    char archivoEditorial[128];

    do
      {
    	controlMenu = menuPrincipal(&opcionMenu);

        if(opcionMenu == MENU_PRINCIPAL_Q || opcionMenu == -1)
        {
        	printf("Gracias por utilizar el Parcial 2 \n");
			pausa(MENSAJE_PAUSA);
			exit(EXIT_SUCCESS);

        }
        cantidadLibros = ll_len(libro);
        cantidadEditoriales = ll_len(editorial);


    	switch(opcionMenu)
    	{
		case 1: //carga libros
			system("cls");

			//cantidadLibros = controller_loadFromTextLibro("libro.csv",libro); //debería ir path
			inputString(archivoLibro, "Ingrese el nombre del archivo de libros: ", "Error, Ingrese el nombre del archivo de libros: ", 1,  128);
	    	cantidadLibros = controller_loadFromTextLibro(archivoLibro,libro); //debería ir path

			if(cantidadLibros > 0)
			{
				printf("Se cargaron %d libros desde el archivo en modo texto.\n", cantidadLibros);
				pausa(MENSAJE_PAUSA);
			}
			else
			{
				printf("Error en el archivo, no se puede cargar los datos de libros.\n");
				pausa(MENSAJE_PAUSA);
			}
			break;

    	case 2: //carga editorial
			system("cls");

			//cantidadEditoriales = controller_loadFromText_Editorial("editorial.csv",editorial);
			inputString(archivoEditorial, "Ingrese el nombre del archivo de editorial: ", "Error, Ingrese el nombre del archivo de editorial: ", 1,  128);
	    	cantidadEditoriales = controller_loadFromText_Editorial(archivoEditorial,editorial);

			if(cantidadEditoriales > 0)
			{
				printf("Se cargaron %d editoriales desde el archivo en modo texto.\n", cantidadEditoriales);
				pausa(MENSAJE_PAUSA);
			}
			else
			{
				printf("Error en el archivo, no se puede cargar los datos de editoriales.\n");
				pausa(MENSAJE_PAUSA);
			}
			break;
    	case 3: //ordenar datos
            system("cls");

            if(cantidadLibros == 0)
            {
                printf("****************  ORDENAR DATOS *******************\n");
                printf("***************************************************\n");
            	printf("No hay libros cargados \n");
            }
            else
            {
                if(!controller_sortLibro(libro))
                {
                    printf("Error al ordenar libros \n");
                }
            }

            pausa(MENSAJE_PAUSA);

            break;
    	case 4: //listados

    		system("cls");
            if(cantidadLibros == 0)
            {
                printf("**************  LISTADO DE LIBROS  *************\n");
                printf("***************************************************\n");
                printf("No hay libros cargados\n");
            }
            else
            {
                printf("**************  LISTADO DE LIBROS  *************\n");
                printf("***************************************************\n");
                cantidadLibros = controller_ListadoLibros(libro,editorial);
            	printf("\n");
            }

            pausa(MENSAJE_PAUSA);

            break;

    	case 5: //guardar minutauro
    		system("cls");
            printf("**********  GENERACION ARCHIVO MINOTAURO **********\n");
            printf("***************************************************\n");
            cantidadLibros = controller_librosEditorialMinotauro(libro, editorial);

            if (cantidadLibros>=0)
            {
            	printf("Se guardaron %d libros de la editorial Minotauro en el archivo libros_minotauro.csv\n", cantidadLibros);
            }
            else
    		{
            	printf("Error en el archivo, no se puede grabar el archivo libros_minotauro.csv \n");
    		}

            pausa(MENSAJE_PAUSA);

            break;
    	case 6: //guardar archivo mapeado
    		system("cls");
            printf("**********  ARCHIVO MAPEADO **********\n");
            printf("***************************************************\n");
            cantidadLibros = controller_librosConDescuento(libro,editorial);

            if (cantidadLibros>=0)
            {
            	printf("Se guardaron los libros en el archivo mapeado.csv\n");
            }
            else
    		{
            	printf("Error en el archivo, no se puede grabar el archivo mapeado.csv \n");
    		}

            pausa(MENSAJE_PAUSA);

            break;
    	}
      }while(controlMenu == 0);

    ll_deleteLinkedList(libro);
    ll_deleteLinkedList(editorial);

    return 0;

}

