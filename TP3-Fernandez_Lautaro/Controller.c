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
	char nombre[128];
	Employee* empleado;

	idnueva=atoi(newId);
	idnueva+=1;
	sprintf(id,"%d",idnueva);
	printf("Su id asignada fue: %s\n", id);
	//GetString("Ingrese el nombre: ", nombre);
	get_StringLetters("Ingrese el nombre:", nombre, "ERROR.Reingrese el nombre:");
	//GetString("Ingrese las horas trabajadas: ", horas);
	get_Stringnumber("Ingerse las horas trabajadas:", horas, "ERROR.Reingrese las horas trabajadas:");
	//GetString("Ingrese el sueldo: ", sueldo);
	get_Stringnumber("Ingrese el sueldo:", sueldo, "ERROR.Reingrese el sueldo:");

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

	char nombreIngresado[128];
	int sueldoIngresado;
	int horasIngresadas;
	char idIngresadaStr[50];
    int idIngresada;
    char optionStr[50];
    int option;
    int len;

    char sueldoStr[50];
    char horasStr[50];
    Employee* empleadoRecibido;

    controller_ListEmployee(pArrayListEmployee);

    len= ll_len(pArrayListEmployee);

	//idIngresada=GetInt("Ingrese el id a editar: ");
    if((get_Stringnumber("Ingrese el id a editar:", idIngresadaStr, "ERROR.Ingrese una id valida:"))==1)
    {
    	idIngresada = atoi(idIngresadaStr);
    }

	while(idIngresada<0 || idIngresada>len)
	{
		if((get_Stringnumber("Ingrese el id a editar:", idIngresadaStr, "ERROR.Ingrese una id valida:"))==1)
		{
			idIngresada = atoi(idIngresadaStr);
		}

	}

	if(pArrayListEmployee!=NULL)
	{
		empleadoRecibido=ll_get(pArrayListEmployee, idIngresada);
		printf("1. Editar nombre: \n");
		printf("2. Editar sueldo: \n");
		printf("3. Editar horas trabajadas: \n");
		printf("4. Editar todos los elementos: \n");
		//option=GetInt("Ingrese una opcion: ");
		if((get_Stringnumber("Ingrese una opcion:", optionStr, "ERROR.Reingrese un numero valido:"))==1)
		{
			option = atoi(optionStr);
		}

		switch(option)
		{
			case 1:
				//GetString("Ingrese el nuevo nombre: ",nombreIngresado);
				get_StringLetters("Ingrese el nuevo nombre:", nombreIngresado, "ERROR.Reingrese el nombre:");
				employee_setNombre(empleadoRecibido, nombreIngresado);
				printf("Nombre actualizado!\n");
				break;
			case 2:
				//sueldoIngresado=GetInt("Ingresar el nuevo sueldo:");
				if((get_Stringnumber("Ingresar el nuevo sueldo:", sueldoStr, "ERROR.Reingrese el sueldo:"))==1)
				{
					sueldoIngresado = atoi(sueldoStr);
					employee_setSueldo(empleadoRecibido, sueldoIngresado);
					printf("Sueldo actualizado!\n");
				}

				break;
			case 3:
				//horasIngresadas=GetInt("Ingrese la nueva cantidad de horas: ");
				if((get_Stringnumber("Ingrese la nueva cantidad de horas:", horasStr, "ERROR.Reingrese las horas:"))==1)
				{
					horasIngresadas=atoi(horasStr);
					employee_setHorasTrabajadas(empleadoRecibido, horasIngresadas);
					printf("Horas actualizadas!\n");
				}

				break;
			case 4:
				get_StringLetters("Ingrese el nuevo nombre:", nombreIngresado, "ERROR.Reingrese el nombre:");
				employee_setNombre(empleadoRecibido, nombreIngresado);

				if((get_Stringnumber("Ingresar el nuevo sueldo:", sueldoStr, "ERROR.Reingrese el sueldo:"))==1)
				{
					sueldoIngresado = atoi(sueldoStr);
					employee_setSueldo(empleadoRecibido, sueldoIngresado);

				}

				if((get_Stringnumber("Ingrese la nueva cantidad de horas:", horasStr, "ERROR.Reingrese las horas:"))==1)
				{
					horasIngresadas=atoi(horasStr);
					employee_setHorasTrabajadas(empleadoRecibido, horasIngresadas);

				}
				printf("Datos editados con exito!");
				break;
			default:

				printf("OPCION NO VALIDA!\n");

			break;
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
    char idIngresadaStr[50];
    int idIngresada;
    char respuestaStr[50];
    int respuesta;


    controller_ListEmployee(pArrayListEmployee);

    len=ll_len(pArrayListEmployee);

    if((get_Stringnumber("Ingrese el id a eliminar:", idIngresadaStr, "ERROR.Ingrese una id valida:"))==1)
	{
		idIngresada = atoi(idIngresadaStr);
	}

	while(idIngresada<0 || idIngresada>len)
	{
		if((get_Stringnumber("Ingrese el id a eliminar:", idIngresadaStr, "ERROR.Ingrese una id valida:"))==1)
		{
			idIngresada = atoi(idIngresadaStr);
		}

	}

    if(pArrayListEmployee!=NULL)
    {
    	//respuesta=GetInt("Ingrese 1 para confimar la eliminacion (con cualquier otro numero se cancela):");
    	if((get_Stringnumber("Ingrese 1 para confimar la eliminacion (con cualquier otro numero se cancela):", respuestaStr, "ERROR.Reingrese 1 para confimar la eliminacion (con cualquier otro numero se cancela):"))==1)
		{
    		respuesta=atoi(respuestaStr);
		}



    	if(respuesta==1)
    	{

			ll_remove(pArrayListEmployee,idIngresada);
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
	int len;
	int i;
	Employee* empleados;


	if(pArrayListEmployee!=NULL)
	{

	len= ll_len(pArrayListEmployee);


		for(i=1;i<len;i++)
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
	int r=0;

	if(pArrayListEmployee!=NULL)
	{
		 ll_sort(pArrayListEmployee,employee_compareByName,1);
		 r=1;
	}
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

    int id;
    char nombre[128];
    int horas;
    int sueldo;

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
    	archivo = fopen(path,"w");

    	len=ll_len(pArrayListEmployee);

    	for(i=0;i<len;i++)
    	{
    		auxEmpleado = ll_get(pArrayListEmployee, i);

    		employee_getId(auxEmpleado, &id);
    		employee_getNombre(auxEmpleado, nombre);
    		employee_getHorasTrabajadas(auxEmpleado, &horas);
    		employee_getSueldo(auxEmpleado, &sueldo);


    		fprintf(archivo,"%d,%s,%d,%d\n", id,nombre,horas,sueldo);
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
    FILE* archivo;
    Employee* empleado;
    int len;

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
    	archivo=fopen(path,"wb");
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

