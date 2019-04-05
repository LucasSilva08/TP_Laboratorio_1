#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
#include "Operando.h"
#include "Menu.h"

void MostrarMenu(void)
{
    float op1;
    float op2;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    int factorialA;
    int factorialB;
    int flag1=0;
    int flag2=0;

    int opcion;
    int seguir = 's';

    do
    {
        if (flag1==0)
        {
            printf("1. Ingrear 1er operando A=X\n");
        }
        else
        {
            printf("1. Ingresar 1er operando A= %f\n",op1);
        }
        if(flag2==0)
        {
            printf("2. Ingrear 2do operando B=Y\n");
        }
        else
        {
            printf("2. Ingrear 2do operando B= %f\n",op2);
        }

        printf("3. Calcular todas las Operaciones \n4. Informar Resultado\n5. Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                op1 = PedirOperando("Ingrese el Operando: ");
                flag1=1;
                break;
            case 2:
                op2 = PedirOperando("Ingrese el Operando: ");
                flag2=1;
                break;
            case 3:
                if (flag1==0||flag2==0)
                {
                    printf("Ingrese Los 2 Operando para poder calcular!!\n");
                }
                else
                {
                    suma=calcularSuma(op1,op2);
                    resta=calcularResta(op1,op2);
                    multiplicacion=calcularMultiplicacion(op1,op2);
                    if(op2!=0)
                    {
                        division=calcularDivision(op1,op2);
                    }
                    factorialA=calcularFactorail(op1);
                    factorialB=calcularFactorail(op2);
                }
                break;
            case 4:
                if (flag1==0||flag2==0)
                {
                    printf("Ingrese los dos Operando para poder calcular\n");
                }
                else
                {
                    printf("El resultado de A+B es: %f\nEl resultado de A-B es: %f\nEl resultado de A*B es: %f\n",suma,resta,multiplicacion);
                    if (op2!=0)
                    {
                        printf("El resultado de A/B es: %f\n",division);
                    }
                    else
                    {
                        printf("No es posible dividir por 0\n");
                    }

                    printf("El factorial de A es: %d\nEl factorial de B es: %d\n",factorialA,factorialB);
                }

                break;
            case 5:
                printf("Estas Saliendo del Sistema\n");
                seguir='n';
                break;
            default:
                printf("Error, Ingrese una Opcion valida\n");

        }
        system("pause");
        system("cls");


    }while (seguir=='s');
}
