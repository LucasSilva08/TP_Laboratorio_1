#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int estado=0;
    FILE* pFile;
    pFile = fopen(path,"r");
    if(pFile!=NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        estado=1;
    }
    fclose(pFile);
    return estado;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int estado=0;
    FILE* pFile;
    pFile = fopen(path,"rb");
    if(pFile!=NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        estado=1;
    }
    fclose(pFile);
    return estado;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    char nombre[128];
    int horas;
    int sueldo;
    int index;
    Employee* pEmployee;
    pEmployee=employee_new();
    if(pEmployee!=NULL)
    {
        id=getSoloNumero("Ingrese Nro de ID: ");
        index=findOneById(pArrayListEmployee,id);
        if(index==-1)
        {
          employee_setId(pEmployee,id);
          getValidString("Ingrese Nombre: ","ERROR, Tiene que estar compuesto solo por Letras",nombre);
          employee_setNombre(pEmployee,nombre);
          horas=getSoloNumero("Ingrese Horas Trabajadas: ");
          employee_setHorasTrabajadas(pEmployee,horas);
          sueldo=getSoloNumero("Ingrese Sueldo: ");
          employee_setSueldo(pEmployee,sueldo);
          ll_add(pArrayListEmployee,pEmployee);
        }
        else
        {
            printf("\nYA EXISTE UN EMPLEADO CON ESE ID\n\n");
        }
    }
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    char auxNombre[128];
    int auxHrs;
    int auxSueldo;
    char confirmar;
    int id;
    int index;
    int opcion;
    Employee* pEmployee;
    id=getSoloNumero("Ingrese Nro de ID: ");
    index=findOneById(pArrayListEmployee,id);
    if(index!=-1)
    {
        pEmployee=ll_get(pArrayListEmployee,index);
         do
        {
        opcion = getInt("\n1.Nombre\n2.Horas Trabajadas\n3.Sueldo\n4.Salir\nElija una opcion a modificar: ");
        switch(opcion)
        {
            case 1:
                confirmar=getChar("Estas seguro que desea modificar el Nombre? (s/n): ");
                if(confirmar=='s'||confirmar=='S')
                {
                    getValidString("Ingrese Nombre: ","ERROR, Tiene que estar compuesto solo por Letras",auxNombre);
                    confirmar=getChar("Estas seguro que desea modificar el Nombre? (s/n): ");
                    if(confirmar=='s'||confirmar=='S')
                    {
                       strcpy(pEmployee->nombre,auxNombre);
                    }
                    else
                    {
                         break;
                    }
                }
            break;
            case 2:
                confirmar=getChar("Estas seguro que desea modificar las Hras Trabajadas? (s/n): ");
                if (confirmar=='s'||confirmar=='S')
                {
                    auxHrs=getSoloNumero("Ingrese Nueva Hras trabajadas: ");
                    confirmar=getChar("Estas seguro que desea modificar las Hras Trabajadas ? (s/n): ");
                    if (confirmar=='s'||confirmar=='S')
                    {
                        pEmployee->horasTrabajadas=auxHrs;
                    }
                    else
                    {
                        break;
                    }
                }
                break;
            case 3:
                confirmar=getChar("Estas seguro que desea modificar el SUELDO? (s/n): ");
                if (confirmar=='s'||confirmar=='S')
                {
                    auxSueldo=getSoloNumero("Ingrese Nuevo Sueldo: ");
                    confirmar=getChar("Estas seguro que desea modificar el SUELDO? (s/n): ");
                    if (confirmar=='s'||confirmar=='S')
                    {
                        pEmployee->sueldo=auxSueldo;
                    }
                    else
                    {
                        break;
                    }
                }
                break;
        }
        }while(opcion!=4);
        retorno=1;
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int id;
    int index;
    char confirmar;
    id=getSoloNumero("Ingrese Nro de ID: ");
    index=findOneById(pArrayListEmployee,id);
    if(index!=-1)
    {
        confirmar=getChar("Estas Seguro que quiere dar de BAJA este empleado?(s/n): ");
        if(confirmar=='s'||confirmar=='S')
        {
            ll_remove(pArrayListEmployee,index);
            retorno=1;
        }

    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int auxId;
    char auxNombre[25];
    int auxHrs;
    int auxSueldo;
    Employee* pEmployee;
    int largoLista;
    int i;
    largoLista= ll_len(pArrayListEmployee);
    printf("   ID |     NOMBRE       |   HS TRABAJADAS |  SUELDO \n");

    for(i=0;i<largoLista;i++)
    {
        pEmployee=ll_get(pArrayListEmployee,i);
        if(pEmployee!=NULL)
        {
             employee_getId(pEmployee,&auxId);
             employee_getNombre(pEmployee,auxNombre);
             employee_getHorasTrabajadas(pEmployee,&auxHrs);
             employee_getSueldo(pEmployee,&auxSueldo);
             if(i%250==0)
             {
                 system("pause");
             }
             printf("%5d |    %15s    |    %5dHs        |  $%5d\n",auxId,auxNombre,auxHrs,auxSueldo);
        }
    }
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    do
    {
        printf("1.ID\n");
        printf("2.Nombre\n");
        printf("3.Hrs Trabajadas\n");
        printf("4.Sueldo\n");
        printf("5.Salir\n");
        opcion=getInt("Ingrese Opcion por la Cual desea Ordenar: ");
        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListEmployee,employee_CompareById,1);
            break;
        case 2:
            ll_sort(pArrayListEmployee,employee_CompareByNombre,1);
            break;
        case 3:
            ll_sort(pArrayListEmployee,employee_CompareByHrsTrabajadas,1);
            break;
        case 4:
            ll_sort(pArrayListEmployee,employee_CompareBySueldo,1);
            break;
        }
    }while(opcion!=5);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int estado=0;
    int i;
    FILE* pFile;
    Employee* pEmployee;
    pFile=fopen(path,"w");
    if(pFile!=NULL)
    {
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee=ll_get(pArrayListEmployee,i);
            fprintf(pFile,"%d,%s,%d,%d\n",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
            estado=1;
        }
        fclose(pFile);
    }
    return estado;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int estado=0;
    int i;
    FILE* pFile;
    Employee* pEmployee;
    int cantidad;
    pFile=fopen(path,"wb");
    if(pFile!=NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee=ll_get(pArrayListEmployee,i);
            cantidad=fwrite(pEmployee,sizeof(Employee),1,pFile);
            estado=1;
        }
        if(cantidad!=1)
        {
             printf("\nError al Guardar los datos\n");
        }
        fclose(pFile);
    }
    return estado;
}
/** \brief Busca a uno por ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int Retorna -1 si no lo encontro - El indice si lo encontro
 *
 */
int findOneById(LinkedList* pArrayListEmployee,int id)
{
    int i;
    int index =-1 ;
    Employee* pEmployee;
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        pEmployee=ll_get(pArrayListEmployee,i);
        if(pEmployee->id==id)
        {
            index=i;
            break;
        }
    }
    return index;
}
