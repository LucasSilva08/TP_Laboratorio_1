#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int pedirEntero(char mensaje[],int numero )
{
    //int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);
    return numero;
}
void pedirCadena(char mensaje[],char cadena[])
{
   printf("%s",mensaje);
   fflush(stdin);
   scanf("%[^\n]",cadena);
}
float pedirFlotante(char mensaje[])
{
    float numero;
    printf("%s",mensaje);
    scanf("%f",&numero);
    return numero;
}
char pedirCaracter(char mensaje[])
{
    char letra;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&letra);
    return letra;
}
int getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    int numero;
    if(iniciar)
    {
        srand (time(NULL));
    }
       numero=( desde + (rand() % (hasta + 1 - desde))) ;
    return numero;
}
int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    pedirCadena(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    pedirCadena(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
