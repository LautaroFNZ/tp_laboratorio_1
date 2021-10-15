/*
 * empleados.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Lautaro
 */

#include "empleados.h"


int IdIncremental=0;

int ObtenerId()
{
	return IdIncremental+=1;
}

void InicializarEmpleados(eEmpleados empleado[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		empleado[i].isEmpty=EMPTY;

	}


}

int BuscarLibre(eEmpleados empleados[],int tam)
{
	int i;
	int index;

	index=-1;

	for(i=0;i<tam;i++)
	{
		if(empleados[i].isEmpty==EMPTY)
		{
			index=i;
			break;
		}

	}

	return index;
}

eEmpleados CargarEmpleado()
{
	eEmpleados empleado;

	empleado.id=ObtenerId();
	printf("Generando id automatica...\n1");
	GetString("Ingrese el nombre: ", empleado.nombre);
	GetString("Ingrese el apellido: ", empleado.apellido);
	empleado.sueldo=GetFloat("Ingrese el sueldo: ");
	empleado.sector=GetInt("Ingrese el numero de sector: ");
	empleado.isEmpty=OCUPADO;

	return empleado;
}

int InsertarEmpleado(eEmpleados empleados[], int tam)
{
	int index;

	index=BuscarLibre(empleados,tam);

	if(index==-1)
	{
		printf("No hay espacio disponible.");
	}else
	{

		empleados[index]=CargarEmpleado(empleados,tam);
	}



	return 0;
}

void MostrarUnEmpleado(eEmpleados empleado)
{
	printf("Id Asignado: %d--Apellido y Nombre: %s,%s--Sueldo: %.2f--Sector: %d.\n", empleado.id,
																				 empleado.apellido,
																				 empleado.nombre,
																				 empleado.sueldo,
																				 empleado.sector);
}

void MostrarTodosLosEmpleados(eEmpleados empleado[], int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		if(empleado[i].isEmpty!=EMPTY)
		{
			MostrarUnEmpleado(empleado[i]);
		}


	}

}

int BuscarEmpleado(eEmpleados empleados[],int tEmpleados)
{
	int i;
	int index;
	int idIngresado;

	index=-1;

	idIngresado=GetInt("Ingrese el id: ");

	for(i=0;i<tEmpleados;i++)
	{
		if(empleados[i].id==idIngresado&&empleados[i].id!=EMPTY)
		{
			index=i;
		}

	}


	return index;
}

void EliminarEmpleado(eEmpleados empleados[],int tam)
{
	int index;

	index=BuscarEmpleado(empleados,tam);

	if(index==-1)
	{
		printf("No se encontro el id ingresado.");

	}else
	{
		empleados[index].isEmpty=EMPTY;
		printf("Datos eliminados con exito!");
	}

}

void ModificarEmpleado(eEmpleados empleados[],int tam)
{
	int index;

	index=BuscarEmpleado(empleados,tam);

	if(index==-1)
	{
		printf("No se encontro el id ingresado.");
	}else
	{
		EditarEmpleado(empleados,index);
	}


}

void EditarEmpleado(eEmpleados empleados[],int index)
{
	int menu;

	printf("\n1.Editar nombre: ");
	printf("2.Editar apellido: ");
	printf("3. Editar Sueldo: ");
	printf("4. Editar Sector: ");
	printf("5. Cancelar");
	menu=GetInt("Elija una opcion: ");

	switch(menu)
	{
	case 1:
		GetString("Ingrese nuevo nombre: ", empleados[index].nombre);
		break;
	case 2:
		GetString("Ingrese nuevo apellido: ", empleados[index].apellido);
		break;
	case 3:
		empleados[index].sueldo=GetFloat("Ingrese nuevo salario: ");
		break;
	case 4:
		empleados[index].sector=GetInt("Ingrese nuevo sector: ");
		break;
	case 5:
		printf("Ha cancelado la operacion. ");
		break;
	default:
		printf("Ingrese una opcion valida.");
	 break;

	}

}

void OrdenarPorApellido(eEmpleados empleados[],int tam,int index)
{
	int k;
	eEmpleados aux;


	for(k=index+1;k<tam;k++)
	{
		if(strcmp(empleados[index].apellido,empleados[k].apellido)>0)
		{
			aux = empleados[index];
			empleados[index]=empleados[k];
			empleados[k]=aux;

		}

	}

}

void OrdenarPorSector(eEmpleados empleados[],int tam, int index)
{

	int j;
	eEmpleados aux;

		for(j=index+1;j<tam;j++)
		{
			if(empleados[index].sector>empleados[j].sector)
			{
				aux = empleados[index];
				empleados[index]=empleados[j];
				empleados[j]=aux;

			}else
			{
				OrdenarPorApellido(empleados,tam,index);
			}

		}





}

float TotalSueldos(eEmpleados empleados[],int tam)
{
	int i;
	float total;
	total=0;

	for(i=0;i<tam;i++)
	{
		if(empleados[i].isEmpty!=EMPTY)
		{
			total+=empleados[i].sueldo;
		}


	}

	return total;
}

float ObtenerPromedio(float sueldos,int empleados)
{
	float promedio;
	promedio=0;

	promedio=sueldos/empleados;


	return promedio;
}

int EmpleadosGranSalario(eEmpleados empleados[],int tam ,float promedio)
{
	int contador;
	int i;

	contador=0;

	for(i=0;i<tam;i++)
	{
		if(empleados[i].isEmpty!=EMPTY)
		{
			if(empleados[i].sueldo>promedio)
			{
				contador++;
			}
		}

	}

	return contador;
}

void Ordenamiento(eEmpleados empleados[],int tam)
{
	int i;

	for(i=0;i<tam;i++)
	{
		OrdenarPorSector(empleados,tam,i);

	}


}

void OrdenPorId(eEmpleados empleados[],int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		OrdenarPorId(empleados,tam,i);

	}

}

void OrdenarPorId(eEmpleados  empleados[],int tam,int index)
{
	int j;
	eEmpleados aux;

	for(j=0;j<tam;j++)
	{
		if(empleados[index].id<empleados[j].id)
		{
			aux = empleados[index];
			empleados[index]=empleados[j];
			empleados[j]=aux;

		}

	}


}
