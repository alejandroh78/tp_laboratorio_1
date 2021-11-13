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
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); // Constructor
int ll_len(LinkedList* this); // Informa largo dela lista
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement); // Agrega un emento a la linkedlist
void* ll_get(LinkedList* this, int index); // retorna el elemento de una posicion especifica
int ll_set(LinkedList* this, int index,void* pElement); //reemplaza un elemento por otro
int ll_remove(LinkedList* this,int index); //quita un elemento del indice especificado
int ll_clear(LinkedList* this); //limpia toda la lista
int ll_deleteLinkedList(LinkedList* this);//Borra un linkedlist
int ll_indexOf(LinkedList* this, void* pElement);//retorna indice de un elemento
int ll_isEmpty(LinkedList* this); // chequea si el linkedlist esta vacio
int ll_push(LinkedList* this, int index, void* pElement); //agrega un elemento en el indice especificado
void* ll_pop(LinkedList* this,int index); //remueve un elemento y lo retorna
int ll_contains(LinkedList* this, void* pElement); //verifica si un elemento existe en la lista
int ll_containsAll(LinkedList* this,LinkedList* this2); //verifica si una lista es en otra lista
LinkedList* ll_subList(LinkedList* this,int from,int to); //crea una lista desde un indice hasta otro indice
LinkedList* ll_clone(LinkedList* this); //clona la lista
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
