#include <stdio.h>
#include <stdlib.h>
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
            for(i=0;i<lista->len(lista);i++)
            {
                employee = (Employee*)lista->get(lista,i);
                employee_print(employee);

            }

            system("pause");
            break;
        case 3:
            printf("--ORDENAR POR NOMBRE--\n");
            lista->sort(lista,employee,employee_compare,1);

            for(i=0;i<lista->len(lista);i++)
            {
                employee = (Employee*)lista->get(lista,i);
                employee_print(employee);

            }

            system("pause");
            break;
        case 4:


            system("pause");
            break;
        case 5:

            break;
        case 6:

            break;
        case 7:


            seguir = 'n';
            break;
        }
    }

    return 0;
}
