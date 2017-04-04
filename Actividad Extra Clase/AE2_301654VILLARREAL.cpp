#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>

// Estructuras
typedef struct { 
		char nombreMat[30]; 
		float calif[3]; 
		float promMat;
	} MAT; 
	
typedef struct { 
	long int *matricula; 
	char nombre[30]; 
	int nMaterias;
	MAT materias[15];
	float prom;
} EST; 
	
typedef struct { 
	long int *matricula; 
	char nombre[30]; 
	int nMaterias;
	MAT *materias;
	float prom;
} ESTP; 
	
// Bloquear Sistema y limpiar pantalla
void bloquearSistema();
void clearScreen();

// Mostrar y Repetir Menu
int mostrarMenu();
bool repetir();

// Selecciones del Menu
void estructuraArreglos();
void estrucuraPunteros();
void estructuraArreglosPuntero();
void estructuraPunterosArreglos();

// Funciones para mostrar
void mostrarEstructuraArreglos(EST[], int);
void mostrarEstrucuraPunteros(ESTP *, int);
void mostrarEstructuraArreglosPuntero(ESTP [], int);
void mostrarEstructuraPunterosArreglos(EST *, int);


int main() {
	
	char *password;
	const char apellido[11] = "VILLARREAL";
	int opc, passCount = 0;
	
	// Reservar memoria para la contraseña
	password = (char *) malloc(20*sizeof(char));
	
	do {
		printf("Introduzca la contrase%ca: ", 164);
		fflush(stdin);
		scanf("%s", password);
		
		if(strcmp(password, apellido) == 0) {
			printf("\n********** BIENVENIDO **********\n");
		} else {
			printf("Contrase%ca incorrecta!\n", 164);
			passCount++;
			if(passCount == 3) {
				bloquearSistema();
			}
		}
	} while(strcmp(password, apellido) != 0);
	
	// Ciclo para cerrar el programa hasta que el usuario lo pida
	do{
		opc = mostrarMenu();
		
		switch(opc){
			case 1:
				// Estructura - arreglos
				clearScreen();
				estructuraArreglos();
				break;
			case 2:
				clearScreen();
				estrucuraPunteros();
				break;
			case 3:
				clearScreen();
				estructuraArreglosPuntero();
				break;
			case 4:
				clearScreen();
				estructuraPunterosArreglos();
				break;
			case 5:
				exit(EXIT_SUCCESS);
			default:
				break;
		}
		
	}while(repetir());
	
	// Liberar Memoria
	free(password);
	
	return 0;
}

int mostrarMenu() {
	clearScreen();
	
	int opc = 0;
	
	printf("\n************* MENU *************\n\n");
	
	printf("1) Estructura - arreglos\n");
	printf("2) Estructura - punteros\n");
	printf("3) Estructura - arreglos-punteros\n");
	printf("4) Estructura - punteros- arreglos\n");
	printf("5) Salir\n");
	
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

void bloquearSistema() {
	while(1 > 0) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		printf("CONTRASE%cA INCORRECTA - SISTEMA BLOQUEADO!!!!!\n", 164);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
		printf("CONTRASE%cA INCORRECTA - SISTEMA BLOQUEADO!!!!!\n", 164);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
		printf("CONTRASE%cA INCORRECTA - SISTEMA BLOQUEADO!!!!!\n", 164);
		//system("C:\\WINDOWS\\System32\\shutdown /s");
	}
}

void clearScreen() {
	system("cls");
}

void estructuraArreglos() {
	// // Estructura - Arreglos
	
	void mostrarPrimero(EST [], int);
	
	printf("***** Estructura - Arreglos *****\n\n");
	
	int n, i, j, k;
	
	// Validar estudiantes
	do{
		printf("Introduzca numero de estudiantes: ");
		scanf("%d", &n);
	
		if(n <= 0 || n > 40) { printf("\nEl numero de estudiantes debe ser entre 1 y 40!!!\n\n"); }

	}while(n <= 0 || n > 40);
	
	// Declarar variable de estudiantes
	EST e[n];
	
	// Reservar Memoria para matriculas
	for(i = 0; i < n; i++) {
		e[i].matricula = (long int *) malloc(sizeof(long int));	
	}
	
	for(int i = 0; i < n; i++) {
		printf("\n*** ESTUDIANTE #%d ***\n", (i+1));
		
		printf("Matricula: "); 
		scanf("%d", e[i].matricula);
		
		fflush(stdin);
		printf("Nombre: "); 
		gets(e[i].nombre);
	
		do{
			printf("Numero de materias: ");
			scanf("%d", &e[i].nMaterias);
			
			if(e[i].nMaterias < 0 || e[i].nMaterias > 15) {
				printf("La cantidad de materias debe ser entre 1 y 15!!!\n");	
			}
			
		}while(e[i].nMaterias < 0 || e[i].nMaterias > 15);
		
		e[i].prom = 0;
		
		for(j = 0; j < e[i].nMaterias; j++) {
			printf("\n\n*** MATERIA #%d ***\n", (j+1));
			
			printf("Nombre Materia: ");
			fflush(stdin);
			gets(e[i].materias[j].nombreMat);
			
			e[i].materias[j].promMat = 0;
			
			for(k = 0; k < 3; k++) {
				do{
					printf("Calificacion Parcial %d: ", (k+1));
					scanf("%f", &e[i].materias[j].calif[k]);
					
					if(e[i].materias[j].calif[k] < 0 || e[i].materias[j].calif[k] > 10) {
						printf("La calificacion debe ser entre 0 y 10!!!\n");
					}
					
					e[i].materias[j].promMat += e[i].materias[j].calif[k];
					
				}while(e[i].materias[j].calif[k] < 0 || e[i].materias[j].calif[k] > 10);
			}
			
			e[i].materias[j].promMat = (e[i].materias[j].promMat)/3;
			
			e[i].prom += e[i].materias[j].promMat;
			
		}
		
		e[i].prom = (e[i].prom)/(e[i].nMaterias);
		
	}
	
	// Llamar a la funcion
	mostrarEstructuraArreglos(e, n);
	
	// Liberar Memoria
	for(i = 0; i < n; i++) {
		free(e[i].matricula);
	}
}

void mostrarEstructuraArreglos(EST e[], int n) {
	int i, j;
	
	// MOSTRAR DATOS
	for(i = 0; i < n; i++) {
		printf("\n\n***** DATOS DEL ALUMNO #%d *****\n", (i+1));
		
		printf("Matricula: %ld\n", *e[i].matricula);
		printf("Nombre: %s\n", e[i].nombre);
		printf("Materias: \n");
		
		for(j = 0; j < e[i].nMaterias; j++) {
			printf("\tNombre: %s\n", e[i].materias[j].nombreMat);
			printf("\tPromedio de la Materia: %.2f\n\n", e[i].materias[j].promMat);
		}
		
		printf("Promedio Total: %.2f\n", e[i].prom);
	}
}

void estrucuraPunteros() {
	// Estructura - Punteros
	
	printf("***** Estructura - Punteros *****\n\n");
	
	int n, i, j, k;
	
	// Declarar variable de estudiantes
	ESTP *e;
	
	// Validar estudiantes
	do{
		printf("Introduzca numero de estudiantes: ");
		scanf("%d", &n);
	
		if(n <= 0 || n > 40) { printf("\nEl numero de estudiantes debe ser entre 1 y 40!!!\n\n"); }

	}while(n <= 0 || n > 40);
	
	// Reservar memoria para EST
	e = (ESTP *) malloc(n*sizeof(ESTP));
	
	// Reservar Memoria para matriculas
	for(i = 0; i < n; i++) {
		e->matricula = (long int *) malloc(sizeof(long int));	
		e++;
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
	
	for(int i = 0; i < n; i++) {
		printf("\n*** ESTUDIANTE #%d ***\n", (i+1));
		
		printf("Matricula: "); 
		scanf("%d", e->matricula);
		
		fflush(stdin);
		printf("Nombre: "); 
		gets(e->nombre);
	
		do{
			printf("Numero de materias: ");
			scanf("%d", &e->nMaterias);
			
			if(e->nMaterias < 0 || e->nMaterias > 15) {
				printf("La cantidad de materias debe ser entre 1 y 15!!!\n");	
			}
			
		}while(e->nMaterias < 0 || e->nMaterias > 15);
		
		e->prom = 0;
		
		// Reservar memoria para MAT
		e->materias = (MAT *) malloc(e->nMaterias*sizeof(MAT));
		
		for(j = 0; j < e->nMaterias; j++) {
			printf("\n\n*** MATERIA #%d ***\n", (j+1));
			
			printf("Nombre Materia: ");
			fflush(stdin);
			gets(e->materias->nombreMat);
			
			e->materias->promMat = 0;
			
			for(k = 0; k < 3; k++) {
				do{
					printf("Calificacion Parcial %d: ", (k+1));
					scanf("%f", &e->materias->calif[k]);
					
					if(e->materias->calif[k] < 0 || e->materias->calif[k] > 10) {
						printf("La calificacion debe ser entre 0 y 10!!!\n");
					}
					
					e->materias->promMat += e->materias->calif[k];
					
				}while(e->materias->calif[k] < 0 || e->materias->calif[k] > 10);
				
			}
			
			e->materias->promMat = (e->materias->promMat)/3;
			
			e->prom += e->materias->promMat;
			
			e->materias++;	
		}
		
		e->materias = e->materias - e->nMaterias;
		
		e->prom = (e->prom)/(e->nMaterias);
		
		e++;
		
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
	
	// Llamar a la funcion mostrar
	mostrarEstrucuraPunteros(e, n);
	
	// Liberar Memoria
	for(i = 0; i < n; i++) {
		free(e->matricula);
		e++;
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
	
	free(e->materias);
	free(e);
}

void mostrarEstrucuraPunteros(ESTP *e, int n) {
	int i, j;
	// MOSTRAR DATOS
	for(i = 0; i < n; i++) {
		printf("\n\n***** DATOS DEL ALUMNO #%d *****\n", (i+1));
		
		printf("Matricula: %ld\n", *e->matricula);
		printf("Nombre: %s\n", e->nombre);
		printf("Materias: \n");
		
		for(j = 0; j < e->nMaterias; j++) {
			printf("\tNombre: %s\n", e->materias->nombreMat);
			printf("\tPromedio de la Materia: %.2f\n\n", e->materias->promMat);
			e->materias++;
		}
		
		e->materias = e->materias - e->nMaterias;
		
		printf("Promedio Total: %.2f\n", e->prom);
		
		e++;
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
}

void estructuraArreglosPuntero() {
	
	printf("***** Estructura - Arreglos-Punteros *****\n\n");
	
	int n, i, j, k;
		
	// Validar estudiantes
	do{
		printf("Introduzca numero de estudiantes: ");
		scanf("%d", &n);
	
		if(n <= 0 || n > 40) { printf("\nEl numero de estudiantes debe ser entre 1 y 40!!!\n\n"); }

	}while(n <= 0 || n > 40);
	
	// Declarar variable de estudiantes
	ESTP e[n];

	
	// Reservar Memoria para matriculas
	for(i = 0; i < n; i++) {
		e[i].matricula = (long int *) malloc(sizeof(long int));	
	}
	
	
	for(int i = 0; i < n; i++) {
		printf("\n*** ESTUDIANTE #%d ***\n", (i+1));
		
		printf("Matricula: "); 
		scanf("%d", e[i].matricula);
		
		fflush(stdin);
		printf("Nombre: "); 
		gets(e[i].nombre);
	
		do{
			printf("Numero de materias: ");
			scanf("%d", &e[i].nMaterias);
			
			if(e[i].nMaterias < 0 || e[i].nMaterias > 15) {
				printf("La cantidad de materias debe ser entre 1 y 15!!!\n");	
			}
			
		}while(e[i].nMaterias < 0 || e[i].nMaterias > 15);
		
		e[i].prom = 0;
		
		// Reservar memoria para MAT
		e[i].materias = (MAT *) malloc(e[i].nMaterias*sizeof(MAT));
		
		for(j = 0; j < e[i].nMaterias; j++) {
			printf("\n\n*** MATERIA #%d ***\n", (j+1));
			
			printf("Nombre Materia: ");
			fflush(stdin);
			gets(e[i].materias->nombreMat);
			
			e[i].materias->promMat = 0;
			
			for(k = 0; k < 3; k++) {
				do{
					printf("Calificacion Parcial %d: ", (k+1));
					scanf("%f", &e[i].materias->calif[k]);
					
					if(e[i].materias->calif[k] < 0 || e[i].materias->calif[k] > 10) {
						printf("La calificacion debe ser entre 0 y 10!!!\n");
					}
					
					e[i].materias->promMat += e[i].materias->calif[k];
					
				}while(e[i].materias->calif[k] < 0 || e[i].materias->calif[k] > 10);
				
			}
			
			e[i].materias->promMat = (e[i].materias->promMat)/3;
			
			e[i].prom += e[i].materias->promMat;
			
			e[i].materias++;	
		}
		
		e[i].materias = e[i].materias - e[i].nMaterias;
		
		e[i].prom = (e[i].prom)/(e[i].nMaterias);
	}
	
	// Llamar a la Funcion mostrar
	mostrarEstructuraArreglosPuntero(e, n);
	
	// Liberar Memoria
	for(i = 0; i < n; i++) {
		free(e[i].matricula);
		free(e[i].materias);
	}
}

void mostrarEstructuraArreglosPuntero(ESTP e[], int n) {
	int i, j;
	// MOSTRAR DATOS
	for(i = 0; i < n; i++) {
		printf("\n\n***** DATOS DEL ALUMNO #%d *****\n", (i+1));
		
		printf("Matricula: %ld\n", *e[i].matricula);
		printf("Nombre: %s\n", e[i].nombre);
		printf("Materias: \n");
		
		for(j = 0; j < e[i].nMaterias; j++) {
			printf("\tNombre: %s\n", e[i].materias->nombreMat);
			printf("\tPromedio de la Materia: %.2f\n\n", e[i].materias->promMat);
			e[i].materias++;
		}
		
		e[i].materias = e[i].materias - e[i].nMaterias;
		
		printf("Promedio Total: %.2f\n", e[i].prom);
		
	}
}

void estructuraPunterosArreglos() {
	// Estructura - Punteros-Arreglos
	
	printf("***** Estructura - Punteros-Arreglos *****\n\n");
	
	int n, i, j, k;
	
	// Declarar variable de estudiantes
	EST *e;
	
	// Validar estudiantes
	do{
		printf("Introduzca numero de estudiantes: ");
		scanf("%d", &n);
	
		if(n <= 0 || n > 40) { printf("\nEl numero de estudiantes debe ser entre 1 y 40!!!\n\n"); }

	}while(n <= 0 || n > 40);
	
	// Reservar memoria para EST
	e = (EST *) malloc(n*sizeof(EST));
	
	// Reservar Memoria para matriculas
	for(i = 0; i < n; i++) {
		e->matricula = (long int *) malloc(sizeof(long int));	
		e++;
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
	
	for(int i = 0; i < n; i++) {
		printf("\n*** ESTUDIANTE #%d ***\n", (i+1));
		
		printf("Matricula: "); 
		scanf("%d", e->matricula);
		
		fflush(stdin);
		printf("Nombre: "); 
		gets(e->nombre);
	
		do{
			printf("Numero de materias: ");
			scanf("%d", &e->nMaterias);
			
			if(e->nMaterias < 0 || e->nMaterias > 15) {
				printf("La cantidad de materias debe ser entre 1 y 15!!!\n");	
			}
			
		}while(e->nMaterias < 0 || e->nMaterias > 15);
		
		e->prom = 0;
		
		for(j = 0; j < e->nMaterias; j++) {
			printf("\n\n*** MATERIA #%d ***\n", (j+1));
			
			printf("Nombre Materia: ");
			fflush(stdin);
			gets(e->materias[j].nombreMat);
			
			e->materias[j].promMat = 0;
			
			// Calificaciones de 3 parciales
			for(k = 0; k < 3; k++) {
				do{
					printf("Calificacion Parcial %d: ", (k+1));
					scanf("%f", &e->materias[j].calif[k]);
					
					if(e->materias[j].calif[k] < 0 || e->materias[j].calif[k] > 10) {
						printf("La calificacion debe ser entre 0 y 10!!!\n");
					}
					
					e->materias[j].promMat += e->materias[j].calif[k];
					
				}while(e->materias[j].calif[k] < 0 || e->materias[j].calif[k] > 10);
				
			}
			
			e->materias[j].promMat = (e->materias[j].promMat)/3;
			
			e->prom += e->materias[j].promMat;
				
		}
		
		e->prom = (e->prom)/(e->nMaterias);
		
		e++;
		
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
	
	// Llamar a la funcion
	mostrarEstructuraPunterosArreglos(e, n);
	
	// Liberar Memoria
	for(i = 0; i < n; i++) {
		free(e->matricula);
		e++;
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
	free(e);
}

void mostrarEstructuraPunterosArreglos(EST *e, int n) {
	int i, j;
	// MOSTRAR DATOS
	for(i = 0; i < n; i++) {
		printf("\n\n***** DATOS DEL ALUMNO #%d *****\n", (i+1));
		
		printf("Matricula: %ld\n", *e->matricula);
		printf("Nombre: %s\n", e->nombre);
		printf("Materias: \n");
		
		for(j = 0; j < e->nMaterias; j++) {
			printf("\tNombre: %s\n", e->materias[j].nombreMat);
			printf("\tPromedio de la Materia: %.2f\n\n", e->materias[j].promMat);
		}
		
		printf("Promedio Total: %.2f\n", e->prom);
		e++;
	}
	
	// Regresar a la direccion de memoria inicial
	e = e - n;
}
