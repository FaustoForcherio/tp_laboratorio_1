#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger){
	int rtn;
	FILE* pFile;
	pFile=NULL;
	rtn=-1;

	if (path != NULL && pArrayListPassenger != NULL){
		pFile=fopen(path, "r");
		if(pFile != NULL){
			rtn=parser_PassengerFromText(pFile , pArrayListPassenger);
			fclose(pFile);
			if(rtn==0){
				printf("\nCarga exitosa de los datos.");
			}
		}
	}
	return rtn;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;
	int rtn;

	rtn=-1;
	if(path!=NULL&&pArrayListPassenger!=NULL){
		pFile = fopen(path,"rb");
		if(pFile==NULL&&path!=NULL){
			pFile=fopen(path,"wb");
			fclose(pFile);
		}
		if((pFile = fopen(path,"rb"))!= NULL){
			rtn  = parser_PassengerFromBinary(pFile, pArrayListPassenger);
			if(rtn==0){
				printf("\nCarga exitosa de los datos.");
			}
		}
		fclose(pFile);
	}

	return rtn;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int rtn;
	Passenger* unPasajero;
	int iD;
	int aux;
	aux=generadorID(&iD, "idGenerator.csv");
	rtn=-1;
	if(aux==0){
		unPasajero=Add_Passenger(iD);
		if(unPasajero!=NULL && pArrayListPassenger !=NULL){
			if(ll_add(pArrayListPassenger, unPasajero)==0){
				aux=ActualizarID(iD, "idGenerator.csv");

				if(aux==0){
					rtn=0;
				}
			}else{
				Passenger_delete(unPasajero);
			}
		}
	}
    return rtn;;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{	int rtn;
	int indice;
	int aux;
	int idBuscar;
	Passenger* unPasajero;
	rtn=-1;
	if(pArrayListPassenger!=NULL){
		aux=PedirEnteroValidacionReintentos ("\nIngrese el ID del pasajero que desea editar: ", &idBuscar);
		if(aux==0){
			indice=find_PassengerbyID(pArrayListPassenger, idBuscar);
			unPasajero=(Passenger*)ll_get(pArrayListPassenger, indice);
			if(unPasajero!=NULL){
				rtn=edit_Passenger(unPasajero);
			}
		}
	}
    return rtn;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int rtn;
	Passenger* pPasajeroABorrar;
	int idABorrar;
	int indiceABorrar;
	char confirmacion;
	int aux;
	rtn = -1;

	if (pArrayListPassenger != NULL && !ll_isEmpty(pArrayListPassenger)) {

		aux=PedirEnteroValidacionReintentos ("\nIngrese el ID del pasajero a borrar: ", &idABorrar);
		if(aux==0){
			indiceABorrar = find_PassengerbyID(pArrayListPassenger, idABorrar);
			if (indiceABorrar != -1) {

				pPasajeroABorrar = (Passenger*) ll_get(pArrayListPassenger, indiceABorrar);
				printUnPasajero(pPasajeroABorrar);
				confirmacion = ConfirmarSiNo("¿Está seguro que desea dar de baja al siguiente empleado?");

				if (confirmacion == 0) {
					aux=ll_remove(pArrayListPassenger, indiceABorrar);
					if(aux==0){
						Passenger_delete(pPasajeroABorrar);
						rtn = 0;
					}
				}
			}
		}
	}


    return rtn;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int rtn;
	int len;
	int i;
	Passenger* unPasajero;
	unPasajero=NULL;

	len=ll_len(pArrayListPassenger);
	rtn=-1;

	if(pArrayListPassenger!=NULL&&len>0){
		rtn=0;
		printf("\nID     NOMBRE\t       APELLIDO\t\tPRECIO\t    CODIGO VUELO\t ESTADO VUELO\t CLASE\n");
		for(i=0; i<len;i++){
			unPasajero= (Passenger*) ll_get(pArrayListPassenger, i);
			printUnPasajero(unPasajero);
		}
	}
    return rtn;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{	int rtn;
	rtn=-1;
	if(pArrayListPassenger!=NULL){
		rtn=sort_Passengers(pArrayListPassenger);
	}
    return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{	int rtn;
	FILE* pFile;
	rtn=-1;
	pFile=NULL;
	if(path!=NULL&&pArrayListPassenger!=NULL){
		pFile=fopen(path, "w");
		if(pFile!=NULL){
			rtn=saveAsText(pFile , pArrayListPassenger);
			fclose(pFile);
		}
	}
    return rtn;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger){
	int rtn;
	FILE* pFile;

	pFile=NULL;
	rtn=-1;
	pFile = fopen(path,"wb");
	   if(pFile != NULL){
		 rtn =  saveAsBinary(pFile, pArrayListPassenger);
	   }

return rtn;
}

