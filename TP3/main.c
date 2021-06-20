#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
	setbuf(stdout, NULL);
	int option = 0;
	char newId[20];
	int opcionunica=0;
	int t=0;
	int b=0;
    LinkedList* listaEmpleados = ll_newLinkedList();

   // controller_getLastId("createId.txt", newId);


    do{
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) \n");
		printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) \n");
		printf("3. Alta de empleado \n");
		printf("4. Modificar datos de empleado \n");
		printf("5. Baja de empleado \n");
		printf("6. Listar empleados \n");
		printf("7. Ordenar empleados \n");
		printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto) \n");
		printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario) \n");
		printf("10. Salir \n");
		option=GetInt("Elija una opcion: ");


    	switch(option)
        {
            case 1:
            	if(opcionunica==0)
            	{

            		t=controller_loadFromText("data.csv",listaEmpleados);

            		if(t!=0)
            		{
            			opcionunica++;
            			controller_getLastId("createId.txt", newId);
            		}

            	}else
            	{
            		printf("...Los datos ya han sido cargados...\n");
            	}

                break;
            case 2:
            	if(opcionunica==0)
            	{
            		b=controller_loadFromBinary("databin.bin",listaEmpleados);

            		if(b!=0)
            		{
            			opcionunica++;
            			controller_getLastId("createId.txt", newId);
            		}

            	}else
            	{
            		printf("...Los datos ya han sido cargados...\n");
            	}

            	break;
            case 3:
            	if(opcionunica!=0)
            	{
            		controller_addEmployee(listaEmpleados,newId);
            		printf("\nSe aconseja realizar lo necesario y guardar antes de cargar nuevamente un empleado...\n");
            	}else
            	{
            		printf("Se necesita cargar datos (opcion 1 o 2)\n");
            	}
                break;
            case 4:
            	if(opcionunica!=0)
				{
					controller_editEmployee(listaEmpleados);
				}else
				{
					printf("Se necesita cargar datos (opcion 1 o 2)\n");
				}

            	break;
            case 5:
            	if(opcionunica!=0)
				{
					controller_removeEmployee(listaEmpleados);
				}else
				{
					printf("Se necesita cargar datos (opcion 1 o 2)\n");
				}

                break;
            case 6:
            	if(opcionunica!=0)
				{
					controller_ListEmployee(listaEmpleados);
				}else
				{
					printf("Se necesita cargar datos (opcion 1 o 2)\n");
				}



            	break;
            case 7:
            	if(opcionunica!=0)
				{
					printf("\nEspere un momento...\n");

            		controller_sortEmployee(listaEmpleados);
					controller_ListEmployee(listaEmpleados);
				}else
				{
					printf("Se necesita cargar datos (opcion 1 o 2)\n");
				}

            	break;
            case 8:
            	 if(opcionunica!=0)
					{
						 controller_saveAsText("data.csv", listaEmpleados);
					}else
					{
						printf("Se necesita cargar datos (opcion 1 o 2)\n");
            		}
            	break;
            case 9:
            	if(opcionunica!=0)
					{
						controller_saveAsBinary("databin.bin", listaEmpleados);
					}else
					{
						printf("Se necesita cargar datos (opcion 1 o 2)\n");
					}


            	break;
        }
    }while(option != 10);
    return 0;



}

/*
 	 if(opcionunica!=0)
	{

	}else
	{
		printf("Se necesita cargar datos (opcion 1 o 2)\n");
	}


 */


