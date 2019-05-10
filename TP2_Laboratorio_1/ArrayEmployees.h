#include <stdio.h>
#include <stdlib.h>
#define TRUE 0
#define FALSE 1


typedef struct
{
   int id;
   char nombre[51];
   char apellido[51];
   float salario;
   int sector;
   int estaLibre;
} Employee;

/** \brief Nos indica que todas las posiciones del Array estan Libres
 *
 * \param [] Employee Array de empleados
 * \param int El largo de la Array
 * \return int Retorna (-1) si hay un ERROR - (0) si esta OK
 *
 */
int initEmployees(Employee [], int);
/** \brief Adiere los parametros recibidos en la primera posicion de la lista de Empleados
 *
 * \param Employee[] lista de Empleados
 * \param int largo del Array
 * \param int Id del Empleado a cargar
 * \param char[] Nombre del Empleado a cargar
 * \param char[] Apellido del Empleado a cargar
 * \param float Salario del Empleado a cargar
 * \param int El sector del Empleado
 * \return int Retorna  (-1) si hay ERROR -(0) si esta OK
 *
 */
int addEmployee(Employee[], int, int , char[],char[],float,int);
/** \brief Busca el indice en el Cual esta Cargado el Id del Empleado
 *
 * \param Employee[] lista de Empleados
 * \param int largo del Array
 * \param int id del Empleado a buscar
 * \return int Retorna el Indice si lo encuantra -(-1) si no lo encontro
 *
 */
int findEmployeeById(Employee[],int,int);
/** \brief Elimina el Empleado por Id (baja logica)
 *
 * \param Employee[] lista de empleados
 * \param int largo del Array
 * \param int Id del Empleado a Eliminar
 * \return int Retorna (-1) si hay Error - (0) si esta OK
 *
 */
int removeEmployee(Employee[],int,int);
/** \brief Busca la primera posicion Libre del Array
 *
 * \param Employee[] lista Empleados
 * \param int Largo del Array
 * \return int Retorna (-1) si no encontro Espacio - El indice de la posicion libre si encontro espacio
 *
 */
int buscarLibre(Employee[],int);
/** \brief Genera un numero Aleatorio para usarlo como Id
 *
 * \param Employee[] lista de Empleados
 * \param int largo del Array
 * \return int Retorna el Id Generado
 *
 */
int legajoAleatorio(Employee[],int);
/** \brief Muestra Todos los Datos de un Empleado
 *
 * \param Employee un Empleado
 * \return void
 *
 */
void mostrarUnEmpleado(Employee);
/** \brief Muestra todo el contenido del Array
 *
 * \param Employee[] lista de Empleados
 * \param int largo del Array
 * \return int
 *
 */
int printEmployees(Employee[],int);
/** \brief Menu de Opciones Para modificar los datos del Array
 *
 * \param Employee[] lista Empleados
 * \param int Indice del Array de los datos que quiero Modificar
 * \return void
 *
 */
void menuModificar(Employee[],int);
/** \brief busco el indice del dato que quiero modificar por Id
 *
 * \param Employee[] lista de empleados
 * \param int Largo del Array
 * \param int Id del Empleado a Modificar
 * \return int Retorna el Indice - (-1) si no lo encontro
 *
 */
int modificarDatos(Employee[],int,int);
/** \brief Ordena los Elementos del Array atravez del orden indicado (UP o DOWN)
 *
 * \param Employee[] lista de Empleados
 * \param int Largo del Arrya
 * \param int Orden
 * \return int Retorna (-1) si hay Error - (0) si esta Ok
 *
 */
int sortEmployees(Employee[],int,int);
/** \brief Calcula El promedio de los Salarios y Cuenta la cantidad de Empleados que lo superan
 *
 * \param Employee[] lista de Empleados
 * \param int largo del Array
 * \return int int Retorna (-1) si hay Error - (0) si esta Ok
 *
 */
int calcularPromedioSalario(Employee[],int);





