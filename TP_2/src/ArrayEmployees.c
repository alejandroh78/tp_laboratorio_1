#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

#define OCUPADO 1
#define VACIO 0



int addEmployee(Employee list[], int len, int id, char name[], char lastName[], float salary, int sector)
{
    int returnValue = -1;
    int emptyIndex;

    if(list != NULL && len > 0 && len <= 1000
        && name != NULL && lastName != NULL)
    {

        if(findEmployeeById(list, len, id) != -1)
        {
            printf("El ID ingresado ya esta en uso.\n");
        }
        else
        {

        	 emptyIndex = initEmployees(list, len);

            if(emptyIndex != -1)
            {

                list[emptyIndex].id = id;
                strcpy(list[emptyIndex].name, name);
                strcpy(list[emptyIndex].lastName, lastName);
                list[emptyIndex].salary = salary;
                list[emptyIndex].sector = sector;
                list[emptyIndex].isEmpty = OCUPADO;

                returnValue = 0;

            }
        }
    }

    return returnValue;
}


int findEmployeeById(Employee list[], int len, int id)
{
    int returnValue = -1;

    if(list != NULL && len > 0 && len <= 1000)
    {
        for (int i = 0; i < len; i++)
        {
            if(list[i].id == id)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}
int removeEmployee(Employee list[],int len, int id)
{
    int retorno = -1;
    int i;

    for(i = 0; i < len; i++)
    {
        if(list[i].id == id)
        {
        	list[i].isEmpty = VACIO;
            retorno = 0;
        }
    }
    return retorno;
}


int findSectorById(eSector list[], int tam,int id)
{
    int i;
    int retorno=-1;

    for(i=0; i<tam; i++)
    {
        if(list[i].idSector==id)
        {
            retorno=i;
        }
    }

    return retorno;
}


int checkEmployeesExists(Employee list[], int tam)
{
    int retorno=0;
    int i;
    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            retorno=1;
            break;
        }
    }

    return retorno;
}


int getNewEmployeeId()
{
    static int id=1000;

    return id++;
}


int initEmployees(Employee list[],int tam)
{
    int retorno = -1;
    int i;
    if(tam > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0; i<tam; i++)
        {
            list[i].isEmpty=0;
            list[i].id=0;
        }
    }
    return retorno;
}



int sortingEmployees(Employee* list, int lengthEmp){
    int order;

    system("cls");
    printf("Ordenar [A-Z] o [Z-A]\n");
    printf("1- Empleados ordernados por apellido y sector de manera ascendente\n");
    printf("2- Empleados ordernados por apellido y sector de manera descendente\n");
    printf("\nIngrese opcion: ");
    scanf("%d",&order);

    sortEmployeesByName(list,lengthEmp,order);

    return order;
}
int printEmployees(Employee list[], int tam, eSector sector[], int tamSec)
{
    int i;
    int retorno=-1;

    printf("***********************************************************************************************************\n");
    printf("  ID             Nombre     	     Apellido    	   Salario      ID Sector                    Sector\n");
    printf("***********************************************************************************************************\n");
    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
        	printEmployee(list[i], sector, tamSec);
            retorno=0;
        }
    }

    return retorno;

}

void reportTotalEmployeeCalc(Employee list[], int tam, eSector sector[], int tamSec)
{
    int i;

    float total=0;
    float promedio;
    int contador=0;
    int contador2=0;

    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            total=total+list[i].salary;
            contador++;
        }

    }

    promedio=total/contador;

    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty==OCUPADO && list[i].salary>promedio)
        {
            contador2++;
        }

    }
    printf("***********************************************************************************************************\n");
    printf("                                    Reporte total y promedio de salarios \n");
    printf("***********************************************************************************************************\n");
    printf("Total de sueldos: %.2f\n", total);
    printf("Promedio de Sueldos: %.2f\n", promedio);
    printf("Total de empleados que superan el salario promedio: %d \n\n", contador2);


}


int sortEmployeesByName(Employee* list, int lengthEmp, int order){

	int retorno=0;

    for(int i=0;i<lengthEmp-1;i++){
        for(int j=i+1;j<lengthEmp;j++){
            if(list[i].isEmpty==OCUPADO){
                if(order==1){
                    if(list[i].sector>list[j].sector){
                    	swapEmployees(list,lengthEmp,i,j);
                    }else{
                        if((list[i].sector==list[j].sector)&&(stricmp(list[i].lastName,list[j].lastName)>0)){
                        	swapEmployees(list,lengthEmp,i,j);
                        }
                    }
                }else if(order==2){
                    if(list[i].sector<list[j].sector){
                    	swapEmployees(list,lengthEmp,i,j);
                    }else{
                        if((list[i].sector==list[j].sector)&&(stricmp(list[i].lastName,list[j].lastName)<0)){
                        	swapEmployees(list,lengthEmp,i,j);
                        }
                    }
                }
            }
        }
    }

    return retorno;
}

void swapEmployees(Employee* list, int length, int i, int j){
    Employee auxEmp;

    auxEmp=list[i];
    list[i]=list[j];
    list[j]=auxEmp;
}

void printEmployee(Employee list, eSector sec[], int tamSec)
{

    int idSector=list.sector;
    int indiceSector=findSectorById(sec, tamSec, idSector);


    printf("%2d     %14s        %14s          %11.2f         %6d    %22s\n", list.id, list.name, list.lastName, list.salary, list.sector, sec[indiceSector].nameSector );
}


int printSectors(eSector sector[], int tamSec)
{

    int i;
    printf("ID SECTOR    -    DESCRIPCION\n");
    for(i=0; i<tamSec; i++)
    {
        printf("%5d         %13s\n", sector[i].idSector, sector[i].nameSector);
    }

    return i;
}


