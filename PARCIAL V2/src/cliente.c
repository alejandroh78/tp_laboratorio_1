#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"



int altaCliente(eCliente listCliente[], int lenCliente, int id, char nombre[],  char cuit[], char direccion[], int idLocalidad)
{
    int returnValue = -1;
    int emptyIndex;

    if(listCliente != NULL && lenCliente > 0 && lenCliente <= 1000
        && nombre != NULL && direccion != NULL  && cuit != NULL )
    {

        if(buscarClienteId(listCliente, lenCliente, id) != -1)
        {
            printf("El ID ingresado ya esta en uso.\n");
        }
        else
        {

        	 emptyIndex = initCliente(listCliente, lenCliente);

            if(emptyIndex != -1)
            {

            	listCliente[emptyIndex].id = id;
                strcpy(listCliente[emptyIndex].nombre, nombre);
                strcpy(listCliente[emptyIndex].cuit, cuit);
                strcpy(listCliente[emptyIndex].direccion, direccion);
                listCliente[emptyIndex].idlocalidad = idLocalidad;
                listCliente[emptyIndex].isEmpty = OCUPADO;

                returnValue = 0;

            }
        }
    }

    return returnValue;
}



int buscarClienteId(eCliente listCliente[], int lenCliente, int id)
{
    int returnValue = -1;

    if(listCliente != NULL && lenCliente > 0 && lenCliente <= 1000)
    {
        for (int i = 0; i < lenCliente; i++)
        {
            if(listCliente[i].id == id)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}



int buscarNombreClienteId(char* nombreCliente, eCliente listCliente[], int lenCliente, int idCliente)
{
    int returnValue = -1;

    if(listCliente != NULL && lenCliente > 0 )
    {
        for(int i = 0; i < lenCliente; i++)
        {
            if(listCliente[i].id == idCliente)
            {
                strcpy(nombreCliente, listCliente[i].nombre);
                returnValue = 0;
                break;
            }
        }
    }

    return returnValue;
}

int bajaCliente(eCliente listCliente[],int lenCliente, int id)
{
    int retorno = -1;
    int i;

    for(i = 0; i < lenCliente; i++)
    {
        if(listCliente[i].id == id)
        {
        	listCliente[i].isEmpty = VACIO;
            retorno = 0;
        }
    }
    return retorno;
}

int checkClienteExiste(eCliente listCliente[], int lenCliente)
{
    int retorno=0;
    int i;

    for(i=0; i<lenCliente; i++)
    {
        if(listCliente[i].isEmpty==OCUPADO)
        {
            retorno=1;
            break;
        }
    }

    return retorno;
}



int getNuevoClienteId()
{
    static int id=1000;

    return id++;
}

int initCliente(eCliente listCliente[],int lenCliente)
{
    int retorno = -1;
    int i;
    if(lenCliente > 0 && listCliente != NULL)
    {
        retorno = 0;
        for(i=0; i<lenCliente; i++)
        {
        	listCliente[i].isEmpty=0;
        	listCliente[i].id=0;
        }
    }
    return retorno;
}

int mostrarClientes(eCliente listCliente[], int lenCliente, eLocalidad listLocalidad[], int lenLocalidad)
{
    int i;
    int retorno=-1;

    printf("***********************************************************************************************************\n");
    printf("* IDCliente          Nombre                  CUIT                   Direccion                   Localidad * \n");
    printf("***********************************************************************************************************\n");

    for(i=0; i < lenCliente; i++)
    {
    	if(listCliente[i].isEmpty == OCUPADO)
        {
        	mostrarCliente(listCliente[i], listLocalidad, lenLocalidad);
            retorno=0;
        }
    }

    return retorno;

}



void mostrarCliente(eCliente listCliente, eLocalidad listLocalidad[], int lenLocalidad)
{
	int i;
    for(i=0; i < lenLocalidad; i++)
    {
    	if(listLocalidad[i].id == listCliente.idlocalidad)
        {
        	//mostrarCliente(listCliente[i]);
        	printf("%11d     %11s        %14s          %18s         %19s    \n",
        	    		listCliente.id, listCliente.nombre, listCliente.cuit, listCliente.direccion, listLocalidad[i].nombre);
        }
    }

}

void clientesHardcode(eCliente listCliente[], int length, int quantity)
{
	eCliente cliente[8] = {
        {getNuevoClienteId(), "empresa 1", "2026411101", "calle 1", 1, OCUPADO},
        {getNuevoClienteId(), "empresa 2", "2026411102", "calle 2", 2, OCUPADO},
        {getNuevoClienteId(), "empresa 3", "2026411123", "calle 3", 3, OCUPADO},
        {getNuevoClienteId(), "empresa 4", "2026411104", "calle 4", 4, OCUPADO},
        {getNuevoClienteId(), "empresa 5", "2026411105", "calle 5", 5, OCUPADO},
        {getNuevoClienteId(), "empresa 6", "2026411106", "calle 6", 1, OCUPADO},
        {getNuevoClienteId(), "empresa 7", "2026411107", "calle 7", 2, OCUPADO},

    };

	for (int i = 0; i < quantity; i++)
	{
		listCliente[i] = cliente[i];
	}

}
void localidadesHardcode(eLocalidad listLocalidad[], int length, int quantity)
{
	eLocalidad localidad[5] = {
        {1,"Adrogue", OCUPADO},
        {2,"Avellaneda", OCUPADO},
        {3,"Banfield", OCUPADO},
        {4,"Lanus", OCUPADO},
        {5,"San Vicente", OCUPADO}
    };

	for (int i = 0; i < quantity; i++)
	{
		listLocalidad[i] = localidad[i];
	}

}

int mostrarLocalidades(eLocalidad listLocalidad[], int lenLocalidad)
{
    int i;
    int retorno=-1;

    printf("*************************************************\n");
    printf("* IDLocalidad                            Nombre * \n");
    printf("*************************************************\n");

    for(i=0; i < lenLocalidad; i++)
    {
    	if(listLocalidad[i].isEmpty == OCUPADO)
        {
        	//mostrarCliente(listLocalidad[i]);
        	printf("%8d           %28s \n", listLocalidad[i].id, listLocalidad[i].nombre);
            retorno=0;
        }
    }

    return retorno;

}


int buscarLocalidadId(eLocalidad listLocalidad[], int lenlocalidad, int idLocalidad, char* localidadNombre[])
{
    int returnValue = -1;
    char nombre[50];
    if(listLocalidad != NULL && lenlocalidad > 0 && lenlocalidad <= TAMLOC)
    {
        for (int i = 0; i < lenlocalidad; i++)
        {
            if(listLocalidad[i].id == idLocalidad)
            {
            	 strcpy(listLocalidad[i].nombre,*localidadNombre);
            	returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}
