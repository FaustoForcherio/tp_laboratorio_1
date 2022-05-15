#ifndef INPUT_H_
#define INPUT_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define CleanBuff fflush(stdin)


//NUMEROS
int VerificarNumero(char numero[]);
int PedirEnteroValidacion (char mensaje[]);
int PedirEnteroValidacionReintentos (char mensaje[], int* numero);
int PedirEnteroRangoValidacion (char mensaje[], int minimo, int maximo);
int PedirEnteroRangoValidacionReintentos (char mensaje[], int minimo, int maximo, int* numero);
int VerificarNumeroFlotante(char numero[]);
float PedirFloatValidacion (char mensaje[]);
float PedirFloatRangoValidacion (char mensaje[],int minimo, int maximo);
int PedirFloatValidacionReintentos (char mensaje[],float* numero);
int PedirFloatRangoValidacionReintentos (char mensaje[],int minimo, int maximo, float* numero);
void MostrarIDgenerado(int estado, int* idGenerado);

//STRING
int ValidarSoloLetras(char palabra[]);
void MensajeAlerta(int num, char mensajeERROR[], char mensajeB[]);
int PedirStringSoloLetras (char mensaje[], char stringIngresado[]);
void EmprolijarString(char palabra[]);

/// @brief Pide un string sin restricciones
void PedirStringSinRestricciones(char mensaje[], char stringIngresado[]);
//Funcion para confirmar una accion
//Retorna un entero para verificar la opcion
int ConfirmarSiNo(char mensaje[]);

//Funcion para elegir entre opcion A o B
//Retorna un entero para verificar la opcion
int OpcionAoB(char mensaje[]);




#endif /* INPUT_H_ */

