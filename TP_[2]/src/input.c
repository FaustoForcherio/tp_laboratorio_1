#include "input.h"

/// @fn int VerificarNumeroEntero(char[])
/// @brief Chequear que el string que recibe no contenga letras y que no esté vacío
/// @param numero
/// @return retorna 1 en caso de error y 0 si sale bien
int VerificarNumeroEntero(char numero[]){
	int i;
	int retorno=0;
	if(numero[0]=='\n'||numero[0]=='\0'){
				retorno=1;
		}
	for(i=0;i<strlen(numero);i++){
		if(!(isdigit(numero[i]))){
			retorno=1;
		}
	}
 return retorno;
}
/// @fn int PedirEnteroValidacion(char[])
/// @brief Pide un numero entero y lo deriva a la funcion que lo valida
/// @param mensaje string para especificar que se debe insertar
/// @return el numero transformado en entero
int PedirEnteroValidacion (char mensaje[])
{
    char numeroIngresado[20];
    int num;
    printf("%s", mensaje);
    CleanBuff;
    scanf("%[^\n]",numeroIngresado);
    while(VerificarNumeroEntero(numeroIngresado)){

    		 printf("%s", mensaje);
    		 CleanBuff;
    		 scanf("%[^\n]",numeroIngresado);
    	 }
    num=atoi(numeroIngresado);
    return num;
}
/// @fn int PedirEnteroValidacionReintentos(char[], int*)
/// @brief Pide una cadena, la deriva a una funcion que la valida y devuelve el valor, transformado en entero a la direccion de memoria  pedida
/// @param mensaje mensaje string para especificar que se debe insertar
/// @param numero. Puntero de una variable a la que se le asigna el numero que se ingresa
/// @return retorna 1 en caso de error y 0 si no hay error
int PedirEnteroValidacionReintentos (char mensaje[],int* numero)
{
    char numeroIngresado[20];
    int rtn;
    int i=0;
    rtn=0;
    printf("%s", mensaje);
    CleanBuff;
    scanf("%[^\n]",numeroIngresado);
    while(VerificarNumeroEntero(numeroIngresado)){
    	i++;
    	printf("%s", mensaje);
    	CleanBuff;
    	scanf("%[^\n]",numeroIngresado);
    	if(i==2){
    		rtn=-1;
    		break;
    	}
    }
    	*numero=atoi(numeroIngresado);
    return rtn;
}
/// @fn int PedirEnteroRangoValidacion(char[], int, int)
/// @brief Pide una cadena, la valida y la devuelve como entero
/// @param mensaje mensaje string para especificar que se debe insertar
/// @param minimo limite minimo que se puede ingresar
/// @param maximo limite maximo que se puede ingresar
/// @return el numero validado
int PedirEnteroRangoValidacion(char mensaje[],int minimo, int maximo){
	char cNum[20];
	int num;
	printf("%s", mensaje);
	CleanBuff;
	scanf("%[^\n]",cNum);
	while(VerificarNumeroEntero(cNum)||minimo>atoi(cNum)||maximo<atoi(cNum)){
		 printf("%s", mensaje);
		 CleanBuff;
		 scanf("%[^\n]",cNum);
	 }
	num=atoi(cNum);

	return num;
}
/// @fn int PedirEnteroRangoValidacionReintentos(char[], int, int, int*)
/// @brief Recibe parametros que determinan que se tiene que ingresar como cadena y devuelve lo ingresado como Entero validado
/// @param mensaje mensaje string para especificar que se debe insertar
/// @param minimo limite minimo que se puede ingresar
/// @param maximo limite maximo que se puede ingresar
/// @param numero
/// @return retorna 1 en caso de error y 0 si no hay error
int PedirEnteroRangoValidacionReintentos(char mensaje[],int minimo, int maximo, int* numero){
	char cNum[20];
	int rtn;
	int i;
	i=0;
	rtn=0;
	printf("%s", mensaje);
	CleanBuff;
	scanf("%[^\n]",cNum);
	while(VerificarNumeroEntero(cNum)||minimo>atoi(cNum)||maximo<atoi(cNum)){
		 i++;
		 printf("%s", mensaje);
		 CleanBuff;
		 scanf("%[^\n]",cNum);
		 if(i==2){
		     		rtn=-1;
		     		break;
		  }
	 }
	*numero=atoi(cNum);

	return rtn;
}


/// @fn int VerificarNumeroFlotante(char[])
/// @brief Chequear que el string que recibe no contenga letras y que no esté vacío
/// @param numero
/// @return retorna 1 en caso de error y 0 si sale bien
int VerificarNumeroFlotante(char numero[]){
	int retorno;
	int i;
	int flag=0;
	retorno=1;
	if(numero[0]=='\n'||numero[0]=='\0'){
					retorno=1;
			}
	if(isdigit(numero[0])){
		retorno=0;
		for(i=0;i<strlen(numero);i++){
			if(numero[i]=='.'&&flag==0){
				flag=1;
			}
			else if(!isdigit(numero[i])){
				retorno=1;
				break;
			}

		}

	}


 return retorno;
}
/// @fn float PedirFloatValidacion(char[])
/// @brief Pide una cadena y la valida con una funcion para que la devuelva como flotante
/// @param mensaje especifica lo que se tiene que ingresar
/// @return Retorna la cadena como un flotante
float PedirFloatValidacion (char mensaje[])
{
    char numeroIngresado[20];
    float numeroflotante;
    printf("%s \n", mensaje);
    CleanBuff;
    scanf("%[^\n]",numeroIngresado);
    while(VerificarNumeroFlotante(numeroIngresado)){

        		 printf("%s", mensaje);
        		 CleanBuff;
        		 scanf("%[^\n]",numeroIngresado);
        	 }
    numeroflotante=atof(numeroIngresado);
    return numeroflotante;
}
/// @fn int PedirFloatValidacionReintentos(char[], float*)
/// @brief Pide una cadena, valida que sea numero flotante, la pasa a numero flotante y corta si no se ingreso despues de 3 intentos
/// @param mensaje especifica que se tiene que ingresar
/// @param numero la direccion de memoria donde se guarda el numero
/// @return retorna 1 en caso de error y 0 si sale bien
int PedirFloatValidacionReintentos (char mensaje[], float* numero)
{
    char numeroIngresado[20];
    int rtn;
    int i=0;
    rtn=0;
    printf("%s \n", mensaje);
    CleanBuff;
    scanf("%[^\n]",numeroIngresado);
    while(VerificarNumeroFlotante(numeroIngresado)){
    	i++;
    	    	printf("%s", mensaje);
    	    	CleanBuff;
    	    	scanf("%[^\n]",numeroIngresado);
    	    	if(i==2){
    	    		rtn=-1;
    	    		break;
    	    	}
    	    }
    	   *numero=atof(numeroIngresado);
    return rtn;
}
/// @fn float PedirFloatRangoValidacion(char[], int, int)
/// @brief Pide una cadena, valida que sea numero flotante y la pasa a numero flotante
/// @param mensaje especifica que se tiene que ingresar
/// @param minimo limite minimo que se puede ingresar
/// @param maximo limite maximo que se puede ingresar
/// @return retorna la cadena transformada como numero floante
float PedirFloatRangoValidacion (char mensaje[],int minimo, int maximo)
{
		char cNum[20];
		float num;
		printf("%s", mensaje);
		CleanBuff;
		scanf("%[^\n]",cNum);
		while(VerificarNumeroEntero(cNum)||minimo>atof(cNum)||maximo<atof(cNum)){
			 printf("%s", mensaje);
			 CleanBuff;
			 scanf("%[^\n]",cNum);
		 }
		num=atof(cNum);

    return num;
}
/// @fn int PedirFloatRangoValidacionReintentos(char[], int, int, float*)
/// @brief Pide una cadena(Luego la transforma a flotante), valida que este dentro del rango, que sea flotante y limita los intentos a 3.
/// @param mensaje especifica que se tiene que ingresar
/// @param minimo limite minimo que se puede ingresar
/// @param maximo limite maximo que se puede ingresar
/// @param numero direccion de memoria donde se guarda el numero flotante
/// @return retorna 1 en caso de error y 0 si sale bien
int PedirFloatRangoValidacionReintentos (char mensaje[],int minimo, int maximo, float* numero)
{
		char cNum[20];
		int rtn;
		int i;
		i=0;
		rtn=0;
		printf("%s", mensaje);
		CleanBuff;
		scanf("%[^\n]",cNum);
		while(VerificarNumeroEntero(cNum)||minimo>atof(cNum)||maximo<atof(cNum)){
			i++;
			 printf("%s", mensaje);
			 CleanBuff;
			 scanf("%[^\n]",cNum);
			 if(i==2){
				 rtn=1;
				 break;
			 }

		 }
		*numero=atof(cNum);

    return rtn;
}
/// @fn void MostrarIDgenerado(int, int*)
/// @brief printea un id si es que se genero uno
/// @param estado
/// @param idGenerado Muestra el id generado
void MostrarIDgenerado(int estado, int* idGenerado){
	if(estado==1){
		printf("\nID generado: %d", *idGenerado-1);
	}
}

//STRINGs
/// @fn int ValidarSoloLetras(char[])
/// @brief Comprueba que el string no esté vacio y que solo contenga letras
/// @param palabra string que recibe
/// @return retorna 1 si hay error y 0 si no lo hay
int ValidarSoloLetras(char palabra[]){
	int i;
	int retorno=0;
	if(palabra[0]=='\n'||palabra[0]=='\0'){
			retorno=1;
	}
	for(i=0;i<(strlen(palabra));i++){
		if(!(isalpha(palabra[i]))){
			retorno=1;
		}
	}
 return retorno;
}

/// @fn int PedirStringSoloLetras(char[], char[])
/// @brief Pide una string de letras que se guarda en una variable y se valida con una funcion, al final se usa otra funcion para corregir.
/// @param mensaje especfica que se va a ingresar
/// @param stringIngresado array donde se va a guardar lo que se ingresa
/// @return retorna 1 en caso de error y 0 si no lo hubo
int PedirStringSoloLetras (char mensaje[], char stringIngresado[])
{
	int rtn;
	int i=0;
	rtn=1;
    printf("%s \n", mensaje);
    CleanBuff;
    scanf("%[^\n]", stringIngresado);
    while(ValidarSoloLetras(stringIngresado)){
    	i++;
    		printf("%s \n", mensaje);
    	    CleanBuff;
    	    scanf("%[^\n]", stringIngresado);
    	    if(i==2){
    	    	rtn=1;
    	    	return rtn;
    	    }
    }
    EmprolijarString(stringIngresado);
    rtn=0;
   return rtn;
}
/// @fn void MensajeAlerta(int, char[], char[])
/// @brief Recibe 2 mensajes que se ejectuan dependiendo de una variable numerica.
/// @param num valor recibido de una funcion
/// @param mensajeA Mensaje que recibe si hubo error
/// @param mensajeB Mensaje que recibe si no hubo error
void MensajeAlerta(int num, char mensajeERROR[], char mensajeB[]){
    char enter;
    if(num==-1){
        printf("%s\n",mensajeERROR);
    } else{
        printf("%s\n",mensajeB);
    }
    printf("Presione cualquier tecla para continuar.");
    CleanBuff;
    scanf("%c", &enter);

    printf("\n");

}
/// @fn void EmprolijarString(char[])
/// @brief Recibe una cadena de solo letras y transforma la primer letra en mayuscula y las siguientes en minuscula
/// @param palabra string que recibe
void EmprolijarString(char palabra[]){
	int i;

    palabra[0]=toupper(palabra[0]);
	for(i=1;i<strlen(palabra)&&palabra[i]!='\0';i++){
		palabra[i]=tolower(palabra[i]);
	}
}

void PedirStringSinRestricciones(char mensaje[], char stringIngresado[]){
	    printf("%s \n", mensaje);
	    CleanBuff;
	    scanf("%[^\n]", stringIngresado);
}
int ConfirmarSiNo(char mensaje[]){
	int contadorIntentos=0;
	int rtn;
	char opcion;
	rtn=-1;
		printf("%s \n", mensaje);
		printf("Ponga 's' para Si/Ponga 'n' para no\n");
		CleanBuff;
		scanf("%c", &opcion);
		opcion=tolower(opcion);
		while(opcion != 's' && opcion != 'n'){
			 contadorIntentos++;
			if(contadorIntentos==3){
			 	break;
			}
			printf("%s \n", mensaje);
			printf("Ponga 's' para Si/Ponga 'n' para no\n");
			CleanBuff;
			scanf("%c", &opcion);
			opcion=tolower(opcion);

		}
		if(opcion=='s'){
			rtn=1;
		}
		else{
			rtn=0;
		}


	return rtn;
}

int OpcionAoB(char mensaje[]){
	int contadorIntentos=0;
	int rtn=-1;
	char opcion;
		printf("%s \n", mensaje);
		CleanBuff;
		scanf("%c", &opcion);
		opcion=tolower(opcion);
		while(opcion != 'a' && opcion != 'b'){
			 contadorIntentos++;
			if(contadorIntentos==3){
				rtn=-1;
			 	break;
			}
			printf("%s \n", mensaje);
			CleanBuff;
			scanf("%c", &opcion);
			opcion=tolower(opcion);

		}
		if(opcion=='a'){
			rtn=1;
		}
		if(opcion=='b'){
			rtn=2;
		}


	return rtn;
}

