#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ArrayList.h"
#include "Employee.h"
#include "input.h"

int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
{
    char id[128],name[128],lastName[128],isEmpty[128];
    int fail1,fail2,fail3;
    Employee *emp;


    int cant;
    int returnAux = -1;

    if(pArrayListEmployee != NULL)
    {
        pFile = fopen("data.csv","r");
        if(pFile == NULL)
        {
            printf("Error, no se puede abrir el archivo\n");
        }

        fscanf(pFile, "%[^,] , %[^,], %[^,], %[^\n] \n",id,name,lastName,isEmpty);

        while( !feof(pFile))
        {
            cant =  fscanf(pFile, "%[^,] , %[^,] , %[^,], %[^\n] \n",id,name,lastName,isEmpty);

            if(cant != 4)
            {
                if(feof(pFile))
                {
                    break;
                }
                else
                {
                    printf("No se pudo leer el ultimo registro\n");
                    break;
                }
            }
            emp = employee_new();
            fail1 = employee_setId(emp,id);
            if(fail1 == -1)
            {
                returnAux = -1;
            }
            else
            {
                fail2 = employee_setName(emp,name);
                if(fail2 == -1)
                {
                    returnAux = -1;
                }
                else
                    fail3 = employee_setLastName(emp,lastName);
                if(fail3 == -1)
                {
                    returnAux = -1;
                }
                else
                {
                    if(strcmp(isEmpty,"true") == 0)
                    {
                        emp->isEmpty = 1;
                    }
                    else
                    {
                        emp->isEmpty = 0;
                    }
                }

                 pArrayListEmployee->add(pArrayListEmployee,emp);
                returnAux = 0;

            }


        }

    }


return returnAux;

}






