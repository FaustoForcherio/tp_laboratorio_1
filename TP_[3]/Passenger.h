/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "parser.h"

#define ATERRIZADO 1
#define ENHORARIO 2
#define ENVUELO 3
#define DEMORADO 4

#define ECONOMYCLASS 1
#define EXECUTIVECLASS 2
#define FIRSTCLASS 3

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[50];
	int statusFlight;
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* priceStr,char* flyCodeStr,char* tipoPasajeroStr, char* statusFlightStr);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,int statusFlight);
int Passenger_getEstadoVuelo(Passenger* this,int* statusFlight);

/// @brief Transforma cualquiera de las 3 strings de tipo de pasajero predeterminado a su equivalente en entero
///	EconomyClass=1,ExecutiveClass=2,FirstClass=3
/// @param tipoPasajero
/// @return Retorna el entero que equivale a cualquiera de las 3 clases y -1 Si hay algun error.
int TipoPasajeroStrAInt(char tipoPasajero[]);

/// @brief Transforma cualquiera de los 3 enteros que se corresponde a cada tipo de pasajero predeterminado y guarda la string
/// correspondiente en una variable por puntero.
/// EconomyClass=1,ExecutiveClass=2,FirstClass=3
/// @param tipoPasajero
/// @param tipoPasajeroInt
void TipoPasajeroIntAStr(char* tipoPasajero, int tipoPasajeroInt);

/// @brief Imprime en consola los tipos de pasajeros que existen.
///
void printTipos(void);

/// @brief Transforma cualquiera de las 4 strings de los estados de vuelo a su correspondiente equivalente en numero
/// Aterrizado=1, En Horario=2, En Vuelo=3, Demorado=4
/// @param statusFlight
/// @return Retorna el entero correspondiente a cualquier estado de vuelo y retorna -1 en caso de error.
int EstadoVueloStrAInt(char statusFlight[]);

/// @brief Transforma un entero en string respecto a los estado de vuelos y lo guarda en una cadena.
///	Aterrizado=1, En Horario=2, En Vuelo=3, Demorado=4
/// @param statusFlight
/// @param statusFlightInt
void EstadoVueloIntAStr(char* statusFlight, int statusFlightInt);

/// @brief Imprime en consola los tipos de estado de vuelo que existen.
///
void printEstados(void);

//PRINT
int printUnPasajero(Passenger* this);
//MENU
Passenger* Add_Passenger(int iD);
int edit_Passenger(Passenger* this);
/// @brief Copia una estructura de passenger a otra
///
/// @param pPasajero
/// @param pPasajeroCopia
/// @return retorna -1 si hubo error y 0 si no hubo errores.
int copyPassenger(Passenger* pPasajero, Passenger* pPasajeroCopia);

//ID
int find_PassengerbyID(LinkedList* pArrayListEmployee, int idABuscar);

//SORT
int sort_Passengers(LinkedList* pArrayListPassenger);
int Sort_Nombre(void* elementoA, void* elementoB);
int Sort_Apellido(void* elementoA, void* elementoB);
int Sort_Id(void* elementoA, void* elementoB);
int Sort_Prices(void* elementoA, void* elementoB);


#endif /* PASSENGER_H_ */
