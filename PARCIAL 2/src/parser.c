#include <stdio.h>
#include <stdlib.h>

#include "parser.h"
#include "input.h"
#include "libro.h"
#include "editorial.h"
#include "LinkedList.h"


int parser_FromTextLibro(FILE* pFile, LinkedList* pArrayList)
{
	int id;
    char titulo[128];
    char autor[128];
    int precio;
    int idEditorial;

    int contador = 0;
    char buffer[5][128];

    eLibro* auxLibro;

    if(pFile != NULL && pArrayList != NULL)
    {
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4]) == 5
               && inputStringToInt(buffer[0], &id)
               && buffer[1] != NULL
			   && strcpy(titulo,buffer[1])
               && buffer[2] != NULL
			   && strcpy(autor,buffer[2])
			   && inputStringToInt(buffer[3], &precio)
               && inputStringToInt(buffer[4], &idEditorial)
            )
            {

            	auxLibro = libro_newParametros(&id, buffer[1], buffer[2], &precio, &idEditorial);

                if(auxLibro != NULL && ll_len(pArrayList) < 1000 //METER DEFINE MAX LIBROS
                					   && ll_add(pArrayList, (eLibro*)auxLibro) == 0)
                {
                	contador++;
                }
            }
        }
    }

    return contador;
}

int parser_FromText_Editorial(FILE* pFile, LinkedList* pArrayList)
{
	int idEditorial;
	char nombre[128];

	int contador = 0;
	char buffer[1][128];

	eEditorial* auxEditorial;

	if(pFile != NULL && pArrayList != NULL)
	{

		while(!feof(pFile))
		{

			if(fscanf(pFile,"%[^,],%[^\n]\n", buffer[0], buffer[1]) == 2
			   && inputStringToInt(buffer[0], &idEditorial)
			   && buffer[1] != NULL
			   && strcpy(nombre,buffer[1])

			)
			{

				auxEditorial = editorial_newParametros(&idEditorial, buffer[1]);

				if(auxEditorial != NULL && ll_len(pArrayList) < 1000 //METER DEFINE MAX LIBROS
									   && ll_add(pArrayList, (eEditorial*)auxEditorial) == 0)
				{
					contador++;
				}
			}
		}
	}

	return contador;
}


