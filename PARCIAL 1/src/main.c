/*
 ============================================================================
 Name        : Parcial 1
 Author      : Alejandro Holik
 ============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "cliente.h"
#include "pedido.h"
#include "reporte.h"
#include "input.h"

#define OCUPADO 1
#define VACIO 0
#define ESTADO_PEDIDO_RECOLECCION "PENDIENTE"

int main()
{

	setbuf(stdout, NULL);


    char checkContinuar;
    /*int flag1=0;
    int idBaja;
    int idModificar;
    int indice;
    */
    int opcionMenu;

    int idCliente;
    int nroPedido;
    int indicePedido;
    int idPedido;
    int kilosTotales=0;
    int kilosDisponibles=0;
    int kilosReciclados=0;

    opcionMenu = 0;

    eCliente cliente[TAMCLI];
    ePedido pedido[TAMPEDIDO];
    ePedido pedidoAux;
    eLocalidad localidad[TAMLOC];

    initCliente(cliente, TAMCLI);
    initPedido(pedido, TAMPEDIDO);

    clientesHardcode(cliente, TAMCLI, 8);
    pedidosHardcode(pedido, TAMPEDIDO, 5);
    localidadesHardcode(localidad, TAMLOC,5);

    do
    {

    	 opcionMenu = menuPrincipal();
    	 //flag1=1;
    	 switch(opcionMenu)
        {
        case 1:
            system("cls");
            menuClientes(cliente , TAMCLI, pedido, TAMPEDIDO, localidad, TAMLOC);
            break;
        case 2:
            system("cls");
            if(checkClienteExiste(cliente, TAMCLI)==0)
            {
                printf("Error ! Pedido de Recoleccion, primero debe dar de alta clientes.\n");
                system("pause");
                break;
            }
            else
            {
                printf("***********************************************************************************************************\n");
                printf("                                    Pedido Recoleccion de Residuos \n");
				mostrarClientes(cliente, TAMCLI, localidad, TAMLOC );
				printf("\n");
				inputNumberInt(&idCliente, "Ingrese el ID del cliente que desea recolectar residuos: ", "Error, Ingrese el ID del cliente que desea recolectar residuos: ", 1000, 2000);
				inputNumberInt(&pedidoAux.kilosTotales, "Ingrese la cantidad de Kilos a recolectar: ", "Error, Ingrese la cantidad de Kilos a recolectar: ", 1, 50000);

				nroPedido = getNuevoPedidoId();

                 if (altaPedido(pedido, TAMPEDIDO, nroPedido, idCliente, pedidoAux.kilosTotales, ESTADO_PEDIDO_RECOLECCION)==0)
                 {
                	 printf("Se genero el Numero de Pedido %d con exito.\n", nroPedido);
                	 system("pause");
                	// flag1=1;
                 }
            }
            break;
        case 3:
        	system("cls");
			if( checkClienteExiste(cliente, TAMCLI)==0)
			{
				printf("Error ! procesamiento de residuos, no hay clientes cargados.\n");
				system("pause");
				break;
			}
			else
			{
				printf("***************************************************************************************\n");
				printf("*                                   Procesamiento de Residuos                         *\n");
				mostrarPedidosPendientes(pedido, TAMPEDIDO,cliente , TAMCLI );
				printf("\n");
				inputNumberInt(&idPedido, "Ingrese el IDPedido a procesar: ", "Error, Ingrese el IDPedido a procesar: ", 0, 50000);

				indicePedido=buscarPedidoId(pedido, TAMPEDIDO, idPedido);

				if(indicePedido==-1)
				{
					printf("El ID Pedido no existe\n");

				}
				else
				{
					printf("\n");
					printf("Pedido a procesar: \n");
					printf("**************\n");
					printf("* IDPedido   * \n");
					printf("**************\n");
					mostrarPedidoAProcesar(pedido[indicePedido]);
					printf("**************\n");

					kilosTotales = pedido[indicePedido].kilosTotales;
					checkContinuar=checkContinue();
					if(checkContinuar=='S')
					{

						printf("\n");
						printf("Cantidad maxima de kilos disponibles %d \n\n", kilosTotales);
						inputNumberInt(&pedido[indicePedido].kilosHdpe, "Ingrese la cantidad de Kilos HDPE Polietileno de alta densidad : ", "Error, Ingrese la cantidad de Kilos HDPE Polietileno de alta densidad: ", 0, kilosTotales);
						kilosDisponibles = kilosTotales - pedido[indicePedido].kilosHdpe;
						printf("\n");


						printf("Cantidad maxima de kilos disponibles %d \n", kilosDisponibles);
						inputNumberInt(&pedido[indicePedido].kilosLdpe, "Ingrese la cantidad de Kilos LDPE Polietileno de baja densidad: ", "Error, Ingrese la cantidad de Kilos LDPE Polietileno de baja densidad: ", 0, kilosDisponibles);
						kilosDisponibles = kilosDisponibles - pedido[indicePedido].kilosLdpe;
						printf("\n");

						printf("Cantidad maxima de kilos disponibles %d \n", kilosDisponibles);
						inputNumberInt(&pedido[indicePedido].kilosPp, "Ingrese la cantidad de Kilos PP Polipropileno: ", "Error, Ingrese la cantidad de Kilos PP Polipropileno: ", 0, kilosDisponibles);
						kilosDisponibles = kilosDisponibles - pedido[indicePedido].kilosPp;
						printf("\n");

						kilosReciclados = pedido[indicePedido].kilosHdpe + pedido[indicePedido].kilosLdpe +  pedido[indicePedido].kilosPp;

						printf("Se reciclo un total de %d kg.\n", kilosReciclados);
						printf("Pedido procesado\n");
						strcpy(pedido[indicePedido].estado, "COMPLETADO");

					}
					else
					{
						printf("El procesamiento de pedido fue cancelado.\n");
						system("pause");
						break;
					}
				}
			}

			system("pause");
			break;
        case 4:
            system("cls");
            menuReportes(cliente, TAMCLI, pedido, TAMPEDIDO, localidad, TAMLOC);

            system("pause");
            break;

        case 5:

			system("cls");
			printf("Gracias por utilizar Parcial \n\n");
			system("pause");
            break;
        }


    }
   while( opcionMenu!=5 );


   return 0;
}
