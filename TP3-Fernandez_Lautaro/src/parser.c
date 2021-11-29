#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	char id[50];
	char nombre[50];
	char sueldo[50];
	char horas[50];
	int r;
	Employee* empleado;


	if(pFile==NULL)
	{
		printf("Error al leer el archivo");
	}else
	{
		do{


			r =	fscanf(pFile,"%[^,], %[^,], %[^,], %[^\n]\n",id,nombre,sueldo,horas);

			if(r==4)
			{
				//printf("%s--%s--%s--%s\n",id,nombre,horas,sueldo);
				empleado=employee_newParametros(id,nombre,sueldo,horas);
				ll_add(pArrayListEmployee,empleado);
			}else
			{
				break;
			}

		}while(!feof(pFile));

	}

	controller_createLastId("createId.txt", id);

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee *empleado;
	int r;
	int id;
	char idS[50];

	if(pFile==NULL)
	{
		printf("Error al leer el archivo");
	}else
	{

			do{
				empleado=employee_new();
				r= fread(empleado, sizeof(Employee), 1, pFile);

				if(r==1)
				{

					employee_getId(empleado,&id);
					sprintf(idS,"%d",id);
					controller_createLastId("createId.txt", idS);
					ll_add(pArrayListEmployee,empleado);
				}


			}while(!feof(pFile));

	}



    return 1;
}
