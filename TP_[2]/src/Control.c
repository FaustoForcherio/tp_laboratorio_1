#include "Control.h"

void opcionMenuUno(ePassenger list[],int len){
	int aux;
	aux=findEmptySpot(list, len);
	if(aux==0){
	aux=addPassengers(list, len);
	MensajeAlerta(aux, "\nError al dar de alta un pasajero", "\nSe ha dado de alta con exito.");
	}
	else{
		printf("\nLa lista esta llena.");
	}
}
void opcionMenuDos(ePassenger list[], int len){
	int aux;
	aux=checkEmptyList(list, len);
	if(aux==0){
		aux=editPassenger(list, len);
		MensajeAlerta(aux, "\nError al modificar un pasajero", "\nSe ha modificado con exito.");
	}
}
void opcionMenuTres(ePassenger list[], int len){
	int aux;
	aux=checkEmptyList(list, len);
	if(aux==0){
		aux=removePassenger(list, len);
		MensajeAlerta(aux, "\nError al dar de baja el pasajero", "\nSe ha dado de baja al pasajero.");
	}
}
void opcionMenuCuatro(ePassenger list[],int len){
	int opcion;
	int aux;
	int orden;
	aux=checkEmptyList(list, len);
	if(aux==0){
		printf("\n\tMENU INFORMAR"
				"\n1) Listar pasajeros por orden alfabetico y tipo de pasajero"
				"\n2) Informar total y promedio de precios de los pasajes y cuantos pasajeros superan el promedio."
				"\n3) Listar los pasajeros por codigo de vuelo y estado de vuelo."
				"\n4) Salir.");
		aux=PedirEnteroRangoValidacionReintentos ("\nIngrese opcion: ", 1, 4, &opcion);
		if(aux!=-1){
		switch(opcion){
			case 1:
				orden=PedirEnteroRangoValidacionReintentos ("\nIngrese orden(1 para ascendente | 2 para descendente): ", 1, 2, &orden);
				if(orden!=-1){
					aux=sortPassengers(list, len, orden);
					if(aux!=-1){
						aux=printPassenger(list, len);
						MensajeAlerta(aux, "\nError al imprimir pasajeros.", "\nFin de la lista.");
					}
				}
				break;
			case 2:

					aux=InformarPromedio(list, len);
					MensajeAlerta(aux, "\nError al dar informe.", "\nFin del informe.");

				break;
			case 3:
				orden=PedirEnteroRangoValidacionReintentos ("\nIngrese orden(1 para ascendente | 2 para descendente): ", 1, 2, &orden);
				if(orden!= -1){
					aux=sortPassengersByCode(list, len, orden);
					if(aux!=-1){
					aux=printPassenger(list, len);
					MensajeAlerta(aux, "\nError al imprimir pasajeros.", "\nFin de la lista.");
					}
				}
				break;
			case 4:
				break;
		}
		}
	}
}
