/*
 * pedido.h
 *
 *  Created on: 19 oct. 2021
 *      Author: aholi
 */

#ifndef PEDIDO_H_
#define PEDIDO_H_
#define OCUPADO 1
#define VACIO 0
#define ESTADO_PEDIDO_RECOLECCION "PENDIENTE"
#define TAMPEDIDO 1000

#include "cliente.h"
#include "pedido.h"

typedef struct
{
    int idPedido;
    int idCliente;
    int kilosTotales;
    int kilosHdpe;
    int kilosLdpe;
    int kilosPp;
    char estado[51];
    int isEmpty;
}ePedido;

/// @fn int initPedido(ePedido[], int)
/// @brief Funcion que blanquea todas las posiciones del array pedidos
///        colocando la bandera isEmpty en TRUE.
///
/// @param listPedido array de pedido
/// @param lenPedido longitud del array de pedidos
/// @return
int initPedido(ePedido listPedido[],int lenPedido);

/// @fn int getNuevoPedidoId()
/// @brief genera un nuevo ID de Pedido.
///
/// @return el id de pedido generado
int getNuevoPedidoId();

/// @fn int buscarPedidoId(ePedido[], int, int)
/// @brief Obtiene el indice del array de Pedido del ID ingresado como parametro
///
/// @param listPedido array de pedido
/// @param lenPedido longitud del array
/// @param id ID del pedido
/// @return  [-1] Si no encuentra el ID del cliente ingresado.
///          Encuentra el indice del cliente buscado.
int buscarPedidoId(ePedido listPedido[], int lenPedido, int id);

/// @fn int altaPedido(ePedido[], int, int, int, int, char[])
/// @brief Agregar un pedido con los valores cargados como parametros
///        en el primer lugar vacio de la lista ingresada.
///
/// @param listPedido array de pedido
/// @param lenPedido longitud del array de pedido
/// @param idPedido id del pedido
/// @param idCliente id del cliente
/// @param kilosTotales cantida de kilos
/// @param estadoPedido estado del pedido
/// @return
int altaPedido(ePedido listPedido[], int lenPedido, int idPedido, int idCliente, int kilosTotales, char estadoPedido[]);

/// @fn int buscarCantidadPedidosPorClienteId(int*, ePedido[], int, int)
/// @brief busca por id de cliente la cantidad de kilos pendientes
///
/// @param cantidadKilos retorna la cantidad de kilos pendientes
/// @param listPedido array de pedido
/// @param len longitud del array
/// @param idCliente id del cliente a buscar
/// @return   [-1] No hay datos .
///           [0]  Si existe datos .
int buscarCantidadPedidosPorClienteId(int* cantidadKilos, ePedido listPedido[], int len, int idCliente);

/// @fn int buscarCantidadPedidosPendientes(int*, ePedido[], int, int)
/// @brief
///
/// @param cantidad retorna la cantidad de pedidos pendeintes
/// @param listPedido array de pedido
/// @param lenPedido  longitud del array pedido
/// @param idCliente  id del cliente a buscar
/// @return   [-1] No hay datos .
///           [0]  Si existe datos .
int buscarCantidadPedidosPendientes(int* cantidad, ePedido listPedido[], int lenPedido,  int idCliente);

/// @fn int mostrarPedidosPendientes(ePedido[], int, eCliente[], int)
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
int mostrarPedidosPendientes(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente);

/// @fn void mostrarPedidoPendiente(ePedido)
/// @brief muestra los datos de un pedido pendiente

/// @param listPedido dato pedido
void mostrarPedidoPendiente(ePedido listPedido);

/// @fn void mostrarPedidoAProcesar(ePedido)
/// @brief muestra el id a procesar
///
/// @param listPedido dato pedido
void mostrarPedidoAProcesar(ePedido listPedido);

/// @fn void pedidosHardcode(ePedido[], int, int)
/// @brief   datos precargados de pedidos
///
/// @param listPedido array de pedido
/// @param lenPedido longitud del array de pedido
/// @param quantity cantidad de pedidos
void pedidosHardcode(ePedido listPedido[], int lenPedido, int quantity);


//chequear
int swapPedidos(ePedido* pedido1, ePedido* pedido2);
int comparePedido(ePedido pedido1, ePedido pedido2);
int ordenarPedidos(ePedido listPedido[], int lenPedido, eCliente listCliente[], int lenCliente, int order);


#endif /* PEDIDO_H_ */
