/*
 * funciones.c
 *
 *  Created on: 14 sep. 2021
 *      Author: Lauty
 */

#include "funciones.h"

int flag(int flag1,int flag2)
{
	int retorno=0;

	if(flag1==0 && flag2==0)
	{
		retorno=1;
	}

	if(flag1!=0 && flag2==0)
	{
		retorno=1;
	}

	if(flag1==0 && flag2!=0)
	{
		retorno=1;
	}



	return retorno;
}

int menu(int op1,int op2,int flag,int flag2)
{
	int opcion;

	printf("Bienvenido a la calculadora!.\n\n");

	if(flag==0)
	{
		printf("1. Ingresar 1er operando (A=x) \n");
	}else
	{
		printf("1. Ingresar 1er operando (A= %d) \n",op1 );
	}

	if(flag2==0)
	{
		printf("2. Ingresar 2do operando (B=y) \n");
	}else
	{
		printf("2. Ingresar 2do operando (B= %d) \n",op2 );
	}

	printf("3. Calcular todas las operaciones \n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
	printf("-Ingrese una opcion: ");
	scanf("%d", &opcion);

	return opcion;
}

int Operando(int* operando)
{
	int x;

	printf("Ingrese el valor del operando: ");
	scanf("%d", &x);

	*operando=x;

	return 0;
}

int sumar(int op1,int op2,int* resultado)
{
	int x;
	int retorno=0;

	if(resultado!=NULL)
	{

		x = op1 + op2;

		*resultado=x;

		retorno=1;
	}

	return retorno;
}

int restar(int op1,int op2,int* resultado)
{
	int retorno=0;
	int x;

	if(resultado!=NULL)
	{

		x = op1 - op2;
		*resultado=x;

		retorno=1;

	}



	return retorno;
}

int dividir(int op1,int op2,float* resultado)
{
	int retorno;
	int x;

	if(resultado!=NULL)
	{
		if(op1==0 || op2==0)
		{
			retorno=0;
		}else
		{
		x = op1/op2;
		*resultado=x;
		retorno=1;
		}


	}

	return retorno;
}

int multiplicar(int op1,int op2,int* resultado)
{
	int retorno=0;
	int x;

	if(resultado!=NULL)
	{

		x = op1 * op2;
		*resultado=x;

		retorno=1;

	}



	return retorno;
}

int Factorial(float numero ,float* resultado)
{

	int i;
	int factorial;

	factorial=1;

	for(i=numero;i>1;i--)
	{
	    factorial*= i;

	}

	*resultado =factorial;

	return 0;

}
