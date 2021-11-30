#include "controlador_libro.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "input.h"
#include "libro.h"
#include "editorial.h"
#include "menu.h"


int controller_loadFromTextLibro(char* path, LinkedList* this)
{
    FILE* pFile;
    int retorno = 0;
    ll_clear(this);
    pFile = fopen(path,"r");

    if(this!= NULL)
    {
        if(pFile != NULL)
        {
        	retorno = parser_FromTextLibro(pFile,this);
        }

    }
    fclose(pFile);
    return retorno;
}

int controller_ListadoLibros(LinkedList* thisLibro, LinkedList* thisEditorial)
{
    eLibro* auxLibro;
    eEditorial* auxEditorial;
    int i;
    int j;
    int size1;
    int size2;

    int id;
    char titulo[128];
    char autor[128];
    int precio;
    int idEditorial;
    char nombreEditorial[128];

    if(thisLibro != NULL && thisEditorial!=NULL)
    {
        printf("%5s %24s %24s %24s %10s\n","IDLIBRO","EDITORIAL","TITULO","AUTOR","PRECIO");
        printf("**********************************************************************************************\n");
        size1=ll_len(thisLibro);
        size2=ll_len(thisEditorial);

        for(i=0;i<size1;i++)
        {
        	auxLibro = ll_get(thisLibro,i);
            libro_getId(auxLibro,&id);
            libro_getIdEditorial(auxLibro,&idEditorial);

            for(j=0;j<size2;j++)
            {
            	auxEditorial = (eEditorial*)ll_get(thisEditorial,j);

            	if(auxLibro->idEditorial == auxEditorial->idEditorial)
                {
                    editorial_getNombre(auxEditorial,nombreEditorial);
                }
            }
            libro_getTitulo(auxLibro,titulo);
            libro_getAutor(auxLibro,autor);
            libro_getPrecio(auxLibro,&precio);
            printf("%7d %25s %23s %24s %10d\n",id,nombreEditorial,titulo,autor,precio);
        }
    }
    return 1;
}


int controller_sortLibro(LinkedList* this)
{
    int retorno = 0;

    int controlMenu;
    int opcionMenu;

    int opcionOrdenamiento;

    if(this != NULL)
    {
        if(ll_len(this) > 0)
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
                    case 1: //nombre
                        if(ll_sort(this, libro_CompararPorNombre, opcionOrdenamiento) == 0)
                        {
                            printf("Los datos fueron ordenados por Nombre\n");
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


int controller_saveAsText(char* path, LinkedList* this)
{
    FILE* pFile;
    eLibro* auxLibro;
    int i;

    int size;

    int id;
    char titulo[128];
    char autor[128];
    int precio;
    int idEditorial;

    if(this != NULL)
    {
    	pFile = fopen(path,"w");

		if(pFile == NULL)
		{
			printf("NO SE PUDO ABRIR EL ARCHIVO\n");
			return 0;
		}
		else
		{
			size = ll_len(this);
			fprintf(pFile,"id,titulo,autor,precio,idEditorial\n");

			for(i=0;i<size;i++)
			{

				auxLibro = ll_get(this,i);
				libro_getId(auxLibro,&id);
				libro_getTitulo(auxLibro,titulo);
				libro_getAutor(auxLibro,autor);
				libro_getPrecio(auxLibro,&precio);
				libro_getIdEditorial(auxLibro,&idEditorial);
				fprintf(pFile,"%d,%s,%s,%d,%d\n",id,titulo,autor,precio,idEditorial);
			}
		}
		fclose(pFile);
		return 1;
	}
	else
	{
		printf("DIRECCION DE MEMORIA DE LINKEDLIST INCORRECTA");
		return 0;
	}

}


int controller_librosEditorialMinotauro(LinkedList* this,LinkedList* this2)
{
    int retorno = -1;
    LinkedList* librosMinotauro;

    if(this!=NULL && this2 != NULL)
    {
    	librosMinotauro = ll_newLinkedList();
        librosMinotauro = ll_filter(this,editorial_filtroMinotauro);
        retorno = ll_len(librosMinotauro);
        controller_saveAsText("libros_minotauro.csv",librosMinotauro);

    }
    return retorno;
}

int controller_librosConDescuento(LinkedList* this,LinkedList* this2)
{
    int retorno = -1;
    //LinkedList* librosPlanetaSigloXXI;

    if(this!=NULL && this2 != NULL)
    {
    	//librosPlanetaSigloXXI = ll_newLinkedList();
    	//librosPlanetaSigloXXI = ll_filter(this,editorial_filtroPlanetaSigloXXI);
    	//controller_ListadoLibros(librosPlanetaSigloXXI, this2);

    	ll_map(this,this2,&calcularDescuento);
    	retorno = ll_len(this);
        controller_saveAsText("mapeado.csv",this);

    }

    return retorno;
}
