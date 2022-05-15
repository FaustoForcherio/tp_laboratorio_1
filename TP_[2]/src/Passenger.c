#include "Passenger.h"

static int iDIncPassenger=1000;
static int iDIncrementalPassenger();

static int iDIncrementalPassenger(){
	return iDIncPassenger++;
}

int findEmptySpot(ePassenger list[], int len){
	int rtn;
	int i;
	rtn=-1;
	 for(i=0;i<len;i++){
		 if(list[i].isEmpty==EMPTY){
		 rtn=0;
		 break;
		 }
	 }
	 return rtn;
}

int checkEmptyList(ePassenger list[], int len){
	int i;
	int check;
	check=-1;
	for(i=0;i<len;i++){
		if(list[i].isEmpty==LOAD){
			check=0;
		}
	}

	if(check==-1){
		printf("\nLa lista está vacía, ingrese un empleado primero.\n");
	}
	return check;
}

int initEmployees(ePassenger list[], int len){
	int rtn;
	int i;
	rtn=-1;
	if(len>=0){
		for(i=0;i<len;i++){
			list[i].isEmpty=EMPTY;
		}
		rtn=0;
	}
return rtn;
}

int addPassengers(ePassenger list[],int len){
	int rtn;
	int id;
	char nombre[51];
	char apellido[51];
	float precio;
	char codigo[10];
	int tipo;
	int estado;
	int opcion;
	do{
	//Pedir nombre
		rtn=PedirStringSoloLetras ("\nIngrese el nombre:", nombre);
		if(rtn==-1){
		break;
		}
	//Pedir apellido
		rtn=PedirStringSoloLetras ("\nIngrese el Apellido:", apellido);
		if(rtn==-1){
		break;
		}
	//Insertar precio flotante
		rtn=PedirFloatValidacionReintentos ("\nIngrese el precio del pasaje: ",&precio);
		if(rtn==-1){
			break;
		}
	//Pedir codigo de vuelo
		PedirStringSinRestricciones("\nIngrese el código del vuelo: ", codigo);
	//Seleccionar tipo de pasajero
		rtn=PedirEnteroRangoValidacionReintentos ("\n| 1- Primera clase"
				"\n| 2- Clase business"
				"\n| 3- Clase turista"
				"\nIngrese el numero del tipo de pasajero:", 1, 3, &tipo);
		if(rtn==-1){
		break;
		}
	//Seleccionar estado de vuelo
		rtn=PedirEnteroRangoValidacionReintentos ("\n| 1- Vuelo ACTIVO"
						"\n| 2- Vuelo DEMORADO"
						"\n| 3- Vuelo CANCELADO"
						"\nIngrese el numero del estado del vuelo:", 1, 3, &estado);
		if(rtn==-1){
		break;
		}
	//Ingresar ID
		id=iDIncrementalPassenger();


		rtn=addPassenger(list, len, id, nombre,apellido,precio, tipo , codigo, estado);

		if(rtn==-1){
			break;
		}
		else{
			rtn=0;
		}

		opcion=ConfirmarSiNo("\n¿Desea ingresar otro pasajero? (Ingrese 's' para SI / Ingrese 'n' para NO");
	}while(opcion==1);

	return rtn;
}

int addPassenger(ePassenger list[], int len, int id, char name[],char
lastname[],float price,int typePassenger, char flycode[], int flyStatus)
{
		int rtn;
		int i;
		rtn=-1;
		for(i=0;i<len;i++){
			if(list[i].isEmpty==EMPTY){
				list[i].id=id;
				strcpy(list[i].name, name);
				strcpy(list[i].lastname, lastname);
				list[i].price=price;
				strcpy(list[i].flycode, flycode);
				list[i].typePassenger=typePassenger;
				list[i].statusFlight=flyStatus;
				list[i].isEmpty=LOAD;
				rtn=0;
			}
		}
	 return rtn;
}

int findPassengerById(ePassenger list[], int len,int id){
	int i;
	int rtn;
	rtn=-1;
	for(i=0;i<len;i++){
		if(id==list[i].id&&list[i].isEmpty==LOAD){
			rtn=i;
			break;
		}
	}


	return rtn;
}


int editPassenger(ePassenger list[], int len){
		int rtn;
		int id;
		int indice;
		int opcion;
		char nombre[51];
		char apellido[51];
		float fnumero;
		int numero;
		rtn=0;
		rtn=PedirEnteroValidacionReintentos ("\nIngrese el ID del empleado que desea modificar:", &id);
		if(rtn==-1){
			return rtn;
		}
		indice=findPassengerById(list,len,id);
		if(indice!=0){
		printf("\tMENÚ DE MODIFICACIÓN\n"
				"1) Modificar nombre.\n"
				"2) Modificar apellido.\n"
				"3) Modificar precio.\n"
				"4) Modificar tipo de pasajero.\n"
				"5) Modificar código de vuelo.\n"
				"6) Salir.\n");
		rtn=PedirEnteroRangoValidacionReintentos ("\nIngrese opcion: ", 1, 6, &opcion);
		if(rtn==-1){
			return rtn;
		}
		switch(opcion){
		case 1:
			rtn=PedirStringSoloLetras ("\nIngrese el nuevo nombre: ", nombre);
			if(rtn==-1){
				return rtn;
			}
			strcpy(list[indice].name, nombre);
			break;
		case 2:
			rtn=PedirStringSoloLetras ("\nIngrese el nuevo apellido: ", apellido);
			if(rtn==-1){
				return rtn;
			}
			strcpy(list[indice].lastname, apellido);
			break;
		case 3:
			rtn=PedirFloatValidacionReintentos ("\nIngrese nuevo precio del pasaje: ", &fnumero);
			if(rtn==-1){
				return rtn;
			}
			list[indice].price=fnumero;
			break;
		case 4:
			rtn=PedirEnteroRangoValidacionReintentos ("\n| 1- Primera clase"
							"\n| 2- Clase business"
							"\n| 3- Clase turista"
							"\nIngrese el numero del tipo de pasajero:", 1, 3, &numero);
			if(rtn==-1){
				return rtn;
			}
			list[indice].typePassenger=numero;
			break;
		case 5:
			rtn=PedirEnteroRangoValidacionReintentos ("\n| 1- Vuelo ACTIVO"
									"\n| 2- Vuelo DEMORADO"
									"\n| 3- Vuelo CANCELADO"
									"\nIngrese el numero del estado del vuelo:", 1, 3, &numero);
			if(rtn==-1){
				return rtn;
			}
			list[indice].statusFlight=numero;
			break;
		case 6:
			rtn=0;
			break;
		default:
			printf("\nIngrese una opcion valida.\n");
			break;
			}
		}
		return rtn;
}



int removePassenger(ePassenger list[], int len)
{	int auxID;
	int pos;
	int rtn;
	int aux;
	aux=PedirEnteroValidacionReintentos ("\nIngrese el ID del pasajero a dar de baja:", &auxID);
		if(aux==-1){
			rtn=-1;
			return rtn;
		}
	pos=findPassengerById(list, len,auxID);
	if(pos!=-1){
	list[pos].isEmpty=EMPTY;
	rtn=0;
	}
	else{
		printf("No se ha encontrado el pasajero.");
		rtn=-1;
	}
 return rtn;
}

int sortPassengers(ePassenger list[], int len, int order){
	int flag;
	int rtn;
	rtn=-1;
	ePassenger aux;
	int i;
	int j;
	for(i=0;i<len-1;i++){
		for(j=i+ 1;j<len;j++){
			flag=0;
			if((strcmp(list[i].lastname, list[j].lastname)>0)){
				flag=1;

			}
			else if(strcmp(list[i].lastname, list[j].lastname)==0 && list[i].typePassenger>list[j].typePassenger){
				flag=1;

			}
			if(flag==order){

				aux=list[j];
				list[j]=list[i];
				list[i]=aux;

			}

		}
	}
	if(i==len-1&&j==len){
	rtn=0;
	}
 return rtn;
}

int printPassenger(ePassenger list[], int len){
	int rtn;
	rtn=-1;
	int i;

		printf("\n ID\t  VUELO\tAPELLIDO\tNOMBRE\t\t     PRECIO\tESTADO DE VUELO\t\tTIPO DE PASAJERO");
	for(i=0;i<len;i++){
		if(list[i].isEmpty==LOAD){
			printf("\n %d\t %s\t%-15s %-20s $%-8.2f", list[i].id ,list[i].flycode, list[i].lastname,list[i].name,list[i].price);


			if(list[i].statusFlight==ACTIVO){
				printf("\tACTIVO");
			}
			else if(list[i].statusFlight==DEMORADO){
				printf("\tDEMORADO");
			}
			else if(list[i].statusFlight==CANCELADO){
				printf("\tCANCELADO");
			}
			if(list[i].typePassenger==PRIMERA){
				printf("\t\tPRIMERA");
			}
			else if(list[i].typePassenger==BUSINESS){
				printf("\t\tBUSINESS");
			}
			else if(list[i].typePassenger==TURISTA){
				printf("\t\tTURISTA");
			}

			rtn=0;
		}
	}


	return rtn;
}


int sortPassengersByCode(ePassenger list[], int len, int order)
{
	int flag;
	int rtn;
	rtn=-1;
	ePassenger aux;
	int i;
	int j;
	for(i=0;i<len-1;i++){
		for(j=i+ 1;j<len;j++){
			flag=0;
			if((strcmp(list[i].flycode, list[j].flycode)>0)){
				flag=1;

			}
			else if(strcmp(list[i].flycode, list[j].flycode)==0 && list[i].statusFlight>list[j].statusFlight){
				flag=1;

			}
			if(flag==order){

				aux=list[j];
				list[j]=list[i];
				list[i]=aux;

			}


		}
	}
	if(i==len-1&&j==len){
	rtn=0;
	}
 return rtn;
}


int InformarPromedio(ePassenger list[], int len){
	int rtn;
	int i;
	int contadorPasajeros;
	float totalPrecios;
	float promedio;
	int contadorMayorAPromedio;
	rtn=-1;
	contadorPasajeros=0;
	contadorMayorAPromedio=0;
	if(len>=0){
		for(i=0;i<len;i++){
			if(list[i].isEmpty==LOAD){
				contadorPasajeros++;
				totalPrecios=totalPrecios+list[i].price;
			}
		}
	}
	promedio=totalPrecios/contadorPasajeros;
	for(i=0;i<len;i++){
		if(list[i].isEmpty==LOAD&&list[i].price>promedio){
			contadorMayorAPromedio++;
		}
	}
	if(contadorPasajeros>0){
		rtn=0;
		printf("\nEl total del precio de los pasajes es de $ %2.f", totalPrecios);
		printf("\nEl promedio del precio entre todos los pasajes es de $ %2.f", promedio);
		printf("\nLa cantidad de pasajeros que superan el promedio es %d\n", contadorMayorAPromedio);
	}

	return rtn;
}

