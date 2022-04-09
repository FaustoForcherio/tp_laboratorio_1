/*
 * bibliotecaTP1.h
 *
 *  Created on: 18 sep. 2021
 *      Author: faust
 */

#ifndef BIBLIOTECATP1_H_
#define BIBLIOTECATP1_H_

#include <stdio.h>
#include <stdlib.h>



/// @fn float PedirFloat(char[])
/// @brief Recibe una cadena de caracteres para mostar un mensaje, en una funcion donde se piden numeros flotantes.
/// @param mensaje
/// @return retorna un numero flotante
void PedirFloatMayorCero(char[], float*);

/// @fn float Restar(float, float)
/// @brief resta el primer numero que se ingrese, con el segundo numero que se ingrese
/// @param un numero flotante
/// @param un numero flotante
/// @return retorna el resultado de una resta de numeros flotante.
void CalcularDiferencia(float*, float, float);

/// @fn float Dividir(float, float)
/// @brief divide el primer numero que se ignresa por el segundo numero que se ingresa
/// @param se ingresa el dividendo
/// @param se ingresa el divisor
/// @return retorna el resultado de la division
void Dividir(float*, float, float);


void AplicarCambioBitcoin(float*, float);

void AplicarDescuento(float*, float);
void AplicarInteres(float*, float);
void FuncionPausa(void);
#endif /* BIBLIOTECATP1_H_ */


//resumen de la funcion
//parametros
//lo que retorna
