/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

#include "Controller.h"
#include "LinkedList.h"
#include "Input.h"
#include "Passenger.h"
#include "parser.h"
int main()
{
    setbuf(stdout, NULL);
    int option;
    int flagCambios=0;
    int flagCarga=0;
    int aux;
    int aux2;
    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	printf("\n\nMenu:\n"
    			"1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
    			"2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
    			"3. Alta de pasajero\n"
    			"4. Modificar datos de pasajero\n"
    			"5. Baja de pasajero\n"
    			"6. Listar pasajeros\n"
    			"7. Ordenar pasajeros\n"
    			"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n"
    			"9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
    			"10. Salir\n");
    	option=PedirEnteroRangoValidacion ("\nInserte opción: ",1,10);
        switch(option){
            case 1:
            	if(flagCarga==0){
            		aux=controller_loadFromText("data.csv",listaPasajeros);
            		if(aux==0){
            			flagCarga=1;
            		}else{
            			printf("\nNo se pudieron cargar los datos");
            		}
            	}else{
            		printf("\nYa se cargaron los datos anteriormente.\n");
            	}
                break;
            case 2:
            	if(flagCarga==0){
            		aux=controller_loadFromBinary("data.bin" , listaPasajeros);
            		if(aux==0){
            			flagCarga=1;
            		}else{
            			printf("\nNo se pudieron cargar los datos");
            		}
            	}else{
            		printf("\nYa se cargaron los datos anteriormente.\n");
            	}
                break;
            case 3:
            	if(flagCarga==1){
            		aux=controller_addPassenger(listaPasajeros);
        			if(aux==0){
        				flagCambios=1;
        				printf("\nPasajero dado de alta.");
        			}else{
        				printf("Error al dar de alta el pasajero.");
        			}
            	}else{
            			printf("\nSe requiere cargar los archivos con los datos primero.");
            	}
                break;
            case 4:
            	aux=ll_isEmpty(listaPasajeros);
            	if(aux==0){
            		aux=controller_editPassenger(listaPasajeros);
            		if(aux==0){
            			flagCambios=1;
            			printf("\nSe se ha modificado el pasajero con exito.");
            		}else{
            			printf("\nNo se modificó el pasajero.");
            		}
            	}else{
            		printf("\nLa lista está vacía, cargue un pasajero antes.");
            	}
                break;
            case 5:
            	aux=ll_isEmpty(listaPasajeros);
            	if(aux==0){
            		aux=controller_removePassenger(listaPasajeros);
            		if(aux==0){
            			flagCambios=1;
            			printf("\nSe removió el pasajero con exito.");
            		}else{
            			printf("\nNo se ha podido remover el Pasajero.");
            		}
            	}else{
            		printf("\nLa lista está vacía, cargue un pasajero antes.");
            	}
                break;
            case 6:
            	aux=ll_isEmpty(listaPasajeros);
            	if(aux==0){
            	controller_ListPassenger(listaPasajeros);
            	}else{
            		printf("\nLa lista está vacía, cargue un pasajero antes.");
            	}
                break;
            case 7:
            	aux=ll_isEmpty(listaPasajeros);
            	if(aux==0){
            		aux=controller_sortPassenger(listaPasajeros);
        			if(aux==0){
        				flagCambios=1;
        				printf("\nLa lista se ordenó correctamente.");
        			}else{
        				printf("\nNo se pudo ordenar la lista");
        			}
            	}else{
            		printf("\nLa lista está vacía, cargue un pasajero antes.");
            	}
                break;
            case 8:
            	if(flagCambios==1&&flagCarga==1){
            		aux=controller_saveAsText("data.csv", listaPasajeros);
            		aux2=controller_saveAsBinary("data.bin" , listaPasajeros);
            		if(aux==0&&aux2==0){
            			flagCambios=0;
            			printf("\nDatos Guardados");
            		}else{
            			printf("\nError al guardar los datos.");
            		}
            	}else{
            		if(flagCambios==0){
            			printf("\nNo hay cambios para guardar.");
            		}else{
            			printf("\nSe requiere cargar los archivos con los datos primero.");
            		}
            	}
                break;
            case 9:
            	if(flagCambios==1&&flagCarga==1){
            		aux=controller_saveAsBinary("data.bin" , listaPasajeros);
            		aux2=controller_saveAsText("data.csv", listaPasajeros);
            		if(aux==0&&aux2==0){
            			flagCambios=0;
            			printf("\nDatos Guardados");
            		}else{
            			printf("\nError al guardar los datos.");
            		}
            	}else{
            		if(flagCambios==0){
            			printf("\nNo hay cambios para guardar.");
            		}else{
            			printf("\nSe requiere cargar los archivos con los datos primero.");
            		}
            	}
                break;
            case 10:
            	if(flagCambios==0){
            	printf("\nOFF.\n");
            	ll_deleteLinkedList(listaPasajeros);
            	option=11;
            	}else{
            		aux=ConfirmarSiNo("\n No se guardaron los datos. ¿Desea continuar?");
            		if(aux==0){
                    	printf("\nOFF.\n");
                    	ll_deleteLinkedList(listaPasajeros);
            			option=11;
            		}else{
            			printf("\nError. Volviendo al menú.");
            		}
            	}
            	break;
        }
    }while(option != 11);
    return 0;
}

/*
 * COSAS QUE FALTAN:
 * Documentar (en .h y solamente brief)
*/

