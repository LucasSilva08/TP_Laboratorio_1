#include "Operaciones.h"


float calcularSuma(float A,float B)
{
    float resultado;
    resultado= A+B;

    return resultado;
}

float calcularResta(float A, float B)
{

    float resultado;
    resultado=A-B;

    return resultado;
}

float calcularMultiplicacion(float A,float B)
{
    float resultado;
    resultado=A*B;

    return resultado;
}

float calcularDivision(float A,float B)
{
    float resultado;
    resultado=A/B;
    return resultado;
}
int calcularFactorail(float A)
{
    float resultado=1;
    float fac;

    for(fac=A;fac>1;fac--)
    {
        resultado= resultado*fac;
    }

    return resultado;
}


