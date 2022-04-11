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

/// @brief Transforma la moneda peso a Bitcoin
/// @param Puntero en la que se guarda el valor de bitcoin
/// @param Precio que recibe para efectuar el cambio
void AplicarCambioBitcoin(float*, float);

/// @brief Aplica un descuento al precio
/// @param Puntero en la que se guarda el precio
/// @param Precio al que se le aplica el descuento
void AplicarDescuento(float*, float);

/// @brief Aplica un aumento al precio
/// @param Puntero en la que se guarda el precio final
/// @param Precio al que se le aplica el aumento
void AplicarInteres(float*, float);

/// @brief Aplica una pausa para que se permita leer los datos antes de limpiar la consola
void FuncionPausa(void);
#endif /* BIBLIOTECATP1_H_ */


//resumen de la funcion
//parametros
//lo que retorna
