/*
 * inputs.c
 *
 *  Created on: 7 jun. 2021
 *      Author: Lautaro
 */

#include "inputs.h"


int GetInt(char *msj)
{
    int value;

    printf(msj);
    scanf("%d", &value);

    return value;
}

float GetFloat(char *msj)
{
    float value;

    printf(msj);
    scanf("%f", &value);

    return value;
}

void GetString(char *msj, char value[])
{
    printf(msj);
    fflush(stdin);
    scanf("%[^\n]", value);
}

char GetChar(char *msj)
{
    char value;

    printf(msj);
    fflush(stdin);
    scanf("%c", &value);

    return value;
}

int get_Stringnumber(char* message, char* value,char* messageError)
{
	int exito=0;

	printf(message);
	fflush(stdin);
	scanf("%[^\n]",value);


	if(isNaN(value)==1)
	{
		while(isNaN(value)==1)
		{
			printf("%s",messageError);
			scanf("%s",value);
		}
		exito=1;
	}else
	{
		exito=1;
	}

	return exito;
}

int get_StringLetters(char* message, char* value,char* messageError)
{
	int exito=0;

	printf(message);
	fflush(stdin);
	scanf("%[^\n]",value);


	if(isNaN(value)==0)
	{
		while(isNaN(value)!=1)
		{
			printf("%s", messageError);
			scanf("%s",value);
		}
		exito=1;
	}else
	{
		exito=1;
	}

	return exito;
}

int isNaN(char* value)
{
	int i=0;
	int sw=0;
	int len= strlen(value);

	while(i<len && sw==0)
	{
		if(isdigit(value[i])!=0)
		{
			i++;
		}else
		{
			sw=1;
		}
	}

	return sw;
}


