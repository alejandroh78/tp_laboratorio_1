
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "reporte.h"
#include "cliente.h"
#include "pedido.h"
#include <string.h>
#include <ctype.h>

/// @fn int menuPrincipal()
/// @brief muestra las opciones del menu principal
///
/// @return
int menuPrincipal();

/// @fn int menuClientes(eCliente*, int, ePedido*, int)
/// @brief muestra las opciones del menu clientes
///
/// @param listCliente listCliente array de clientes
/// @param lenCliente lenCliente longitud del array de clientes
/// @param listPedidos pedidos array de pedidos
/// @param lenPedidos longitud del array de pedidos
/// @return
int menuClientes(eCliente* listCliente, int lenCliente, ePedido* listPedidos, int lenPedidos, eLocalidad* listLocalidad, int lenLocalidad);

/// @fn int menuModificacionCliente()
/// @brief muestras las opciones para modificar datos del cliente
///
/// @return
int menuModificacionCliente();

/// @fn int menuReportes(eCliente[], int, ePedido[], int)
/// @brief muestra las opciones de reportes
///
/// @param listCliente listCliente array de clientes
/// @param lenCliente lenCliente longitud del array de clientes
/// @param listPedidos pedidos array de pedidos
/// @param lenPedidos longitud del array de pedidos
/// @return
//int menuReportes(eCliente listCliente[], int lenCliente, ePedido listPedidos[], int lenPedidos);
int menuReportes(eCliente listCliente[], int lenCliente, ePedido listPedidos[], int lenPedidos, eLocalidad listLocalidad[], int lenLocalidad);
#endif /* MENU_H_ */
