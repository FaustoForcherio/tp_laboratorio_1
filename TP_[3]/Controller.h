#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "Passenger.h"
#include "LinkedList.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);

#endif

/*
 * Agregar Validaciones para que no se pueda ingresar a una opción sin cargar archivo o sin cargar pasajero antes.
 * Insertar mensajes de error.
 * Insertar SystemCls de ser necesario.
 */
