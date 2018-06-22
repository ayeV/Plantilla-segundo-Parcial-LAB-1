#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

#include "ArrayList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

/****************************************************
    Menu:
        1. Parse del archivo data.csv
        2. Listar Empleados
        3. Ordenar por nombre
        4. Agregar un elemento
        5. Elimina un elemento
        6. Listar Empleados (Desde/Hasta)
*****************************************************/


int main()
{
    int opcion = 0;
    char seguir = 's';
    char guardar= 's';
    int i;

    Employee *employee;
    ArrayList *lista;

    FILE *pArch;

    lista = al_newArrayList();

    while(seguir=='s')
    {
        printf("1-Parse del archivo data.csv \n");
        printf("2-Listar Empleados\n");
        printf("3-Ordenar por nombre\n");
        printf("4-Agregar un elemento\n");
        printf("5-Elimina un elemento\n");
        printf("6-Listar Empleados (Desde/Hasta)\n");
        printf("7- Salir\n");

        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:
//pArch uninitalized PREGUNTAR
            if(  parserEmployee(pArch,lista) == 0)
            {
                printf("Parser exitoso\n");
            }
            else
            {
                printf("error\n");
            }
            system("pause");

            break;
        case 2:

            printf("--LISTAR EMPLEADOS--\n");
            printf("ID\t\t  NOMBRE\t\t   APELLIDO\tISEMPTY\n");
            for(i=0; i<lista->len(lista); i++)
            {
                employee = (Employee*)lista->get(lista,i);
                employee_print(employee);

            }

            system("pause");
            break;
        case 3:
            printf("--ORDENAR POR NOMBRE--\n");
            lista->sort(lista,employee,employee_compare,1);

            for(i=0; i<lista->len(lista); i++)
            {
                employee = (Employee*)lista->get(lista,i);
                employee_print(employee);

            }

            system("pause");
            break;
        case 4:
            cargarEmpleado(lista,employee);

            system("pause");
            break;
        case 5:
            deleteEmployee(lista,employee);
            system("pause");
            break;
        case 6:
            listarEmpleadosDesdeHasta(lista,employee);
            system("pause");
            break;
        case 7:
               /* printf("\nGuardar cambios S/N ?: ");
				guardar = tolower(getche());

				if(guardar == 's')
				{
				    cant = lista->len(lista);
					guardarArchivo(lista,employee);

                }
                else
                {
                    printf("Ha cancelado guardar\n");
                }*/


            seguir = 'n';
            break;
        default:
            printf("Opcion invalida\n");
            system("pause");
            break;
        }
    }

    return 0;
}
