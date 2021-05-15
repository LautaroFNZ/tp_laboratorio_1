/*
 * empleados.h
 *
 *  Created on: 7 may. 2021
 *      Author: Lautaro
 */

#ifndef EMPLEADOS_H_
#define EMPLEADOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#define OCUPADO 1
#define EMPTY 0

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float sueldo;
	int sector;
	int isEmpty;

}eEmpleados;

int ObtenerId();
void InicializarEmpleados(eEmpleados[],int);
int BuscarLibre(eEmpleados[],int);
eEmpleados CargarEmpleado(eEmpleados[],int);
int InsertarEmpleado(eEmpleados[], int);
void MostrarUnEmpleado(eEmpleados);
void MostrarTodosLosEmpleados(eEmpleados[], int);
int BuscarEmpleado(eEmpleados[],int);
void EliminarEmpleado(eEmpleados[],int);
void ModificarEmpleado(eEmpleados[],int);
void EditarEmpleado(eEmpleados[],int);
void OrdenarPorApellido(eEmpleados[],int,int);
void OrdenarPorSector(eEmpleados[],int,int);
float TotalSueldos(eEmpleados[],int);
float ObtenerPromedio(float,int);
int EmpleadosGranSalario(eEmpleados[],int,float);
void Ordenamiento(eEmpleados[],int);


#endif /* EMPLEADOS_H_ */
