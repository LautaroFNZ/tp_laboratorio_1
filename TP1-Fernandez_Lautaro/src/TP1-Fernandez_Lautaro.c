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


	int opcion;
	float operando1;
	float operando2;
	float suma;
	float resta;
	float division;
	float multiplicacion;
	float factorialA;
	float factorialB;




	printf("*******************Calculadora*******************");
	setbuf(stdout, NULL);
	do{

		if(operando1 == 0 && operando2 == 0)
		{
		printf("\n1. Ingresar 1er operando (A=%.1f)\n",operando1);
		printf("2. Ingresar 2do operando(B=%.1f)\n",operando2);
		}
		printf("3. Calcular todas las operaciones\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n\n");
		printf("Elija una opcion:");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				printf("\n*************************************************\n");
				operando1= PedirOperando(operando1);
				printf("El operando ingresado fue: %.2f", operando1);
				printf("\n*************************************************");
			break;
			case 2:
				printf("\n*************************************************\n");
				operando2= PedirOperando(operando2);
				printf("El operando ingresado fue %.2f", operando2);
				printf("\n*************************************************");

			break;
			case 3:
				if(operando1 == 0 && operando2 == 0)
				{
					printf("\n*************************************************");
					printf("\nIngrese numeros para calcular operaciones.");
				    printf("\nIngrese 1 o 2 para ingresar numeros.");
				    printf("\n*************************************************");
                }else
                {
                printf("\n*************************************************");
                printf("\nCalculando operaciones...");
				printf("\nIngrese 4 para mostrar resultados.");
				printf("\n*************************************************");
				suma= Sumar(operando1, operando2);
				resta= Restar(operando1,operando2);
				division = Dividir(operando1,operando2);
				multiplicacion= Multiplicar(operando1,operando2);
				factorialA= Factorial(operando1);
				factorialB= Factorial(operando2);
                }
			break;
			case 4:
				if(operando1 == 0 && operando2 == 0)
				{
					printf("\n*************************************************");
					printf("\nIngrese numeros para mostrar resultados.");
					printf("\nIngrese 1 o 2 para ingresar numeros.");
					printf("\n*************************************************");

				}
				else
				{
					printf("\n*************************************************");
					printf("\nInformando resultados...");

					printf("\n-La suma es: %.2f", suma);
					printf("\n-La resta es: %.2f", resta);
					if(operando2 == 0)
					{
					printf("\n-No se puede dividir por cero.");

					}else
					{
				     printf("\n-La division es: %f", division);

					}
					printf("\n-La multiplicacion es: %.2f", multiplicacion);
					printf("\n-El factorial del primer operando es: %.2f", factorialA);
					printf("\n-El factorial del segundo operando es: %.2f", factorialB);
					printf("\n*************************************************");
				}

			break;

			case 5:
					printf("\n*************************************************");
					printf("\nGracias por usar mi calculadora. Vuelva pronto!");
					printf("\n*************************************************");
			break;

			default:
				printf("\n*************************************************");
				printf("\nOpcion incorrecta.");
				printf("\n*************************************************");
				break;

		}// fin del switch



	}while(opcion!=5);


	return EXIT_SUCCESS;
}
