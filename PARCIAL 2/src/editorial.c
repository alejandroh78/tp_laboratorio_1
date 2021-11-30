#include "editorial.h"


eEditorial* editorial_new()
{
	eEditorial* auxEditorial;
	auxEditorial = malloc(sizeof(eEditorial));
    if(auxEditorial==NULL)
    {
        printf("NO HAY ESPACIO EN MEMORIA EDITORIAL");
        return 0;
    }
    return auxEditorial;
}

eEditorial* editorial_newParametros(int* pIdEditorial, char pNombre[])
{
	eEditorial* auxEditorial;
	auxEditorial = editorial_new();

    editorial_setIdEditorial(auxEditorial,*pIdEditorial);
    editorial_setNombre(auxEditorial, pNombre);

    return auxEditorial;
}




int libro_setIdEditorial(eLibro* this, int pIdEditorial)
{
	int retorno = 0;

	if(this!=NULL)
    {
		this->idEditorial= pIdEditorial;
        retorno = 1;
    }

    return retorno;

}
int libro_getIdEditorial(eLibro* this, int* pIdEditorial)
{
	int retorno = 0;

	if(this!=NULL)
    {
		*pIdEditorial= this->idEditorial;
        retorno = 1;
    }

    return retorno;
}


int editorial_setIdEditorial(eEditorial* this, int pIdEditorial)
{
	int retorno = 0;

	if(this!=NULL)
    {
    	this->idEditorial = pIdEditorial;
    	retorno = 1;
    }

    return retorno;

}
int editorial_getIdEditorial(eEditorial* this, int* pIdEditorial)
{
	int retorno = 0;

	if(this!=NULL)
    {
		*pIdEditorial = this->idEditorial;
        retorno = 1;
    }

    return retorno;
}

int editorial_setNombre(eEditorial* this, char* pNombre)
{
	int retorno = 0;

	if(this!=NULL)
    {
		strcpy(this->nombre, pNombre);
        retorno = 1;
    }

    return retorno;
}

int editorial_getNombre(eEditorial* this, char* pNombre)
{
	int retorno = 0;

	if(this!=NULL)
    {
    	strcpy(pNombre,this->nombre);
    	retorno = 1;
    }
	return retorno;

}
