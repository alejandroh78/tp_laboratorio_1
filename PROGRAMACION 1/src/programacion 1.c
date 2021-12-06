/*
Cargar un array con medidas de ángulos (Validar los ingresos).
En un segundo array clasificar los ángulos del array anterior en “AGUDO”, “RECTO”, “OBTUSO” y “LLANO”.
Ordenar los arrays por medida de forma decreciente y mostrar los datos.
Notas:
Cada ítem deberá resolverse en funciones separadas, parametrizadas según corresponda.
Recuerden que estamos trabajando con vectores paralelos

Alejandro Holik

*/

#include <stdio.h>
#include <stdlib.h>
#include "input.h"

#define TAM_ARRAY 4

void imprimirArray(int arrayResultado[], int tam);
void nuevoArray(int enteros[], int tam, int arrayResultado[]);
void determinarAngulo(int arrayResultado[],char cadena[][20],int tam);
void ordenarAngulos(int arrayResultado[],int tam);
void cargarValoresAngulo();

int main()
{
	setbuf(stdout, NULL);

   int arrayEnteros[TAM_ARRAY];
   int arrayResultado[TAM_ARRAY];
   char arrayCadenas[TAM_ARRAY][20];

   cargarValoresAngulo(arrayEnteros, TAM_ARRAY);
   imprimirArray(arrayEnteros, TAM_ARRAY);
   nuevoArray(arrayEnteros, TAM_ARRAY, arrayResultado);
   imprimirArray(arrayResultado,TAM_ARRAY);
   determinarAngulo(arrayResultado,arrayCadenas,TAM_ARRAY);
   ordenarAngulos(arrayResultado,TAM_ARRAY);
   imprimirArray(arrayResultado,TAM_ARRAY);

   return 0;
}


void cargarValoresAngulo( int lista[], int len)
{
	char checkContinuar;
	int i = 0;

   do
   {
	   inputNumberInt(&lista[i], "Ingrese la medida del angulo: ", "Error, a medida del angulo: ", 0, 180);
	   checkContinuar=checkContinue();
	   i++;
   }while( checkContinuar == 'S' && i < len);
}


void ordenarAngulos(int arrayResultado[],int tam)
{
    int aux;
    for (int i = 0; i < tam-1; i++)
    {
    	for (int j = i+1 ; j < tam; j++)
    	{
            if(arrayResultado[i]<arrayResultado[j])
            {
                aux=arrayResultado[i];
                arrayResultado[i]=arrayResultado[j];
                arrayResultado[j]=aux;
            }
        }
    }
}

void determinarAngulo(int arrayResultado[],char cadena[][20],int tam)
{

    for (int i = 0; i < tam; i++) {

        if(arrayResultado[i] > 90 && arrayResultado[i] < 180)
		{
			strcpy(cadena[i],"ANGULO OBTUSO");
			printf("%d %s  \n", arrayResultado[i],cadena[i]);
		}
        else
        {
            if(arrayResultado[i] < 90)
             {

                  strcpy(cadena[i],"ANGULO AGUDO");
                  printf("%d %s \n", arrayResultado[i],cadena[i]);
             }
            else
            {
                if(arrayResultado[i] == 90)
                {
                    strcpy(cadena[i],"ANGULO RECTO");
                    printf("%d %s  \n", arrayResultado[i],cadena[i]);
                }
                else
                {
                    if(arrayResultado[i] == 180)
            		{
            			strcpy(cadena[i],"ANGULO LLANO");
            			printf("%d %s  \n", arrayResultado[i],cadena[i]);
            		}

                }
            }

        }


    }
}

void imprimirArray(int arrayResultado[], int tam)
{
    for (int i = 0; i < tam; i++) {

        printf("%d \n", arrayResultado[i]);
    }
}

void nuevoArray(int enteros[], int tam, int arrayResultado[])
{

    for (int i = 0; i < tam; i++)
    {
        arrayResultado[i] = enteros[i];
    }
}

