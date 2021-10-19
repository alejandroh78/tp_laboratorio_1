#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pedido.h"
#include "cliente.h"
#include "reporte.h"

int mostrarPedidosPendientesKilos(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente)
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



int mostrarPedidosProcesados(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente)
{
    int i;
    int retorno=-1;

    printf("***************************************************************************************************************\n");
    printf("*  IDPedido              CUIT     	            Direccion                Kg Hdpe       Kg Ldpe      Kg PP * \n");
    printf("***************************************************************************************************************\n");
    for(i=0; i<lenPedido; i++)
    {

        if(listPedido[i].isEmpty == OCUPADO && strcmp(listPedido[i].estado, "COMPLETADO") == 0)
        {

            for(int j=0; j<lenCliente; j++)
              {
            	if(listCliente[j].id == listPedido[i].idCliente)
                  {
            		printf("%10d     %14s  %30s    %17dkg  %10dkg  %7dkg \n",
            			listPedido[i].idPedido,  listCliente[j].cuit, listCliente[j].direccion,
						listPedido[i].kilosHdpe, listPedido[i].kilosLdpe, listPedido[i].kilosPp);
                  }
              }


            retorno=0;
        }
    }

    return retorno;

}


int mostrarClientesConPedidosPendientes(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente, eLocalidad listLocalidad[], int lenLocalidad)
{
    int i;
    int retorno=-1;
    int cantidad;

    printf("***************************************************************************************************************\n");
    printf("* IDCliente                Nombre           CUIT               Direccion            Localidad         Pedidos * \n");
    printf("*                                                                                                  Pendientes *  \n");
    printf("***************************************************************************************************************\n");
    for(i=0; i<lenCliente; i++)
    {

        if(listCliente[i].isEmpty == OCUPADO )
        {
        	buscarCantidadPedidosPendientes(&cantidad, listPedido, lenPedido, listCliente[i].id);
        	//buscarLocalidadId(listLocalidad, lenLocalidad, listCliente[i].idlocalidad, localidadNombre);
            for (int k = 0; i < lenLocalidad; k++)
            {
                if(listLocalidad[k].id == listCliente[i].idlocalidad && listLocalidad[k].isEmpty == OCUPADO)
                {
               		printf("%11d %21s %14s %22s  %20s %15d \n", listCliente[i].id, listCliente[i].nombre, listCliente[i].cuit,
                										   listCliente[i].direccion , listLocalidad[k].nombre,  cantidad);
                    break;
                }
            }

            retorno=0;
        }
    }


    return retorno;

}


//int pedidosPendientesLocalidad(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente, char localidad[50] )
int pedidosPendientesLocalidad(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente, int idLocalidad )
{
    int i;
    int retorno=-1;
    int cantidad;
    int contadorPedidos=0;

    for(i=0; i<lenCliente; i++)
    {

        if(listCliente[i].isEmpty == OCUPADO && listCliente[i].idlocalidad == idLocalidad )
        {


        	buscarCantidadPedidosPendientes(&cantidad, listPedido, lenPedido, listCliente[i].id);
        	contadorPedidos = contadorPedidos + cantidad;
            retorno=0;
        }
    }


    printf("Se encontraron %d pedidos pendientes para la localidad seleccionada \n ", contadorPedidos );
    return retorno;

}


int promedioKilosPolipropileno(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente )
{
    float promedio;
    int acumulador = 0;
    int contadorCliente=0;
    int retorno=-1;
    if(listPedido != NULL && lenPedido > 0 )
    {
        for(int i = 0; i < lenPedido; i++)
        {

			if(listPedido[i].kilosPp > 0 && strcmp(listPedido[i].estado, "COMPLETADO") == 0 && listPedido[i].isEmpty == OCUPADO)
			{
				acumulador += listPedido[i].kilosPp;
			}
        }


        for(int j = 0; j < lenCliente; j++)
        {
        	if(listCliente[j].isEmpty == OCUPADO)
			{
        		for(int k = 0; k < lenPedido; k++)
        		{
        			if (listCliente[j].id == listPedido[k].idCliente && listPedido[k].kilosPp > 0)
        			{
        				contadorCliente++;
        				break;
        			}
        		}
			}
        }

        if (acumulador > 0)
        {
        	promedio = acumulador / contadorCliente;
    		printf("Promedio kilos de polipropileno por cliente %.2fkg \n ",  promedio);
    		retorno = 0;
        }


    }

    return retorno;
}

int clienteMasPedidosPendientes (ePedido listaPedido[], int lenPedido)
{
	  int banderaMasCantidad;
	  //eProducto productoMasCaro;
	  int clienteMasCantidad;

	  banderaMasCantidad = 0;

	  for (int i = 0; i < lenPedido; i++)
	  {
	      if (strcmp(listaPedido[i].estado, "COMPLETADO") && (listaPedido[i].idCliente > clienteMasCantidad || banderaMasCantidad == 0))
	      {
	    	  clienteMasCantidad = listaPedido[i].idCliente;
	    	  banderaMasCantidad = 1;
		}
	  }
	  printf("cliente mas pedidos %d", clienteMasCantidad);
	  //*precioMasCaro = precioMasCaroLocal;

	  return banderaMasCantidad;
}

