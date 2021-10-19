#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pedido.h"
#include "cliente.h"


int initPedido(ePedido listPedido[],int lenPedido)
{
    int retorno = -1;
    int i;
    if(lenPedido > 0 && listPedido != NULL)
    {
        retorno = 0;
        for(i=0; i<lenPedido; i++)
        {
        	listPedido[i].isEmpty=0;
        	listPedido[i].idPedido=0;
        }
    }
    return retorno;
}
int altaPedido(ePedido listPedido[], int lenPedido, int idPedido, int idCliente, int kilosTotales, char estadoPedido[])
{
    int returnValue = -1;
    int emptyIndex;

    if(listPedido != NULL && lenPedido > 0 && lenPedido <= TAMPEDIDO && estadoPedido != NULL)
    {

        if(buscarPedidoId(listPedido, lenPedido, idPedido) != -1)
        {
            printf("El ID ingresado ya esta en uso.\n");
        }
        else
        {

        	 emptyIndex = initPedido(listPedido, lenPedido);

            if(emptyIndex != -1)
            {

            	listPedido[emptyIndex].idPedido = idPedido;
            	listPedido[emptyIndex].idCliente = idCliente;
            	listPedido[emptyIndex].kilosTotales = kilosTotales;
                strcpy(listPedido[emptyIndex].estado, estadoPedido);
                listPedido[emptyIndex].isEmpty = OCUPADO;

                returnValue = 0;

            }
        }
    }

    return returnValue;
}

int buscarPedidoId(ePedido listPedido[], int lenPedido, int id)
{
    int returnValue = -1;

    if(listPedido != NULL && lenPedido >= 0 && lenPedido <= TAMPEDIDO)
    {
        for (int i = 0; i < lenPedido; i++)
        {
            if(listPedido[i].idPedido == id)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int buscarCantidadPedidosPorClienteId(int* cantidadKilos, ePedido listPedido[], int lenPedido, int idCliente)
{
    int returnValue = -1;
    int contadorPedidos=0;

    if(listPedido != NULL && lenPedido >= 0 && lenPedido <= TAMPEDIDO)
    {
        for (int i = 0; i < lenPedido; i++)
        {
            if(listPedido[i].idCliente == idCliente && strcmp(listPedido[i].estado, ESTADO_PEDIDO_RECOLECCION) == 0)
            {
            	contadorPedidos++;
            	returnValue = 0;
                break;
            }
        }
    }
    *cantidadKilos = contadorPedidos;
    return returnValue;
}



int getNuevoPedidoId()
{
    static int id=1;

    return id++;
}


int mostrarPedidosPendientes(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente)
{

	   int i;
	   int retorno=-1;

	   printf("***************************************************************************************\n");
	   printf("* IDPedido                  CUIT                  DIRECCION               Cantidad de * \n");
	   printf("*                                                                       Kg Pendientes * \n");
	   printf("***************************************************************************************\n");
	   for(i=0; i<lenPedido; i++)
	   {

		   if(listPedido[i].isEmpty == OCUPADO && strcmp(listPedido[i].estado, ESTADO_PEDIDO_RECOLECCION) == 0)
		   {

			   for(int j=0; j<lenCliente; j++)
				 {
				if(listCliente[j].id == listPedido[i].idCliente)
					 {
					printf("%10d     %17s       %20s   %21dkg  \n",
						listPedido[i].idPedido, listCliente[j].cuit, listCliente[j].direccion, listPedido[i].kilosTotales);
					 }
				 }


			   retorno=0;
		   }
	   }

	   return retorno;

}

void mostrarPedidoPendiente(ePedido listPedido)
{

    printf("%6d   %14d         %14d    \n", listPedido.idPedido, listPedido.idCliente, listPedido.kilosTotales);

}

void mostrarPedidoAProcesar(ePedido listPedido)
{

    printf("%6d\n", listPedido.idPedido);

}

int buscarCantidadPedidosPendientes(int* cantidad, ePedido listPedido[], int lenPedido,  int idCliente)
{
    int rtn = 1;
    int contTipo = 0;

    if(listPedido != NULL && lenPedido > 0)
    {
        for(int i = 0; i < lenPedido; i++)
        {

			if(listPedido[i].idCliente == idCliente && strcmp(listPedido[i].estado, ESTADO_PEDIDO_RECOLECCION) == 0)
			{
				contTipo++;
				rtn = 0;
			}
        }

    }
    *cantidad = contTipo;

    return rtn;
}



//chequear si las uso
int swapPedidos(ePedido* pedido1, ePedido* pedido2)
{
    int returnValue = -1;
    ePedido aux1;
    ePedido aux2;

    aux1 = *pedido1;
    aux2 = *pedido2;
    *pedido1 = *pedido2;
    *pedido2 = aux1;

    if(!comparePedido(*pedido1, aux2) && !comparePedido(*pedido2, aux1))
    {
        returnValue = 0;
    }

    return returnValue;
}


int comparePedido(ePedido pedido1, ePedido pedido2)
{
    int compare = -2;

    /**< Si sus ID son iguales, como no pueden repetirse se toman como Empleados iguales. >*/
    if(pedido1.idPedido == pedido2.idPedido)
    {
        compare = 0;
    }
    else
    {
        /**< Si el ID del primero es menor al ID del segundo, son diferentes y el ID 1 es menor. >*/
        if(pedido1.idPedido < pedido2.idPedido)
        {
            compare = 1;
        }
        else
        {
            /**< Si el ID del primero es mayor al ID del segundo, son diferentes y el ID 2 es menor. >*/
            if(pedido1.idPedido > pedido2.idPedido)
            {
                compare = -1;
            }
        }
    }

    return compare;
}


int ordenarPedidos(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente, int order)
{
    int returnValue = -1;
    int indexCliente1;
    int indexCliente2;

    if(listPedido != NULL && lenPedido > 0 && listCliente != NULL && listCliente > 0)
    {
        for(int i= 0; i < lenPedido-1 ; i++)
        {
            for(int j = i+1; j < lenPedido; j++)
            {

				if(!swapPedidos(&listPedido[i], &listPedido[j]))
				{
					returnValue = 0;
				}

                    if(listPedido[i].idPedido == listPedido[j].idPedido)
                    {
                        indexCliente1 = buscarClienteId(listCliente, lenCliente, listPedido[i].idCliente);
                        indexCliente2 = buscarClienteId(listCliente, lenCliente, listPedido[j].idCliente);

                        if(indexCliente1 != -1 && indexCliente2 != -1)
                        {

							if(!swapPedidos(&listPedido[i], &listPedido[j]))
							{
								returnValue = 0;
							}

                        }
                    }
                }
            }
        }


    return returnValue;
}

void pedidosHardcode(ePedido listPedido[], int lenPedido, int quantity)
{
	ePedido auxCliente[5] = {
		{getNuevoPedidoId(),1000, 300,0,0,200,  "PENDIENTE", OCUPADO},
		{getNuevoPedidoId(),1001, 1000,0,0,200,  "PENDIENTE", OCUPADO},
		{getNuevoPedidoId(),1001, 1500,0,0,0,  "PENDIENTE", OCUPADO},
		{getNuevoPedidoId(),1002, 3000,100,0,300,  "PENDIENTE", OCUPADO},
		{getNuevoPedidoId(),1002, 200, 0,150,500, "PENDIENTE", OCUPADO}



    };

	for (int i = 0; i < quantity; i++)
	{
		listPedido[i] = auxCliente[i];
	}

}

