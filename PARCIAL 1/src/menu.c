#include "menu.h"
#include "cliente.h"
#include "reporte.h"
#include "pedido.h"

//#define TAMCLI 1000

int flagAltaCliente;

//flagAltaCliente = 0;

int menuPrincipal()
{
    int opcion;

   // opcion = 0;
    system("cls");
    //system("color A");
    system("color A");
    printf("***********************************************************************************************************\n");
    printf("                                    Menu Principal \n");
    printf("***********************************************************************************************************\n");
    printf("1) GESTION DE CLIENTES \n");
    printf("2) CREAR PEDIDO RECOLECCION \n");
    printf("3) PROCESAR RESIDUOS \n");
    printf("4) REPORTES \n");
    printf("5) SALIR \n");

    inputNumberInt(&opcion, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 5);

    return opcion;
}

int menuClientes(eCliente* listCliente, int lenCliente, ePedido* listPedidos, int lenPedidos, eLocalidad* listLocalidad, int lenLocalidad)
{

    int validation=0;
    int opcionMenu = 0;
    int idCliente=0;
    int indice=0;
    int idModificar;
    char checkContinuar;
    int opcionModificacion;
    int indiceAux=0;
    int idBaja;

    //eCliente cliente[TAMCLI];
    eCliente clienteAux;

    flagAltaCliente = 1;
    printf("***********************************************************************************************************\n");
    printf("                                    Menu de Clientes \n");
    printf("***********************************************************************************************************\n");
    printf("1- Alta de Cliente \n");
    printf("2- Modificar Cliente \n");
    printf("3- Baja de Cliente \n");
    printf("4- Volver al Menu Principal \n");

    inputNumberInt(&opcionMenu, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 4);

    switch(opcionMenu){
    	case 1:
    		 	system("cls");
                printf("***********************************************************************************************************\n");
                printf("                                    Alta de Cliente \n");
                printf("***********************************************************************************************************\n");
                inputString(clienteAux.nombre, "Ingrese el nombre: ","Error, vuelva a ingresa el Nombre:", 1, 51);

                 do
                 {
                	 inputStringAlpha(clienteAux.cuit, "Ingrese el cuit: ","Error, vuelva a ingresa el cuit: ", 1, 12);
                 }while(!isCharNumeric(clienteAux.cuit) || strlen(clienteAux.cuit) != 11);


                 inputStringAlpha(clienteAux.direccion, "Ingrese la direccion: ","Error, vuelva a ingresa la direccion:", 1, 51);
                 idCliente = getNuevoClienteId();
                 mostrarLocalidades(listLocalidad, lenLocalidad);
                 inputNumberInt(&clienteAux.idlocalidad, "Ingrese la localidad: ","Error, vuelva a ingresa la localidad:", 1, 5);

                 if (altaCliente(listCliente, lenCliente, idCliente,clienteAux.nombre, clienteAux.cuit, clienteAux.direccion, clienteAux.idlocalidad)==0)
                 {
					printf("\n");
                	printf("Cliente cargado con exito.\n\n");
					printf("El ID del cliente es: %d \n\n", idCliente);
                	flagAltaCliente = 1;
                 }

                 system("pause");
        break;
    	case 2:
    		system("cls");
    		if(checkClienteExiste(listCliente, lenCliente)==0)
				{
					printf("Error ! Modificacion de cliente, no hay clientes cargados.\n");
					system("pause");
					break;
				}
				else
				{
					system("cls");
					printf("***********************************************************************************************************\n");
					printf("                                    Menu Modificacion de Clientes \n");
					//mostrarClientes(cliente, TAMCLI);
					mostrarClientes(listCliente, lenCliente, listLocalidad, lenLocalidad);
					printf("\n");
					inputNumberInt(&idModificar, "Ingrese el ID del cliente a modificar: ", "Error, Ingrese el ID del cliente a modificar: ", 1000, 2000);

					//indiceAux=buscarClienteId(cliente, TAMCLI, idModificar);
					indiceAux=buscarClienteId(listCliente, lenCliente, idModificar);
					if(indiceAux==-1)
					{
						printf("El ID de cliente no existe.\n");
						system("pause");
					}
					else
					{
						system("cls");
						printf("***********************************************************************************************************\n");
						printf("                                    Menu Modificacion de Clientes \n");
						printf("***********************************************************************************************************\n");
						printf("  ID             Cliente     	     CUIT    	   Direccion                  Localidad                    \n");
						printf("***********************************************************************************************************\n");
						//mostrarCliente(cliente[indiceAux]);
						mostrarCliente(listCliente[indiceAux], listLocalidad, lenLocalidad);
						printf("\n\n");
						printf("Confirme si el empleado seleccionado es el que desea modificar:\n\n");

						checkContinuar=checkContinue();

						if(checkContinuar=='S')
						{
							system("cls");
							printf("***********************************************************************************************************\n");
							printf("                                    Menu Modificacion de Empleados \n");
							printf("***********************************************************************************************************\n");
							printf("  ID             Cliente     	     CUIT    	   Direccion                  Localidad                    \n");
							printf("***********************************************************************************************************\n");
							//mostrarCliente(cliente[indiceAux]);
							mostrarCliente(listCliente[indiceAux],listLocalidad, lenLocalidad);
							printf("\n\n");
							opcionModificacion = menuModificacionCliente();
							switch(opcionModificacion)
							{

							case 1:
								//inputStringAlpha(cliente[indiceAux].direccion, "Ingrese direccion: ","Error, vuelva a ingresar la direccion:", 1, 51);
								inputStringAlpha(listCliente[indiceAux].direccion, "Ingrese direccion: ","Error, vuelva a ingresar la direccion:", 1, 51);
								printf("Direccion modificada con exito\n");
								//mostrarCliente(cliente[indiceAux]);
								printf("***********************************************************************************************************\n");
								printf("  ID             Cliente     	     CUIT    	   Direccion                  Localidad                    \n");
								printf("***********************************************************************************************************\n");

								mostrarCliente(listCliente[indiceAux],listLocalidad, lenLocalidad);
								break;
							case 2:
								//inputString(cliente[indice].localidad, "Ingrese la localidad: ","Error, vuelva a ingresar la localiad:", 1, 51);
								mostrarLocalidades(listLocalidad, lenLocalidad);
								inputNumberInt(&listCliente[indice].idlocalidad, "Ingrese la localidad: ","Error, vuelva a ingresa la localidad:", 1, 6);
								printf("Localidad modificada con exito\n");
								printf("***********************************************************************************************************\n");
								printf("  ID             Cliente     	     CUIT    	   Direccion                  Localidad                    \n");
								printf("***********************************************************************************************************\n");

								mostrarCliente(listCliente[indiceAux],listLocalidad, lenLocalidad);
								break;
							case 3:
					    		system("cls");
					    		menuPrincipal();
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
    	{
    		system("cls");

    		//if(checkClienteExiste(cliente, TAMCLI)==0)
    		if(checkClienteExiste(listCliente, lenCliente)==0)
			{
				printf("Error ! Baja de clientes, no hay clientes cargados.\n");
				system("pause");
				break;
			}
			else
			{
				printf("***********************************************************************************************************\n");
				printf("                                    Menu Baja de Clientes \n");

				//mostrarClientes(cliente, TAMCLI);
				mostrarClientes(listCliente, lenCliente, listLocalidad, lenLocalidad);
				printf("\n");
				inputNumberInt(&idBaja, "Ingrese el ID del cliente a dar de baja: ", "Error, Ingrese el ID del cliente a dar de baja: ", 1000, 2000);

				//indiceAux=buscarClienteId(cliente, TAMCLI, idBaja);
				indiceAux=buscarClienteId(listCliente, lenCliente, idBaja);

				if(indiceAux==-1)
				{
					printf("El ID de Cliente no existe\n");

				}
				else
				{

					//mostrarCliente(cliente[indiceAux]);
					printf("***********************************************************************************************************\n");
					printf("  ID             Cliente     	     CUIT    	   Direccion                  Localidad                    \n");
					printf("***********************************************************************************************************\n");
					mostrarCliente(listCliente[indiceAux], listLocalidad, lenLocalidad);
					printf("Este Cliente se dara de baja de forma permanent ?\n");
					checkContinuar=checkContinue();
					if(checkContinuar=='S')
					{
						//if(bajaCliente(cliente, TAMCLI, idBaja)==-1)
						if(bajaCliente(listCliente, lenCliente, idBaja)==-1)
						{
							printf("No se pudo realizar la baja del cliente.\n");
						}
						else
						{
							printf("La baja se realizo correctamente.\n");
						}
					}
					else
					{
						printf("Baja del cliente se cancelo.\n");
						system("pause");
						break;
					}
				}
			}

			system("pause");
			break;
    	}

    	case 4:
    		system("cls");
    		menuPrincipal();
    }

    return validation;
}

int menuModificacionCliente()
{
    int opcion;
    printf("***********************************************************************************************************\n");
    printf("Opciones disponibles para modificar el cliente\n");
    printf("***********************************************************************************************************\n");
    printf("1- Modificar Direccion \n");
    printf("2- Modificar Localidad \n");
    printf("3- Volver al menu principal \n");

    inputNumberInt(&opcion, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 3);

    return opcion;


}

int menuReportes(eCliente listCliente[], int lenCliente, ePedido listPedidos[], int lenPedidos, eLocalidad listLocalidad[], int lenLocalidad)
{

    int validation=0;
    int opcionMenu = 0;
    //char localidad[50];
    int idLocalidad;
    int indice=0;
    printf("***********************************************************************************************************\n");
    printf("                                    Menu de Reportes \n");
    printf("***********************************************************************************************************\n");
    printf("1- Listado de Clientes \n");
    printf("2- Pedidos Pendientes \n");
    printf("3- Pedidos Procesados \n");
    printf("4- Pedidos por Localidad \n");
    printf("5- Cantidad de kilos de poliproleno reciclado promedio por cliente \n");
    printf("6- Cliente con mas pedidos Pendientes \n");
    printf("7- Cliente con mas pedidos Completados \n");
    inputNumberInt(&opcionMenu, "Ingrese una opcion: ", "Error, ingrese una opcion: ", 1, 7);

    switch(opcionMenu){
        case 1:
        	system("cls");
            printf("***************************************************************************************************************\n");
            printf("*                                    1- Listado de Clientes                                                   *\n");

            if(mostrarClientesConPedidosPendientes(listPedidos, lenPedidos, listCliente, lenCliente, listLocalidad, lenLocalidad))
            {
            	printf("Ho hay clientes ingresados");
            }
            printf("\n");
            break;
        case 2:
        	system("cls");
        	printf("***************************************************************************************\n");
            printf("*                                    Pedidos Pendientes                               *\n");
            mostrarPedidosPendientesKilos(listPedidos, lenPedidos, listCliente, lenCliente);
            printf("\n");
            break;

        case 3:
        	system("cls");
        	printf("***************************************************************************************************************\n");
            printf("*                                    Pedidos Procesados                                                       *\n");
            mostrarPedidosProcesados(listPedidos, lenPedidos, listCliente, lenCliente);
            printf("\n");
            break;
        case 4:
        	system("cls");
            printf("***********************************************************************************************************\n");
            printf("                                    Pedidos Totales Localidad \n");
            printf("***********************************************************************************************************\n");

			mostrarLocalidades(listLocalidad, lenLocalidad);
			inputNumberInt(&listCliente[indice].idlocalidad, "Ingrese la localidad: ","Error, vuelva a ingresa la localidad:", 1, 6);

            //inputStringAlpha(localidad, "Ingrese la localidad: ","Error, vuelva a ingresa la localidad:", 1, 51);
            printf("\n");
            pedidosPendientesLocalidad(listPedidos, lenPedidos, listCliente, lenCliente, listCliente[indice].idlocalidad);
            printf("\n");
            break;
        case 5:
        	system("cls");
            printf("***********************************************************************************************************\n");
            printf("                                    Polipropileno reciclado \n");
            printf("***********************************************************************************************************\n");
            promedioKilosPolipropileno(listPedidos,lenPedidos, listCliente, lenCliente);
            printf("\n");
            break;
        case 6:
        	system("cls");
            printf("***********************************************************************************************************\n");
            printf("                                    Cliente con mas pedidos Pendientes \n");
            printf("***********************************************************************************************************\n");
            clienteMasPedidosPendientes(listPedidos,lenPedidos, listCliente, lenCliente);

            printf("\n");
            break;
        case 7:
        	system("cls");
            printf("***********************************************************************************************************\n");
            printf("                                    Cliente con mas pedidos Completados \n");
            printf("***********************************************************************************************************\n");
            clienteMasPedidosCompletados(listPedidos,lenPedidos, listCliente, lenCliente);

            printf("\n");
            break;
    }
    return validation;
}

