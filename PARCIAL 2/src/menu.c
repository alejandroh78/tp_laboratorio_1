#include "menu.h"

int menuPrincipal(int* opcion)
{
    int retorno = -1;

    system("cls");

    printf("********************************************************************************\n");
    printf("*                                MENU PRINCIPAL                                *\n");
    printf("********************************************************************************\n");
    printf("1. Cargar los datos de los LIBROS desde el archivo libro.csv                    \n");
    printf("2. Cargar los datos de las EDITORIALES desde el archivo editorial.csv           \n");
    printf("3. Ordenar Datos                                                                \n");
    printf("4. Listados por Pantalla                                                        \n");
    printf("5. Guardar libros de la Editorial MINUTAURO en el archivo minotauro.csv         \n");
    printf("6. Generar el archivo de salida mapeado.csv                                     \n");
    printf("7. Salir del programa                                                          \n\n");

    if(!inputNumberInt(opcion, "Elija una opcion del menu: ", "Error, Elija una opcion del menu: ", 1, MENU_PRINCIPAL_Q))
    {
    	retorno = 0;
    }

    return retorno;
}

int menuOrdenamiento(int* opcion)
{
    int retorno = -1;

    system("cls");

    printf("*********************************************\n");
    printf("*         MENU PARA ORDENAR LOS DATOS       *\n");
    printf("*********************************************\n");
    printf("1. Ordenar por Autor                          \n");
    printf("2. Volver al menu principal                   \n\n");

    if(!inputNumberInt(opcion, "Elija una opcion del menu: ", "Error, Elija una opcion del menu: ", 1, MENU_ORDENAMIENTO_Q))
    {
    	retorno = 0;
    }

    return retorno;
}
