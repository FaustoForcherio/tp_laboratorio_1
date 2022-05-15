
#ifndef PASSENGER_H_
#define PASSENGER_H_

#include "input.h"
#define PRIMERA 1
#define BUSINESS 2
#define TURISTA 3

#define ACTIVO 1
#define DEMORADO 2
#define CANCELADO 3

#define LOAD 1
#define EMPTY 0

#define TAM 2000

typedef struct{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
} ePassenger;


int checkEmptyList(ePassenger list[], int len);
int initEmployees(ePassenger list[], int len);
int findEmptySpot(ePassenger list[], int len);
int addPassengers(ePassenger list[],int len);
int addPassenger(ePassenger list[], int len, int id, char name[],char lastname[],float price,int typePassenger, char flycode[], int flyStatus);
int findPassengerById(ePassenger list[], int len,int id);
int removePassenger(ePassenger list[], int len);
int editPassenger(ePassenger list[], int len);
int sortPassengers(ePassenger list[], int len, int order);
int printPassenger(ePassenger list[], int len);
int InformarPromedio(ePassenger list[], int len);
int sortPassengersByCode(ePassenger list[], int len, int order);
#endif /* PASSENGER_H_ */
