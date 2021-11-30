#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "controlador_editorial.h"
#include "LinkedList.h"
#include "parser.h"
#include "input.h"
#include "libro.h"
#include "menu.h"



int controller_loadFromText_Editorial(char* path, LinkedList* this)
{
    FILE* pFile;
    int retorno = 0;
    ll_clear(this);
    pFile = fopen(path,"r");

    if(this!= NULL)
    {
        if(pFile != NULL)
        {
        	retorno = parser_FromText_Editorial(pFile,this);
        }

    }
    fclose(pFile);
    return retorno;
}

