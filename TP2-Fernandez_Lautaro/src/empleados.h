/*
 * empleados.h
 *
 *  Created on: 12 oct. 2021
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
/**
 * @fn int ObtenerId()
 * @brief esta funcion le suma 1 a la variable local que esta en empleados.c cada vez que se la solicita.
 *
 * @return un nuevo numero cada vez que se la llama, generando un Id diferente para cada alta que se realice.
 */
int ObtenerId();
/**
 * @fn void InicializarEmpleados(eEmpleados[], int)
 * @brief esta funcion inicializa a un array de tipo eEmpleados en EMPTY (0) dentro de su variable isEmpty.
 *
 * @param eEmpleados recibe un array de este tipo de dato
 * @param  recibe un entero, que representa el tamaño del array previamente mencionado
 */
void InicializarEmpleados(eEmpleados[],int);
/**
 * @fn int BuscarLibre(eEmpleados[], int)
 * @brief esta funcion se encarga de buscar en un array de tipo eEmpleados, alguna posicion de el donde la variable isEmtpy sea EMPTY, es decir 0.
 * Va acompañada de la funcion inicializaempleados previamente descripta.
 *
 * @param el array de tipo eEmpleados
 * @param el tamaño del array previamente mencionado
 * @return la posicion del array donde se encontro el espacio "libre"
 */
int BuscarLibre(eEmpleados[],int);
/**
 * @fn eEmpleados CargarEmpleado()
 * @brief esta funcion permite la carga de las variables de tipo eEmpleados y las almacena en una variable de tipo eEmpleados, que luego sera retornada. Tambien permite la creacion del Id.
 *
 * @return la variable con los datos cargados.
 */
eEmpleados CargarEmpleado();
/**
 * @fn int InsertarEmpleado(eEmpleados[], int)
 * @brief esta funcion permite cargar los datos a una posicion del array especifica que es la que previamente nos brinda el buscarLibre.
 *
 * @param recibe el array de eEmpleados para hacer funcionar la funcion BuscarLibre
 * @param recibe un enter que representa el tamaño del array previamente mencionado
 * @return retorna 0
 */
int InsertarEmpleado(eEmpleados[], int);
/**
 * @fn void MostrarUnEmpleado(eEmpleados)
 * @brief esta funcion se encarga de mostrar las variables de la estructura eEmpleados
 *
 * @param recibe la estructura de la cual mostrara sus variables
 */
void MostrarUnEmpleado(eEmpleados);
/**
 * @fn void MostrarTodosLosEmpleados(eEmpleados[], int)
 * @brief  esta funcion permite llamar a MostrarUnEmpleado para mostrar el array de eEmpleados solicitado
 *
 * @param recibe la estructura en forma de array
 * @param recibe un entero representando el temaño del array
 */
void MostrarTodosLosEmpleados(eEmpleados[], int);
/**
 * @fn int BuscarEmpleado(eEmpleados[], int)
 * @brief esta funcion permite ingresar un numero y buscarlo entre las iD(variable) de un array de tipo eEmpleados
 *
 * @param array de tipo eEmpleados
 * @param entero que representa el tamaño del array
 * @return retorna un numero distinto a -1  en caso de coincidencia que representa la posicion del array, o -1 si no se encuentra el numero ingresado
 */
int BuscarEmpleado(eEmpleados[],int);
/**
 * @fn void EliminarEmpleado(eEmpleados[], int)
 * @brief esta funcion permite a traves de BuscarEmpleado, dejar en EMPTY la casilla del id que recibe para luego sobrecargar sus datos en esa posicion del array al ingresar la opcion ALTA
 *
 * @param array de tipo eEmpleados
 * @param entero que representa el tamaño del array
 */
void EliminarEmpleado(eEmpleados[],int);
/**
 * @fn void ModificarEmpleado(eEmpleados[], int)
 * @brief permite modificar los datos de una posicion de array especifica mediante un menu para que el usuario elija
 *
 * @param array de tipo eEmpleados
 * @param entero que representa el tamaño del array
 */
void ModificarEmpleado(eEmpleados[],int);
/**
 * @fn void EditarEmpleado(eEmpleados[], int)
 * @brief llama a la funcion modificarEmpleado y hace que esta se efectua en la posicion que devuelve la funcion BUSCARLIBRE, si es que esta lo hace
 *
 * @param array de tipo eEmpleados
 * @param entero que representa el tamaño del array
 */
void EditarEmpleado(eEmpleados[],int);
/**
 * @fn void OrdenarPorApellido(eEmpleados[], int, int)
 * @brief esta funcion permite ordenar alfabeticamende de la A a la Z los nombres del array eEmpleados
 *
 * @param array de tipo eEmpleados
 * @param entero que representa el tamaño del array
 * @param entero que representa una posicion del array
 */
void OrdenarPorApellido(eEmpleados[],int,int);
/**
 * @fn void OrdenarPorSector(eEmpleados[], int, int)
 * @brief esta variable ordena por sector de menor a mayor, y en caso de coindicencia de sectores, llama a ordenaralfabeticamente
 *
 * @param array de tipo eEmpleados
 * @param entero que representa el tamaño del array
 * @param entero que representa una posicion del array
 */
void OrdenarPorSector(eEmpleados[],int,int);
/**
 * @fn float TotalSueldos(eEmpleados[], int)
 * @brief permite sumar los sueldos de los empleados cuya variable isEmpty este en OCUPADO
 *
 * @param array de tipo eEmpleados
 * @param entero que representa el tamaño del array
 * @return la suma anteriormente mencionada
 */
float TotalSueldos(eEmpleados[],int);
/**
 * @fn float ObtenerPromedio(float, int)
 * @brief 	esta funcion calcula el promedio de sueldos.
 *
 * @param recibe un flotante que representa el total de los sueldos obtenidos a traves de la funcion TotalSueldos
 * @param recibe un entero que representa la cantidad de Empleados para
 * @return retorna el promedio de Sueldos/cantidad de empleados.
 */
float ObtenerPromedio(float,int);
/**
 * @fn int EmpleadosGranSalario(eEmpleados[], int, float)
 * @brief calcula la cantidad de personas que sueldo es igual o mayor al promedio
 *
 * @param array de tipo eEmpleados
 * @param entero que representa el tamaño del array
 * @param recibe el salario promedio
 * @return la cantidad de personas que su salario esta por mayor del promedio
 */
int EmpleadosGranSalario(eEmpleados[],int,float);
/**
 * @fn void Ordenamiento(eEmpleados[], int)
 * @brief esta funcion engloba las de OrdenarAlfabeticamente y ordenar por sector para llamarla directamente en el main
 *
 * @param array de tipo eEmpleados
 * @param entero que representa el tamaño del array
 */
void Ordenamiento(eEmpleados[],int);
/**
 * @fn void OrdenPorId(eEmpleados[], int)
 * @brief esta funcion llama a OrdenarPorId para que se ordene de menor a mayor los ID de las personas. Se utiliza para que sea mas comodo modificar y dar de baja
 *
 * @param array de tipo eEmpleados
 * @param entero que representa el tamaño del array
 */
void OrdenPorId(eEmpleados[],int);
/**
 * @fn void OrdenarPorId(eEmpleados[], int, int)
 * @brief esta funcion permite ordenar de menor a mayor los ID de los empleados
 *
 * @param array de tipo eEmpleados
 * @param entero que representa el tamaño del array
 * @param entero que representa una posicion del array
 */
void OrdenarPorId(eEmpleados[],int,int);

#endif /* EMPLEADOS_H_ */
