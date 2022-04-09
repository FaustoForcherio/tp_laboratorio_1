/*
 * bibliotecaTP1.c
 *
 *  Created on: 18 sep. 2021
 *      Author: faust
 */

#include <stdio.h>
#include <stdlib.h>

void PedirFloatMayorCero(char mensaje[], float* unNumero){
	float numero;
	printf(mensaje);
	scanf("%f", &numero);
		while(numero<0){
			printf(mensaje);
			scanf("%f", &numero);
		}
		*unNumero=numero;
}


void CalcularDiferencia(float* resultado, float unNumero, float otroNumero){
	float resultadoDentro;
	resultadoDentro=unNumero-otroNumero;
		if(resultadoDentro<=0){
			resultadoDentro=resultadoDentro*(-1);
		}

		*resultado=resultadoDentro;
}

void Dividir(float* resultado,float dividendo, float divisor){
	float resultadoDentro;
	resultadoDentro=dividendo/divisor;

		*resultado=resultadoDentro;
}

void AplicarCambioBitcoin(float* resultado, float precio){
	float resultadoDentro;
	resultadoDentro=precio/4606954.55;

	*resultado=resultadoDentro;
}

void AplicarDescuento(float* resultado, float precio){

	*resultado=precio*0.9;

}

void AplicarInteres(float* resultado, float precio){
	*resultado=precio*1.25;
}
void FuncionPausa(){
	char enter;
	printf("Presione cualquier tecla para continuar.");
	fflush(stdin);
	scanf("%c", &enter);
}
