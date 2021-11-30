#include "libro.h"


eLibro* libro_new()
{
	eLibro* auxLibro;
	auxLibro = malloc(sizeof(eLibro));
    if(auxLibro==NULL)
    {
        printf("NO HAY ESPACIO EN MEMORIA PARA LIBROS");
        return 0;
    }
    return auxLibro;
}


eLibro* libro_newParametros(int* pIdLibro, char pTitulo[], char pAutor[], int* pPrecio, int* pIdEditorial)
{
	eLibro* auxLibro;
	auxLibro = libro_new();

    libro_setId(auxLibro, *pIdLibro);
    libro_setTitulo(auxLibro,pTitulo);
    libro_setAutor(auxLibro,pAutor);
    libro_setPrecio(auxLibro,*pPrecio);
    libro_setIdEditorial(auxLibro, *pIdEditorial);
    return auxLibro;
}


int libro_setId(eLibro* this, int pId)
{
	int retorno = 0;

    if(this!=NULL)
    {
        this->id = pId;
        retorno = 1;
    }

    return retorno;

}
int libro_getId(eLibro* this, int* pId)
{
	int retorno = 0;

	if(this!=NULL)
    {
	    *pId= this->id;
	    retorno = 1;
    }

	return retorno;
}

int libro_setTitulo(eLibro* this, char pTitulo[])
{
	int retorno = 0;

	if(this!=NULL)
    {
		strcpy(this->titulo,pTitulo);
        retorno = 1;
    }

    return retorno;
}

int libro_getTitulo(eLibro* this, char pTitulo[])
{
	int retorno = 0;

	if(this!=NULL)
    {
		strcpy(pTitulo,this->titulo);
        retorno = 1;
    }

    return retorno;

}

int libro_setAutor(eLibro* this, char pAutor[])
{
	int retorno = 0;

	if(this!=NULL)
    {
		strcpy(this->autor,pAutor);
        retorno = 1;
    }

    return retorno;
}

int libro_getAutor(eLibro* this, char pAutor[])
{
	int retorno = 0;

	if(this!=NULL)
    {
		strcpy(pAutor,this->autor);
        retorno = 1;
    }

    return retorno;

}

int libro_setPrecio(eLibro* this, int pPrecio)
{
	int retorno = 0;

	if(this!=NULL)
    {
		this->precio = pPrecio;
        retorno = 1;
    }

    return retorno;

}
int libro_getPrecio(eLibro* this, int* pPrecio)
{
	int retorno = 0;

	if(this!=NULL)
    {
		*pPrecio= this->precio;
        retorno = 1;
    }

    return retorno;
}


int libro_CompararPorNombre(void* pElement1, void* pElement2)
{
    int retorno;
    eLibro* auxLibro1 = (eLibro*)pElement1;
    eLibro* auxLibro2 = (eLibro*)pElement2;

    if(auxLibro1 != NULL && auxLibro2 != NULL)
    {
    	retorno = strcmp(auxLibro1->autor, auxLibro2->autor);
    }

    return retorno;
}

int editorial_filtroMinotauro(void* this)
{
    int returnAux = 0;
    eLibro* libro;
    int editorialMinotauro = 4;

    if(this != NULL)
    {
    	libro = (void*)this;

        if(libro->idEditorial == editorialMinotauro)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

int editorial_filtroPlanetaSigloXXI(void* this)
{
    int returnAux = 0;
    eLibro* libro;
    int editorialPlaneta = 1;
    int editorialSigloXXI = 2;

    if(this != NULL)
    {
    	libro = (void*)this;

        if((libro->idEditorial == editorialPlaneta) || (libro->idEditorial == editorialSigloXXI))
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

void calcularDescuento(void* val){

	eLibro* auxLibro;
	auxLibro = val;
    if (auxLibro != NULL)
    {

    	if (auxLibro->idEditorial == 1 && (auxLibro->precio >= 300))
    	{
        	auxLibro->precio =  (auxLibro->precio)-(auxLibro->precio * 0.20);
        }
    	else
    	{
        	if (auxLibro->idEditorial == 2 && (auxLibro->precio <= 200))
        	{
        		auxLibro->precio =  (auxLibro->precio)-(auxLibro->precio * 0.10);
        	}
    	}

    }
}
