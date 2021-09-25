/*
 ============================================================================
 Name        : TP1.c
 Author      : Alejandro Holik
 Version     :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "biblioteca.h"


int main(void) {

	setbuf(stdout, NULL);


	float numeroIngresado1Float;
	float numeroIngresado2Float;
	float numeroAuxiliar;


	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicar;
	float resultadoDividir;
	int resultadoFactorial1;
	int resultadoFactorial2;
	int flagMenu3;
	int retornoFactorial1;
	int retornoFactorial2;

	int retornoDividir;
	int inputMenu;

	flagMenu3 =0;
	resultadoFactorial1 = 0;
	resultadoFactorial2 = 0;
	numeroAuxiliar = 0;
	inputMenu = 0;


		do
		{
			system("color 03");
			printf("*********** CALCULADORA TP 1 *********** \n");
			//system("color 07"); /*ponemos las letras en rojo*/

			printf("1. Ingresar 1er operando (%.2f)\n", numeroIngresado1Float);

			printf("2. Ingresar 2do operando (%.2f)\n", numeroIngresado2Float);
			printf("3. Calcular todas las operaciones\n");
			printf("4. Informar resultados\n");
			printf("5. Salir\n");


			PideNumeroInt("Ingrese una opcion: ", &inputMenu);

			system("cls");

			switch(inputMenu)
			{
				case 1:
					PideNumeroFloat("Ingrese 1er operando: ",&numeroAuxiliar);
					numeroIngresado1Float = numeroAuxiliar;
					system("cls");

				break;

				case 2:

	                PideNumeroFloat("Ingrese 2do operando: ", &numeroAuxiliar);
	                numeroIngresado2Float = numeroAuxiliar;
	                system("cls");
	                break;


				case 3:
					if (numeroIngresado1Float == 0 && numeroIngresado2Float == 0){
						system("color 04");
						printf("3. Calcular todas las operaciones\n\n");
						printf("*********************************************************************\n");
						printf("                          < ERROR >\n");
						printf("Para ejecutar los calculos debe ingresar los operando 1 y operando 2 \n");
						printf("desde el menu y luego ejecutar el calculo de operaciones.\n");
						printf("*********************************************************************\n");

						system("pause");
						system("cls");
					}
					else
					{
						system("color 02");
						system("cls");
						printf("3. Calcular todas las operaciones\n\n");
						printf("********************************\n");
						printf("Se realizaron todos los calculos \n");
						printf("********************************\n\n");
						funcionSuma(numeroIngresado1Float,numeroIngresado2Float, &numeroAuxiliar);
						resultadoSuma = numeroAuxiliar;

						funcionResta(numeroIngresado1Float,numeroIngresado2Float, &numeroAuxiliar);
						resultadoResta = numeroAuxiliar;

						funcionMultiplicar(numeroIngresado1Float,numeroIngresado2Float, &numeroAuxiliar);
						resultadoMultiplicar = numeroAuxiliar;

						retornoDividir = funcionDividir(numeroIngresado1Float,numeroIngresado2Float, &numeroAuxiliar);
						resultadoDividir = numeroAuxiliar;

						retornoFactorial1 = CalculoFactorial(numeroIngresado1Float,&numeroAuxiliar);
						resultadoFactorial1 = numeroAuxiliar;

						retornoFactorial2 = CalculoFactorial(numeroIngresado2Float,&numeroAuxiliar);
						resultadoFactorial2 = numeroAuxiliar;

						flagMenu3=1;
						system("pause");
						system("cls");
					}

				break;

				case 4:
					system("cls");

					if (flagMenu3 == 0)
					{
						system("color 04");
						printf("4. Informar resultados\n\n");
						printf("************************************************************\n");
						printf("                          < ERROR >\n");
						printf("Para ver los resultados primero debe ingresar a la opcion 3\n");
						printf("del menu para que se realicen los calculos.\n");
						printf("************************************************************\n");

						system("pause");
						system("cls");
					}
					else
					{
						if (numeroIngresado1Float == 0 && numeroIngresado2Float == 0)
						{
							system("color 06");
							printf("4. Informar resultados\n\n");
							printf("Los resultados de los calculos son los siguientes: \n");
							printf("**************************************************\n");
							printf("No ingreso valores para los operando 1 y operando 2\n");
							printf("**************************************************\n\n");
							printf("\n\n");
							system("pause");
							system("cls");
						}
						else
						{
							system("color 02");
							printf("4. Informar resultados\n\n");
							printf("Los resultados de los calculos son los siguientes: \n");
							printf("************************************************************************************\n");

							MostrarNumeroEvaluado("Valor ingresando operando 1:", numeroIngresado1Float);

							MostrarNumeroEvaluado("Valor ingresando operando 2:", numeroIngresado2Float);

							printf("\n");

							MostrarNumeroEvaluado("Resultado de la suma:", resultadoSuma);

							MostrarNumeroEvaluado("Resultado de la resta:", resultadoResta);

							MostrarNumeroEvaluado("Resultado de la multiplicacion:", resultadoMultiplicar);

							if (retornoDividir == 0)
							{
								MostrarNumeroEvaluado("Resultado de la division:", resultadoDividir);
							}
							else
							{
								printf("Resultado de la division no se puede realizar porque operando2 es 0\n");
							}

							if (retornoFactorial1 == 0)
							{
								MostrarNumeroEvaluado("Resultado factorial operando1:", resultadoFactorial1);
							}
							else
							{
								printf("Resultado factorial operando1, no es posible calcularlo porque esta fuera del limite\n");
							}

							if (retornoFactorial2 == 0)
							{
								MostrarNumeroEvaluado("Resultado factorial operando2:", resultadoFactorial2);
							}
							else
							{
								printf("Resultado factorial operando2, no es posible calcularlo porque esta fuera del limite\n");
							}

							printf("************************************************************************************\n\n");

							system("pause");
							system("cls");
						}
					}

				break;

				case 5:
					system("cls");

						printf("Gracias por utilizar la calculara TP 1\n\n");
						system("pause");

			}

		}while(inputMenu !=5);

		return 0;

}

