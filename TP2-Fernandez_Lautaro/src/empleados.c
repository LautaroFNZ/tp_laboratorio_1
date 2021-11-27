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
	char sueldo[50];
	char sector[50];

	empleado.id=ObtenerId();
	printf("Generando id automatica...\n");
	//GetString("Ingrese el nombre: ", empleado.nombre);
	get_StringLetters("Ingrese el nombre: ", empleado.nombre, "ERROR. Reingrese el nombre:");
	//GetString("Ingrese el apellido: ", empleado.apellido);
	get_StringLetters("Ingrese el apellido:", empleado.apellido, "ERROR. Reingrese el apellido:");
	//empleado.sueldo=GetFloat("Ingrese el sueldo: ");
	int retorno1= get_Stringnumber("Ingrese el sueldo:", sueldo, "ERROR. Reingrese el sueldo:");

	if(retorno1==1)
	{
		empleado.sueldo=atof(sueldo);

	}
	//empleado.sector=GetInt("Ingrese el numero de sector: ");
	int retorno2= get_Stringnumber("Ingrese el numero de sector:", sector, "ERROR. Reingrese el numero del sector:");
	if(retorno2==1)
	{
		empleado.sector=atof(sector);
	}
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
	printf("Id: %d|Apellido y Nombre: %s,%s|Sueldo: %.2f|Sector: %d.\n", empleado.id,
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
	char menuStr[50];
	char salarioStr[50];
	int retornoSS;
	char sectorStr[50];
	int retornoS;

	printf("1. Editar nombre\n");
	printf("2. Editar apellido\n");
	printf("3. Editar Sueldo\n");
	printf("4. Editar Sector\n");
	printf("5. Cancelar");
	int retorno = get_Stringnumber("\nElija una opcion:", menuStr, "ERROR.Reingrese una opcion valida:");
	if(retorno==1)
	{
		menu = atoi(menuStr);
	}

	switch(menu)
	{
	case 1:
		get_StringLetters("Ingrese nuevo nombre:", empleados[index].nombre, "ERROR.Reingrese el nombre:");
		printf("Nombre actualizado!\n");
		break;
	case 2:
		//GetString("Ingrese nuevo apellido: ", empleados[index].apellido);
		get_StringLetters("Ingrese nuevo apellido:", empleados[index].apellido, "ERROR.Reingrese el apellido:");
		printf("Apellido actualizado!\n");
		break;
	case 3:
		//empleados[index].sueldo=GetFloat("Ingrese nuevo salario: ");
		retornoSS=get_Stringnumber("Ingrese nuevo salario:", salarioStr, "ERROR.Reingrese nuevo salario:");
		if(retornoSS==1)
		{
			empleados[index].sueldo = atof(salarioStr);
			printf("Salario actualizado!\n");
		}
		break;
	case 4:
		//empleados[index].sector=GetInt("Ingrese nuevo sector: ");
		retornoS=get_Stringnumber("Ingrese nuevo sector:", sectorStr, "ERROR.Reingrese nuevo sector:");
		if(retornoS==1)
		{
			empleados[index].sector = atoi(sectorStr);
			printf("Sector actualizado!\n");
		}
		break;
	case 5:
		printf("Ha cancelado la operacion.\n");
		break;
	default:
		printf("ERROR.Vuelva a seleccionar modificar\n");
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
