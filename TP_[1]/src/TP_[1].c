/*
 ============================================================================
 Author      : Fausto Forcherio
 ============================================================================
 */

#include "bibliotecaTP1.h"


int main(void) {
float kilometros=0;
float precioAerolineas=0;
float precioLatam=0;
int opcion;

float	resulDebitoLatam=0;
float	resulDebitoAerolineas=0;
float	resulcreditoLatam=0;
float	resulcreditoAerolineas=0;
float	resulbitLatam=0;
float	resulbitAerolineas=0;
float	resultadoDivisionAerolineas=0;
float	resultadoDivisionLatam=0;
float	resultadoDiferencia=0;

int flagX=0;
int flagY=0;
int flagCalculos=0;

setbuf(stdout, NULL);
do{
	system("cls") ;
printf("\n    CALCULADORA DE COSTOS \n");
printf("\t    Menú \n");



if(flagX==1){
printf("\n 1) Ingresar kilometros. (A=%.2f)", kilometros);
}
else{
printf("\n 1) Ingresar kilometros. (A=X)");
}


if(flagY==1){
printf("\n 2) Ingresar precio de vuelos. (Aerolineas=%.2f , Latam=%.2f)", precioAerolineas, precioLatam);
}
else{
printf("\n 2) Ingresar precio de vuelos. (Aerolineas=Y , Latam=Z)");
}



printf("\n 3) Calcular todos los costos.");
printf("\n 4) Informar resultados.");
printf("\n 5) Carga forzada.");
printf("\n 6) Salir.");
printf("\n \nIngrese opcion: ");
scanf("%d", &opcion);
while(opcion<1||opcion>6){
	printf("\nERROR. Ingrese opcion: ");
	scanf("%d", &opcion);
}


switch(opcion){
case 1:
	PedirFloatMayorCero("\nIngrese la cantidad de kilometros: ", &kilometros);
 flagX=1;
	break;
case 2:
	PedirFloatMayorCero("\nIngresar precio de aerolineas: ", &precioAerolineas);
	PedirFloatMayorCero("\nIngresar precio de Latam: ", &precioLatam);
 flagY=1;
	break;
case 3:
	if(flagX==1&&flagY==1){
	printf("\nCALCULOS HECHOS\n");
	AplicarDescuento(&resulDebitoLatam, precioLatam);
	AplicarInteres(&resulcreditoLatam, precioLatam);
	AplicarCambioBitcoin(&resulbitLatam, precioLatam);
	Dividir(&resultadoDivisionLatam,precioLatam,kilometros);

	AplicarDescuento(&resulDebitoAerolineas,precioAerolineas);
	AplicarInteres(&resulcreditoAerolineas,precioAerolineas);
	AplicarCambioBitcoin(&resulbitAerolineas,precioAerolineas);
	Dividir(&resultadoDivisionAerolineas,precioAerolineas,kilometros);

	CalcularDiferencia(&resultadoDiferencia, precioLatam, precioAerolineas);
	flagCalculos=1;
	FuncionPausa();
	}else{
		printf("\nSe requiere cargar los datos primero.\n");
		FuncionPausa();
	}

	break;

case 4:
	if(flagCalculos==1&&flagX==1&&flagY==1){
	printf( "\nLatam:"
			"\na) Precio con tarjeta de débito: $ %.2f"
			"\nb) Precio con tarjeta de crédito: $ %.2f"
			"\nc) Precio pagando con bitcoin : %.8f BTC"
			"\nd) Precio unitario: $ %.2f"
				"\nAerolíneas:"
			"\na) Precio con tarjeta de débito: $ %.2f"
			"\nb) Precio con tarjeta de crédito: $ %.2f"
			"\nc) Precio pagando con bitcoin : %.8f BTC"
			"\nd) Precio unitario: $ %.2f"
			"\nLa diferencia de precio es : $ %.2f\n",resulDebitoLatam,resulcreditoLatam, resulbitLatam,resultadoDivisionLatam, resulDebitoAerolineas,resulcreditoAerolineas,resulbitAerolineas,resultadoDivisionAerolineas,resultadoDiferencia);
	FuncionPausa();
	}
	else
	{
		printf("\nSe requiere calcular los costos.\n");
		FuncionPausa();
	}
	break;
case 5:
	kilometros=7090;
	precioAerolineas=162965;
	precioLatam=159339;
	AplicarDescuento(&resulDebitoLatam, precioLatam);
	AplicarInteres(&resulcreditoLatam, precioLatam);
	AplicarCambioBitcoin(&resulbitLatam, precioLatam);
	Dividir(&resultadoDivisionLatam,precioLatam,kilometros);

	AplicarDescuento(&resulDebitoAerolineas,precioAerolineas);
	AplicarInteres(&resulcreditoAerolineas,precioAerolineas);
	AplicarCambioBitcoin(&resulbitAerolineas,precioAerolineas);
	Dividir(&resultadoDivisionAerolineas,precioAerolineas,kilometros);

	CalcularDiferencia(&resultadoDiferencia, precioLatam, precioAerolineas);
	printf( "\n\tLatam:"
				"\n a) Precio con tarjeta de débito: $ %.2f"
				"\n b) Precio con tarjeta de crédito: $ %.2f"
				"\n c) Precio pagando con bitcoin : %.8f BTC"
				"\n d) Precio unitario: $ %.2f"
					"\n\tAerolíneas:"
				"\n a) Precio con tarjeta de débito: $ %.2f"
				"\n b) Precio con tarjeta de crédito: $ %.2f"
				"\n c) Precio pagando con bitcoin : %.8f BTC"
				"\n d) Precio unitario: $ %.2f"
				"\n La diferencia de precio es : $ %.2f\n",resulDebitoLatam,resulcreditoLatam, resulbitLatam,resultadoDivisionLatam, resulDebitoAerolineas,resulcreditoAerolineas,resulbitAerolineas,resultadoDivisionAerolineas,resultadoDiferencia);
	flagCalculos=1;
	flagX=1;
	flagY=1;
	FuncionPausa();
	break;
}

}while(opcion!=6);
printf("\n Off");
return 0;
}

/* Validaciones que entran
 * Se pued los precios.
 * La carga forzada se tiene que mostrar exactamente igual a la pantalla de resultados sin ingresar ninguna opción previamente. (solo mostrar los resultados ya calculados)
 */
