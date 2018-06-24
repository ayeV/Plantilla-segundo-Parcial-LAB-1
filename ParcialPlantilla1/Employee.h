#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
struct
{
    int id;
    char name[51];
    char lastName[51];
    int isEmpty;

}typedef Employee;



int employee_compare(void* pEmployeeA,void* pEmployeeB);


void employee_print(Employee* this);
Employee* employee_new(void);

void employee_delete(Employee* this);

int employee_setId(Employee* this, char* id);
int employee_getId(Employee* this);

int employee_setName(Employee* this, char* name);
char* employee_getName(Employee* this);


int employee_setLastName(Employee* this, char* lastName);
char* employee_getlastName(Employee* this);


void cargarEmpleado(ArrayList* this, Employee* emp);
void listarEmpleadosDesdeHasta(ArrayList* this, Employee* emp);

int guardarArchivo(ArrayList* this);
void deleteEmployee(ArrayList* this, Employee* emp);

void employees_print(ArrayList* this);



#endif // _EMPLOYEE_H



