#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "inputs.h"


Employee* employee_new()
{
	Employee* empleado;

	empleado= (Employee*) calloc(sizeof(Employee),1);


	return empleado;
}

int employee_setId(Employee* this,int id)
{
	int exito=0;

	if(this!=NULL && id!=0)
	{
		this->id=id;
		exito=1;
	}

	return exito;
}

int employee_getId(Employee* this,int* id)
{

	int exito=0;
	if(this!=NULL && id!=0)
	{
		*id=this->id;
		exito=1;
	}

	return exito;

}


int employee_setNombre(Employee* this,char* nombre)
{
	int exito=0;

	if(this!=NULL && nombre!=NULL)
	{

		strcpy(this->nombre,nombre);
		exito=1;

	}

	return exito;
}

int employee_getNombre(Employee* this,char* nombre)
{

	int exito=0;
	if(this!=NULL && nombre!=NULL)
	{

		strcpy(nombre,this->nombre);
		exito=1;

	}

	return exito;


}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int exito;

	if(this!=NULL && horasTrabajadas!=0)
	{
		this->horasTrabajadas=horasTrabajadas;
		exito=1;
	}


	return exito;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

	int exito=0;
	if(this!=NULL && horasTrabajadas>0)
	{
		*horasTrabajadas=this->horasTrabajadas;

		exito=1;
	}


	return exito;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int exito;

	if(this!=NULL && sueldo!=0)
	{
		this->sueldo=sueldo;
		exito=1;
	}


	return exito;
}

int employee_getSueldo(Employee* this,int* sueldo)
{

	int exito=0;
	if(this!=NULL && sueldo>0)
	{

		*sueldo=this->sueldo;
		exito=1;
	}


	return exito;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* empleado=employee_new();

	if(empleado!=NULL)
	{
		employee_setId(empleado,atoi(idStr));
		employee_setHorasTrabajadas(empleado,atoi(horasTrabajadasStr));
		employee_setSueldo(empleado,atoi(sueldoStr));
		employee_setNombre(empleado,nombreStr);
	}

	return empleado;
}

int employee_compareByName(Employee *employee1, Employee *employee2)
{
	int index;

	index= strcmp(employee1->nombre,employee2->nombre);

	return index;
}



int employee_showHeader()
{
	char id[50]="ID";
	char nombre[50]="NOMBRE";
	char horas[50]="HORAS TRABAJADAS";
	char sueldo[50]="SUELDO";


	printf("%4s %7s %7s %4s\n", id,nombre,horas,sueldo);

	return 1;
}
