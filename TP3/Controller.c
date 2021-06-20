#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "controller.h"
#include "Employee.h"
#include "parser.h"
#include "inputs.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int exito=0;
    FILE* archivo= fopen(path,"r");

    if(archivo!=NULL)
    {
    	parser_EmployeeFromText(archivo,pArrayListEmployee);
    	printf("\n...Datos cargados con exito!... \n");
    	exito=1;
    	fclose(archivo);
    }else
	{
		printf("Error al abrir el archivo.");
	}

	return exito;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int exito=0;
	FILE* archivo= fopen(path,"r+b");

	if(archivo!=NULL)
	{
		parser_EmployeeFromBinary(archivo,pArrayListEmployee);
		printf("\n...Datos cargados con exito!... \n");
		exito=1;


	}else
	{
		printf("Error al abrir el archivo.\n");
	}
	fclose(archivo);

	return exito;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, char *newId)
{
	int idnueva;
	char id[50];
	char horas[50];
	char sueldo[50];
	char nombre[50];
	Employee* empleado;

	idnueva=atoi(newId);
	idnueva+=1;
	sprintf(id,"%d",idnueva);
	printf("Su id asignada fue: %s\n", id);
	GetString("Ingrese el nombre: ", nombre);
	GetString("Ingrese las horas trabajadas: ", horas);
	GetString("Ingrese el sueldo: ", sueldo);

	empleado=employee_newParametros(id,nombre,horas,sueldo);

	ll_add(pArrayListEmployee,empleado);

	return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

	char nombreIngresado[50];
	int sueldoIngresado;
	int horasIngresadas;
    int idIngresada;
    int option;
    int len;
    Employee* empleadoRecibido;

    controller_ListEmployee(pArrayListEmployee);

    len= ll_len(pArrayListEmployee);

	idIngresada=GetInt("Ingrese el id a editar: ");
	while(idIngresada<0 || idIngresada>len)
	{
		idIngresada=GetInt("ERROR. Ingrese el id a editar: ");
	}

	if(pArrayListEmployee!=NULL)
	{
		empleadoRecibido=ll_get(pArrayListEmployee, idIngresada);
		printf("1. Editar nombre: \n");
		printf("2. Editar sueldo: \n");
		printf("3. Editar horas trabajadas: \n");
		printf("4. Editar todos los elementos: \n");
		option=GetInt("Ingrese una opcion: ");

		switch(option)
		{
			case 1:
				GetString("Ingrese el nuevo nombre: ",nombreIngresado);
				employee_setNombre(empleadoRecibido, nombreIngresado);
				break;
			case 2:
				sueldoIngresado=GetInt("Ingresar el nuevo sueldo:");
				employee_setSueldo(empleadoRecibido, sueldoIngresado);
				break;
			case 3:
				horasIngresadas=GetInt("Ingrese la nueva cantidad de horas: ");
				employee_setHorasTrabajadas(empleadoRecibido, horasIngresadas);
				break;
			case 4:
				GetString("Ingrese el nuevo nombre: ",nombreIngresado);
				employee_setNombre(empleadoRecibido, nombreIngresado);

				sueldoIngresado=GetInt("Ingresar el nuevo sueldo:");
				employee_setSueldo(empleadoRecibido, sueldoIngresado);

				horasIngresadas=GetInt("Ingrese la nueva cantidad de horas: ");
				employee_setHorasTrabajadas(empleadoRecibido, horasIngresadas);

				break;

			printf("Datos editados con exito!");
		}



	}


	return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int len;
    int id;
    int respuesta;
    Employee* empleados;

    controller_ListEmployee(pArrayListEmployee);

    len=ll_len(pArrayListEmployee);

    id=GetInt("Ingrese el id del empleado: ");
    while(id<0 || id>len)
    {
    	id=GetInt("ERROR.Ingrese el id del empleado: ");
    }

    if(pArrayListEmployee!=NULL)
    {
    	respuesta=GetInt("Ingrese 1 para procedeer a la eliminacion: ");

    	if(respuesta==1)
    	{
    		empleados = ll_get(pArrayListEmployee,id);
			free(empleados);
			ll_remove(pArrayListEmployee,id);
			printf("Se ha elminado con exito\n");

    	}else
    	{
    		printf("La eliminacion se ha cancelado con exito!");
    	}



    }else
    {
    	printf("No se ha encontrado el archivo");
    }


	return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int id;
	char nombre[50];
	int horas;
	int sueldo;
	int cantidad;
	int i;
	Employee* empleados;


	if(pArrayListEmployee!=NULL)
	{

	cantidad= ll_len(pArrayListEmployee);

		//employee_showHeader(pArrayListEmployee);

		for(i=1;i<cantidad;i++)
		{
			empleados= (Employee*) ll_get(pArrayListEmployee,i);


			employee_getId(empleados,&id);
			employee_getNombre(empleados,nombre);
			employee_getHorasTrabajadas(empleados,&horas);
			employee_getSueldo(empleados,&sueldo);

			printf("%4d  %7s %7d %4d\n",id, nombre, horas, sueldo);

		}

	}

	return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int r;
	r = ll_sort(pArrayListEmployee,employee_compareByName,1);
	return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int i;
	int len;
    Employee* auxEmpleado;
    FILE* archivo;


    len=ll_len(pArrayListEmployee);


    archivo = fopen(path,"w");

    if(archivo!=NULL)
    {

    	for(i=0;i<len;i++)
    	{
    		auxEmpleado = ll_get(pArrayListEmployee, i);
    		fprintf(archivo,"%d,%s,%d,%d\n", auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
    	}

    	printf("Se han guardado los datos con exito!\n");
    	fclose(archivo);
    }



	return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int i;
    FILE* archivo= fopen(path,"wb");
    Employee* empleado;
    int len;

    if(pArrayListEmployee!=NULL)
    {
    	len= ll_len(pArrayListEmployee);

    	if(archivo!=NULL)
    	{
    		for(i=0;i<len;i++)
    		{
    			empleado= (Employee*) ll_get(pArrayListEmployee, i);
    			fwrite(empleado,sizeof(Employee), 1, archivo);

    		}
    		printf("Se han guardado los datos con exito!\n");
    		fclose(archivo);
    	}


    }


	return 1;
}

int controller_createLastId(char* path, char *lastId)
{
	FILE* archivo= fopen(path,"w");
	int exito=0;

	if(archivo!=NULL)
	{
		fprintf(archivo,lastId);
		fclose(archivo);
		exito=1;
	}else
	{
		printf("ERROR\n");
	}


	return exito;
}

int controller_getLastId(char* path, char *lastId)
{
	int exito=0;
	FILE* archivo= fopen(path,"r");

	if(archivo!=NULL)
	{
		fscanf(archivo,"%s", lastId);
		fclose(archivo);
		exito=1;

	}else
	{
		printf("ERROR\n");
	}

	return exito;
}

