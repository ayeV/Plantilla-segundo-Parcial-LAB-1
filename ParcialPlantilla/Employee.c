#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayList.h"
#include "Employee.h"
#include "input.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    int retorno = -1;
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
                retorno = 0;
            }

        }

    return retorno;
}


void employee_print(Employee* this)
{
    if(this !=NULL)
    {
        printf("%4d\t %16s\t%16s\t%4d\n",employee_getId(this), employee_getName(this), employee_getlastName(this), this->isEmpty);
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


void listarEmpleadosDesdeHasta(ArrayList* this, Employee* emp)
{
    int desde, hasta;
    int i;
    ArrayList* this2 = al_newArrayList();

    if(this != NULL && emp != NULL)
    {
        getInt(&desde,"Ingrese ID desde donde quiere obtener la lista\n","Error, ingrese ID valido\n",0,this->len(this)-1);
        getInt(&hasta,"Ingrese ID hasta donde quiere obtener la lista\n","Error, ingrese ID valido\n",desde+1,this->len(this));

        this2 = this->subList(this,desde-1,hasta);
        printf("Empleados desde %d hasta %d\n",desde,hasta);
        printf("\n\n");
        printf("ID\t\t  NOMBRE\t\t   APELLIDO\tISEMPTY\n");
        for(i=0; i<this2->len(this)-1; i++)
        {

            emp = (Employee*)this->get(this2,i);
            employee_print(emp);
        }

             /* for(i=desde-1; i<hasta; i++)
            {

                emp = (Employee*)this->get(this,i);
                employee_print(emp);

            }*/




    }
    else
    {
        printf("Ha ocurrido un error, se cierra el programa\n");
        system("pause");
        exit(1);
    }


}

void cargarEmpleado(ArrayList* this, Employee* emp)
{
   // Employee* aux;
    char name[100],lastName[100];
    int i;


    emp = employee_new();
    getString(name,"Nombre: ","Error ingrese nombre valido",2,50);
    strcpy(emp->name,name);
    getString(lastName,"Apellido: ","Error ingrese apellido valido",2,50);
    strcpy(emp->lastName,lastName);
    for(i=0;i<=this->len(this);i++)
    {
        emp->id = i+1; //id autoincremental
    }

    emp->isEmpty = 1;

    this->add(this,emp);
    printf("Datos del empleado agregado: \n");
    printf("ID\t\t  NOMBRE\t\t   APELLIDO\tISEMPTY\n");

    employee_print(emp);


}

void deleteEmployee(ArrayList* this, Employee* emp)
{
    int id;
    char opc;

    if( this != NULL && emp != NULL)
    {
        getInt(&id,"ingrese el ID del empleado a eliminar","Error usuario no existente",0,this->size);

        do
        {
            printf("Confirma la baja? S/N\n");
            fflush(stdin);
            scanf("%c", &opc);
            opc = tolower(opc);
        }while(opc != 's' && opc != 'n');
        if(opc == 's')
        {
            emp=(Employee*)this->pop(this,id-1);
            printf("Empleado eliminado: \n");
            employee_print(emp);
            system("pause");

        }
        else
        {
            printf("Se ha cancelado la baja\n");
        }


    }


}

void guardarArchivo(ArrayList* this, Employee* emp)
{
    FILE* f;

    int cantidad;

    f = fopen("data.csv", "wb");
    if(f != NULL)
    {
        cantidad = this->len(this);

        fwrite(emp,sizeof(Employee),cantidad,f);


        fclose(f);

        printf("Archivo guardado con exito\n\n");
    }
    else
    {
        printf("error al guardar el archivo\n");
    }


}


