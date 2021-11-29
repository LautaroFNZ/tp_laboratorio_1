/*
 * funciones.c
 *
 *  Created on: 14 sep. 2021
 *      Author: Lauty
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

float PedirOperando(float numero)
{
	printf("Ingrese el operando: ");
	scanf("%f", &numero);

	return numero;

}



float Sumar(float numero1, float numero2)
{
	float resultado;

	resultado = numero1 + numero2;

	return resultado;
}

float Restar(float numero1, float numero2)
{

	float resultado;

	resultado = numero1 - numero2;

	return resultado;
}


float Dividir(float numero1, float numero2)
{
	float resultado;

	resultado= numero1/numero2;

	return resultado;


}


float Multiplicar(float numero1, float numero2)
{

	float resultado;

	resultado = numero1 * numero2;

	return resultado;

}


float Factorial(float numero)
{

	int i;
	int factorial;

	factorial=1;

	for(i=numero;i>1;i--)
	{
	    factorial*= i;

	}

	return factorial;

}



