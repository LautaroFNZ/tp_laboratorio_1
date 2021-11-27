/*
 ============================================================================
 Name        : TP2-.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "empleados.h"
#define T 5 //Este numero es solo de referencia, sabemos que T<1000!


int main(void) {
	setbuf(stdout, NULL);


	eEmpleados ListaEmpleados[T];
	char opcionStr [50];
	int opcion;
	int contadorEmpleados;
	float totalsueldo;
	float promedio;
	int sueldoalto;

	contadorEmpleados=0;

	InicializarEmpleados(ListaEmpleados,T);



	do{

		printf("BIENVENIDO!");
		printf("\n1. ALTA:");
		printf("\n2. MODIFICAR:");
		printf("\n3. BAJA:");
		printf("\n4. MOSTRAR LISTA DE EMPLEADOS: ");
		printf("\n5. TOTAL Y PROMEDIO DE SALARIOS:");
		printf("\n6. SALIR\n");

		int retorno=get_Stringnumber("Ingrese una opcion:", opcionStr, "ERROR:Reingrese una opcion válida:");
		if(retorno==1)
		{
			opcion = atoi(opcionStr);
		}


		switch(opcion)
		{
			case 1:
				InsertarEmpleado(ListaEmpleados,T);
				contadorEmpleados+=1;
			break;
			case 2:
				if(contadorEmpleados==0)
				{
					printf("Primero debe dar de alta un empleado.");

				}else
				{
					OrdenPorId(ListaEmpleados,T);
					MostrarTodosLosEmpleados(ListaEmpleados,T);
					ModificarEmpleado(ListaEmpleados,T);

				}

			break;
			case 3:
				if(contadorEmpleados==0)
				{
					printf("Primero debe dar de alta un empleado.");

				}else
				{
					OrdenPorId(ListaEmpleados,T);
					MostrarTodosLosEmpleados(ListaEmpleados,T);
					EliminarEmpleado(ListaEmpleados,T);
					contadorEmpleados-=1;

				}


			break;
			case 4:
				if(contadorEmpleados==0)
				{
					printf("Primero debe dar de alta un empleado.");

				}else
				{
					Ordenamiento(ListaEmpleados,T);
					MostrarTodosLosEmpleados(ListaEmpleados,T);

				}


				break;
			break;
			case 5:
				if(contadorEmpleados==0)
				{
					printf("Primero debe dar de alta un empleado.");

				}else
				{
					totalsueldo=TotalSueldos(ListaEmpleados,T);
					printf("El total es $%.2f\n",totalsueldo);
					promedio=ObtenerPromedio(totalsueldo,contadorEmpleados);
					printf("El promedio es $%.2f\n", promedio);
					sueldoalto=EmpleadosGranSalario(ListaEmpleados,T,promedio);
					if(sueldoalto==0)
					{
						printf("Nadie supera el sueldo promedio.");
					}
					else
					{
						printf("La cantidad de empleados que superan el sueldo promedio es: %d\n", sueldoalto);
					}

				}

			break;
			case 6:
				printf("Ha salido con exito!");
			break;

			default:
				printf("Error.Ingrese una opcion valida.");
			break;

		}



	}while(opcion!=6);




	return EXIT_SUCCESS;
}
