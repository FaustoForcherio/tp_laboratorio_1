
#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
#include "input.h"
#include "Passenger.h"

int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);

/// @brief Funcion que guarda los datos de la linkedlist en un archivo de texto .csv
///
/// @param pFile
/// @param pArrayListPassenger
/// @return Retorna -1 si no se pudo guardar correctamente, y 0 si se pudo guardar correctamente
int saveAsText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

/// @brief funcion que guarda los datos de la linkedlist en un archivo binario .bin
///
/// @param pFile
/// @param pArrayListPassenger
/// @return retorna -1 si no se pudo guardar correctamente y 0 si se pudo guardar correctamente
int saveAsBinary(FILE* pFile, LinkedList* pArrayListPassenger);

/// @brief Genera un archivo .csv (en caso de que no exista) y guarda el ultimo ID que se uso y lo incrementa para implementarlo.
///
/// @param iD
/// @param path
/// @return Retorna -1 si hubo un error al generar el archivo o al incrementar el id. Retorna 0 si no hubo errores.
int generadorID(int* iD, char* path);

/// @brief Actualiza el archivo .csv que contiene el maximo ID con el ultimo que se implemento.
///
/// @param iD
/// @param path
/// @return retorna -1 si hubo errores y 0 si no hubo errores.
int ActualizarID(int iD, char* path);
#endif
