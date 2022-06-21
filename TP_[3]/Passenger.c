#include "Passenger.h"
//--------------------------------------------------------------Constructores-------------------------------------------------------------------------------------------------
Passenger* Passenger_new(){
	Passenger* pPasajero;
	pPasajero=NULL;
	pPasajero= (Passenger*)calloc(sizeof(Passenger),1);
	if(pPasajero==NULL){
		printf("\nError al reservar espacio de memoria.");
	}
	return pPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* priceStr,char* flyCodeStr,char* tipoPasajeroStr, char* statusFlightStr){
	Passenger* pPassenger;
	Passenger* pAuxPassenger;
	float precio;
	int id;
	int estadoVuelo;
	int tipoPasajero;
	pPassenger=NULL;
	pAuxPassenger = Passenger_new();

	if(pAuxPassenger!=NULL && idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && priceStr!=NULL && flyCodeStr!=NULL && tipoPasajeroStr!=NULL && statusFlightStr!=NULL){
		id=atoi(idStr);
		precio=atof(priceStr);
		tipoPasajero=TipoPasajeroStrAInt(tipoPasajeroStr);
		estadoVuelo=EstadoVueloStrAInt(statusFlightStr);

		if(Passenger_setId(pAuxPassenger,id)==0 &&
				Passenger_setNombre(pAuxPassenger,nombreStr)==0 &&
				Passenger_setApellido(pAuxPassenger,apellidoStr)==0 &&
				Passenger_setCodigoVuelo(pAuxPassenger,flyCodeStr)==0 &&
				Passenger_setTipoPasajero(pAuxPassenger, tipoPasajero)==0 &&
				Passenger_setPrecio(pAuxPassenger,precio)==0 &&
				Passenger_setEstadoVuelo(pAuxPassenger,estadoVuelo)==0){
					pPassenger=pAuxPassenger;
		}else{
			Passenger_delete(pAuxPassenger);
		}
	}
	return pPassenger;
}

//--------------------------------------------------------------Destructor-------------------------------------------------------------------------------

void Passenger_delete(Passenger* this){
	if(this!=NULL){
		free(this);
	}
}

//--------------------------------------------------------------Setters y Getters------------------------------------------------------------------------
int Passenger_setId(Passenger* this,int id){
	int rtn;
	rtn=-1;
	if (this!=NULL){
		this->id=id;
		rtn=0;
	}
	return rtn;

}
int Passenger_getId(Passenger* this,int* id){
	int rtn;
	rtn=-1;
	if(this!=NULL&&id!=NULL){
		*id=this->id;
		rtn=0;
	}
	return rtn;
}

int Passenger_setNombre(Passenger* this,char* nombre){
	int rtn;
	rtn=-1;
	if(this!=NULL&&nombre!=NULL){
		strcpy(this->nombre,nombre);
		rtn=0;
	}
	return rtn;
}
int Passenger_getNombre(Passenger* this,char* nombre){
	int rtn;
	rtn=-1;
	if(this!=NULL&&nombre!=NULL){
		strcpy(nombre,this->nombre);
		rtn=0;
	}
	return rtn;
}

int Passenger_setApellido(Passenger* this,char* apellido){
	int rtn;
	rtn=-1;
	if(this!=NULL&&apellido!=NULL){
		strcpy(this->apellido,apellido);
		rtn=0;
	}
	return rtn;
}
int Passenger_getApellido(Passenger* this,char* apellido){
	int rtn;
	rtn=-1;
	if(this!=NULL&&apellido!=NULL){
		strcpy(apellido,this->apellido);
		rtn=0;
	}
	return rtn;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int rtn;
	rtn=-1;
	if(this!=NULL && codigoVuelo!=NULL){
		strcpy(this->codigoVuelo,codigoVuelo);
		rtn=0;
	}
	return rtn;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int rtn;
	rtn=-1;
	if(this!=NULL && codigoVuelo!=NULL){
		strcpy(codigoVuelo,this->codigoVuelo);
		rtn=0;
	}
	return rtn;
}

int Passenger_setPrecio(Passenger* this,float precio){
	int rtn;
	rtn=-1;
	if(this!=NULL){
		this->precio=precio;
		rtn=0;
	}
	return rtn;
}
int Passenger_getPrecio(Passenger* this,float* precio){
	int rtn;
	rtn=-1;
	if(this!=NULL && precio!=NULL){
		*precio=this->precio;
		rtn=0;
	}
	return rtn;
}

int Passenger_setEstadoVuelo(Passenger* this,int statusFlight){
	int rtn;
	rtn=-1;
	if(this!=NULL){
	this->statusFlight=statusFlight;
	rtn=0;
	}
	return rtn;
}
int Passenger_getEstadoVuelo(Passenger* this,int* statusFlight){
	int rtn;
	rtn=-1;
	if(this!=NULL && statusFlight!=NULL){
		*statusFlight=this->statusFlight;
		rtn=0;
	}
	return rtn;
}


int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int rtn;
	rtn=-1;
	if(this!=NULL){
	this->tipoPasajero=tipoPasajero;
	rtn=0;
	}
	return rtn;

}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int rtn;
	rtn=-1;
	if(this!=NULL && tipoPasajero!=NULL){
		*tipoPasajero=this->tipoPasajero;
		rtn=0;
	}
	return rtn;
}

//---------------------------------------------------------------Aterrizado, En Horario, En Vuelo, Demorado--------------------------------------------------------------
int EstadoVueloStrAInt(char statusFlight[]){
	int rtn;
	if(strcmp(statusFlight,"Aterrizado")==0){
		rtn=1;
	}
	else if(strcmp(statusFlight,"En Horario")==0){
		rtn=2;
	}
	else if(strcmp(statusFlight, "En Vuelo")==0){
		rtn=3;
	}
	else if(strcmp(statusFlight, "Demorado")==0){
		rtn=4;
	}else{
		rtn=-1;
	}
	return rtn;
}

void EstadoVueloIntAStr(char* statusFlight, int statusFlightInt){
	if(statusFlightInt==1){
		strcpy(statusFlight,"Aterrizado");
	}
	else if(statusFlightInt==2){
		strcpy(statusFlight,"En Horario");
	}
	else if(statusFlightInt==3){
		strcpy(statusFlight,"En Vuelo");
	}
	else{
		strcpy(statusFlight,"Demorado");
	}
}

//--------------------------------------------------------------EconomyClass,ExecutiveClass,FirstClass--------------------------------------------------------------
int TipoPasajeroStrAInt(char tipoPasajero[]){
	int rtn;
	if(strcmp(tipoPasajero, "EconomyClass")==0){
		rtn=1;
	}
	else if(strcmp(tipoPasajero, "ExecutiveClass")==0){
		rtn=2;
	}
	else if(strcmp(tipoPasajero, "FirstClass")==0){
		rtn=3;
	}else{
		rtn=-1;
	}

	return rtn;
}

void TipoPasajeroIntAStr(char* tipoPasajero, int tipoPasajeroInt){
	if(tipoPasajeroInt==1){
		strcpy(tipoPasajero,"EconomyClass");
	}
	else if(tipoPasajeroInt==2){
		strcpy(tipoPasajero,"ExecutiveClass");
	}
	else{
		strcpy(tipoPasajero,"FirstClass");
	}
}


//--------------------------------------------------------------PRINTS-------------------------------------------------------------------------------------------------------
int printUnPasajero(Passenger* this){
	int rtn;

	float precio;
	int tipoPasajero;
	int statusFlight;
	char codigoVuelo[50];
	char apellido[50];
	char nombre[50];
	char statusFlightStr[50];
	char tipoPasajeroStr[50];
	int id;
	rtn=-1;

	Passenger_getEstadoVuelo(this,&statusFlight);
	Passenger_getPrecio(this,&precio);
	Passenger_getTipoPasajero(this,&tipoPasajero);
	Passenger_getCodigoVuelo(this,codigoVuelo);
	Passenger_getApellido(this,apellido);
	Passenger_getNombre(this,nombre);
	Passenger_getId(this,&id);

	TipoPasajeroIntAStr(tipoPasajeroStr, tipoPasajero);
	EstadoVueloIntAStr(statusFlightStr, statusFlight);

	if(this!=NULL){
		rtn=0;
		printf("%-6d %-15s %-15s $%-14.2f %-10s %-15s %-10s\n",	id,
															nombre,
															apellido,
															precio,
															codigoVuelo,
															statusFlightStr,
															tipoPasajeroStr);
	}
	return rtn;
}

void printTipos(){
	printf("\nLISTA DE TIPOS DE PASAJERO\n"
			"1) Clase economica.\n"
			"2) Clase ejecutiva.\n"
			"3) Primera clase.\n");
}

void printEstados(){
	printf("\nLISTA DE LOS ESTADOS DE VUELO\n"
			"1) Aterrizado.\n"
			"2) En Horario.\n"
			"3) En vuelo.\n"
			"4) Demorado.\n");

}
//--------------------------------------------------------------MENU----------------------------------------------------------------------------------------------------------
Passenger* Add_Passenger(int iD){
	Passenger* unPasajero;
	char idStr[50];
	char nombre[50];
	char apellido[50];
	float precio;
	char precioStr[50];
	int tipoPasajero;
	char tipoPasajeroStr[50];
	char codigoVuelo[50];
	int statusFlight;
	char statusFlightStr[50];
	int aux;

	aux=PedirStringSoloLetras("\nIngrese nombre:", nombre);
	if(aux==0){
		aux=PedirStringSoloLetras("\nIngrese apellido:", apellido);
		if(aux==0){
			aux=PedirStringNumerosLetras("\nIngrese código de vuelo: ", codigoVuelo);
			if(aux==0){
				printTipos();
				aux=PedirEnteroRangoValidacionReintentos ("\nIngrese la opción de pasajero: ", 1, 3, &tipoPasajero);
				if(aux==0){
					aux=PedirFloatValidacionReintentos ("\nIngrese el precio: ",&precio);
					if(aux==0){
						printEstados();
						aux=PedirEnteroRangoValidacionReintentos ("\nIngrese la opción de estado: ", 1, 4, &statusFlight);
						if(aux==0){
							itoa(iD, idStr, 10);
							itoa(precio,precioStr,10);
							TipoPasajeroIntAStr(tipoPasajeroStr, tipoPasajero);
							EstadoVueloIntAStr(statusFlightStr, statusFlight);
							unPasajero=Passenger_newParametros(idStr,nombre,apellido,precioStr,codigoVuelo,tipoPasajeroStr, statusFlightStr);
						}
					}
				}
			}
		}
	}

	return unPasajero;
}


int find_PassengerbyID(LinkedList* pArraylistPassenger, int idABuscar) {
    int rtn;
    int auxId;
    int len;

    Passenger* pPasajero;
    len = ll_len(pArraylistPassenger);
    rtn = -1;

    for(int i = 0; i < len; i++){
    	pPasajero = (Passenger*) ll_get(pArraylistPassenger, i);
        if(!Passenger_getId(pPasajero, &auxId) && auxId == idABuscar){
            rtn = i;
            break;
        }
    }
    if(rtn==-1){
    	printf("\nNo se encontró un pasajero con ese ID.");
    }
    return rtn;
}

int copyPassenger(Passenger* pPasajero, Passenger* pPasajeroCopia){
	int rtn;

	rtn = -1;

	if (pPasajero != NULL && pPasajeroCopia != NULL && Passenger_setId(pPasajero,pPasajeroCopia->id)==0 &&
							Passenger_setNombre(pPasajero,pPasajeroCopia->nombre)==0 &&
							Passenger_setApellido(pPasajero,pPasajeroCopia->apellido)==0 &&
							Passenger_setCodigoVuelo(pPasajero,pPasajeroCopia->codigoVuelo)==0 &&
							Passenger_setTipoPasajero(pPasajero, pPasajeroCopia->tipoPasajero)==0 &&
							Passenger_setPrecio(pPasajero,pPasajeroCopia->precio)==0 &&
							Passenger_setEstadoVuelo(pPasajero,pPasajeroCopia->statusFlight)==0) {
		rtn = 0;
	}

	return rtn;
}


int edit_Passenger(Passenger* this){
	int rtn;
	int opcion;
	int aux;
	Passenger* auxPasajero;
	char nombre[50];
	int flag;
	char apellido[50];
	float precio;
	char codigoVuelo;
	int tipo;
	char tipoPasajeroStr[50];
	int estadoVuelo;
	char statusFlightStr[50];
	flag=1;
	if(this!=NULL){
		auxPasajero=Passenger_new();
		aux=copyPassenger(auxPasajero, this);
		if(aux==0){
			do{
				printf("\nMENU DE MODIFICACIONES"
						"\n1) Nombre."
						"\n2) Apellido."
						"\n3) Precio."
						"\n4) Codigo de vuelo."
						"\n5) Clase del pasajero."
						"\n6) Estado del vuelo."
						"\n7) Salir.");
				opcion=PedirEnteroRangoValidacion ("\nInserte la opción: ", 1, 7);

				switch(opcion){
				case 1:
					aux=PedirStringSoloLetras ("\nIngrese nombre: ", nombre);
					if(aux==0){
						aux=Passenger_setNombre(auxPasajero,nombre);
						if(aux==0){
							flag=0;
						}
					}
					break;
				case 2:
					aux=PedirStringSoloLetras ("\nIngrese apellido: ", apellido);
					if(aux==0){
						aux=Passenger_setApellido(auxPasajero,apellido);
						if(aux==0){
							flag=0;
						}
					}
					break;
				case 3:
					aux=PedirFloatValidacionReintentos ("\nIngrese precio:",&precio);
					if(aux==0){
						aux=Passenger_setPrecio(auxPasajero,precio);
						if(aux==0){
							flag=0;
						}
					}
					break;
				case 4:
					aux=PedirStringNumerosLetras ("\nIngrese codigo de vuelo: ", &codigoVuelo);
					if(aux==0){
						aux=Passenger_setCodigoVuelo(auxPasajero, &codigoVuelo);
						if(aux==0){
							flag=0;
						}
					}
					break;
				case 5:
					printTipos();
					aux=PedirEnteroRangoValidacionReintentos ("\nIngrese opcion de tipo de pasajero: ", 1, 3, &tipo);
					if(aux==0){
						aux=Passenger_setTipoPasajero(auxPasajero, tipo);
						if(aux==0){
							flag=0;
						}
					}
					break;
				case 6:
					printEstados();
					aux=PedirEnteroRangoValidacionReintentos ("\nIngrese opcion de estado de vuelo: ", 1, 4, &estadoVuelo);
					if(aux==0){
						aux=Passenger_setEstadoVuelo(auxPasajero,estadoVuelo);
						if(aux==0){
							flag=0;
						}
					}
					break;
				case 7:
					if(flag==0){
						TipoPasajeroIntAStr(tipoPasajeroStr, this->tipoPasajero);
						EstadoVueloIntAStr(statusFlightStr, this->statusFlight);
						printf("\nID     NOMBRE\t       APELLIDO\t\tPRECIO\t   CODIGO VUELO\t ESTADO VUELO\t CLASE\n");
						printf("Antiguos datos del pasajero: ");
						printf("\n%-6d %-15s %-15s $%-14.2f %-10s %-15s %-10s\n",	this->id,
																					this->nombre,
																					this->apellido,
																					this->precio,
																					this->codigoVuelo,
																					statusFlightStr,
																					tipoPasajeroStr);

						TipoPasajeroIntAStr(tipoPasajeroStr, auxPasajero->tipoPasajero);
						EstadoVueloIntAStr(statusFlightStr, auxPasajero->statusFlight);
						printf("Nuevos datos del pasajero:");
						printf("\n%-6d %-15s %-15s $%-14.2f %-10s %-15s %-10s\n",	auxPasajero->id,
																					auxPasajero->nombre,
																					auxPasajero->apellido,
																					auxPasajero->precio,
																					auxPasajero->codigoVuelo,
																					statusFlightStr,
																					tipoPasajeroStr);

						aux=ConfirmarSiNo("\n¿Desea confirmar los cambios?");
						if(aux==0){
							copyPassenger(this, auxPasajero);
							printf("\nDatos guardados.");
						}else{
							printf("\nDatos no guardados.");
						}
							rtn=0;
					}
					printf("\nDevuelta al menú.\n");
					Passenger_delete(auxPasajero);
					break;

				}
			}while(opcion!=7);
		}
	}
	return rtn;
}

int sort_Passengers(LinkedList* pArrayListPassenger){
	int rtn;
	int opcion;
	int aux;
	rtn=-1;


		printf("\nMENU DE ORDENAMIENTO"
				"\n1) Ordenar por ID."
				"\n2) Ordenar por nombre."
				"\n3) Ordenar por apellido."
				"\n4) Ordenar por precio."
				"\n5) Salir.");
		aux=PedirEnteroRangoValidacionReintentos ("\nIngresar opcion: ", 1, 5, &opcion);
		if(aux==0){
			switch(opcion){
				case 1:
					aux=PedirEnteroRangoValidacionReintentos ("\nOPCIONES DE MODO:"
																"\n1) Ascendente."
																"\n0) Descendente."
																"\nIngrese modo de ordenar: ", 0, 1,&opcion);
					if(aux==0){
						ll_sort(pArrayListPassenger, Sort_Id, opcion);
						rtn=0;
					}
					break;
				case 2:
					aux=PedirEnteroRangoValidacionReintentos ("\nOPCIONES DE MODO:"
																"\n1) Ascendente."
																"\n0) Descendente."
																"\nIngrese modo de ordenar: ", 0, 1,&opcion);
					if(aux==0){
						ll_sort(pArrayListPassenger, Sort_Nombre, opcion);
						rtn=0;
					}
					break;
				case 3:
					aux=PedirEnteroRangoValidacionReintentos ("\nOPCIONES DE MODO:"
																"\n1) Ascendente."
																"\n0) Descendente."
																"\nIngrese modo de ordenar: ", 0, 1,&opcion);
					if(aux==0){
						ll_sort(pArrayListPassenger, Sort_Apellido, opcion);
						rtn=0;
					}
					break;
				case 4:
					aux=PedirEnteroRangoValidacionReintentos ("\nOPCIONES DE MODO:"
															"\n1) Ascendente."
															"\n0) Descendente."
															"\nIngrese modo de ordenar: ", 0, 1,&opcion);
					if(aux==0){
						ll_sort(pArrayListPassenger, Sort_Prices, opcion);
						rtn=0;
					}
					break;
				case 5:
					rtn=0;
					break;
			}
		}else{
			printf("\nError al superar maximo de intentos.");
		}

	return rtn;
}

//--------------------------------------------------------------SORTS--------------------------------------------------------------------------------------------------------
int Sort_Nombre(void* elementoA, void* elementoB){
	char auxA[50];
	char auxB[50];
	int rtn;

	Passenger_getNombre(elementoA, auxA);
	Passenger_getNombre(elementoB, auxB);
	rtn = strcmp(auxA,auxB);

	return rtn;
}
int Sort_Apellido(void* elementoA, void* elementoB){
	char auxA[50];
	char auxB[50];
	int rtn;

	Passenger_getApellido(elementoA, auxA);
	Passenger_getApellido(elementoB, auxB);
	rtn = strcmp(auxA,auxB);

	return rtn;
}

int Sort_Id(void* elementoA, void* elementoB){
	int rtn;
	int auxA;
	int auxB;
	Passenger_getId(elementoA, &auxA);
	Passenger_getId(elementoB, &auxB);
	if(auxA > auxB){
		rtn = 1;
	}else if(auxA < auxB){
		rtn = -1;
	}else{
		rtn = 0;
	}
	return rtn;
}

int Sort_Prices(void* elementoA, void* elementoB){
	int rtn;
	float auxA;
	float auxB;

	Passenger_getPrecio(elementoA, &auxA);
	Passenger_getPrecio(elementoB, &auxB);

	if(auxA > auxB){
		rtn = 1;
	}else if(auxA < auxB){
		rtn = -1;
	}else{
		rtn = 0;
	}

	return rtn;
}








