/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Fausto Forcherio
 ============================================================================
 */

#include "control.h"

int main(void) {
	ePassenger lista[TAM]={{1, "Fausto", "Forcherio", 534.34, "AA53AA", 2, 3,1},{2, "Sofia", "Vega Buono", 600.45, "AB54BB", 3, 2,1},{3, "Sol", "Ovit", 123.54,"AC55CC", 1, 1,1},{4, "Tamara", "Sbarbaro", 890.56, "BC13DD", 1, 2,1},{5, "Paloma", "Romero", 1234.78, "DF66GH", 2, 3,1},{6, "Ignacio", "Vega Buono", 768.45, "AS22LK", 1, 3,1}};
	//ePassenger lista[TAM];
	int opcion;

	setbuf(stdout, NULL);
	//initEmployees(lista, TAM);
	do{
	printf("\n\tMENU\n"
			"1) Dar de alta a un pasajero.\n"
			"2) Modificar datos de un pasajero.\n"
			"3) Dar de baja a un pasajero.\n"
			"4) Informar.\n"
			"5) Salir.\n ");
	opcion=PedirEnteroValidacion ("Ingrese opción:");
	switch(opcion){
	case 1:
		opcionMenuUno(lista, TAM);
		break;
	case 2:
		opcionMenuDos(lista, TAM);
		break;
	case 3:
		opcionMenuTres(lista, TAM);
		break;
	case 4:
		opcionMenuCuatro(lista, TAM);
		break;
	case 5:
		printf("\nOFF.\n");
		return 0;
	default:
		printf("\nIngrese una opción válida.\n");
		break;
	}
	}while(opcion!=5);
}


/* ERRORES:
 *
 */
