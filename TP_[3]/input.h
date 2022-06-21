#ifndef INPUT_H_
#define INPUT_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CleanBuff fflush(stdin)


//INT Y FLOAT
/// @brief Validacion para saber si el string es un numero
///
/// @param numero
/// @return retorna 0 si es numero, -1 si no lo es
int VerificarNumeroEntero(char numero[]);

/// @brief Pide un numero entero y lo deriva a la funcion que lo valida
///
/// @param mensaje string para especificar que se debe insertar
/// @return el numero transformado en entero
int PedirEnteroValidacion (char mensaje[]);

/// @brief Pide una cadena, la deriva a una funcion que la valida y devuelve el valor, transformado en entero a la direccion de memoria  pedida
/// @param mensaje mensaje string para especificar que se debe insertar
/// @param numero. Puntero de una variable a la que se le asigna el numero que se ingresa
/// @return retorna -1 en caso de error y 0 si no hay error
int PedirEnteroValidacionReintentos (char mensaje[], int* numero);

/// @brief Pide una cadena, la valida y la devuelve como entero
/// @param mensaje mensaje string para especificar que se debe insertar
/// @param minimo limite minimo que se puede ingresar
/// @param maximo limite maximo que se puede ingresar
/// @return el numero validado
int PedirEnteroRangoValidacion (char mensaje[], int minimo, int maximo);

/// @brief Recibe parametros que determinan que se tiene que ingresar como cadena y devuelve lo ingresado como Entero validado
/// @param mensaje mensaje string para especificar que se debe insertar
/// @param minimo limite minimo que se puede ingresar
/// @param maximo limite maximo que se puede ingresar
/// @param numero
/// @return retorna -1 en caso de error y 0 si no hay error
int PedirEnteroRangoValidacionReintentos (char mensaje[], int minimo, int maximo, int* numero);

/// @brief Chequear que el string que recibe no contenga letras y que no esté vacío
/// @param numero
/// @return retorna -1 en caso de error y 0 si sale bien
int VerificarNumeroFlotante(char numero[]);

/// @brief Pide una cadena y la valida con una funcion para que la devuelva como flotante
/// @param mensaje especifica lo que se tiene que ingresar
/// @return Retorna la cadena como un flotante
float PedirFloatValidacion (char mensaje[]);

/// @brief Pide una cadena, valida que sea numero flotante y la pasa a numero flotante
/// @param mensaje especifica que se tiene que ingresar
/// @param minimo limite minimo que se puede ingresar
/// @param maximo limite maximo que se puede ingresar
/// @return retorna la cadena transformada como numero flotante
float PedirFloatRangoValidacion (char mensaje[],int minimo, int maximo);


/// @brief Pide una cadena, valida que sea numero flotante, la pasa a numero flotante y corta si no se ingreso despues de 3 intentos
/// @param mensaje especifica que se tiene que ingresar
/// @param numero la direccion de memoria donde se guarda el numero
/// @return retorna -1 en caso de error y 0 si sale bien
int PedirFloatValidacionReintentos (char mensaje[],float* numero);

/// @brief Pide una cadena(Luego la transforma a flotante), valida que este dentro del rango, que sea flotante y limita los intentos a 3.
/// @param mensaje especifica que se tiene que ingresar
/// @param minimo limite minimo que se puede ingresar
/// @param maximo limite maximo que se puede ingresar
/// @param numero direccion de memoria donde se guarda el numero flotante
/// @return retorna -1 en caso de error y 0 si sale bien
int PedirFloatRangoValidacionReintentos (char mensaje[],int minimo, int maximo, float* numero);

/// @brief printea un id si es que se genero uno
/// @param estado
/// @param idGenerado Muestra el id generado
void MostrarIDgenerado(int estado, int* idGenerado);

//STRING
/// @brief Comprueba que el string no esté vacio y que solo contenga letras
/// @param palabra string que recibe
/// @return retorna -1 si hay error y 0 si no lo hay
int ValidarSoloLetras(char palabra[]);

/// @brief Recibe 2 mensajes que se ejectuan dependiendo de una variable numerica.
/// @param num valor recibido de una funcion
/// @param mensajeA Mensaje que recibe si hubo error
/// @param mensajeB Mensaje que recibe si no hubo error
void MensajeAlerta(int num, char mensajeERROR[], char mensajeB[]);

/// @brief Pide una string de letras que se guarda en una variable y se valida con una funcion, al final se usa otra funcion para corregir.
/// @param mensaje especfica que se va a ingresar
/// @param stringIngresado array donde se va a guardar lo que se ingresa
/// @return retorna -1 en caso de error y 0 si no lo hubo
int PedirStringSoloLetras (char mensaje[], char stringIngresado[]);

/// @brief Recibe una cadena de solo letras y transforma la primer letra en mayuscula y las siguientes en minuscula
/// @param palabra string que recibe
void EmprolijarString(char palabra[]);

/// @brief Valida que el string ingresado solo contenga numeros o letras
///
/// @param palabra
/// @return retorna -1 si hay error y 0 si está correcto
int ValidarLetrasNumeros(char palabra[]);

/// @brief Pide una string que solo contenga numeros o letras
///
/// @param mensaje
/// @param stringIngresado
/// @return devuelve -1 si no se ingresó correctamente el string o da error. Y devuelve 0 si no hubo error.
int PedirStringNumerosLetras (char mensaje[], char stringIngresado[]);


/// @brief Pide un string sin restricciones
///
/// @param mensaje
/// @param stringIngresado
void PedirStringSinRestricciones(char mensaje[], char stringIngresado[]);

/// @brief Funcion para confirmar una accion entre Si y NO
///
/// @param mensaje
/// @return Retorna -1 si el usuario puso que no (o si se superan los intentos), retorna 0 si el usuario puso que si
int ConfirmarSiNo(char mensaje[]);

//Funcion para elegir entre opcion A o B
//Retorna un entero para verificar la opcion
/// @brief Funcion para elegir entre la opcion A o la opcion B
///
/// @param mensaje
/// @return retorna 1 si se elije la opcion A y retorna 2 si se elije la opcion B. Retorna -1 en caso de error.
int OpcionAoB(char mensaje[]);




#endif /* INPUT_H_ */

