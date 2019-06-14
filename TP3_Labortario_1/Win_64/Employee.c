#include "Employee.h"
#include <string.h>
#include <stdlib.h>

/** \brief Compara los elementos por Id
 *
 * \param empl1 void*
 * \param empl2 void*
 * \return int retorna (1) si el primer elemento es mayor-(-1) si el elemento es menor -(0) si son iguales
 *
 */
int employee_CompareById(void* empl1,void* empl2)
{
    int estado=0;
    Employee* Employee1;
    Employee* Employee2;
    if(empl1!=NULL && empl2!=NULL)
    {
        Employee1=(Employee*)empl1;
        Employee2=(Employee*)empl2;

        if((Employee1->id)>(Employee2->id))
        {
            estado=1;
        }
        else if((Employee1->id)<(Employee2->id))
        {
            estado=-1;
        }
        else if((Employee1->id)==(Employee2->id))
        {
            estado=0;
        }
    }
    return estado;
}
/** \brief Compara los elementos por Horas Trabajadas
 *
 * \param empl1 void*
 * \param empl2 void*
 * \return int retorna (1) si el primer elemento es mayor-(-1) si el elemento es menor -(0) si son iguales
 *
 */
int employee_CompareByHrsTrabajadas(void* empl1,void* empl2)
{
    int estado=0;
    Employee* Employee1;
    Employee* Employee2;
    if(empl1!=NULL && empl2!=NULL)
    {
        Employee1=(Employee*)empl1;
        Employee2=(Employee*)empl2;

        if((Employee1->horasTrabajadas)>(Employee2->horasTrabajadas))
        {
            estado=1;
        }
        else if ((Employee1->horasTrabajadas)<(Employee2->horasTrabajadas))
        {
            estado=-1;
        }
        else if ((Employee1->horasTrabajadas)==(Employee2->horasTrabajadas))
        {
            estado=0;
        }
    }
    return estado;
}
/** \brief Compara los elementos por el Sueldo
 *
 * \param empl1 void*
 * \param empl2 void*
 * \return int retorna (1) si el primer elemento es mayor-(-1) si el elemento es menor -(0) si son iguales
 *
 */
int employee_CompareBySueldo(void* empl1,void* empl2)
{
    int estado=0;
    Employee* Employee1;
    Employee* Employee2;

    if(empl1!=NULL && empl2!=NULL)
    {
        Employee1=(Employee*)empl1;
        Employee2=(Employee*)empl2;

        if(Employee1->sueldo > Employee2->sueldo)
        {
            estado=1;
        }
        else if(Employee1->sueldo < Employee2->sueldo)
        {
            estado=-1;
        }
        else if(Employee1->sueldo == Employee2->sueldo)
        {
            estado=0;
        }
    }
    return estado;

}
/** \brief Compara los elementos por el Nombre
 *
 * \param empl1 void*
 * \param empl2 void*
 * \return int retorna (1) si el primer elemento es mayor-(-1) si el elemento es menor -(0) si son iguales
 *
 */
int employee_CompareByNombre(void* empl1,void* empl2)
{
    int estado=-1;
    Employee* Employee1;
    Employee* Employee2;

    if(empl1!=NULL && empl2!=NULL)
    {
        Employee1=(Employee*)empl1;
        Employee2=(Employee*)empl2;
        estado=strcmp(Employee1->nombre,Employee2->nombre);
    }
    return estado;

}
Employee* employee_new()
{
    Employee* empleado;
    empleado=(Employee*)malloc(sizeof(Employee));
    return empleado;
}
int employee_setId(Employee* this,int id)
{
    int estado=0;
    if(id>0)
    {
        this->id=id;
        estado=1;
    }
    return estado;
}
int employee_getId(Employee* this,int* id)
{
    int estado=-1;
    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        estado=0;
    }
    return estado;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int estado=-1;
    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        estado=0;
    }
    return estado;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int estado=-1;
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        estado=0;
    }
    return estado;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int estado=-1;
    if (this!=NULL&&horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        estado=0;
    }
    return estado;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int estado=-1;
    if (this!=NULL&&horasTrabajadas>0)
    {
       *horasTrabajadas=this->horasTrabajadas;
        estado=0;
    }
    return estado;
}
int employee_setSueldo(Employee* this,int sueldo)
{
   int estado=-1;
    if (this!=NULL)
    {
       this->sueldo=sueldo;
        estado=0;
    }
    return estado;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int estado=-1;
    if (this!=NULL)
    {
       *sueldo=this->sueldo;
       estado=0;
    }
    return estado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    int id;
    int horasTrabajadas;
    int sueldo;
    id=atoi(idStr);
    horasTrabajadas=atoi(horasTrabajadasStr);
    sueldo=atoi(sueldoStr);
    Employee* oneEmployee=employee_new();
    if(oneEmployee!=NULL)
    {
        employee_setId(oneEmployee,id);
        employee_setNombre(oneEmployee,nombreStr);
        employee_setHorasTrabajadas(oneEmployee,horasTrabajadas);
        employee_setSueldo(oneEmployee,sueldo);
    }

    return oneEmployee;
}
