#include "ArrayEmployees.h"
#include "PedirDatos.h"
#define CANTIDAD_EMPLEADOS 1000
#define UP 1
#define DOWN 0


int main()
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;

    char auxSalario[50];
    char auxSector[50];
    char auxId[50];

    int opcion;
    char confirmar;
    int flag=0;
    Employee listaEmpleados[CANTIDAD_EMPLEADOS];
    initEmployees(listaEmpleados,CANTIDAD_EMPLEADOS);
    do
    {
       opcion=pedirEntero("\n1.ALTA\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.SALIR\nElija una  Opcion: ");
        switch(opcion)
        {
            case 1:
                       if(buscarLibre(listaEmpleados,CANTIDAD_EMPLEADOS)==-1)
                       {
                           printf("No HAY ESPACIO\n");
                       }
                       else
                       {
                           id=legajoAleatorio(listaEmpleados,CANTIDAD_EMPLEADOS);
                       if(!getStringLetras("Ingrese Nombre: ",nombre))
                       {
                           printf ("El nombre debe estar compuesto solo por letras\n");
                           break;
                       }
                       if(!getStringLetras("Ingrese Apellido: ",apellido))
                       {
                           printf ("El Apellido debe estar compuesto solo por letras\n");
                           break;
                       }
                       if(!getStringNumeros("Ingrese Salario: ",auxSalario))
                       {
                           printf ("El Salario debe estar compuesto solo por Numeros\n");
                           break;
                       }
                       if(!getStringNumeros("Ingrese Sector: ",auxSector))
                       {
                           printf ("El Sector debe estar compuesto solo por Numeros\n");
                           break;
                       }
                       salario=atoi(auxSalario);
                       sector=atoi(auxSector);
                       addEmployee(listaEmpleados,CANTIDAD_EMPLEADOS,id,nombre,apellido,salario,sector);
                       flag=1;
                       }
                break;
            case 2:
                if (flag==1)
                {
                   printEmployees(listaEmpleados,CANTIDAD_EMPLEADOS);
                   if(!getStringNumeros("Ingrese ID del Empleado: ",auxId))
                   {
                       printf("El id tiene que estar compuesto solo por numeros\n");
                   }
                   id=atoi(auxId);

                   modificarDatos(listaEmpleados,CANTIDAD_EMPLEADOS,id);
                }
                else
                {
                    printf("Se debe Ingresar un Empleado!!\n");
                }
                break;
            case 3:
                if (flag==1)
                {
                    printEmployees(listaEmpleados,CANTIDAD_EMPLEADOS);
                    if(!getStringNumeros("Ingrese ID del Empleado: ",auxId))
                       {
                           printf ("El Id debe estar compuesto solo por Numeros\n");
                           break;
                       }
                    id=atoi(auxId);
                    confirmar=pedirCaracter("Esta seguro que quiere dar de BAJA este empleado?(s/n): ");
                    if(confirmar=='s')
                    {
                       removeEmployee(listaEmpleados,CANTIDAD_EMPLEADOS,id);
                    }
                }
                else
                {
                    printf("Se debe Ingresar un Empleado!!\n");
                }
                break;
            case 4:
                if(flag==1)
                {
                    sortEmployees(listaEmpleados,CANTIDAD_EMPLEADOS,UP);
                    printEmployees(listaEmpleados,CANTIDAD_EMPLEADOS);
                    calcularPromedioSalario(listaEmpleados,CANTIDAD_EMPLEADOS);
                }
                else
                {
                    printf("Se debe Ingresar un Empleado!!\n");
                }
                break;
        }
    }while (opcion!=5);
    return 0;
}
