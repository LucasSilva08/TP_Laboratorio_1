#include "ArrayEmployees.h"
#include "PedirDatos.h"
#include <string.h>
#define UP 1
#define DOWN 0


int initEmployees(Employee listaEmpleados[], int largo)
{
    int i;
    int retorno=-1;
    for(i=0;i<largo;i++)
    {
        listaEmpleados[i].estaLibre=TRUE;
        retorno=0;
    }
    return retorno;
}
int addEmployee(Employee listaEmpleados[], int largo, int id , char nombre[],char apellido[],float salario,int sector)
{
    int retorno=-1;
    int i;
    i=buscarLibre(listaEmpleados,largo);
    if(i!=-1)
    {
            listaEmpleados[i].id=id;
            strcpy(listaEmpleados[i].nombre,nombre);
            strcpy(listaEmpleados[i].apellido,apellido);
            listaEmpleados[i].salario=salario;
            listaEmpleados[i].sector=sector;
            listaEmpleados[i].estaLibre=FALSE;
            retorno=0;
    }
    else
    {
        printf("NO HAY ESPACIO PARA DAR DE ALTA OTRO EMPLEADO!!!\n");
    }
    return retorno;
}
int buscarLibre(Employee listaEmpleados[],int largo)
{
    int i;
    int indice=-1;

    for(i=0;i<largo;i++)
    {
        if(listaEmpleados[i].estaLibre==TRUE)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int findEmployeeById(Employee listaEmpleados[],int largo,int id)
{
    int i;
    int indice =-1 ;
    for(i=0;i<largo;i++)
    {
        if(listaEmpleados[i].id==id&&listaEmpleados[i].estaLibre==FALSE)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int legajoAleatorio(Employee listaEmpleados[],int largo)
{

    int id;
    do
    {
        id=getNumeroAleatorio(1,largo,1);
    }while(findEmployeeById(listaEmpleados,largo,id)!=-1);

    return id;
}
int removeEmployee(Employee listaEmpleados[],int largo,int id)
{
    int retorno=-1;
    int indice;
    indice=findEmployeeById(listaEmpleados,largo,id);
    if(indice!=-1)
    {
        listaEmpleados[indice].estaLibre=TRUE;
        retorno=0;
    }
    else
    {
        printf("No se encontro al Empleado\n");
    }

    return retorno;
}
void mostrarUnEmpleado(Employee empleado)
{
    printf("\n %3d  |         %10s %10s            |   %10.2f    | %8d   \n",empleado.id,empleado.nombre,empleado.apellido,empleado.salario,empleado.sector);
}
int printEmployees(Employee listaEmpleados[],int largo)
{
    int retorno=-1;
    int i;
    printf("\n   ID |              NOMBRE y APELLIDO           |     SALARIO     |     SECTOR   ");
    for(i=0;i<largo;i++)
    {
        if (listaEmpleados[i].estaLibre==FALSE)
        {
            mostrarUnEmpleado(listaEmpleados[i]);
            retorno=0;
        }

    }
    return retorno;
}
void menuModificar(Employee listaEmpleados[],int indice)
{
    char nombre[20];
    char apellido[20];
    char auxSalario[50];
    char auxSector[50];
    int opcion;
    do
    {
        opcion = pedirEntero("1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n5.SALIR\nElija una opcion a modificar: ");
        switch(opcion)
        {
            case 1:
                       if(!getStringLetras("Ingrese Nombre: ",nombre))
                       {
                           printf ("El nombre debe estar compuesto solo por letras\n");
                           break;
                       }
                       strcpy(listaEmpleados[indice].nombre,nombre);

            break;
            case 2:
                       if(!getStringLetras("Ingrese Nombre: ",apellido))
                       {
                           printf ("El nombre debe estar compuesto solo por letras\n");
                           break;
                       }
                       strcpy(listaEmpleados[indice].apellido,apellido);

                break;
            case 3:
                       if(!getStringNumeros("Ingrese Salario: ",auxSalario))
                       {
                           printf ("El Salario debe estar compuesto solo por Numeros\n");
                           break;
                       }
                       listaEmpleados[indice].salario=atoi(auxSalario);

                break;
            case 4:
                       if(!getStringNumeros("Ingrese Salario: ",auxSector))
                       {
                           printf ("El Sector debe estar compuesto solo por Numeros\n");
                           break;
                       }
                       listaEmpleados[indice].sector=atoi(auxSector);
                break;
        }
    }while(opcion!=5);
}
int modificarDatos(Employee listaEmpleados[],int largo ,int id)
{
    int retorno=-1;
    int indice;
    indice=findEmployeeById(listaEmpleados,largo,id);
    if(indice!=-1)
    {
        menuModificar(listaEmpleados,indice);
        retorno=0;
    }
    else
    {
        printf("NO SE ENCONTRO!!!\n");
    }
    return retorno;
}
int sortEmployees(Employee listaEmpleados[],int largo,int sentido)
{
    int i;
    int j;
    Employee auxiliar;
    if(sentido==1)
    {
        for(i=1;i<largo;i++)
        {
            auxiliar=listaEmpleados[i];
            j=i-1;
            while (j>=0&&stricmp(auxiliar.apellido,listaEmpleados[j].apellido)<0)
            {
                listaEmpleados[j+1]=listaEmpleados[j];
                j--;

            }
            listaEmpleados[j+1]=auxiliar;
        }
    }
    if(sentido==0)
    {
        for(i=0;i<largo-1;i++)
        {
            for(j=i+1;j<largo;j++)
            {
                if(stricmp(listaEmpleados[i].apellido,listaEmpleados[j].apellido)<0&&listaEmpleados[i].sector<listaEmpleados[j].sector)
                {
                    auxiliar=listaEmpleados[i];
                    listaEmpleados[i]=listaEmpleados[j];
                    listaEmpleados[j]=auxiliar;
                }
            }
        }
    }
    return 0;
}
int calcularPromedioSalario(Employee listaEmpleados[],int largo)
{
    int retorno=-1;
    int acumuladorSalario=0;
    int contadorSalario=0;
    int contadorMayoresSalarios=0;
    float promedioSalario;
    int i;
    for(i=0;i<largo;i++)
    {
        if(listaEmpleados[i].estaLibre==FALSE)
        {
            acumuladorSalario=acumuladorSalario+listaEmpleados[i].salario;
            contadorSalario++;
        }
    }
    promedioSalario=(float)acumuladorSalario/contadorSalario;
    for(i=0;i<largo;i++)
    {
        if(listaEmpleados[i].estaLibre==FALSE&&listaEmpleados[i].salario>promedioSalario)
        {
            contadorMayoresSalarios++;
            retorno=0;
        }
    }
    printf("\nEl total de salario es: %d y su Promedio es: %.2f\n",acumuladorSalario,promedioSalario);
    printf("La cantidad de empleados que superan el promedio del salario: %d",contadorMayoresSalarios);
    return retorno;

}


