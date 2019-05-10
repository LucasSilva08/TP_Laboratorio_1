/** \brief pedimos un dato tipo int
 *
 * \param char[] mensaje que muestra la funcion
 * \return int entero que escanea la funcion
 *
 */
int pedirEntero(char[]);
/** \brief pedimos un dato tipo float
 *
 * \param char[] mensaje que muestra la funcion
 * \return float flotante que escanea la funcion
 *
 */
float pedirFlotante(char[]);
/** \brief pedimos un array de caracteres
 *
 * \param char[] mensaje que muestra la funcion
 * \param char[] cadena donde se guarda los datos
 * \return void
 *
 */
void pedirCadena(char[],char[]);
/** \brief pedimos un dato tipo char
 *
 * \param char[] mensaje que muestra la funcion
 * \return char cadena que devuelve la funcion
 *
 */
char pedirCaracter(char[]);

/** \brief Genera un Numero aleatorio
 *
 * \param int Indica desde que numero
 * \param int Indica Hasta que numero
 * \param int Indica donde Inicia
 * \return int Retorna el Numero Aleatorio Generado
 *
 */
int getNumeroAleatorio(int, int, int);

/** \brief Verifica si el Array esta compuesto solo por Numeros
 *
 * \param str[] char Array
 * \return int int Retorna (-1) si hay Error - (0) si esta Ok
 *
 */
int esNumerico(char str[]) ;
/** \brief Verifica que el Array esta Compuesto solo por Letras
 *
 * \param str[] char Array
 * \return int int Retorna (-1) si hay Error - (0) si esta Ok
 *
 */
int esSoloLetras(char str[]);
void getString(char mensaje[],char input[]);
/** \brief Verifica que el Valor este Compuesto solo por letras, en Caso contrario Vuelve a Pedir el Ingreso
 *
 * \param mensaje[] char Mensaje que Muestro
 * \param input[] char Donde Guarda el Dato
 * \return int int Retorna (-1) si hay Error - (0) si esta Ok
 *
 */
int getStringLetras(char mensaje[],char input[]);
/** \brief Verifica que el Valor este Compuesto solo por Numeros, en Caso contrario vuelve a pedir el Ingreso
 *
 * \param mensaje[] char Mensaje que muestro
 * \param input[] char Donde guarda el dato
 * \return int int Retorna (-1) si hay Error - (0) si esta Ok
 *
 */
int getStringNumeros(char mensaje[],char input[]);

