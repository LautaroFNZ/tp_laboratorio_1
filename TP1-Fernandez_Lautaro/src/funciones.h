/*
 * funciones.h
 *
 *  Created on: 14 sep. 2021
 *      Author: Lauty
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int flag(int flag1,int flag2);
int menu(int op1,int op2,int flag,int flag2);
int Operando(int* operando);
int sumar(int op1,int op2,int* resultado);
int restar(int op1,int op2,int* resultado);
int dividir(int op1,int op2,float* resultado);
int multiplicar(int op1,int op2,int* resultado);
int Factorial(float numero,float* resultado);


#endif /* FUNCIONES_H_ */
