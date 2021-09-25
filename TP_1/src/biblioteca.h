
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMERO_MAX_FACTORIAL 13

#ifndef FNCCALCULOS_H_
#define FNCCALCULOS_H_


/// @fn int PideNumeroInt(char[], int*)
/// @brief Ingreso de carga de un numero entero y dentro de la funcion se valida
///
/// @param mensaje es el mensaje que se muestra ej: "ingrese un numero:"
/// @param input se carga el numero ingresado
/// @return se retorna el valor para validar, si retorna 0 es valido, si retorna 1 es invalido
int  PideNumeroInt(char mensaje[], int* input);

/// @fn int PideNumeroFloat(char[], float*)
/// @brief Ingreso de carga de un numero flotante y dentro de la funcion se valida
///
/// @param mensaje es el mensaje que se muestra ej: "ingrese un numero:"
/// @param input se carga el numero ingresado
/// @return se retorna el valor para validar, si retorna 0 es valido, si retorna 1 es invalido
int  PideNumeroFloat(char mensaje[], float* input);


/// @fn int validarInt(char[])
/// @brief valida si el numero es tipo int
///
/// @param mensaje a mostrar en caso del valor ingresado no sea un numero, ej El valor ingresado no es un numero
/// @return se retorna el valor validado, si retorna 0 es valido, si retorna 1 es invalido
int   validarInt(char[20]);


/// @fn int validarFloat(char[])
/// @brief valida si el numero es tipo float
///
/// @param mensaje a mostrar en caso del valor ingresado no sea un numero, ej El valor ingresado no es un numero
/// @return se retorna el valor validado, si retorna 0 es valido, si retorna 1 es invalido
int   validarFloat(char[20]);

/// @fn void funcionSuma(float, float, float*)
/// @brief realiza el calculo de una suma utilizando 2 parametros de ingreso y retorna el resultado
///
/// @param numero ingresado operando1
/// @param numero ingresado operando2
/// @param varibable donde guarda el resultado
void funcionSuma(float , float , float* );

/// @fn void funcionResta(float, float, float*)
/// @brief realiza el calculo de una resta utilizando 2 parametros de ingreso y retorna el resultado
///
/// @param numero ingresado operando1
/// @param numero ingresado operando2
/// @param varibable donde guarda el resultado
void funcionResta(float , float , float* );

/// @fn int funcionDividir(float, float, float*)
/// @brief realiza el calculo de una division utilizando 2 parametros de ingreso y retorna el resultado
///
/// @param numero ingresado operando1
/// @param numero ingresado operando2
/// @param varibable donde guarda el resultado
/// @return se retorna el valor validado, si retorna 0 es valido, si retorna 1 no se pudo realizar la operacion
int funcionDividir(float , float , float* );

/// @fn void funcionMultiplicar(float, float, float*)
/// @brief realiza el calculo de una multiplicacion utilizando 2 parametros de ingreso y retorna el resultado
///
/// @param numero ingresado operando1
/// @param numero ingresado operando2
/// @param varibable donde guarda el resultado
void funcionMultiplicar(float , float , float* );

/// @fn int CalculoFactorial(float, float*)
/// @brief realiza el calculo factorial utilizando 1 parametro de ingreso y retorna el resultado
///
/// @param numero ingresado para el calculo factorial
/// @param varibable donde guarda el resultado
/// @return se retorna el valor validado, si retorna 0 es valido, si retorna 1 no se pudo realizar la operacion
int CalculoFactorial(float , float* );

/// @fn int TipoDeNumero(float)
/// @brief se evalua el tipo de numero, si es entero o flotante
///
/// @param numero ingresado para evaluar
/// @return se retorna 1 para los numeros enteros y 2 para los numeros flotantes
int TipoDeNumero(float );

/// @fn void MostrarNumeroEvaluado(char[], float)
/// @brief se muestra un mensaje y un numero, ej Resultado de la suma: 10
/// dentro de esta funcion, se llama la funcion Tipo de numero que evalua
/// si es entero o flotante.
///
///
/// @param mensaje que se desea mostrar
/// @param numero que se desea mostrar
void MostrarNumeroEvaluado(char mensaje[], float numeroIngresado);


#endif /* FNCCALCULOS_H_ */
