/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

 ============================================================================
 Name        : Trabajo practico 4
 Author      : Alejandro Holik
 ============================================================================

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
	startTesting(1);  // ll_newLinkedList // Constructor *** IMPLEMENTADO ***
    startTesting(2);  // ll_len // Informa largo dela lista *** IMPLEMENTADO ***
    startTesting(3);  // getNode - test_getNode // retorna un nodo *** IMPLEMENTADO ***
    startTesting(4);  // addNode - test_addNode agrega un nodo // *** IMPLEMENTADO ***
	startTesting(5);  // ll_add // Agrega un elemento a la linkedlist *** IMPLEMENTADO ***
	startTesting(6);  // ll_get // Retorna el elemento *** IMPLEMENTADO ***
	startTesting(7);  // ll_set /reemplaza un elemento por otro *** IMPLEMENTADO ***
	startTesting(8);  // ll_remove //quita un elemento del indice especificado ***  IMPLEMENTADO ***
	startTesting(9);  // ll_clear //limpia toda la lista *** IMPLEMENTADO ***
	startTesting(10); // ll_deleteLinkedList //Borra un linkedlist *** IMPLEMENTADO ***
	startTesting(11); // ll_indexOf //retorna indice de un elemento *** IMPLEMENTADO ***
	startTesting(12); // ll_isEmpty // chequea si el linkedlist esta vacio *** IMPLEMENTADO ***
	startTesting(13); // ll_push //agrega un elemento en el indice especificado *** IMPLEMENTADO ***
	startTesting(14); // ll_pop //remueve un elemento y lo retorna *** IMPLEMENTADO ***
	startTesting(15); // ll_contains //verifica si un elemento existe en la lista *** IMPLEMENTADO ***
	startTesting(16); // ll_containsAll //verifica si una lista es en otra lista *** IMPLEMENTADO ***
	startTesting(17); // ll_subList //crea una lista desde un indice hasta otro indice *** IMPLEMENTADO ***
	startTesting(18); // ll_clone //clona la lista *** IMPLEMENTADO ***
	startTesting(19); // ll_sort //ordenimiento burbujeo *** IMPLEMENTADO ***


    return 0;
}
