
#include "biblioteca.h"



int PideNumeroInt(char mensaje[], int* input)
{

	char inputNumero[20];
	int salida;
	int control;
	salida = 0;

	do
	{

		printf("%s ", mensaje);
		fflush(stdin);

		scanf("%[^\n]", inputNumero);

		control = validarInt(inputNumero);

	}
	while(control == 1);

	*input = atoi(inputNumero);
	salida = 1;

	return salida;

}

int PideNumeroFloat(char mensaje[], float* input)
{

	char inputNumero[20];

	int control;
	int salida;
	salida = 0;

	do
	{
		printf("%s ", mensaje);
		fflush(stdin);
		scanf("%[^\n]", inputNumero);

		control = validarFloat(inputNumero);

	}
	while(control == 1);

	*input = atof(inputNumero);
	salida = 1;

	return salida;

}

int validarInt(char stringNumero[20]){


	    int salida;

	    int i;
	    int control1;
	    int signoPunto;

	    control1=0;
	    signoPunto=0;

        for (i = 0; i < strlen(stringNumero); i++)
        {
            if(stringNumero[i] == '.')
            {
            	signoPunto++;
            }

            if ((!isdigit(stringNumero[i]) && stringNumero[i] != '.' && stringNumero[i] != '-' && stringNumero[i] != '\n' ))
            {
                control1 = 1;
            }


        }

        if(control1 == 1 || signoPunto > 1)
	    {
	        printf("El valor ingresado no es un numero\n");
	        salida = 1;
	    }
	    else
	    {
	    	salida = 0;
	    }

	    return salida;

}

int validarFloat(char stringNumero[20]){


	    int salida;
	    int i;

	    int control1;
	    int signoPunto;

	    control1 = 0;
	    signoPunto = 0;

        for (i = 0; i < strlen(stringNumero); i++)
        {

            if(stringNumero[i] == '.')
            {
            	signoPunto++;
            }


            if ((!isdigit(stringNumero[i]) && stringNumero[i] != '.' && stringNumero[i] != '-' && stringNumero[i] != '\n'))
            {
                control1 = 1;
            }


        }

        if(control1 == 1 || signoPunto > 1)
	    {
	        printf("El valor ingresado no es un numero\n");
	        salida = 1;
	    }
	    else
	    {
	    	salida = 0;

	    }

	    return salida;
}


void funcionSuma(float operando1, float operando2, float* result)
{
    float auxResult;

    auxResult = 0;

    auxResult = operando1 + operando2;

	*result = auxResult;

}

void funcionResta(float operando1, float operando2, float* result)
{
    float auxResult;
    auxResult = 0;

    auxResult = operando1 - operando2;

	*result = auxResult;

}

void funcionMultiplicar(float operando1, float operando2, float* result)
{
    float auxResult;
    auxResult = 0;

    auxResult = operando1 * operando2;

	*result = auxResult;

}

int funcionDividir(float operando1, float operando2, float* result)
{
    int returnValue;
    float auxResult;
    auxResult = 0;

    if (operando2 == 0)
    {
    	returnValue = 1;
    }
    else
    {
    	auxResult = operando1 / operando2;
    	returnValue = 0;
    }

	*result = auxResult;

    return returnValue;
}

int CalculoFactorial(float numeroIngresado, float* result)
{
	int resultado;
	float resultadoFac;
	int i;
	resultadoFac = 1;
	resultado = 1;

	if (TipoDeNumero(numeroIngresado) == 1)
	{
		if(numeroIngresado > 0 && numeroIngresado < NUMERO_MAX_FACTORIAL)
		{
			for(i = 1; i <= numeroIngresado; i++)
			{
				resultadoFac = resultadoFac * i;
			}

			*result = resultadoFac;
			resultado = 0;
		}
		else
		{
			if(numeroIngresado == 0)
			{
				*result = 1;
				resultado = 0;
			}
		}
	}
	return resultado;
}



int TipoDeNumero(float numeroIngresado)
{
    int resultado = 0;
    float auxNumero;

    auxNumero = (float)((int)numeroIngresado);

    if (numeroIngresado == auxNumero)
    {
    	resultado = 1;
    }
    else
    {
        if (numeroIngresado - auxNumero != 0.0f)
        {
        	resultado = 2;
        }
    }

    return resultado;
}
void MostrarNumeroEvaluado(char mensaje[], float numeroIngresado)
{
    switch (TipoDeNumero(numeroIngresado))
    {
        case 1:
            printf("%s %.0lf\n", mensaje, numeroIngresado);
            break;
        case 2:
            printf("%s %.2lf\n", mensaje, numeroIngresado);
            break;
    }
}
