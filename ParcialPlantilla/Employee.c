#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Employee.h"
#include "input.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno = 0;
    Employee* auxiliarA;
    Employee* auxiliarB;

        if(pEmployeeA != NULL && pEmployeeB != NULL)
        {
            auxiliarA = (Employee*) pEmployeeA;
            auxiliarB = (Employee*) pEmployeeB;

            if(strcmp(auxiliarA->name,auxiliarB->name) > 0)
            {
                retorno = 1;
            }

             if(strcmp(auxiliarA->name,auxiliarB->name) < 0)
            {
                retorno = -1;
            }

        }

    return retorno;
}


void employee_print(Employee* this)
{
    if(this !=NULL)
    {
        printf("ID: %4d\tNAME: %16s\tLASTNAME: %16s\tISEMPTY: %4d\n",employee_getId(this), employee_getName(this), employee_getlastName(this), this->isEmpty);
    }

}


Employee* employee_new(void)
{
    Employee* returnAux = (Employee*) malloc(sizeof(Employee));

    return returnAux;
}


/*int deleteEmployee(ArrayList* pList)
{
    int option;
    char continueDo='s';
    int indexAux;
    Employee* mostrar=NULL;
    do
    {
        system("cls");
        getInt(&option,"\n1-Dar de baja un empleado\n2-Dar de baja un empleado y mostrar datos eliminados\n3-Volver al menu principal\nOption:","",1,3);
        switch(option)
        {
        case 1:
            getInt(&indexAux,"ingrese el legajo del usuario a eliminar","Error usuario no existente",0,pList->size);
            pList->remove(pList,indexAux-1);
            printf("Usuario eliminado");
            break;
        case 2:
             getInt(&indexAux,"ingrese el legajo del usuario a eliminar","Error usuario no existente",0,pList->size);
            mostrar=(Employee*)pList->pop(pList,indexAux-1);
            printf("Usuario eliminado");
            employee_print(mostrar);
            system("pause");
            break;
        case 3:
            continueDo='n';
            break;
        default:
            break;

        }

    }while(continueDo!='n');
}*/

//SET ID

int employee_setId(Employee* this, char* id)
{
    int retorno = -1;
    int aux;
    if(this != NULL && id !=NULL)
    {
        aux = atoi(id);
        this->id = aux;
        retorno = 0;
    }


    return retorno;

}
//GET ID
int employee_getId(Employee* this)
{
    int retorno= -1;
    if(this != NULL)
    {
        retorno = this->id;
    }
    return retorno;

}
//SET NAME
int employee_setName(Employee* this, char* name)
{
    int returnAux = -1;
    int len;


    if(this != NULL && name != NULL)
    {

        len = strlen(name);
        if(len >50)
        {
            printf("Error\n");
            exit(1);
        }
        else
        {

            strcpy(this->name, name);
        }

         returnAux = 0;

    }

    return returnAux;

}
//GET NAME
char* employee_getName(Employee* this)
{
    char* retorno;

    if(this != NULL)
    {
        retorno = this->name;
    }

    return retorno;


}

//SET LASTNAME
int employee_setLastName(Employee* this, char* lastName)
{
    int returnAux = -1;
    int len;

    if(this != NULL && lastName != NULL)
    {
        len = strlen(lastName);
        if(len>50)
        {
            printf("Error\n");
            exit(1);
        }
        else
        {
             strcpy(this->lastName, lastName);
        }


        returnAux = 0;

    }

    return returnAux;

}

//GET LASTNAME
char* employee_getlastName(Employee* this)
{
    char* retorno;

    if(this != NULL)
    {
        retorno = this->lastName;
    }

    return retorno;


}



