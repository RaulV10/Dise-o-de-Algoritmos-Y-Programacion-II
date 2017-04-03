//
//  Actividad-1.cpp
//  
//
//  Created by Raul Villarreal on 2/14/17.
//
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

// Mostrar y Repetir Menu
int mostrarMenu();

// Funciones en las que pregunta por los datos
void revalidacionVehicular();
void ordenarPalabra();
void fPrimo();
void pilaYCola();
void fCuentaNom();
bool repetir();

// Funciones en los que muestra el resultado pedido por la profesora
void mostrarRevalidacionVehicular(char *, int *, char *, float *);
void mostrarPalabraOrdenada(char *, int);
char* mostrarPrimo(int *); 
void mostrarCola(char *[15],int);
void mostrarPila(char *[15],int);
int mostrarFCuentaNom(char *[20], char *, int);

int main() {
	
	char *password;
	const char matricula[7] = "301654";
	int opc;
	
	// Reservar memoria para la contraseña
	password = (char *) malloc(20*sizeof(char));
	
	do {
		printf("Introduzca la contrase%ca: ", 164);
		fflush(stdin);
		scanf("%s", password);
		
		if(strcmp(password, matricula) == 0) {
			printf("\n********** BIENVENIDO **********\n");
		} else {
			printf("Contrase%ca incorrecta!\n", 164);
		}
	} while(strcmp(password, matricula) != 0);
	
	// Ciclo para cerrar el programa hasta que el usuario lo pida
	do{
		opc = mostrarMenu();
		
		switch(opc){
			case 1:
				revalidacionVehicular();
				break;
			case 2:
				ordenarPalabra();
				break;
			case 3:
				fPrimo();
				break;
			case 4:
				pilaYCola();
				break;
			case 5:
				fCuentaNom();
				break;
			default:
				break;
		}
		
	}while(repetir());
	
	return 0;
}

int mostrarMenu() {
	int opc = 0;
	
	printf("\n************* MENU *************\n\n");
	
	printf("1) Revalidacion Vehicular\n");
	printf("2) Ordenar Letras\n");
	printf("3) Numeros Primos\n");
	printf("4) Pilas y Colas\n");
	printf("5) Nombres\n");
	
	do {
		printf("\nSeleccione una opcion: ");
		scanf("%d", &opc);
	} while(opc < 1 || opc > 5);
	
	return opc;
}

bool repetir() {
	int opc = 0;
	
	printf("\n\n************* MENU *************\n");
	
	printf("1) Menu Principal\n");
	printf("2) Salir\n");
	
	do {
		printf("\nSeleccione una opcion: ");
		scanf("%d", &opc);
	} while(opc < 1 || opc > 2);
	
	if(opc == 1) {
		return true;
	} else {
		return false;
	}
}

void revalidacionVehicular() {
	char *propietario;
	int *edad;
	char *placas;
	float *pago;
	
	// Reservar memoria para el Nombre, Edad, Placas y Pago
	propietario = (char *) malloc(20*sizeof(char));
	edad = (int *) malloc(sizeof(int));
	placas = (char *) malloc(10*sizeof(char));
	pago = (float *) malloc(sizeof(float));
	
	// Pedir Nombre de Propietario
	printf("Introduzca el Nombre del Propietario: ");
	fflush(stdin);
	scanf("%s", propietario);
	
	// Validad edad
	do {
		printf("Introduzca la edad de %s: ", propietario);
		fflush(stdin);
		scanf("%d", edad);
		
		if((*edad <=0) || (*edad > 130)) {
			printf("Edad invalida!\nEdad no puede ser negativa ni mayor a 130\n");
		}
	} while((*edad <=0) || (*edad > 130));
	
		
	// Pedir Numero de Placas
	printf("Introduzca el Numero de Placas: ");
	fflush(stdin);
	scanf("%s", placas);
	
	// Pedir Pago
	// Pedir Nombre de Propietario
	printf("Introduzca el Monto a Pagar: ");
	fflush(stdin);
	scanf("%f", pago);
	
	// Llamar a la funcion para mostrar los registros
	mostrarRevalidacionVehicular(propietario, edad, placas, pago);
	
	// Liberar la memoria
	free(propietario);
	free(edad);
	free(placas);
	free(pago);
	
}

void ordenarPalabra() {
	// Declaracion de variables
	char *palabra;
	int n = 0;
	
	// Reservar memoria para la palabra
	palabra = (char *) malloc(20*sizeof(char));
	
	// Pedir palabra
	printf("Introduzca la palabra: ");
	fflush(stdin);
	scanf("%s", palabra);
	
	// Obtener longitud de la palabra
	n = strlen(palabra);
	
	// Mostrar Informacion
    printf("\n********** Ordenar Palabra *********");
    
    printf("\n--------------------------------------------\n");
    printf("\t   Informacion Registrada\n");
    printf("---------------------------------------------\n");
    
	printf("Escrito:\t\t%s", palabra);
	mostrarPalabraOrdenada(palabra, n); // Mandar a llamar a la funcion mandando como parametros el escrito y tamaño
	
	// Liberar memoria
	free(palabra);
}

void fPrimo() {
	// Declaracion de variables
	int *numero;
	char *primo;
	
	// Reservar memoria
	numero = (int *) malloc(sizeof(int));
	
	// Pedir numero a evaluar
	printf("Introduzca un numero: ");
	fflush(stdin);
	scanf("%d", numero);
	
	// Manda a la funcion el puntero y regresa un valor indicando si es primo o no
	primo = mostrarPrimo(numero);
	
	// Mostrar Informacion
    printf("\n********** Numeros Primos *********");
    
    printf("\n---------------------------------------\n");
    printf("\tInformacion Registrada\n");
    printf("----------------------------------------\n");
	printf("\t    %d %s es primo", *numero, primo);
	
	// Liberar memoria
	free(numero);
}

void pilaYCola() {
	// Declaracion de variables
	int n, i;
	
	// Pedir cantidad de nombres a ingresar
	do {
        printf("Introduzca la cantidad de nombres: ");
        scanf("%d", &n);
        
        if(n<=0 || n>15) {
            printf("La cantidad debe ser entre 1 y 15\n");
        } 
        
    } while (n<=0 || n>15);
    
    // Declaracion del arreglo de nombres
	char *nombres[n];
	
	// Reservar memoria para cada nombre
    for (i=0; i<n; i++) {
        nombres[i] = (char *) malloc(20*sizeof(char));
    }
    
    // Almacenar los nombres
    for (i=0; i<n; i++) {
        printf("Introduzca nombre #%d: ", (i+1));
        fflush(stdin);
        gets(nombres[i]);
    }
    
    printf("\n");
    mostrarCola(nombres, n);
    printf("\n");
    mostrarPila(nombres, n);
    
    // Liberar la Memoria
   	for(i=0;i<n;i++){
		free(nombres[i]);
	}
}

void fCuentaNom() {
	// Declaracion de Variables
	char *nombres[20];
	char *nombreTmp;
	int i, n, cantidad;
	
	// Pedir cantidad de nombres a ingresar
	printf("Introduzca la cantidad de nombres: ");
    scanf("%d", &n);
	
	// Reservar memoria para cada nombre
    for (i=0; i<n; i++) {
        nombres[i] = (char *) malloc(20*sizeof(char));
    }
    
    // Reservar memoria para nombreTmp
    nombreTmp = (char *) malloc(20*sizeof(char));
    
    // Almacenar los nombres
    for (i=0; i<n; i++) {
        printf("Introduzca nombre #%d: ", (i+1));
        fflush(stdin);
        gets(nombres[i]);
    }
    
    // Introducir nombre a contar
    printf("\nIntroduzca el nombre a contar: ");
	fflush(stdin);
	gets(nombreTmp);
    
    // Llamar a la funcion para mostrar nombres y que regrese un valor
    cantidad = mostrarFCuentaNom(nombres, nombreTmp, n);
    
    // Mostrar Nombres
	printf("\n\n***************** Nombres *****************");
	
	printf("\n-----------------------------------------\n");
    printf("\t    Nombres Ingresados\n");
    printf("------------------------------------------\n");
    
    // Pintar de color verde el nombre a buscar
   	for(i=0;i<n;i++){
		if(strcmp(nombres[i],nombreTmp) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
			printf("%s\n", nombres[i]);
		} else {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
			printf("%s\n", nombres[i]);
		}
   	}
   	
   	// Regresar al color original y mostrar resultado
   	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
    printf("\n%s se repite %d veces", nombreTmp, cantidad);
    
    // Liberar Memoria
    for(i=0;i<n;i++){
		free(nombres[i]);
	}
	free(nombreTmp);
}

void mostrarRevalidacionVehicular(char *propietario, int *edad, char *placas, float *pago) {
	
	// Mostrar Informacion
    printf("\n********** Revalidacion Vehicular *********");
    
    printf("\n--------------------------------------------\n");
    printf("\t   Informacion Registrada\n");
    printf("---------------------------------------------\n");
    
    // Mostrar Informacion Registrada
    printf("Nombre:\t\t\t%s", propietario);
	printf("\nEdad:\t\t\t%d", *edad);
	printf("\nPlacas:\t\t\t%s", placas);
	printf("\nPago:\t\t\t$%.2f", *pago);
	
	// Si es mayor de 60 años hacer y mostrar un 50% de descuento
    if((*edad >= 60)) {
		printf("\nDescuento:\t\t50%c", 37);
		printf("\nPago Total:\t\t$%.2f", (*pago * .5));
	} else {
		printf("\nDescuento:\t\tSin Descuento");
		printf("\nPago Total:\t\t$%.2f", *pago);
	}
}

void mostrarPalabraOrdenada(char *palabra, int n) {
	
	// Declaracion de Variables
	int i, j, aux;
	
	// Comenzar el Booble Sort para ir acomodando las palabras de mayor a menor
	for(i=0; i < n; i++) {
		for(j= (i+1); j < n; j++) {
			if(*(palabra+j) < *(palabra+i)) {
				aux = *(palabra + j);
				*(palabra + j) = *(palabra + i);
				*(palabra + i) = aux;
			}
		}
	}
    
	printf("\nOrdenado:\t\t%s", palabra);
}

char* mostrarPrimo(int *numero) {
	
	// Delcarar las variables
	int i;
	char *primo;
	
	// Reservar memoria
	primo = (char *) malloc(20*sizeof(char));
	
	// Verificamos si el usuario ingreso 1, el cual no es primo
	if(*numero == 1) {
		strcpy(primo, "NO");
	}
	
	// Ciclamos para ver si el numero es primo
	for(i = 2; i <= (*numero - 1); i++) {
		if(*numero%i == 0) {
			strcpy(primo, "NO");
			break;
		}
	}
	
	// Si el numero no se llego a dividir en el ciclo anterior significa que solo es divisible por si mismo
	// Lo cual lo hace primo
	if(i == *numero) {
		strcpy(primo, "SI");
	}
	
	return primo;
	free(primo);
}

void mostrarCola(char *nombres[15],int n){
	
	int i;
	char *ordenIngresado[n];
	
	// Mostrar Nombres
	printf("***************** Cola *****************");
	
	printf("\n-----------------------------------------\n");
    printf("Orden Ingresado\t\tOrden en Cola\n");
    printf("------------------------------------------\n");
    
   	for(i=0;i<n;i++){
		printf("%s\t\t\t%s\n", nombres[i], nombres[i]);
   	}
}

void mostrarPila(char *nombres[15],int n){
	
	// Declaracion de Variables
	int i;
    
    // Mostrar Nombres
	printf("***************** Pila *****************");
	
	printf("\n-----------------------------------------\n");
    printf("Orden Ingresado\t\tOrden en Pila\n");
    printf("------------------------------------------\n");
    
	for(i=(n-1);i>=0;i--){
		printf("%s\t\t\t%s\n", nombres[n-(i + 1)], nombres[i]);
	}	
}

int mostrarFCuentaNom(char *nombres[20], char *nombreTmp, int n){
	int i;
	int cont = 0;
	
	for(i=0;i<n;i++){
		if(strcmp(nombres[i],nombreTmp) == 0){
			cont++;
		}
	}	
	return cont;
}
