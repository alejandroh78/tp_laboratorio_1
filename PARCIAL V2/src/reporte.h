

#ifndef REPORTE_H_
#define REPORTE_H_

#include "reporte.h"
#include "cliente.h"
#include "pedido.h"

#define OCUPADO 1
#define VACIO 0
#define ESTADO_PEDIDO_RECOLECCION "PENDIENTE"

/// @fn int mostrarClientesConPedidosPendientes(ePedido[], int, eCliente[], int)
/// @brief muestra el reporte de clientes con los siguientes datos
/// IDCliente
/// Nombre
/// CUIT
/// Direccion
/// Localidad
/// Cantidad Pedidos Pendientes
/// @param listPedido array de pedido
/// @param lenPedido longitud del array de pedido
/// @param listCliente array de cliente
/// @param lenCliente longitud del array de cliente
/// @return   [-1] No hay datos para mostrar.
///           [0]  Si existe datos para mostrar.
//int mostrarClientesConPedidosPendientes(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente);
int mostrarClientesConPedidosPendientes(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente,
										eLocalidad listLocalidad[], int lenLocalidad);

/// @fn int mostrarPedidosPendientesKilos(ePedido[], int, eCliente[], int)
/// @brief muestra el reporte de pedidos pendientes con los siguientes datos
/// IDPedido
/// CUIT
/// DIRECCION
/// Cantidad de Kg Pendientes
/// @param listPedido array de pedido
/// @param lenPedido longitud del array de pedido
/// @param listCliente array de cliente
/// @param lenCliente longitud del array de cliente
/// @return   [-1] No hay datos para mostrar.
///           [0]  Si existe datos para mostrar.
int mostrarPedidosPendientesKilos(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente);


/// @fn int mostrarPedidosProcesados(ePedido[], int, eCliente[], int)
/// @brief muestra el linstado de pedidos procesados con los kg de los diferentes materiales
/// IDPedido
/// CUIT
/// Direccion
/// Kg Hdpe
/// Kg Ldpe
/// Kg PP
/// @param listPedido array de pedido
/// @param lenPedido longitud del array pedido
/// @param listCliente array de cliente
/// @param lenCliente longitud del array cliente
/// @return   [-1] No hay datos para mostrar.
///           [0]  Si existe datos para mostrar.
int mostrarPedidosProcesados(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente);

/// @fn int pedidosPendientesLocalidad(ePedido[], int, eCliente[], int, char[])
/// @brief informa la cantidad de pedidos pendientes por localidad, el parametro
/// localidad se recibe por parametro
///
/// @param listPedido array de pedido
/// @param lenPedido longitud del array pedido
/// @param listCliente array de cliente
/// @param lenCliente longitud del array cliente
/// @param localidad parametro que ingresa el usuario para la busqueda
/// @return   [-1] No hay datos para mostrar.
///           [0]  Si existe datos para mostrar.
//int pedidosPendientesLocalidad(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente, char localidad[50] );
int pedidosPendientesLocalidad(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente, int idLocalidad );

/// @fn int promedioKilosPolipropileno(ePedido[], int, eCliente[], int)
/// @brief  informa Promedio kilos de polipropileno por cliente
///
/// @param listPedido array de pedido
/// @param lenPedido longitud del array pedido
/// @param listCliente array de cliente
/// @param lenCliente longitud del array cliente
/// @return   [-1] No hay datos para mostrar.
///           [0]  Si existe datos para mostrar.
int promedioKilosPolipropileno(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente );
int clienteMasPedidosPendientes (ePedido listaPedido[], int lenPedido);
int clienteMasPedidosCompletados (ePedido listaPedido[], int lenPedido);
#endif /* REPORTE_H_ */
