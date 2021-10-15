/*
 ============================================================================
 Name        : TP1-Fernandez_Lautaro.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "funciones.h"

int main(void) {

	setbuf(stdout,NULL);
	int opcion;
	int operando1;
	int operando2;
	int suma;
	int resta;
	float division;
	int divisionR;
	float factorial1;
	float factorial2;
	int flag1=0;
	int flag2=0;

	do{
		system("cls");
		opcion = menu(operando1, operando2,flag1,flag2);

		switch(opcion)
		{
		case 1:
			Operando(&operando1);
			flag1=1;

			break;
		case 2:
			Operando(&operando2);
			flag2=1;

			break;
		case 3:
			if(flag(flag1, flag2)==0)
			{
				printf("\n...Calculando operaciones...\n");
				sumar(operando1, operando2, &suma);
				restar(operando1, operando2, &resta);
				divisionR=dividir(operando1, operando2, &division);
				Factorial(operando1,&factorial1);
				Factorial(operando2,&factorial2);

			}else printf("\nPrimero debes ingresar los operandos\n");

			break;
		case 4:
			if(flag(flag1, flag2)==0)
			{
				printf("\n...Mostrando resultados...\n");

				printf("El resultado de la suma es: %d\n", suma);
				printf("El resultado de la resta es: %d\n", resta);
				if(divisionR!=0)
				{
					printf("El resultado de la division es: %.2f\n", division);
				}else printf("No se puede dividir si alguno de los operandos es 0\n");
				printf("El factorial de %d es: %.2f \n", operando1,factorial1);
				printf("El factorial de %d es: %.2f \n", operando2,factorial2);


			}else printf("\nPrimero debes ingresar los operandos\n");

			break;
		case 5:
					printf("Saliendo del programa!\n");

			break;
		default:
			printf("ERROR. Ingrese una opcion valida!\n");
			break;
		}

	}while(opcion!=5);




	return EXIT_SUCCESS;
}


/*

 	 	 	if(flag(operando1, operando2)==0)
			{

			}else printf("\nPrimero debes ingresar los operandos\n");


 */
