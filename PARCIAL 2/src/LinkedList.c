#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controlador_editorial.h"
#include "controlador_libro.h"

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this=NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this!=NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

        if(this!=NULL)
        {
            returnAux=this->size;
        }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodoAux = NULL;
	int i;

	if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
	{
		nodoAux = this->pFirstNode;//indice 0
		for(i=0;i<nodeIndex;i++)
		{
			nodoAux = nodoAux->pNextNode;
		}
	}
    return nodoAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    Node* nodoAnterior = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
    	Node* nodoNuevo = (Node*)malloc(sizeof(Node));

    	nodoNuevo->pElement = pElement;

    	if (nodeIndex ==0) //CONTROL PARA EL FIRSTNODE
    	{
    		nodoNuevo->pNextNode = this->pFirstNode;
			this->pFirstNode = nodoNuevo;
    	}
    	else
    	{
    		nodoAnterior = getNode(this,nodeIndex-1); //LLAMO EL GETNODE NODINDEX-1 PARA RECUPERAR EL NODO ANTERIOR
			nodoNuevo->pNextNode = nodoAnterior->pNextNode; //nodoNuevo GUARDA EL NODO SIGIENTE
    		nodoAnterior->pNextNode = nodoNuevo; //nodoAnterior GUARDA EL NUEVO
    	}
    	this->size++;
		returnAux = 0;

    }

   	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
		addNode(this, ll_len(this), pElement);
		returnAux = 0;

    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodoAux;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
    	nodoAux = getNode(this,index);
    	if(nodoAux != NULL)
    	{
    		returnAux = nodoAux->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodoAux = NULL;

    if (this != NULL && index >= 0 && index < ll_len(this))
    {
    	nodoAux = getNode(this, index);
    	nodoAux->pElement = pElement;
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodoAux;
    Node* pNodeAnterior;
    if(this!=NULL && index>=0 && index <ll_len(this))
    {
    	nodoAux=getNode(this, index);
    	pNodeAnterior=getNode(this, index-1);
    	if(nodoAux != NULL)
    	{
    		if(index==0)
    		{
    			//this->pFirstNode=NULL; coreccion, si lo dejaba en NULL rompia los nodos...
    			this->pFirstNode = nodoAux->pNextNode;
    		}else
    		{
    			pNodeAnterior->pNextNode = nodoAux->pNextNode;
    		}
    		// me falta llamada al free. chequear siempre
    		free(nodoAux);
    		this->size--;
    		returnAux=0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int index;

    if(this!=NULL)
    {
    	index = ll_len(this);
    	while(index > 0)
    	{
    		ll_remove(this, 0);
    		index--;
    	}
    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	//verificar un retorno para hacer el resto.
        ll_clear(this);
        free(this);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodoAux = NULL;
    int i;

    if(this != NULL){

        for(i = 0; i < ll_len(this); i++)
        {
        	//utilizar el get en vez del getnode.
        	nodoAux = getNode(this, i);

            if(nodoAux->pElement == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {

        if(ll_len(this) > 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        addNode(this, index, pElement);
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL)
    {
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* nodoAux = NULL;
    int i;

    if(this != NULL)
    {
        returnAux = 0;
        for(i = 0; i < ll_len(this); i++)
        {
        	nodoAux = getNode(this, i);
            if(nodoAux->pElement == pElement)
            {
                returnAux = 1;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElementAux = NULL;
    int retorno;
    int i;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(i = 0; i < ll_len(this2); i++)
        {
        	pElementAux = ll_get(this, i);
            retorno = ll_contains(this2, pElementAux);
            if(retorno == 0)
            {
                returnAux = 0;
                break;
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* pElementAux;

    if(this!=NULL)
    {
    	if(from>=0 && from<=ll_len(this) && to > from && to<= ll_len(this))
    	{
    		cloneArray=ll_newLinkedList();

    		if(cloneArray!= NULL)
    		{
    			for(i=from; i<to; i++)
    			{
    				pElementAux = ll_get(this, i);
    				//validar si metio el dato y con el retorno controlar si salio ok o dio mal
    				ll_add(cloneArray, pElementAux);
    			}
    		}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if(this!=NULL)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    void* pElementAux1;
    void* pElementAux2;
    int i;
    int flagSort;
    int length;

    if(this!=NULL && order>=0 && pFunc != NULL)
    {
        length = ll_len(this);

        do
        {
        	flagSort=0;

            for (i = 0; i < length-1; i++)
            {
            	pElementAux1 = ll_get(this, i);
            	pElementAux2 = ll_get(this, i + 1);

                if( ((pFunc(pElementAux1, pElementAux2) < 0) && !order) || ((pFunc(pElementAux1, pElementAux2) > 0) && order) )
                {
                    ll_set(this, i, pElementAux2);
                    ll_set(this, i + 1, pElementAux1);
                    flagSort = 1;
                }
            }
        }while(flagSort);

        returnAux = 0;
    }
    return returnAux;
}


/**
 * @brief  Recorre los elemento de una lista y acumula los valores que se paron por por funcion.
 * @param  this Lista para iterar los elementos
 * @param  fn funcion que devuelve la cantidad que debe contarse.
 * @return Retorna el valor acumulado.
 */
int ll_count(LinkedList* this, int (*fn)(void* element))
{
	int contador = 0;
	int valorActual; //valor actual de la iteracion
	int lenght; // largo de la lista
	void* pElement; //elemento actual para iterar.

	if(this != NULL && *fn != NULL)
	{
		lenght = ll_len(this);
		for (int i = 0; i < lenght; i++)
		{
			pElement = ll_get(this, i); //recorro la lista original.
			valorActual = fn(pElement);

			if (valorActual != -1)
			{ // si la variable es distinto de -1, me copio el valor.
				contador = contador + valorActual; //sumo el numero a mi acumulador
			}
		}
	}
	return contador;
}

/**
 * @brief  Copia una lista en la que los elementos coincidan con elemento pasado por parametro.
 * @param  this linkenlist
 * @param  pFunc
 * @return Retorna la lista copiada sino NULL.
 */
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
{
    int i;
    int size;
    void* elemento;
    LinkedList* newLinkedList;
    int controlAdd;

    if(this!=NULL && *fn != NULL)
    {
    	newLinkedList = ll_newLinkedList();
        size = ll_len(this);
        for(i=0;i<size;i++)
        {
            elemento = (void*) ll_get(this,i);
            controlAdd = fn(elemento);
            if(controlAdd == 1)
            {
                ll_add(newLinkedList,elemento);
            }
        }
    }
    return newLinkedList;
}

/**
 * @brief  Copia una lista en la que los elementos coincidan con elemento pasado por parametro.
 * @param  this linkenlist
 * @param  pFunc
 * @return Retorna la lista copiada sino NULL.
 */
LinkedList* ll_filter_Parametro(LinkedList* this, int (*fn)(void* element,char* cadena),char* stringCadena)
{
    int i;
    int size;
    void* elemento;
    LinkedList* retorno;
    int dev;

    if(this!=NULL)
    {
        retorno = ll_newLinkedList();
        size = ll_len(this);
        for(i=0;i<size;i++)
        {
            elemento = (void*) ll_get(this,i);
            dev = fn(elemento,stringCadena);
            if(dev==1)
            {
                ll_add(retorno,elemento);
            }
        }
    }
    return retorno;
}

int ll_map(LinkedList* this, LinkedList* this2,void (*pFunc) (void*))
{
    int i, returnAux=0;
    void* pElement;
    if (this != NULL && pFunc != NULL)
    {
        returnAux =1;
        for (i=0; i<ll_len(this); i++)
        {
            pElement = ll_get(this,i);
            pFunc(pElement);
        }
    }

    return returnAux;
}

