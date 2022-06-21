#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger){
	int rtn;
	char idStr[50];
	char nombreStr[50];
	char apellidoStr[50];
	char priceStr[50];
	char flyCodeStr[50];
	char tipoPasajeroStr[50];
	char statusFlightStr[50];
	Passenger* unPasajero;
	unPasajero=NULL;
	rtn=-1;
	if(pFile!=NULL && pArrayListPassenger!=NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,apellidoStr,priceStr,flyCodeStr,tipoPasajeroStr,statusFlightStr);
		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,nombreStr,apellidoStr,priceStr,flyCodeStr,tipoPasajeroStr,statusFlightStr);

			if(VerificarNumeroEntero(idStr)==0 && ValidarSoloLetras(nombreStr)==0 && ValidarSoloLetras(apellidoStr)==0 && VerificarNumeroFlotante(priceStr)==0 && ValidarLetrasNumeros(flyCodeStr)==0 && ValidarSoloLetras(tipoPasajeroStr)==0 && ValidarSoloLetras(statusFlightStr)==0){

				unPasajero=Passenger_newParametros(idStr,nombreStr,apellidoStr,priceStr,flyCodeStr,tipoPasajeroStr,statusFlightStr);
				if(unPasajero!=NULL){
					if(ll_add(pArrayListPassenger, unPasajero)!=-1){
						rtn=0;
					}else{
						Passenger_delete(unPasajero);
					}
				}
			}
		}

	}
    return rtn;
}

int saveAsText(FILE* pFile , LinkedList* pArrayListPassenger){
	int rtn;
	int len;
	int i;
	char tipoPasajeroStr[50];
	char statusFlightStr[50];

	rtn=-1;
	Passenger* pPasajero;
	pPasajero=NULL;
	len=ll_len(pArrayListPassenger);
	if(pFile!=NULL&&pArrayListPassenger!=NULL){
		fprintf(pFile,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(i=0;i<len;i++){
			pPasajero=(Passenger*)ll_get(pArrayListPassenger, i);
			TipoPasajeroIntAStr(tipoPasajeroStr, pPasajero->tipoPasajero);
			EstadoVueloIntAStr(statusFlightStr, pPasajero->statusFlight);
			fprintf(pFile,"%d,%s,%s,%f,%s,%s,%s\n",pPasajero->id,pPasajero->nombre,pPasajero->apellido,pPasajero->precio,pPasajero->codigoVuelo,tipoPasajeroStr,statusFlightStr);
			rtn=0;
		}
	}


	return rtn;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int rtn;
	Passenger* unPasajero;
	unPasajero=NULL;
	rtn = -1;
	if (pFile != NULL && pArrayListPassenger != NULL) {
		while (!feof(pFile)) {
			unPasajero = Passenger_new();
			if (unPasajero != NULL && fread(unPasajero, sizeof(Passenger), 1, pFile) == 1) {
				if (ll_add(pArrayListPassenger, unPasajero) != -1) {
					rtn = 0;
				}else{
					Passenger_delete(unPasajero);
				}
			}
		}
	}
    return rtn;
}

int saveAsBinary(FILE* pFile, LinkedList* pArrayListPassenger){
	int rtn;
	int len;
	Passenger* pPassenger;
	pPassenger= NULL;
	rtn=-1;
	len=ll_len(pArrayListPassenger);
	if(pArrayListPassenger != NULL&&pFile !=NULL){
		for(int i = 0; i<len; i++){
			pPassenger = ll_get(pArrayListPassenger,i);
			if(pPassenger !=NULL){
			fwrite(pPassenger,sizeof(Passenger),1,pFile);
			rtn = 0;
			}
		}
	}
	return rtn;
}

int generadorID(int* iD, char* path){
	int rtn;
	int mainID;
	int auxID;
	FILE* pFile;
	pFile=NULL;
	rtn=-1;
	mainID=1000;
	if(path!=NULL){

		if((pFile=fopen(path, "r"))==NULL)//Si no está creado el archivo, entra al IF
		{

			pFile=fopen(path, "w");
			if(pFile!=NULL){

			fprintf(pFile, "%d\n", mainID);
			fclose(pFile);
			}
		}

	pFile=fopen(path, "r");
	if(pFile!=NULL){

		fscanf(pFile, "%d", &auxID);
		rtn=0;
	}
	fclose(pFile);
	auxID++;
	*iD=auxID;
	}
	return rtn;
}

int ActualizarID(int iD, char* path){
	int rtn;
	FILE* pFile;
	rtn=-1;
if(path!=NULL){

	pFile=fopen(path, "w");
	if(pFile!=NULL){

	fprintf(pFile, "%d\n", iD);
	rtn=0;
	}
	fclose(pFile);
 }
	return rtn;
}

